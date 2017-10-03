package parasail;

public class Result {
    private long CPtr;
    protected boolean CMemOwn;

    protected Result(long cPtr, boolean cMemoryOwn) {
        CMemOwn = cMemoryOwn;
        CPtr = cPtr;
    }

    protected static long getCPtr(Result obj) {
        return (obj == null) ? 0 : obj.CPtr;
    }

    protected void finalize() {
        delete();
    }

    public synchronized void delete() {
        if(CPtr != 0 && CMemOwn) {
            CMemOwn = false;
            JNIparasail.result_free(CPtr);
        }
        CPtr = 0;
    }

    public boolean getSaturated() {
        return JNIparasail.result_saturated(CPtr);
    }

    public int getScore() {
        return JNIparasail.result_score(CPtr);
    }

    public int getMatches() {
        return JNIparasail.result_matches(CPtr);
    }

    public int getSimilar() {
        return JNIparasail.result_similar(CPtr);
    }

    public int getLength() {
        return JNIparasail.result_length(CPtr);
    }

    public int getEndQuery() {
        return JNIparasail.result_end_query(CPtr);
    }

    public int getEndRef() {
        return JNIparasail.result_end_ref(CPtr);
    }

    public Cigar getCigar(String s1, String s2, Matrix matrix) {
        return new Cigar(JNIparasail.result_cigar(CPtr, s1, s2, Matrix.getCPtr(matrix)), true);
    }
}

