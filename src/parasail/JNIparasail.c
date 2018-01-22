#include <assert.h>
#include <stdlib.h>

#include "parasail_JNIparasail.h"
#include "parasail.h"
#include "parasail/cpuid.h"
#include "parasail/matrices/blosum62.h"

JNIEXPORT jstring JNICALL Java_parasail_JNIparasail_matrix_1name
  (JNIEnv *env, jclass this, jlong cptr)
{
    parasail_matrix_t *matrix = NULL;
    jstring result;

    assert(0 != cptr);

    matrix = (parasail_matrix_t*)cptr;
    result = (*env)->NewStringUTF(env,matrix->name);

    return result;
}

JNIEXPORT jintArray JNICALL Java_parasail_JNIparasail_matrix_1data
  (JNIEnv *env, jclass this, jlong cptr)
{
    parasail_matrix_t *matrix = NULL;
    jintArray result;
    int size;

    assert(0 != cptr);

    matrix = (parasail_matrix_t*)cptr;
    size = matrix->size * matrix->size;
    result = (*env)->NewIntArray(env, size);
    assert(NULL != result);
    (*env)->SetIntArrayRegion(env, result, 0, size, matrix->matrix);

    return result;
}

JNIEXPORT jint JNICALL Java_parasail_JNIparasail_matrix_1size
  (JNIEnv *env, jclass this, jlong cptr)
{
    parasail_matrix_t *matrix = NULL;
    jint result;

    assert(0 != cptr);

    matrix = (parasail_matrix_t*)cptr;
    result = matrix->size;

    return result;
}

JNIEXPORT jint JNICALL Java_parasail_JNIparasail_matrix_1max
  (JNIEnv *env, jclass this, jlong cptr)
{
    parasail_matrix_t *matrix = NULL;
    jint result;

    assert(0 != cptr);

    matrix = (parasail_matrix_t*)cptr;
    result = matrix->max;

    return result;
}

JNIEXPORT jint JNICALL Java_parasail_JNIparasail_matrix_1min
  (JNIEnv *env, jclass this, jlong cptr)
{
    parasail_matrix_t *matrix = NULL;
    jint result;

    assert(0 != cptr);

    matrix = (parasail_matrix_t*)cptr;
    result = matrix->min;

    return result;
}

JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_matrix_1user_1matrix
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_matrix_t *matrix = NULL;
    jlong result;

    assert(0 != cptr);

    matrix = (parasail_matrix_t*)cptr;
    result = (jlong)matrix->user_matrix;

    return result;
}

JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_matrix_1lookup
  (JNIEnv *env, jclass class, jstring namej)
{
    const char *nameb = NULL;
    jlong ret;

    nameb = (*env)->GetStringUTFChars(env, namej, NULL);
    ret = (jlong)parasail_matrix_lookup((const char*)nameb);
    assert(0 != ret);

    (*env)->ReleaseStringUTFChars(env, namej, nameb);
    return ret;
}

JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_matrix_1create
  (JNIEnv *env, jclass class, jstring alphabet, jint match, jint mismatch)
{
    const char *c_alphabet = NULL;
    parasail_matrix_t *matrix;

    c_alphabet = (*env)->GetStringUTFChars(env, alphabet, NULL);
    matrix = parasail_matrix_create(c_alphabet, match, mismatch);
    assert(NULL != matrix);
    (*env)->ReleaseStringUTFChars(env, alphabet, c_alphabet);

    return (jlong)matrix;
}

JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_matrix_1set_1value
  (JNIEnv *env, jclass class, jlong cptr, jint row, jint col, jint value)
{
    parasail_matrix_t *matrix = NULL;

    assert(0 != cptr);

    matrix = (parasail_matrix_t*)cptr;
    parasail_matrix_set_value(matrix, row, col, value);
}

JNIEXPORT void JNICALL Java_parasail_JNIparasail_matrix_1free
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_matrix_t *matrix = NULL;

    assert(0 != cptr);

    matrix = (parasail_matrix_t*)cptr;
    parasail_matrix_free(matrix);
}

JNIEXPORT jboolean JNICALL Java_parasail_JNIparasail_result_1saturated
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_result_t *result = NULL;

    assert(0 != cptr);

    result = (parasail_result_t*)cptr;
    return parasail_result_is_saturated(result);
}

JNIEXPORT jint JNICALL Java_parasail_JNIparasail_result_1score
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_result_t *result = NULL;

    assert(0 != cptr);

    result = (parasail_result_t*)cptr;
    return parasail_result_get_score(result);
}

