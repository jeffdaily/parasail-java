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
            if (0 != JNIparasail.matrix_user_matrix(CPtr)) {
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

    public static Matrix lookup(String name) {
        return new Matrix(JNIparasail.matrix_lookup(name), false);
    }

    public static final Matrix blosum100= Matrix.lookup("blosum100");
    public static final Matrix blosum30 = Matrix.lookup("blosum30" );
    public static final Matrix blosum35 = Matrix.lookup("blosum35" );
    public static final Matrix blosum40 = Matrix.lookup("blosum40" );
    public static final Matrix blosum45 = Matrix.lookup("blosum45" );
    public static final Matrix blosum50 = Matrix.lookup("blosum50" );
    public static final Matrix blosum55 = Matrix.lookup("blosum55" );
    public static final Matrix blosum60 = Matrix.lookup("blosum60" );
    public static final Matrix blosum62 = Matrix.lookup("blosum62" );
    public static final Matrix blosum65 = Matrix.lookup("blosum65" );
    public static final Matrix blosum70 = Matrix.lookup("blosum70" );
    public static final Matrix blosum75 = Matrix.lookup("blosum75" );
    public static final Matrix blosum80 = Matrix.lookup("blosum80" );
    public static final Matrix blosum85 = Matrix.lookup("blosum85" );
    public static final Matrix blosum90 = Matrix.lookup("blosum90" );
    public static final Matrix pam10    = Matrix.lookup("pam10"    );
    public static final Matrix pam100   = Matrix.lookup("pam100"   );
    public static final Matrix pam110   = Matrix.lookup("pam110"   );
    public static final Matrix pam120   = Matrix.lookup("pam120"   );
    public static final Matrix pam130   = Matrix.lookup("pam130"   );
    public static final Matrix pam140   = Matrix.lookup("pam140"   );
    public static final Matrix pam150   = Matrix.lookup("pam150"   );
    public static final Matrix pam160   = Matrix.lookup("pam160"   );
    public static final Matrix pam170   = Matrix.lookup("pam170"   );
    public static final Matrix pam180   = Matrix.lookup("pam180"   );
    public static final Matrix pam190   = Matrix.lookup("pam190"   );
    public static final Matrix pam20    = Matrix.lookup("pam20"    );
    public static final Matrix pam200   = Matrix.lookup("pam200"   );
    public static final Matrix pam210   = Matrix.lookup("pam210"   );
    public static final Matrix pam220   = Matrix.lookup("pam220"   );
    public static final Matrix pam230   = Matrix.lookup("pam230"   );
    public static final Matrix pam240   = Matrix.lookup("pam240"   );
    public static final Matrix pam250   = Matrix.lookup("pam250"   );
    public static final Matrix pam260   = Matrix.lookup("pam260"   );
    public static final Matrix pam270   = Matrix.lookup("pam270"   );
    public static final Matrix pam280   = Matrix.lookup("pam280"   );
    public static final Matrix pam290   = Matrix.lookup("pam290"   );
    public static final Matrix pam30    = Matrix.lookup("pam30"    );
    public static final Matrix pam300   = Matrix.lookup("pam300"   );
    public static final Matrix pam310   = Matrix.lookup("pam310"   );
    public static final Matrix pam320   = Matrix.lookup("pam320"   );
    public static final Matrix pam330   = Matrix.lookup("pam330"   );
    public static final Matrix pam340   = Matrix.lookup("pam340"   );
    public static final Matrix pam350   = Matrix.lookup("pam350"   );
    public static final Matrix pam360   = Matrix.lookup("pam360"   );
    public static final Matrix pam370   = Matrix.lookup("pam370"   );
    public static final Matrix pam380   = Matrix.lookup("pam380"   );
    public static final Matrix pam390   = Matrix.lookup("pam390"   );
    public static final Matrix pam40    = Matrix.lookup("pam40"    );
    public static final Matrix pam400   = Matrix.lookup("pam400"   );
    public static final Matrix pam410   = Matrix.lookup("pam410"   );
    public static final Matrix pam420   = Matrix.lookup("pam420"   );
    public static final Matrix pam430   = Matrix.lookup("pam430"   );
    public static final Matrix pam440   = Matrix.lookup("pam440"   );
    public static final Matrix pam450   = Matrix.lookup("pam450"   );
    public static final Matrix pam460   = Matrix.lookup("pam460"   );
    public static final Matrix pam470   = Matrix.lookup("pam470"   );
    public static final Matrix pam480   = Matrix.lookup("pam480"   );
    public static final Matrix pam490   = Matrix.lookup("pam490"   );
    public static final Matrix pam50    = Matrix.lookup("pam50"    );
    public static final Matrix pam500   = Matrix.lookup("pam500"   );
    public static final Matrix pam60    = Matrix.lookup("pam60"    );
    public static final Matrix pam70    = Matrix.lookup("pam70"    );
    public static final Matrix pam80    = Matrix.lookup("pam80"    );
    public static final Matrix pam90    = Matrix.lookup("pam90"    );
    public static final Matrix dnafull  = Matrix.lookup("dnafull"  );
    public static final Matrix nuc44    = Matrix.lookup("nuc44"    );
}

