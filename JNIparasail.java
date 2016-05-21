import java.lang.String;

public class JNIparasail {
    static {
        System.loadLibrary("parasail");
    }

    public static native long sw(byte[] s1, byte[] s2, int open, int extend, long matrix);

    public static void main(String[] args) {
        String s1 = "asdf";
        String s2 = "asdf";
        System.out.println("sw('asdf', 'asdf', ...");
        System.out.println(sw(s1.getBytes(), s2.getBytes(), -10, -1, 0));
    }
}