JNIEXPORT jint JNICALL Java_parasail_JNIparasail_result_1matches
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_result_t *result = NULL;

    assert(0 != cptr);

    result = (parasail_result_t*)cptr;
    return parasail_result_get_matches(result);
}

JNIEXPORT jint JNICALL Java_parasail_JNIparasail_result_1similar
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_result_t *result = NULL;

    assert(0 != cptr);

    result = (parasail_result_t*)cptr;
    return parasail_result_get_similar(result);
}

JNIEXPORT jint JNICALL Java_parasail_JNIparasail_result_1length
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_result_t *result = NULL;

    assert(0 != cptr);

    result = (parasail_result_t*)cptr;
    return parasail_result_get_length(result);
}

JNIEXPORT jint JNICALL Java_parasail_JNIparasail_result_1end_1query
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_result_t *result = NULL;

    assert(0 != cptr);

    result = (parasail_result_t*)cptr;
    return parasail_result_get_end_query(result);
}

JNIEXPORT jint JNICALL Java_parasail_JNIparasail_result_1end_1ref
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_result_t *result = NULL;

    assert(0 != cptr);

    result = (parasail_result_t*)cptr;
    return parasail_result_get_end_ref(result);
}

JNIEXPORT void JNICALL Java_parasail_JNIparasail_result_1free
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_result_t *result = NULL;

    assert(0 != cptr);

    result = (parasail_result_t*)cptr;
    parasail_result_free(result);
}

JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_result_1cigar
  (JNIEnv *env, jclass class, jlong result, jstring s1, jstring s2, jlong matrix)
{
    const char *c_s1 = NULL;
    const char *c_s2 = NULL;
    parasail_matrix_t *c_matrix = NULL;
    parasail_result_t *c_result = NULL;
    parasail_cigar_t *c_cigar = NULL;
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
    c_result = (parasail_result_t*)result;
    c_cigar = parasail_result_get_cigar(c_result, c_s1, s1Len, c_s2, s2Len, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)c_cigar;
}

JNIEXPORT void JNICALL Java_parasail_JNIparasail_cigar_1free
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_cigar_t *cigar = NULL;

    assert(0 != cptr);

    cigar = (parasail_cigar_t*)cptr;
    parasail_cigar_free(cigar);
}

JNIEXPORT jintArray JNICALL Java_parasail_JNIparasail_cigar_1seq
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_cigar_t *cigar = NULL;
    jintArray result;
    int size;

    assert(0 != cptr);

    cigar = (parasail_cigar_t*)cptr;
    size = cigar->len;
    result = (*env)->NewIntArray(env, size);
    assert(NULL != result);
    (*env)->SetIntArrayRegion(env, result, 0, size, (int*)cigar->seq);

    return result;
}

JNIEXPORT jint JNICALL Java_parasail_JNIparasail_cigar_1len
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_cigar_t *cigar = NULL;

    assert(0 != cptr);

    cigar = (parasail_cigar_t*)cptr;
    return cigar->len;
}

JNIEXPORT jint JNICALL Java_parasail_JNIparasail_cigar_1beg_1query
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_cigar_t *cigar = NULL;

    assert(0 != cptr);

    cigar = (parasail_cigar_t*)cptr;
    return cigar->beg_query;
}

JNIEXPORT jint JNICALL Java_parasail_JNIparasail_cigar_1beg_1ref
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_cigar_t *cigar = NULL;

    assert(0 != cptr);

    cigar = (parasail_cigar_t*)cptr;
    return cigar->beg_ref;
}

JNIEXPORT jstring JNICALL Java_parasail_JNIparasail_cigar_1decode
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_cigar_t *cigar = NULL;
    char *decoded = NULL;
    jstring result;

    assert(0 != cptr);

    cigar = (parasail_cigar_t*)cptr;
    decoded = parasail_cigar_decode(cigar);
    result = (*env)->NewStringUTF(env,decoded);
    free(decoded);

    return result;
}

JNIEXPORT jchar JNICALL Java_parasail_JNIparasail_cigar_1decode_1op
  (JNIEnv *env, jclass class, jint cigar_int)
{
    return parasail_cigar_decode_op(cigar_int);
}

JNIEXPORT jint JNICALL Java_parasail_JNIparasail_cigar_1decode_1len
  (JNIEnv *env, jclass class, jint cigar_int)
{
    return parasail_cigar_decode_len(cigar_int);
}

