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
            //JNIparasail.result_free(CPtr);
        }
        CPtr = 0;
    }

}

