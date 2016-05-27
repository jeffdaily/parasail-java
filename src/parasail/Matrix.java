package parasail;

import java.lang.String;
import java.util.Arrays;

public class Matrix {

    public static void main(String[] args) {
        System.out.println("matrix_name(Matrix.getCPtr(Matrix.blosum100))");
        System.out.println(JNIparasail.matrix_name(Matrix.getCPtr(Matrix.blosum100)));
        System.out.println(JNIparasail.matrix_size(Matrix.getCPtr(Matrix.blosum100)));
        System.out.println(JNIparasail.matrix_max(Matrix.getCPtr(Matrix.blosum100)));
        System.out.println(JNIparasail.matrix_min(Matrix.getCPtr(Matrix.blosum100)));
        System.out.println(Arrays.toString(JNIparasail.matrix_data(Matrix.getCPtr(Matrix.blosum62))));
        Matrix made = Matrix.create("asdf", 2, -1);
        System.out.println(Arrays.toString(JNIparasail.matrix_data(Matrix.getCPtr(made))));
        made.finalize();
    }

    private long CPtr;
    protected boolean CMemOwn;

    protected Matrix(long cPtr, boolean cMemoryOwn) {
        CMemOwn = cMemoryOwn;
        CPtr = cPtr;
    }

    protected static long getCPtr(Matrix obj) {
        return (obj == null) ? 0 : obj.CPtr;
    }

    protected void finalize() {
        delete();
    }

    public synchronized void delete() {
        if(CPtr != 0 && CMemOwn) {
            CMemOwn = false;
            if (JNIparasail.matrix_need_free(CPtr)) {
                JNIparasail.matrix_free(CPtr);
            }
        }
        CPtr = 0;
    }

    public String getName() {
        return JNIparasail.matrix_name(CPtr);
    }

    public int getSize() {
        return JNIparasail.matrix_size(CPtr);
    }

    public int getMax() {
        return JNIparasail.matrix_max(CPtr);
    }

    public int getMin() {
        return JNIparasail.matrix_min(CPtr);
    }

    public static Matrix create(String alphabet, int match, int mismatch) {
        return new Matrix(JNIparasail.matrix_create(alphabet, match, mismatch), true);
    }

