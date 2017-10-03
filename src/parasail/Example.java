package parasail;

import java.io.File;
import java.io.FileNotFoundException;
import java.lang.String;
import java.lang.StringBuilder;
import java.util.ArrayList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.List;
import java.util.Scanner;

class Example {

    public static int open;
    public static int gap;
    public static Matrix matrix;
    public static boolean do_cigar;

    private static class AlignTask implements Runnable {

        private Sequence s1;
        private Sequence s2;
        private Result result;

        public AlignTask(Sequence s1, Sequence s2) {
            this.s1 = s1;
            this.s2 = s2;
        }

        @Override
        public void run() {
            result = Aligner.sw(s1.getData(), s2.getData(), Example.open, Example.gap, Example.matrix);
            System.out.println(toString() + " = " + result.getScore());
            result.delete();

        }

        public String toString() {
            String n1 = s1.getName();
            String n2 = s2.getName();
            StringBuilder ret = new StringBuilder();
            if (n1.length() > 33) {
                ret.append(n1.substring(0,15));
                ret.append("...");
                ret.append(n1.substring(n1.length()-15));
            }
            else {
                ret.append(n1);
            }
            ret.append(" <-> ");
            if (n2.length() > 33) {
                ret.append(n2.substring(0,15));
                ret.append("...");
                ret.append(n2.substring(n2.length()-15));
            }
            else {
                ret.append(n2);
            }
            return ret.toString();
        }
    }

    private static class CigarTask implements Runnable {

        private Sequence s1;
        private Sequence s2;
        private Result result;

        public CigarTask(Sequence s1, Sequence s2) {
            this.s1 = s1;
            this.s2 = s2;
        }

        @Override
        public void run() {
            result = Aligner.sw_trace(s1.getData(), s2.getData(), Example.open, Example.gap, Example.matrix);
            System.out.println(toString() + " = " + result.getCigar(s1.getData(), s2.getData(), Example.matrix).decode());
            result.delete();

        }

        public String toString() {
            String n1 = s1.getName();
            String n2 = s2.getName();
            StringBuilder ret = new StringBuilder();
            if (n1.length() > 33) {
                ret.append(n1.substring(0,15));
                ret.append("...");
                ret.append(n1.substring(n1.length()-15));
            }
            else {
                ret.append(n1);
            }
            ret.append(" <-> ");
            if (n2.length() > 33) {
                ret.append(n2.substring(0,15));
                ret.append("...");
                ret.append(n2.substring(n2.length()-15));
            }
            else {
                ret.append(n2);
            }
            return ret.toString();
        }
    }

    private static class Sequence {
        private String name;
        private String data;
        public Sequence(String name, String data) {
            this.name = name;
            this.data = data;
        }
        public String getName() {
            return name;
        }
        public String getData() {
            return data;
        }
    }

    public static ArrayList<Sequence> parse_fasta(String filename) {
        ArrayList<Sequence> sequences = new ArrayList<Sequence>();
        boolean first = true;
        String name = new String();
        String last_name = new String();
        String current = new String();
        try (Scanner sc = new Scanner(new File(filename))) {
            while (sc.hasNextLine()) {
                String line = sc.nextLine().trim();
                if (line.charAt(0) == '>') {
                    last_name = name;
                    name = line;
                    if (first) {
                        first = false;
                    }
                    else {
                        sequences.add(new Sequence(last_name,current));
                        current = "";
                    }
                } else {
                    current += line;
                }
            }
            sequences.add(new Sequence(name,current));
        }
        catch (FileNotFoundException e){
            e.printStackTrace();
        }
        return sequences;
    }

    public static void print_help() {
        System.out.println("parasail.Example [options] filename.fasta");
        System.out.println("Options:");
        System.out.println("  -t number of threads");
        System.out.println("  -o gap open penalty");
        System.out.println("  -e gap extension penalty");
        System.out.println("  -m matrix name");
        System.out.println("  -c (no arg), print cigar");
        System.out.println("  -h this help");
    }

    public static void main(String[] args) {
        Example.open = 10;
        Example.gap = 1;
        Example.matrix = Matrix.blosum62;
        ArrayList<Sequence> sequences = null;
        int threads = 1;
        String filename = null;

        for (int i = 0; i < args.length; i++) {
            switch (args[i].charAt(0)) {
                case '-':
                    if (args[i].charAt(1) == 'h') {
                        print_help();
                        System.exit(0);
                    }
                    else if (args[i].charAt(1) == 'c') {
                        Example.do_cigar = true;
                    }
                    else {
                        if (args.length-1 == i) {
                            throw new IllegalArgumentException("Expected arg after: "+args[i]);
                        }
                        if (args[i].length() != 2) {
                            throw new IllegalArgumentException("Not a valid argument: "+args[i]);
                        }
                        if (args[i].charAt(1) == 't') {
                            threads = Integer.parseInt(args[i+1]);
                        }
                        else if (args[i].charAt(1) == 'o') {
                            Example.open = Integer.parseInt(args[i+1]);
                        }
                        else if (args[i].charAt(1) == 'e') {
                            Example.gap = Integer.parseInt(args[i+1]);
                        }
                        else if (args[i].charAt(1) == 'm') {
                            Example.matrix = Matrix.lookup(args[i+1]);
                        }
                        else if (args[i].charAt(1) == 'm') {
                            Example.matrix = Matrix.lookup(args[i+1]);
                        }
                        else {
                            throw new IllegalArgumentException("Not a valid argument: "+args[i]);
                        }
                        i++;
                    }
                    break;
                default:
                    filename = args[i];
                    break;
            }
        }

        if (null == filename) {
            print_help();
            System.exit(0);
        }
        System.out.println("  filename: " + filename);
        System.out.println("   threads: " + threads);
        System.out.println("  gap open: " + Example.open);
        System.out.println("gap extend: " + Example.gap);
        System.out.println("    matrix: " + Example.matrix.getName());

        sequences = parse_fasta(filename);

        ExecutorService executor = Executors.newFixedThreadPool(threads);
        for (int i = 0; i < sequences.size(); i++) {
            for (int j = i+1; j < sequences.size(); j++) {
                Runnable worker = null;
                if (Example.do_cigar) {
                    worker = new CigarTask(sequences.get(i), sequences.get(j));
                }
                else {
                    worker = new AlignTask(sequences.get(i), sequences.get(j));
                }
                executor.execute(worker);
            }
        }
        executor.shutdown();
        while (!executor.isTerminated()) {
        }
        System.out.println("Finished all threads");
    }

}

