package parasail;

import java.lang.String;
import java.util.Arrays;

public class Cigar {

    public static void main(String[] args) {
    }

    private long CPtr;
    protected boolean CMemOwn;

    protected Cigar(long cPtr, boolean cMemoryOwn) {
        CMemOwn = cMemoryOwn;
        CPtr = cPtr;
    }

    protected static long getCPtr(Cigar obj) {
        return (obj == null) ? 0 : obj.CPtr;
    }

    protected void finalize() {
        delete();
    }

    public synchronized void delete() {
        if(CPtr != 0 && CMemOwn) {
            CMemOwn = false;
            JNIparasail.cigar_free(CPtr);
        }
        CPtr = 0;
    }

    public int[] getSeq() {
        return JNIparasail.cigar_seq(CPtr);
    }

    public int getLen() {
        return JNIparasail.cigar_len(CPtr);
    }

    public int getBegQuery() {
        return JNIparasail.cigar_beg_query(CPtr);
    }

    public int getBegRef() {
        return JNIparasail.cigar_beg_ref(CPtr);
    }

    public String decode() {
        return JNIparasail.cigar_decode(CPtr);
    }

    public static int decode_op(int cigar_int) {
        return JNIparasail.cigar_decode_op(cigar_int);
    }

    public static int decode_len(int cigar_int) {
        return JNIparasail.cigar_decode_len(cigar_int);
    }

}