    public static final Matrix blosum100= new Matrix(JNIparasail.matrix_lookup("blosum100"), false);
    public static final Matrix blosum30 = new Matrix(JNIparasail.matrix_lookup("blosum30" ), false);
    public static final Matrix blosum35 = new Matrix(JNIparasail.matrix_lookup("blosum35" ), false);
    public static final Matrix blosum40 = new Matrix(JNIparasail.matrix_lookup("blosum40" ), false);
    public static final Matrix blosum45 = new Matrix(JNIparasail.matrix_lookup("blosum45" ), false);
    public static final Matrix blosum50 = new Matrix(JNIparasail.matrix_lookup("blosum50" ), false);
    public static final Matrix blosum55 = new Matrix(JNIparasail.matrix_lookup("blosum55" ), false);
    public static final Matrix blosum60 = new Matrix(JNIparasail.matrix_lookup("blosum60" ), false);
    public static final Matrix blosum62 = new Matrix(JNIparasail.matrix_lookup("blosum62" ), false);
    public static final Matrix blosum65 = new Matrix(JNIparasail.matrix_lookup("blosum65" ), false);
    public static final Matrix blosum70 = new Matrix(JNIparasail.matrix_lookup("blosum70" ), false);
    public static final Matrix blosum75 = new Matrix(JNIparasail.matrix_lookup("blosum75" ), false);
    public static final Matrix blosum80 = new Matrix(JNIparasail.matrix_lookup("blosum80" ), false);
    public static final Matrix blosum85 = new Matrix(JNIparasail.matrix_lookup("blosum85" ), false);
    public static final Matrix blosum90 = new Matrix(JNIparasail.matrix_lookup("blosum90" ), false);
    public static final Matrix pam10    = new Matrix(JNIparasail.matrix_lookup("pam10"    ), false);
    public static final Matrix pam100   = new Matrix(JNIparasail.matrix_lookup("pam100"   ), false);
    public static final Matrix pam110   = new Matrix(JNIparasail.matrix_lookup("pam110"   ), false);
    public static final Matrix pam120   = new Matrix(JNIparasail.matrix_lookup("pam120"   ), false);
    public static final Matrix pam130   = new Matrix(JNIparasail.matrix_lookup("pam130"   ), false);
    public static final Matrix pam140   = new Matrix(JNIparasail.matrix_lookup("pam140"   ), false);
    public static final Matrix pam150   = new Matrix(JNIparasail.matrix_lookup("pam150"   ), false);
    public static final Matrix pam160   = new Matrix(JNIparasail.matrix_lookup("pam160"   ), false);
    public static final Matrix pam170   = new Matrix(JNIparasail.matrix_lookup("pam170"   ), false);
    public static final Matrix pam180   = new Matrix(JNIparasail.matrix_lookup("pam180"   ), false);
    public static final Matrix pam190   = new Matrix(JNIparasail.matrix_lookup("pam190"   ), false);
    public static final Matrix pam20    = new Matrix(JNIparasail.matrix_lookup("pam20"    ), false);
    public static final Matrix pam200   = new Matrix(JNIparasail.matrix_lookup("pam200"   ), false);
    public static final Matrix pam210   = new Matrix(JNIparasail.matrix_lookup("pam210"   ), false);
    public static final Matrix pam220   = new Matrix(JNIparasail.matrix_lookup("pam220"   ), false);
    public static final Matrix pam230   = new Matrix(JNIparasail.matrix_lookup("pam230"   ), false);
    public static final Matrix pam240   = new Matrix(JNIparasail.matrix_lookup("pam240"   ), false);
    public static final Matrix pam250   = new Matrix(JNIparasail.matrix_lookup("pam250"   ), false);
    public static final Matrix pam260   = new Matrix(JNIparasail.matrix_lookup("pam260"   ), false);
    public static final Matrix pam270   = new Matrix(JNIparasail.matrix_lookup("pam270"   ), false);
    public static final Matrix pam280   = new Matrix(JNIparasail.matrix_lookup("pam280"   ), false);
    public static final Matrix pam290   = new Matrix(JNIparasail.matrix_lookup("pam290"   ), false);
    public static final Matrix pam30    = new Matrix(JNIparasail.matrix_lookup("pam30"    ), false);
    public static final Matrix pam300   = new Matrix(JNIparasail.matrix_lookup("pam300"   ), false);
    public static final Matrix pam310   = new Matrix(JNIparasail.matrix_lookup("pam310"   ), false);
    public static final Matrix pam320   = new Matrix(JNIparasail.matrix_lookup("pam320"   ), false);
    public static final Matrix pam330   = new Matrix(JNIparasail.matrix_lookup("pam330"   ), false);
    public static final Matrix pam340   = new Matrix(JNIparasail.matrix_lookup("pam340"   ), false);
    public static final Matrix pam350   = new Matrix(JNIparasail.matrix_lookup("pam350"   ), false);
    public static final Matrix pam360   = new Matrix(JNIparasail.matrix_lookup("pam360"   ), false);
    public static final Matrix pam370   = new Matrix(JNIparasail.matrix_lookup("pam370"   ), false);
    public static final Matrix pam380   = new Matrix(JNIparasail.matrix_lookup("pam380"   ), false);
    public static final Matrix pam390   = new Matrix(JNIparasail.matrix_lookup("pam390"   ), false);
    public static final Matrix pam40    = new Matrix(JNIparasail.matrix_lookup("pam40"    ), false);
    public static final Matrix pam400   = new Matrix(JNIparasail.matrix_lookup("pam400"   ), false);
    public static final Matrix pam410   = new Matrix(JNIparasail.matrix_lookup("pam410"   ), false);
    public static final Matrix pam420   = new Matrix(JNIparasail.matrix_lookup("pam420"   ), false);
    public static final Matrix pam430   = new Matrix(JNIparasail.matrix_lookup("pam430"   ), false);
    public static final Matrix pam440   = new Matrix(JNIparasail.matrix_lookup("pam440"   ), false);
    public static final Matrix pam450   = new Matrix(JNIparasail.matrix_lookup("pam450"   ), false);
    public static final Matrix pam460   = new Matrix(JNIparasail.matrix_lookup("pam460"   ), false);
    public static final Matrix pam470   = new Matrix(JNIparasail.matrix_lookup("pam470"   ), false);
    public static final Matrix pam480   = new Matrix(JNIparasail.matrix_lookup("pam480"   ), false);
    public static final Matrix pam490   = new Matrix(JNIparasail.matrix_lookup("pam490"   ), false);
    public static final Matrix pam50    = new Matrix(JNIparasail.matrix_lookup("pam50"    ), false);
    public static final Matrix pam500   = new Matrix(JNIparasail.matrix_lookup("pam500"   ), false);
    public static final Matrix pam60    = new Matrix(JNIparasail.matrix_lookup("pam60"    ), false);
    public static final Matrix pam70    = new Matrix(JNIparasail.matrix_lookup("pam70"    ), false);
    public static final Matrix pam80    = new Matrix(JNIparasail.matrix_lookup("pam80"    ), false);
    public static final Matrix pam90    = new Matrix(JNIparasail.matrix_lookup("pam90"    ), false);
}

