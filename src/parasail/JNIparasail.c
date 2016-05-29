#include <assert.h>
#include <stdlib.h>

#include "parasail_JNIparasail.h"
#include "parasail.h"
#include "parasail/cpuid.h"
#include "parasail/matrices/blosum62.h"

JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_sw
  (JNIEnv *env, jclass this, jbyteArray s1, jbyteArray s2, jint open, jint extend, jlong matrix_)
{
    jbyte *j1b = (*env)->GetByteArrayElements(env, s1, NULL);
    jbyte *j2b = (*env)->GetByteArrayElements(env, s2, NULL);
    jsize s1Len = (*env)->GetArrayLength(env, s1);
    jsize s2Len = (*env)->GetArrayLength(env, s2);

    const char *s1b = (const char *)j1b;
    const char *s2b = (const char *)j2b;
    parasail_matrix_t *matrix = (parasail_matrix_t*)matrix_;

    parasail_result_t *result = parasail_sw(s1b, s1Len, s2b, s2Len, open, extend, matrix);
    jlong ret = result->score;
    parasail_result_free(result);

    (*env)->ReleaseByteArrayElements(env, s2, j2b, JNI_ABORT);
    (*env)->ReleaseByteArrayElements(env, s1, j1b, JNI_ABORT);

    return ret;
}

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

JNIEXPORT jboolean JNICALL Java_parasail_JNIparasail_matrix_1need_1free
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_matrix_t *matrix = NULL;
    jboolean result;

    assert(0 != cptr);

    matrix = (parasail_matrix_t*)cptr;
    result = matrix->need_free;

    return result;
}

JNIEXPORT jlong JNICALL Java_parasail_JNIparasail_matrix_1lookup
  (JNIEnv *env, jclass class, jstring namej)
{
    const char *nameb = NULL;
    jlong ret;

    nameb = (*env)->GetStringUTFChars(env, namej, NULL);
    printf("Java_parasail_JNIparasail_matrix_1lookup '%s'\n", (const char*)nameb);
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
    return result->saturated;
}

JNIEXPORT jint JNICALL Java_parasail_JNIparasail_result_1score
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_result_t *result = NULL;

    assert(0 != cptr);

    result = (parasail_result_t*)cptr;
    return result->score;
}

JNIEXPORT jint JNICALL Java_parasail_JNIparasail_result_1matches
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_result_t *result = NULL;

    assert(0 != cptr);

    result = (parasail_result_t*)cptr;
    return result->matches;
}

JNIEXPORT jint JNICALL Java_parasail_JNIparasail_result_1similar
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_result_t *result = NULL;

    assert(0 != cptr);

    result = (parasail_result_t*)cptr;
    return result->similar;
}

JNIEXPORT jint JNICALL Java_parasail_JNIparasail_result_1length
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_result_t *result = NULL;

    assert(0 != cptr);

    result = (parasail_result_t*)cptr;
    return result->length;
}

JNIEXPORT jint JNICALL Java_parasail_JNIparasail_result_1end_1query
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_result_t *result = NULL;

    assert(0 != cptr);

    result = (parasail_result_t*)cptr;
    return result->end_query;
}

JNIEXPORT jint JNICALL Java_parasail_JNIparasail_result_1end_1ref
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_result_t *result = NULL;

    assert(0 != cptr);

    result = (parasail_result_t*)cptr;
    return result->end_ref;
}

JNIEXPORT void JNICALL Java_parasail_JNIparasail_result_1free
  (JNIEnv *env, jclass class, jlong cptr)
{
    parasail_result_t *result = NULL;

    assert(0 != cptr);

    result = (parasail_result_t*)cptr;
    parasail_result_free(result);
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

