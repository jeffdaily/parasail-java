#!/usr/bin/env python

print """package parasail;

import java.lang.String;

public class Aligner {"""

# serial reference implementations (3x2x3 = 18 impl)
alg = ["nw", "sg", "sw"]
stats = ["", "_stats"]
table = ["", "_table", "_rowcol"]
scan = ["", "_scan"]
for a in alg:
    for s in stats:
        for t in table:
            for d in scan:
                print """
    public static Result {0}{1}{2}{3}(String s1, String s2, int open, int gap, Matrix matrix) {{
        return new Result(JNIparasail.{0}{1}{2}{3}(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }}""".format(a,s,t,d)

# dispatching implementations (3x2x3x3x4 = 216 impl)
alg = ["nw", "sg", "sw"]
stats = ["", "_stats"]
table = ["", "_table", "_rowcol"]
par = ["_scan", "_striped", "_diag"]
width = ["_64", "_32", "_16", "_8", "_sat"]
for a in alg:
    for s in stats:
        for t in table:
            for p in par:
                for w in width:
                    print """
    public static Result {0}{1}{2}{3}{4}(String s1, String s2, int open, int gap, Matrix matrix) {{
        return new Result(JNIparasail.{0}{1}{2}{3}{4}(s1, s2, open, gap, Matrix.getCPtr(matrix)), true);
    }}""".format(a,s,t,p,w)


# dispatching profile implementations (3x2x3x2x4 = 144 impl)
alg = ["nw", "sg", "sw"]
stats = ["", "_stats"]
table = ["", "_table", "_rowcol"]
par = ["_scan_profile", "_striped_profile"]
width = ["_64", "_32", "_16", "_8", "_sat"]
for a in alg:
    for s in stats:
        for t in table:
            for p in par:
                for w in width:
                    print """
    public static Result {0}{1}{2}{3}{4}(Profile profile, String s2, int open, int gap) {{
        return new Result(JNIparasail.{0}{1}{2}{3}{4}(Profile.getCPtr(profile), s2, open, gap), true);
    }}""".format(a,s,t,p,w)

print "}"
print
