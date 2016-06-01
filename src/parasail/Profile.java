package parasail;

import java.lang.String;

public class Profile {
    private long CPtr;
    protected boolean CMemOwn;

    protected Profile(long cPtr, boolean cMemoryOwn) {
        CMemOwn = cMemoryOwn;
        CPtr = cPtr;
    }

    protected static long getCPtr(Profile obj) {
        return (obj == null) ? 0 : obj.CPtr;
    }

    protected void finalize() {
        delete();
    }

    public synchronized void delete() {
        if(CPtr != 0 && CMemOwn) {
            CMemOwn = false;
            JNIparasail.profile_free(CPtr);
        }
        CPtr = 0;
    }

    public static Profile create_64(String s1, Matrix matrix) {
        return new Profile(JNIparasail.profile_create_64(s1, Matrix.getCPtr(matrix)), true);
    }

    public static Profile create_32(String s1, Matrix matrix) {
        return new Profile(JNIparasail.profile_create_32(s1, Matrix.getCPtr(matrix)), true);
    }

    public static Profile create_16(String s1, Matrix matrix) {
        return new Profile(JNIparasail.profile_create_16(s1, Matrix.getCPtr(matrix)), true);
    }

    public static Profile create_8(String s1, Matrix matrix) {
        return new Profile(JNIparasail.profile_create_8(s1, Matrix.getCPtr(matrix)), true);
    }

    public static Profile create_sat(String s1, Matrix matrix) {
        return new Profile(JNIparasail.profile_create_sat(s1, Matrix.getCPtr(matrix)), true);
    }

    public static Profile create_stats_64(String s1, Matrix matrix) {
        return new Profile(JNIparasail.profile_create_stats_64(s1, Matrix.getCPtr(matrix)), true);
    }

    public static Profile create_stats_32(String s1, Matrix matrix) {
        return new Profile(JNIparasail.profile_create_stats_32(s1, Matrix.getCPtr(matrix)), true);
    }

    public static Profile create_stats_16(String s1, Matrix matrix) {
        return new Profile(JNIparasail.profile_create_stats_16(s1, Matrix.getCPtr(matrix)), true);
    }

    public static Profile create_stats_8(String s1, Matrix matrix) {
        return new Profile(JNIparasail.profile_create_stats_8(s1, Matrix.getCPtr(matrix)), true);
    }

    public static Profile create_stats_sat(String s1, Matrix matrix) {
        return new Profile(JNIparasail.profile_create_stats_sat(s1, Matrix.getCPtr(matrix)), true);
    }

    public String getString() {
        return JNIparasail.profile_s1(CPtr);
    }

    public int getLength() {
        return JNIparasail.profile_s1Len(CPtr);
    }

    public Matrix getMatrix() {
        return new Matrix(JNIparasail.profile_matrix(CPtr), false);
    }
}

