package parasail;

public class Matrix {
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
        }
        CPtr = 0;
    }

}

