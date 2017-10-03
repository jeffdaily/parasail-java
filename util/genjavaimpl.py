#!/usr/bin/env python

# mangle parts of the function names the way javah does it
def _(name):
    if name:
        return name.replace('_','_1')
    return name

# serial reference implementations (3x2x3 = 18 impl)
alg = ["nw", "sg", "sw"]
stats = ["", "_stats"]
table = ["", "_table", "_rowcol", "_trace"]
scan = ["", "_scan"]
for a in alg:
    for s in stats:
        for t in table:
            if "trace" in t and "stats" in s: continue
            for d in scan:
                print """
JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_{0}{1}{2}{3}
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{{
    const char *c_s1 = NULL;
    const char *c_s2 = NULL;
    parasail_matrix_t *c_matrix = NULL;
    parasail_result_t *result = NULL;
    jsize s1Len = 0;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s1, NULL));
    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != matrix);

    c_s1 = (*env)->GetStringUTFChars(env, s1, NULL);
    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s1Len = (*env)->GetStringLength(env, s1);
    s2Len = (*env)->GetStringLength(env, s2);

    c_matrix = (parasail_matrix_t*)matrix;

    result = parasail_{4}{5}{6}{7}(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}}
""".format(a,_(s),_(t),_(d),a,s,t,d)

# dispatching implementations (3x2x3x3x4 = 216 impl)
alg = ["nw", "sg", "sw"]
stats = ["", "_stats"]
table = ["", "_table", "_rowcol", "_trace"]
par = ["_scan", "_striped", "_diag"]
width = ["_64", "_32", "_16", "_8", "_sat"]
for a in alg:
    for s in stats:
        for t in table:
            if "trace" in t and "stats" in s: continue
            for p in par:
                for w in width:
                    print """
JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_{0}{1}{2}{3}{4}
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{{
    const char *c_s1 = NULL;
    const char *c_s2 = NULL;
    parasail_matrix_t *c_matrix = NULL;
    parasail_result_t *result = NULL;
    jsize s1Len = 0;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s1, NULL));
    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != matrix);

    c_s1 = (*env)->GetStringUTFChars(env, s1, NULL);
    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s1Len = (*env)->GetStringLength(env, s1);
    s2Len = (*env)->GetStringLength(env, s2);

    c_matrix = (parasail_matrix_t*)matrix;

    result = parasail_{5}{6}{7}{8}{9}(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}}
""".format(a,_(s),_(t),_(p),_(w),a,s,t,p,w)


# dispatching profile implementations (3x2x3x2x4 = 144 impl)
alg = ["nw", "sg", "sw"]
stats = ["", "_stats"]
table = ["", "_table", "_rowcol", "_trace"]
par = ["_scan_profile", "_striped_profile"]
width = ["_64", "_32", "_16", "_8", "_sat"]
for a in alg:
    for s in stats:
        for t in table:
            if "trace" in t and "stats" in s: continue
            for p in par:
                for w in width:
                    print """
JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_{0}{1}{2}{3}{4}
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_{5}{6}{7}{8}{9}(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}}
""".format(a,_(s),_(t),_(p),_(w),a,s,t,p,w)