JNIEXPORT jstring JNICALL Java_parasail_JNIparasail_profile_1s1
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_profile_t *profile = NULL;
    jstring result;

    assert(0 != cptr);

    profile = (parasail_profile_t*)cptr;
    result = (*env)->NewStringUTF(env,profile->s1);

    return result;
}

JNIEXPORT jint JNICALL Java_parasail_JNIparasail_profile_1s1Len
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_profile_t *profile = NULL;

    assert(0 != cptr);

    profile = (parasail_profile_t*)cptr;
    return profile->s1Len;
}

JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_profile_1matrix
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_profile_t *profile = NULL;

    assert(0 != cptr);

    profile = (parasail_profile_t*)cptr;
    return (jlong)profile->matrix;
}

JNIEXPORT void JNICALL Java_parasail_JNIparasail_profile_1free
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_profile_t *profile = NULL;

    assert(0 != cptr);

    profile = (parasail_profile_t*)cptr;
    parasail_profile_free(profile);
}

JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_profile_1create_164
  (JNIEnv *env, jclass class, jstring s1, jlong cptr)
{
    parasail_matrix_t *matrix = NULL;
    const char *c_s1 = NULL;
    jsize length = 0;
    jlong ret;

    assert(0 != cptr);

    matrix = (parasail_matrix_t*)cptr;
    c_s1 = (*env)->GetStringUTFChars(env, s1, NULL);
    length = (*env)->GetStringLength(env, s1);
    ret = (jlong)parasail_profile_create_64(c_s1, length, matrix);

    (*env)->ReleaseStringUTFChars(env, s1, c_s1);
    return ret;
}

JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_profile_1create_132
  (JNIEnv *env, jclass class, jstring s1, jlong cptr)
{
    parasail_matrix_t *matrix = NULL;
    const char *c_s1 = NULL;
    jsize length = 0;
    jlong ret;

    assert(0 != cptr);

    matrix = (parasail_matrix_t*)cptr;
    c_s1 = (*env)->GetStringUTFChars(env, s1, NULL);
    length = (*env)->GetStringLength(env, s1);
    ret = (jlong)parasail_profile_create_32(c_s1, length, matrix);

    (*env)->ReleaseStringUTFChars(env, s1, c_s1);
    return ret;
}

JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_profile_1create_116
  (JNIEnv *env, jclass class, jstring s1, jlong cptr)
{
    parasail_matrix_t *matrix = NULL;
    const char *c_s1 = NULL;
    jsize length = 0;
    jlong ret;

    assert(0 != cptr);

    matrix = (parasail_matrix_t*)cptr;
    c_s1 = (*env)->GetStringUTFChars(env, s1, NULL);
    length = (*env)->GetStringLength(env, s1);
    ret = (jlong)parasail_profile_create_16(c_s1, length, matrix);

    (*env)->ReleaseStringUTFChars(env, s1, c_s1);
    return ret;
}

JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_profile_1create_18
  (JNIEnv *env, jclass class, jstring s1, jlong cptr)
{
    parasail_matrix_t *matrix = NULL;
    const char *c_s1 = NULL;
    jsize length = 0;
    jlong ret;

    assert(0 != cptr);

    matrix = (parasail_matrix_t*)cptr;
    c_s1 = (*env)->GetStringUTFChars(env, s1, NULL);
    length = (*env)->GetStringLength(env, s1);
    ret = (jlong)parasail_profile_create_8(c_s1, length, matrix);

    (*env)->ReleaseStringUTFChars(env, s1, c_s1);
    return ret;
}

JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_profile_1create_1sat
  (JNIEnv *env, jclass class, jstring s1, jlong cptr)
{
    parasail_matrix_t *matrix = NULL;
    const char *c_s1 = NULL;
    jsize length = 0;
    jlong ret;

    assert(0 != cptr);

    matrix = (parasail_matrix_t*)cptr;
    c_s1 = (*env)->GetStringUTFChars(env, s1, NULL);
    length = (*env)->GetStringLength(env, s1);
    ret = (jlong)parasail_profile_create_sat(c_s1, length, matrix);

    (*env)->ReleaseStringUTFChars(env, s1, c_s1);
    return ret;
}

JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_profile_1create_1stats_164
  (JNIEnv *env, jclass class, jstring s1, jlong cptr)
{
    parasail_matrix_t *matrix = NULL;
    const char *c_s1 = NULL;
    jsize length = 0;
    jlong ret;

    assert(0 != cptr);

    matrix = (parasail_matrix_t*)cptr;
    c_s1 = (*env)->GetStringUTFChars(env, s1, NULL);
    length = (*env)->GetStringLength(env, s1);
    ret = (jlong)parasail_profile_create_stats_64(c_s1, length, matrix);

    (*env)->ReleaseStringUTFChars(env, s1, c_s1);
    return ret;
}

JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_profile_1create_1stats_132
  (JNIEnv *env, jclass class, jstring s1, jlong cptr)
{
    parasail_matrix_t *matrix = NULL;
    const char *c_s1 = NULL;
    jsize length = 0;
    jlong ret;

    assert(0 != cptr);

    matrix = (parasail_matrix_t*)cptr;
    c_s1 = (*env)->GetStringUTFChars(env, s1, NULL);
    length = (*env)->GetStringLength(env, s1);
    ret = (jlong)parasail_profile_create_stats_32(c_s1, length, matrix);

    (*env)->ReleaseStringUTFChars(env, s1, c_s1);
    return ret;
}

JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_profile_1create_1stats_116
  (JNIEnv *env, jclass class, jstring s1, jlong cptr)
{
    parasail_matrix_t *matrix = NULL;
    const char *c_s1 = NULL;
    jsize length = 0;
    jlong ret;

    assert(0 != cptr);

    matrix = (parasail_matrix_t*)cptr;
    c_s1 = (*env)->GetStringUTFChars(env, s1, NULL);
    length = (*env)->GetStringLength(env, s1);
    ret = (jlong)parasail_profile_create_stats_16(c_s1, length, matrix);

    (*env)->ReleaseStringUTFChars(env, s1, c_s1);
    return ret;
}

JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_profile_1create_1stats_18
  (JNIEnv *env, jclass class, jstring s1, jlong cptr)
{
    parasail_matrix_t *matrix = NULL;
    const char *c_s1 = NULL;
    jsize length = 0;
    jlong ret;

    assert(0 != cptr);

    matrix = (parasail_matrix_t*)cptr;
    c_s1 = (*env)->GetStringUTFChars(env, s1, NULL);
    length = (*env)->GetStringLength(env, s1);
    ret = (jlong)parasail_profile_create_stats_8(c_s1, length, matrix);

    (*env)->ReleaseStringUTFChars(env, s1, c_s1);
    return ret;
}

JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_profile_1create_1stats_1sat
  (JNIEnv *env, jclass class, jstring s1, jlong cptr)
{
    parasail_matrix_t *matrix = NULL;
    const char *c_s1 = NULL;
    jsize length = 0;
    jlong ret;

    assert(0 != cptr);

    matrix = (parasail_matrix_t*)cptr;
    c_s1 = (*env)->GetStringUTFChars(env, s1, NULL);
    length = (*env)->GetStringLength(env, s1);
    ret = (jlong)parasail_profile_create_stats_sat(c_s1, length, matrix);

    (*env)->ReleaseStringUTFChars(env, s1, c_s1);
    return ret;
}

JNIEXPORT jboolean JNICALL Java_parasail_JNIparasail_can_1use_1avx2
  (JNIEnv *env, jclass class)
{
    return parasail_can_use_avx2();
}

JNIEXPORT jboolean JNICALL Java_parasail_JNIparasail_can_1use_1sse41
  (JNIEnv *env, jclass class)
{
    return parasail_can_use_sse41();
}

JNIEXPORT jboolean JNICALL Java_parasail_JNIparasail_can_1use_1sse2
  (JNIEnv *env, jclass class)
{
    return parasail_can_use_sse2();
}

/* autogenerated */
/* python ../util/genjavaimpl.py */

JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1scan
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_scan(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_table(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1scan
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_table_scan(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_rowcol(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1scan
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_rowcol_scan(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_trace(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1scan
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_trace_scan(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1scan
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_scan(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_table(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1scan
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_table_scan(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_rowcol(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1scan
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_rowcol_scan(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1scan
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_scan(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_table(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1scan
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_table_scan(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_rowcol(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1scan
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_rowcol_scan(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_trace(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1scan
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_trace_scan(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1scan
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_scan(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_table(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1scan
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_table_scan(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_rowcol(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1scan
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_rowcol_scan(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1scan
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_scan(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_table(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1scan
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_table_scan(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_rowcol(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1scan
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_rowcol_scan(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_trace(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1scan
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_trace_scan(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1scan
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_scan(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_table(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1scan
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_table_scan(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_rowcol(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1scan
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_rowcol_scan(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1scan_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_scan_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1scan_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_scan_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1scan_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_scan_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1scan_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_scan_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1scan_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_scan_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1striped_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_striped_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1striped_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_striped_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1striped_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_striped_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1striped_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_striped_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1striped_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_striped_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1diag_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_diag_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1diag_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_diag_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1diag_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_diag_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1diag_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_diag_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1diag_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_diag_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1scan_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_table_scan_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1scan_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_table_scan_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1scan_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_table_scan_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1scan_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_table_scan_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1scan_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_table_scan_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1striped_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_table_striped_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1striped_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_table_striped_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1striped_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_table_striped_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1striped_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_table_striped_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1striped_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_table_striped_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1diag_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_table_diag_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1diag_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_table_diag_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1diag_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_table_diag_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1diag_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_table_diag_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1diag_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_table_diag_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1scan_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_rowcol_scan_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1scan_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_rowcol_scan_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1scan_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_rowcol_scan_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1scan_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_rowcol_scan_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1scan_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_rowcol_scan_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1striped_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_rowcol_striped_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1striped_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_rowcol_striped_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1striped_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_rowcol_striped_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1striped_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_rowcol_striped_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1striped_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_rowcol_striped_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1diag_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_rowcol_diag_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1diag_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_rowcol_diag_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1diag_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_rowcol_diag_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1diag_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_rowcol_diag_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1diag_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_rowcol_diag_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1scan_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_trace_scan_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1scan_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_trace_scan_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1scan_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_trace_scan_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1scan_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_trace_scan_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1scan_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_trace_scan_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1striped_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_trace_striped_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1striped_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_trace_striped_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1striped_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_trace_striped_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1striped_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_trace_striped_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1striped_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_trace_striped_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1diag_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_trace_diag_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1diag_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_trace_diag_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1diag_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_trace_diag_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1diag_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_trace_diag_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1diag_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_trace_diag_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1scan_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_scan_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1scan_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_scan_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1scan_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_scan_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1scan_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_scan_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1scan_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_scan_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1striped_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_striped_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1striped_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_striped_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1striped_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_striped_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1striped_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_striped_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1striped_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_striped_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1diag_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_diag_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1diag_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_diag_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1diag_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_diag_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1diag_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_diag_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1diag_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_diag_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1scan_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_table_scan_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1scan_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_table_scan_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1scan_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_table_scan_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1scan_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_table_scan_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1scan_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_table_scan_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1striped_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_table_striped_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1striped_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_table_striped_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1striped_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_table_striped_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1striped_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_table_striped_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1striped_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_table_striped_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1diag_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_table_diag_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1diag_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_table_diag_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1diag_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_table_diag_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1diag_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_table_diag_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1diag_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_table_diag_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1scan_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_rowcol_scan_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1scan_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_rowcol_scan_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1scan_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_rowcol_scan_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1scan_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_rowcol_scan_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1scan_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_rowcol_scan_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1striped_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_rowcol_striped_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1striped_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_rowcol_striped_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1striped_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_rowcol_striped_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1striped_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_rowcol_striped_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1striped_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_rowcol_striped_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1diag_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_rowcol_diag_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1diag_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_rowcol_diag_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1diag_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_rowcol_diag_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1diag_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_rowcol_diag_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1diag_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_nw_stats_rowcol_diag_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1scan_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_scan_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1scan_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_scan_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1scan_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_scan_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1scan_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_scan_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1scan_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_scan_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1striped_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_striped_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1striped_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_striped_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1striped_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_striped_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1striped_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_striped_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1striped_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_striped_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1diag_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_diag_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1diag_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_diag_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1diag_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_diag_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1diag_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_diag_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1diag_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_diag_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1scan_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_table_scan_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1scan_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_table_scan_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1scan_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_table_scan_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1scan_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_table_scan_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1scan_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_table_scan_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1striped_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_table_striped_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1striped_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_table_striped_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1striped_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_table_striped_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1striped_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_table_striped_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1striped_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_table_striped_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1diag_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_table_diag_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1diag_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_table_diag_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1diag_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_table_diag_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1diag_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_table_diag_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1diag_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_table_diag_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1scan_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_rowcol_scan_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1scan_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_rowcol_scan_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1scan_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_rowcol_scan_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1scan_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_rowcol_scan_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1scan_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_rowcol_scan_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1striped_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_rowcol_striped_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1striped_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_rowcol_striped_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1striped_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_rowcol_striped_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1striped_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_rowcol_striped_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1striped_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_rowcol_striped_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1diag_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_rowcol_diag_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1diag_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_rowcol_diag_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1diag_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_rowcol_diag_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1diag_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_rowcol_diag_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1diag_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_rowcol_diag_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1scan_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_trace_scan_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1scan_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_trace_scan_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1scan_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_trace_scan_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1scan_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_trace_scan_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1scan_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_trace_scan_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1striped_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_trace_striped_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1striped_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_trace_striped_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1striped_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_trace_striped_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1striped_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_trace_striped_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1striped_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_trace_striped_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1diag_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_trace_diag_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1diag_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_trace_diag_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1diag_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_trace_diag_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1diag_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_trace_diag_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1diag_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_trace_diag_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1scan_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_scan_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1scan_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_scan_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1scan_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_scan_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1scan_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_scan_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1scan_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_scan_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1striped_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_striped_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1striped_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_striped_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1striped_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_striped_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1striped_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_striped_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1striped_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_striped_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1diag_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_diag_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1diag_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_diag_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1diag_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_diag_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1diag_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_diag_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1diag_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_diag_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1scan_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_table_scan_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1scan_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_table_scan_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1scan_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_table_scan_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1scan_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_table_scan_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1scan_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_table_scan_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1striped_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_table_striped_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1striped_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_table_striped_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1striped_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_table_striped_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1striped_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_table_striped_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1striped_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_table_striped_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1diag_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_table_diag_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1diag_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_table_diag_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1diag_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_table_diag_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1diag_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_table_diag_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1diag_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_table_diag_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1scan_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_rowcol_scan_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1scan_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_rowcol_scan_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1scan_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_rowcol_scan_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1scan_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_rowcol_scan_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1scan_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_rowcol_scan_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1striped_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_rowcol_striped_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1striped_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_rowcol_striped_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1striped_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_rowcol_striped_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1striped_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_rowcol_striped_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1striped_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_rowcol_striped_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1diag_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_rowcol_diag_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1diag_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_rowcol_diag_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1diag_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_rowcol_diag_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1diag_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_rowcol_diag_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1diag_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sg_stats_rowcol_diag_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1scan_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_scan_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1scan_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_scan_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1scan_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_scan_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1scan_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_scan_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1scan_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_scan_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1striped_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_striped_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1striped_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_striped_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1striped_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_striped_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1striped_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_striped_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1striped_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_striped_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1diag_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_diag_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1diag_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_diag_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1diag_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_diag_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1diag_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_diag_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1diag_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_diag_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1scan_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_table_scan_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1scan_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_table_scan_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1scan_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_table_scan_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1scan_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_table_scan_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1scan_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_table_scan_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1striped_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_table_striped_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1striped_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_table_striped_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1striped_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_table_striped_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1striped_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_table_striped_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1striped_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_table_striped_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1diag_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_table_diag_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1diag_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_table_diag_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1diag_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_table_diag_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1diag_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_table_diag_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1diag_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_table_diag_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1scan_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_rowcol_scan_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1scan_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_rowcol_scan_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1scan_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_rowcol_scan_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1scan_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_rowcol_scan_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1scan_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_rowcol_scan_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1striped_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_rowcol_striped_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1striped_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_rowcol_striped_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1striped_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_rowcol_striped_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1striped_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_rowcol_striped_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1striped_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_rowcol_striped_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1diag_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_rowcol_diag_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1diag_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_rowcol_diag_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1diag_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_rowcol_diag_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1diag_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_rowcol_diag_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1diag_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_rowcol_diag_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1scan_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_trace_scan_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1scan_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_trace_scan_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1scan_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_trace_scan_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1scan_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_trace_scan_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1scan_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_trace_scan_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1striped_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_trace_striped_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1striped_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_trace_striped_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1striped_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_trace_striped_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1striped_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_trace_striped_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1striped_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_trace_striped_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1diag_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_trace_diag_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1diag_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_trace_diag_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1diag_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_trace_diag_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1diag_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_trace_diag_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1diag_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_trace_diag_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1scan_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_scan_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1scan_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_scan_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1scan_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_scan_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1scan_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_scan_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1scan_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_scan_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1striped_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_striped_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1striped_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_striped_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1striped_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_striped_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1striped_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_striped_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1striped_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_striped_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1diag_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_diag_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1diag_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_diag_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1diag_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_diag_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1diag_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_diag_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1diag_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_diag_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1scan_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_table_scan_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1scan_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_table_scan_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1scan_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_table_scan_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1scan_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_table_scan_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1scan_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_table_scan_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1striped_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_table_striped_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1striped_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_table_striped_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1striped_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_table_striped_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1striped_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_table_striped_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1striped_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_table_striped_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1diag_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_table_diag_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1diag_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_table_diag_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1diag_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_table_diag_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1diag_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_table_diag_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1diag_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_table_diag_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1scan_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_rowcol_scan_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1scan_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_rowcol_scan_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1scan_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_rowcol_scan_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1scan_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_rowcol_scan_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1scan_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_rowcol_scan_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1striped_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_rowcol_striped_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1striped_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_rowcol_striped_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1striped_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_rowcol_striped_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1striped_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_rowcol_striped_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1striped_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_rowcol_striped_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1diag_164
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_rowcol_diag_64(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1diag_132
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_rowcol_diag_32(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1diag_116
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_rowcol_diag_16(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1diag_18
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_rowcol_diag_8(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1diag_1sat
  (JNIEnv *env, jclass class, jstring s1, jstring s2, jint open, jint gap, jlong matrix)
{
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

    result = parasail_sw_stats_rowcol_diag_sat(c_s1, s1Len, c_s2, s2Len, open, gap, c_matrix);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);
    (*env)->ReleaseStringUTFChars(env, s1, c_s1);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1scan_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_scan_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1scan_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_scan_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1scan_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_scan_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1scan_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_scan_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1scan_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_scan_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1striped_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_striped_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1striped_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_striped_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1striped_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_striped_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1striped_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_striped_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1striped_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_striped_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1scan_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_table_scan_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1scan_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_table_scan_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1scan_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_table_scan_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1scan_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_table_scan_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1scan_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_table_scan_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1striped_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_table_striped_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1striped_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_table_striped_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1striped_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_table_striped_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1striped_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_table_striped_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1table_1striped_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_table_striped_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1scan_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_rowcol_scan_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1scan_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_rowcol_scan_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1scan_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_rowcol_scan_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1scan_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_rowcol_scan_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1scan_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_rowcol_scan_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1striped_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_rowcol_striped_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1striped_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_rowcol_striped_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1striped_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_rowcol_striped_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1striped_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_rowcol_striped_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1rowcol_1striped_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_rowcol_striped_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1scan_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_trace_scan_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1scan_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_trace_scan_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1scan_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_trace_scan_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1scan_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_trace_scan_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1scan_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_trace_scan_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1striped_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_trace_striped_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1striped_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_trace_striped_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1striped_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_trace_striped_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1striped_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_trace_striped_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1trace_1striped_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_trace_striped_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1scan_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_scan_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1scan_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_scan_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1scan_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_scan_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1scan_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_scan_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1scan_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_scan_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1striped_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_striped_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1striped_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_striped_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1striped_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_striped_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1striped_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_striped_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1striped_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_striped_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1scan_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_table_scan_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1scan_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_table_scan_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1scan_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_table_scan_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1scan_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_table_scan_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1scan_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_table_scan_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1striped_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_table_striped_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1striped_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_table_striped_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1striped_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_table_striped_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1striped_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_table_striped_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1table_1striped_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_table_striped_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1scan_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_rowcol_scan_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1scan_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_rowcol_scan_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1scan_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_rowcol_scan_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1scan_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_rowcol_scan_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1scan_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_rowcol_scan_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1striped_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_rowcol_striped_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1striped_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_rowcol_striped_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1striped_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_rowcol_striped_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1striped_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_rowcol_striped_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_nw_1stats_1rowcol_1striped_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_nw_stats_rowcol_striped_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1scan_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_scan_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1scan_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_scan_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1scan_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_scan_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1scan_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_scan_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1scan_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_scan_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1striped_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_striped_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1striped_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_striped_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1striped_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_striped_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1striped_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_striped_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1striped_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_striped_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1scan_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_table_scan_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1scan_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_table_scan_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1scan_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_table_scan_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1scan_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_table_scan_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1scan_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_table_scan_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1striped_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_table_striped_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1striped_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_table_striped_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1striped_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_table_striped_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1striped_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_table_striped_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1table_1striped_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_table_striped_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1scan_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_rowcol_scan_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1scan_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_rowcol_scan_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1scan_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_rowcol_scan_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1scan_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_rowcol_scan_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1scan_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_rowcol_scan_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1striped_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_rowcol_striped_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1striped_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_rowcol_striped_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1striped_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_rowcol_striped_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1striped_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_rowcol_striped_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1rowcol_1striped_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_rowcol_striped_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1scan_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_trace_scan_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1scan_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_trace_scan_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1scan_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_trace_scan_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1scan_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_trace_scan_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1scan_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_trace_scan_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1striped_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_trace_striped_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1striped_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_trace_striped_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1striped_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_trace_striped_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1striped_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_trace_striped_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1trace_1striped_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_trace_striped_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1scan_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_scan_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1scan_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_scan_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1scan_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_scan_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1scan_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_scan_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1scan_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_scan_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1striped_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_striped_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1striped_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_striped_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1striped_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_striped_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1striped_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_striped_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1striped_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_striped_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1scan_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_table_scan_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1scan_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_table_scan_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1scan_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_table_scan_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1scan_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_table_scan_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1scan_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_table_scan_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1striped_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_table_striped_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1striped_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_table_striped_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1striped_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_table_striped_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1striped_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_table_striped_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1table_1striped_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_table_striped_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1scan_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_rowcol_scan_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1scan_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_rowcol_scan_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1scan_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_rowcol_scan_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1scan_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_rowcol_scan_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1scan_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_rowcol_scan_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1striped_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_rowcol_striped_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1striped_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_rowcol_striped_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1striped_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_rowcol_striped_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1striped_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_rowcol_striped_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sg_1stats_1rowcol_1striped_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sg_stats_rowcol_striped_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1scan_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_scan_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1scan_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_scan_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1scan_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_scan_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1scan_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_scan_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1scan_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_scan_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1striped_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_striped_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1striped_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_striped_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1striped_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_striped_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1striped_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_striped_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1striped_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_striped_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1scan_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_table_scan_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1scan_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_table_scan_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1scan_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_table_scan_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1scan_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_table_scan_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1scan_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_table_scan_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1striped_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_table_striped_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1striped_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_table_striped_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1striped_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_table_striped_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1striped_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_table_striped_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1table_1striped_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_table_striped_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1scan_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_rowcol_scan_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1scan_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_rowcol_scan_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1scan_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_rowcol_scan_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1scan_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_rowcol_scan_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1scan_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_rowcol_scan_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1striped_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_rowcol_striped_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1striped_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_rowcol_striped_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1striped_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_rowcol_striped_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1striped_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_rowcol_striped_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1rowcol_1striped_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_rowcol_striped_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1scan_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_trace_scan_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1scan_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_trace_scan_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1scan_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_trace_scan_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1scan_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_trace_scan_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1scan_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_trace_scan_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1striped_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_trace_striped_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1striped_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_trace_striped_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1striped_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_trace_striped_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1striped_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_trace_striped_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1trace_1striped_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_trace_striped_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1scan_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_scan_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1scan_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_scan_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1scan_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_scan_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1scan_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_scan_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1scan_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_scan_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1striped_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_striped_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1striped_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_striped_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1striped_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_striped_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1striped_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_striped_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1striped_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_striped_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1scan_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_table_scan_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1scan_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_table_scan_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1scan_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_table_scan_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1scan_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_table_scan_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1scan_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_table_scan_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1striped_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_table_striped_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1striped_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_table_striped_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1striped_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_table_striped_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1striped_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_table_striped_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1table_1striped_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_table_striped_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1scan_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_rowcol_scan_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1scan_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_rowcol_scan_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1scan_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_rowcol_scan_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1scan_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_rowcol_scan_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1scan_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_rowcol_scan_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1striped_1profile_164
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_rowcol_striped_profile_64(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1striped_1profile_132
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_rowcol_striped_profile_32(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1striped_1profile_116
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_rowcol_striped_profile_16(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1striped_1profile_18
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_rowcol_striped_profile_8(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}


JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw_1stats_1rowcol_1striped_1profile_1sat
  (JNIEnv *env, jclass class, jlong profile, jstring s2, jint open, jint gap)
{
    const char *c_s2 = NULL;
    parasail_profile_t *c_profile = NULL;
    parasail_result_t *result = NULL;
    jsize s2Len = 0;

    assert(!(*env)->IsSameObject(env, s2, NULL));
    assert(0 != profile);

    c_s2 = (*env)->GetStringUTFChars(env, s2, NULL);
    s2Len = (*env)->GetStringLength(env, s2);

    c_profile = (parasail_profile_t*)profile;

    result = parasail_sw_stats_rowcol_striped_profile_sat(c_profile, c_s2, s2Len, open, gap);

    (*env)->ReleaseStringUTFChars(env, s2, c_s2);

    return (jlong)result;
}

