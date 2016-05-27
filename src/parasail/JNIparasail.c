#include <assert.h>
#include <stdlib.h>

#include "parasail_JNIparasail.h"
#include "parasail.h"
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
    //jbyte *nameb = NULL;
    const char *nameb = NULL;
    jlong ret;

    //nameb = (*env)->GetByteArrayElements(env, namej, NULL);
    nameb = (*env)->GetStringUTFChars(env, namej, NULL);
    printf("Java_parasail_JNIparasail_matrix_1lookup '%s'\n", (const char*)nameb);
    ret = (jlong)parasail_matrix_lookup((const char*)nameb);
    assert(0 != ret);

    //(*env)->ReleaseByteArrayElements(env, namej, nameb, JNI_ABORT);
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

