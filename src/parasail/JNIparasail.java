package parasail;

import java.lang.String;

public class JNIparasail {
    static {
        System.loadLibrary("JNIparasail");
    }

    public static void main(String[] args) {
        String s1 = "asdf";
        String s2 = "asdf";
        System.out.println("sw('asdf', 'asdf', ...");
        //System.out.println(sw(s1.getBytes(), s2.getBytes(), -10, -1, Matrix.getCPtr(Matrix.blosum62)));
    }

    public static native String matrix_name(long CPtr);
    public static native int[] matrix_data(long CPtr);
    public static native int matrix_size(long CPtr);
    public static native int matrix_max(long CPtr);
    public static native int matrix_min(long CPtr);
    public static native boolean matrix_need_free(long CPtr);
    public static native long matrix_lookup(String name);
    public static native long matrix_create(String alphabet, int match, int mismatch);
    public static native void matrix_free(long CPtr);

    /* autogenerated */
    public static native long sw(byte[] s1, byte[] s2, int open, int extend, long matrix);

}
