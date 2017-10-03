package parasail;

import java.lang.String;

public class Aligner {

    public static Result nw(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_scan(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_scan(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_table(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_table(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_table_scan(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_table_scan(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_rowcol(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_rowcol(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_rowcol_scan(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_rowcol_scan(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_trace(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_trace(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_trace_scan(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_trace_scan(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_scan(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_scan(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_table(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_table(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_table_scan(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_table_scan(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_rowcol(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_rowcol(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_rowcol_scan(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_rowcol_scan(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_scan(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_scan(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_table(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_table(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_table_scan(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_table_scan(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_rowcol(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_rowcol(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_rowcol_scan(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_rowcol_scan(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_trace(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_trace(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_trace_scan(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_trace_scan(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_scan(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_scan(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_table(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_table(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_table_scan(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_table_scan(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_rowcol(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_rowcol(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_rowcol_scan(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_rowcol_scan(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_scan(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_scan(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_table(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_table(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_table_scan(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_table_scan(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_rowcol(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_rowcol(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_rowcol_scan(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_rowcol_scan(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_trace(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_trace(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_trace_scan(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_trace_scan(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_scan(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_scan(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_table(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_table(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_table_scan(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_table_scan(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_rowcol(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_rowcol(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_rowcol_scan(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_rowcol_scan(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_scan_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_scan_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_scan_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_scan_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_scan_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_scan_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_scan_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_scan_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_scan_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_scan_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_striped_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_striped_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_striped_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_striped_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_striped_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_striped_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_striped_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_striped_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_striped_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_striped_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_diag_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_diag_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_diag_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_diag_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_diag_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_diag_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_diag_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_diag_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_diag_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_diag_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_table_scan_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_table_scan_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_table_scan_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_table_scan_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_table_scan_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_table_scan_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_table_scan_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_table_scan_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_table_scan_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_table_scan_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_table_striped_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_table_striped_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_table_striped_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_table_striped_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_table_striped_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_table_striped_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_table_striped_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_table_striped_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_table_striped_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_table_striped_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_table_diag_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_table_diag_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_table_diag_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_table_diag_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_table_diag_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_table_diag_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_table_diag_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_table_diag_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_table_diag_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_table_diag_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_rowcol_scan_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_rowcol_scan_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_rowcol_scan_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_rowcol_scan_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_rowcol_scan_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_rowcol_scan_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_rowcol_scan_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_rowcol_scan_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_rowcol_scan_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_rowcol_scan_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_rowcol_striped_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_rowcol_striped_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_rowcol_striped_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_rowcol_striped_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_rowcol_striped_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_rowcol_striped_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_rowcol_striped_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_rowcol_striped_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_rowcol_striped_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_rowcol_striped_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_rowcol_diag_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_rowcol_diag_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_rowcol_diag_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_rowcol_diag_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_rowcol_diag_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_rowcol_diag_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_rowcol_diag_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_rowcol_diag_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_rowcol_diag_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_rowcol_diag_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_trace_scan_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_trace_scan_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_trace_scan_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_trace_scan_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_trace_scan_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_trace_scan_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_trace_scan_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_trace_scan_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_trace_scan_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_trace_scan_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_trace_striped_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_trace_striped_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_trace_striped_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_trace_striped_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_trace_striped_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_trace_striped_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_trace_striped_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_trace_striped_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_trace_striped_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_trace_striped_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_trace_diag_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_trace_diag_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_trace_diag_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_trace_diag_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_trace_diag_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_trace_diag_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_trace_diag_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_trace_diag_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_trace_diag_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_trace_diag_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_scan_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_scan_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_scan_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_scan_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_scan_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_scan_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_scan_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_scan_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_scan_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_scan_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_striped_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_striped_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_striped_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_striped_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_striped_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_striped_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_striped_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_striped_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_striped_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_striped_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_diag_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_diag_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_diag_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_diag_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_diag_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_diag_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_diag_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_diag_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_diag_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_diag_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_table_scan_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_table_scan_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_table_scan_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_table_scan_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_table_scan_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_table_scan_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_table_scan_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_table_scan_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_table_scan_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_table_scan_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_table_striped_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_table_striped_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_table_striped_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_table_striped_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_table_striped_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_table_striped_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_table_striped_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_table_striped_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_table_striped_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_table_striped_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_table_diag_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_table_diag_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_table_diag_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_table_diag_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_table_diag_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_table_diag_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_table_diag_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_table_diag_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_table_diag_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_table_diag_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_rowcol_scan_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_rowcol_scan_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_rowcol_scan_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_rowcol_scan_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_rowcol_scan_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_rowcol_scan_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_rowcol_scan_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_rowcol_scan_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_rowcol_scan_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_rowcol_scan_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_rowcol_striped_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_rowcol_striped_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_rowcol_striped_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_rowcol_striped_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_rowcol_striped_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_rowcol_striped_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_rowcol_striped_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_rowcol_striped_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_rowcol_striped_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_rowcol_striped_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_rowcol_diag_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_rowcol_diag_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_rowcol_diag_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_rowcol_diag_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_rowcol_diag_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_rowcol_diag_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_rowcol_diag_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_rowcol_diag_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_stats_rowcol_diag_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.nw_stats_rowcol_diag_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_scan_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_scan_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_scan_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_scan_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_scan_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_scan_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_scan_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_scan_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_scan_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_scan_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_striped_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_striped_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_striped_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_striped_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_striped_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_striped_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_striped_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_striped_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_striped_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_striped_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_diag_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_diag_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_diag_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_diag_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_diag_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_diag_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_diag_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_diag_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_diag_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_diag_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_table_scan_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_table_scan_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_table_scan_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_table_scan_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_table_scan_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_table_scan_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_table_scan_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_table_scan_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_table_scan_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_table_scan_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_table_striped_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_table_striped_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_table_striped_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_table_striped_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_table_striped_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_table_striped_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_table_striped_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_table_striped_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_table_striped_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_table_striped_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_table_diag_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_table_diag_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_table_diag_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_table_diag_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_table_diag_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_table_diag_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_table_diag_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_table_diag_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_table_diag_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_table_diag_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_rowcol_scan_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_rowcol_scan_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_rowcol_scan_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_rowcol_scan_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_rowcol_scan_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_rowcol_scan_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_rowcol_scan_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_rowcol_scan_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_rowcol_scan_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_rowcol_scan_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_rowcol_striped_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_rowcol_striped_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_rowcol_striped_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_rowcol_striped_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_rowcol_striped_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_rowcol_striped_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_rowcol_striped_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_rowcol_striped_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_rowcol_striped_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_rowcol_striped_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_rowcol_diag_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_rowcol_diag_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_rowcol_diag_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_rowcol_diag_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_rowcol_diag_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_rowcol_diag_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_rowcol_diag_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_rowcol_diag_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_rowcol_diag_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_rowcol_diag_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_trace_scan_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_trace_scan_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_trace_scan_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_trace_scan_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_trace_scan_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_trace_scan_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_trace_scan_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_trace_scan_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_trace_scan_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_trace_scan_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_trace_striped_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_trace_striped_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_trace_striped_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_trace_striped_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_trace_striped_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_trace_striped_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_trace_striped_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_trace_striped_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_trace_striped_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_trace_striped_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_trace_diag_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_trace_diag_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_trace_diag_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_trace_diag_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_trace_diag_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_trace_diag_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_trace_diag_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_trace_diag_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_trace_diag_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_trace_diag_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_scan_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_scan_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_scan_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_scan_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_scan_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_scan_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_scan_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_scan_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_scan_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_scan_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_striped_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_striped_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_striped_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_striped_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_striped_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_striped_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_striped_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_striped_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_striped_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_striped_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_diag_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_diag_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_diag_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_diag_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_diag_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_diag_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_diag_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_diag_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_diag_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_diag_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_table_scan_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_table_scan_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_table_scan_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_table_scan_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_table_scan_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_table_scan_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_table_scan_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_table_scan_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_table_scan_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_table_scan_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_table_striped_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_table_striped_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_table_striped_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_table_striped_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_table_striped_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_table_striped_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_table_striped_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_table_striped_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_table_striped_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_table_striped_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_table_diag_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_table_diag_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_table_diag_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_table_diag_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_table_diag_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_table_diag_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_table_diag_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_table_diag_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_table_diag_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_table_diag_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_rowcol_scan_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_rowcol_scan_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_rowcol_scan_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_rowcol_scan_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_rowcol_scan_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_rowcol_scan_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_rowcol_scan_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_rowcol_scan_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_rowcol_scan_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_rowcol_scan_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_rowcol_striped_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_rowcol_striped_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_rowcol_striped_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_rowcol_striped_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_rowcol_striped_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_rowcol_striped_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_rowcol_striped_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_rowcol_striped_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_rowcol_striped_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_rowcol_striped_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_rowcol_diag_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_rowcol_diag_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_rowcol_diag_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_rowcol_diag_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_rowcol_diag_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_rowcol_diag_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_rowcol_diag_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_rowcol_diag_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sg_stats_rowcol_diag_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sg_stats_rowcol_diag_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_scan_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_scan_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_scan_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_scan_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_scan_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_scan_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_scan_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_scan_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_scan_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_scan_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_striped_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_striped_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_striped_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_striped_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_striped_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_striped_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_striped_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_striped_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_striped_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_striped_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_diag_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_diag_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_diag_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_diag_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_diag_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_diag_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_diag_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_diag_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_diag_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_diag_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_table_scan_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_table_scan_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_table_scan_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_table_scan_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_table_scan_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_table_scan_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_table_scan_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_table_scan_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_table_scan_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_table_scan_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_table_striped_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_table_striped_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_table_striped_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_table_striped_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_table_striped_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_table_striped_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_table_striped_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_table_striped_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_table_striped_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_table_striped_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_table_diag_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_table_diag_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_table_diag_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_table_diag_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_table_diag_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_table_diag_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_table_diag_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_table_diag_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_table_diag_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_table_diag_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_rowcol_scan_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_rowcol_scan_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_rowcol_scan_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_rowcol_scan_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_rowcol_scan_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_rowcol_scan_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_rowcol_scan_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_rowcol_scan_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_rowcol_scan_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_rowcol_scan_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_rowcol_striped_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_rowcol_striped_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_rowcol_striped_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_rowcol_striped_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_rowcol_striped_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_rowcol_striped_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_rowcol_striped_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_rowcol_striped_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_rowcol_striped_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_rowcol_striped_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_rowcol_diag_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_rowcol_diag_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_rowcol_diag_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_rowcol_diag_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_rowcol_diag_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_rowcol_diag_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_rowcol_diag_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_rowcol_diag_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_rowcol_diag_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_rowcol_diag_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_trace_scan_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_trace_scan_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_trace_scan_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_trace_scan_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_trace_scan_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_trace_scan_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_trace_scan_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_trace_scan_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_trace_scan_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_trace_scan_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_trace_striped_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_trace_striped_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_trace_striped_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_trace_striped_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_trace_striped_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_trace_striped_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_trace_striped_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_trace_striped_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_trace_striped_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_trace_striped_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_trace_diag_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_trace_diag_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_trace_diag_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_trace_diag_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_trace_diag_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_trace_diag_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_trace_diag_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_trace_diag_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_trace_diag_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_trace_diag_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_scan_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_scan_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_scan_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_scan_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_scan_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_scan_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_scan_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_scan_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_scan_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_scan_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_striped_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_striped_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_striped_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_striped_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_striped_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_striped_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_striped_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_striped_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_striped_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_striped_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_diag_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_diag_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_diag_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_diag_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_diag_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_diag_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_diag_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_diag_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_diag_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_diag_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_table_scan_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_table_scan_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_table_scan_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_table_scan_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_table_scan_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_table_scan_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_table_scan_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_table_scan_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_table_scan_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_table_scan_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_table_striped_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_table_striped_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_table_striped_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_table_striped_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_table_striped_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_table_striped_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_table_striped_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_table_striped_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_table_striped_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_table_striped_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_table_diag_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_table_diag_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_table_diag_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_table_diag_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_table_diag_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_table_diag_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_table_diag_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_table_diag_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_table_diag_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_table_diag_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_rowcol_scan_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_rowcol_scan_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_rowcol_scan_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_rowcol_scan_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_rowcol_scan_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_rowcol_scan_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_rowcol_scan_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_rowcol_scan_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_rowcol_scan_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_rowcol_scan_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_rowcol_striped_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_rowcol_striped_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_rowcol_striped_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_rowcol_striped_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_rowcol_striped_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_rowcol_striped_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_rowcol_striped_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_rowcol_striped_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_rowcol_striped_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_rowcol_striped_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_rowcol_diag_64(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_rowcol_diag_64(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_rowcol_diag_32(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_rowcol_diag_32(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_rowcol_diag_16(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_rowcol_diag_16(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_rowcol_diag_8(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_rowcol_diag_8(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result sw_stats_rowcol_diag_sat(String s1, String s2, int open, int gap, Matrix matrix) {
        return new Result(JNIparasail.sw_stats_rowcol_diag_sat(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }

    public static Result nw_scan_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_scan_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_scan_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_scan_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_scan_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_scan_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_scan_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_scan_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_scan_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_scan_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_striped_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_striped_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_striped_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_striped_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_striped_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_striped_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_striped_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_striped_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_striped_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_striped_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_table_scan_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_table_scan_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_table_scan_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_table_scan_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_table_scan_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_table_scan_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_table_scan_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_table_scan_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_table_scan_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_table_scan_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_table_striped_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_table_striped_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_table_striped_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_table_striped_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_table_striped_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_table_striped_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_table_striped_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_table_striped_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_table_striped_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_table_striped_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_rowcol_scan_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_rowcol_scan_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_rowcol_scan_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_rowcol_scan_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_rowcol_scan_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_rowcol_scan_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_rowcol_scan_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_rowcol_scan_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_rowcol_scan_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_rowcol_scan_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_rowcol_striped_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_rowcol_striped_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_rowcol_striped_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_rowcol_striped_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_rowcol_striped_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_rowcol_striped_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_rowcol_striped_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_rowcol_striped_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_rowcol_striped_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_rowcol_striped_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_trace_scan_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_trace_scan_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_trace_scan_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_trace_scan_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_trace_scan_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_trace_scan_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_trace_scan_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_trace_scan_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_trace_scan_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_trace_scan_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_trace_striped_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_trace_striped_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_trace_striped_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_trace_striped_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_trace_striped_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_trace_striped_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_trace_striped_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_trace_striped_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_trace_striped_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_trace_striped_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_scan_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_scan_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_scan_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_scan_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_scan_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_scan_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_scan_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_scan_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_scan_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_scan_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_striped_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_striped_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_striped_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_striped_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_striped_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_striped_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_striped_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_striped_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_striped_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_striped_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_table_scan_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_table_scan_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_table_scan_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_table_scan_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_table_scan_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_table_scan_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_table_scan_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_table_scan_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_table_scan_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_table_scan_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_table_striped_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_table_striped_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_table_striped_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_table_striped_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_table_striped_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_table_striped_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_table_striped_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_table_striped_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_table_striped_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_table_striped_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_rowcol_scan_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_rowcol_scan_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_rowcol_scan_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_rowcol_scan_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_rowcol_scan_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_rowcol_scan_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_rowcol_scan_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_rowcol_scan_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_rowcol_scan_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_rowcol_scan_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_rowcol_striped_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_rowcol_striped_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_rowcol_striped_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_rowcol_striped_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_rowcol_striped_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_rowcol_striped_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_rowcol_striped_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_rowcol_striped_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result nw_stats_rowcol_striped_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.nw_stats_rowcol_striped_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_scan_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_scan_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_scan_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_scan_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_scan_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_scan_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_scan_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_scan_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_scan_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_scan_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_striped_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_striped_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_striped_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_striped_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_striped_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_striped_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_striped_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_striped_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_striped_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_striped_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_table_scan_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_table_scan_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_table_scan_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_table_scan_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_table_scan_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_table_scan_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_table_scan_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_table_scan_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_table_scan_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_table_scan_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_table_striped_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_table_striped_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_table_striped_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_table_striped_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_table_striped_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_table_striped_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_table_striped_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_table_striped_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_table_striped_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_table_striped_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_rowcol_scan_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_rowcol_scan_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_rowcol_scan_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_rowcol_scan_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_rowcol_scan_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_rowcol_scan_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_rowcol_scan_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_rowcol_scan_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_rowcol_scan_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_rowcol_scan_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_rowcol_striped_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_rowcol_striped_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_rowcol_striped_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_rowcol_striped_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_rowcol_striped_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_rowcol_striped_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_rowcol_striped_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_rowcol_striped_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_rowcol_striped_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_rowcol_striped_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_trace_scan_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_trace_scan_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_trace_scan_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_trace_scan_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_trace_scan_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_trace_scan_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_trace_scan_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_trace_scan_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_trace_scan_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_trace_scan_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_trace_striped_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_trace_striped_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_trace_striped_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_trace_striped_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_trace_striped_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_trace_striped_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_trace_striped_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_trace_striped_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_trace_striped_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_trace_striped_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_scan_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_scan_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_scan_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_scan_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_scan_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_scan_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_scan_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_scan_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_scan_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_scan_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_striped_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_striped_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_striped_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_striped_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_striped_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_striped_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_striped_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_striped_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_striped_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_striped_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_table_scan_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_table_scan_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_table_scan_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_table_scan_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_table_scan_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_table_scan_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_table_scan_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_table_scan_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_table_scan_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_table_scan_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_table_striped_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_table_striped_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_table_striped_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_table_striped_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_table_striped_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_table_striped_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_table_striped_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_table_striped_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_table_striped_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_table_striped_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_rowcol_scan_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_rowcol_scan_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_rowcol_scan_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_rowcol_scan_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_rowcol_scan_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_rowcol_scan_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_rowcol_scan_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_rowcol_scan_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_rowcol_scan_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_rowcol_scan_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_rowcol_striped_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_rowcol_striped_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_rowcol_striped_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_rowcol_striped_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_rowcol_striped_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_rowcol_striped_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_rowcol_striped_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_rowcol_striped_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sg_stats_rowcol_striped_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sg_stats_rowcol_striped_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_scan_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_scan_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_scan_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_scan_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_scan_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_scan_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_scan_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_scan_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_scan_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_scan_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_striped_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_striped_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_striped_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_striped_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_striped_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_striped_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_striped_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_striped_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_striped_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_striped_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_table_scan_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_table_scan_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_table_scan_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_table_scan_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_table_scan_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_table_scan_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_table_scan_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_table_scan_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_table_scan_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_table_scan_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_table_striped_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_table_striped_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_table_striped_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_table_striped_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_table_striped_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_table_striped_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_table_striped_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_table_striped_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_table_striped_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_table_striped_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_rowcol_scan_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_rowcol_scan_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_rowcol_scan_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_rowcol_scan_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_rowcol_scan_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_rowcol_scan_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_rowcol_scan_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_rowcol_scan_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_rowcol_scan_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_rowcol_scan_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_rowcol_striped_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_rowcol_striped_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_rowcol_striped_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_rowcol_striped_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_rowcol_striped_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_rowcol_striped_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_rowcol_striped_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_rowcol_striped_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_rowcol_striped_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_rowcol_striped_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_trace_scan_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_trace_scan_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_trace_scan_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_trace_scan_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_trace_scan_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_trace_scan_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_trace_scan_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_trace_scan_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_trace_scan_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_trace_scan_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_trace_striped_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_trace_striped_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_trace_striped_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_trace_striped_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_trace_striped_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_trace_striped_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_trace_striped_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_trace_striped_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_trace_striped_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_trace_striped_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_scan_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_scan_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_scan_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_scan_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_scan_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_scan_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_scan_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_scan_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_scan_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_scan_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_striped_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_striped_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_striped_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_striped_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_striped_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_striped_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_striped_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_striped_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_striped_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_striped_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_table_scan_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_table_scan_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_table_scan_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_table_scan_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_table_scan_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_table_scan_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_table_scan_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_table_scan_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_table_scan_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_table_scan_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_table_striped_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_table_striped_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_table_striped_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_table_striped_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_table_striped_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_table_striped_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_table_striped_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_table_striped_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_table_striped_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_table_striped_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_rowcol_scan_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_rowcol_scan_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_rowcol_scan_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_rowcol_scan_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_rowcol_scan_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_rowcol_scan_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_rowcol_scan_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_rowcol_scan_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_rowcol_scan_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_rowcol_scan_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_rowcol_striped_profile_64(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_rowcol_striped_profile_64(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_rowcol_striped_profile_32(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_rowcol_striped_profile_32(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_rowcol_striped_profile_16(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_rowcol_striped_profile_16(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_rowcol_striped_profile_8(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_rowcol_striped_profile_8(Profile.getCPtr(profile), s2, open, gap), true);
    }

    public static Result sw_stats_rowcol_striped_profile_sat(Profile profile, String s2, int open, int gap) {
        return new Result(JNIparasail.sw_stats_rowcol_striped_profile_sat(Profile.getCPtr(profile), s2, open, gap), true);
    }
}

