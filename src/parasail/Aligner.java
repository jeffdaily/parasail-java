package parasail;

import java.lang.String;

public class Aligner {
    public static void main(String[] args) {
        Result result = sw("asdf", "asdf", 10, 1, Matrix.blosum62);
        System.out.println(result.getScore());
        Profile profile = Profile.create_sat("asdf", Matrix.blosum62);
        result.finalize();
        result = sw_striped_profile_sat(profile, "asdf", 10, 1);
        System.out.println(result.getScore());
        result.finalize();
    }

    public static Result sw(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_striped_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_striped_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }
}
