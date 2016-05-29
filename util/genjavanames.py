#!/usr/bin/env python

# serial reference implementations (3x2x3 = 18 impl)
alg = ["nw", "sg", "sw"]
stats = ["", "_stats"]
table = ["", "_table", "_rowcol"]
for a in alg:
    for s in stats:
        for t in table:
            print ("    public static native long "+a+s+t+'('+
                    "String s1, String s2, int open, int gap, long matrix);")

# serial scan reference implementations (3x2x3 = 18 impl)
alg = ["nw", "sg", "sw"]
stats = ["", "_stats"]
table = ["", "_table", "_rowcol"]
for a in alg:
    for s in stats:
        for t in table:
            print ("    public static native long "+a+s+t+'_scan('+
                    "String s1, String s2, int open, int gap, long matrix);")

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
                    print ("    public static native long "+a+s+t+p+w+'('
                            "String s1, String s2, int open, int gap, long matrix);")

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
                    print ("    public static native long "+a+s+t+p+w+'('
                            "long profile, String s2, int open, int gap);")

