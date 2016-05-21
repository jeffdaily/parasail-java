#include <assert.h>
#include <stdlib.h>

#include "JNIparasail.h"
#include "parasail.h"
#include "parasail/matrices/blosum62.h"

JNIEXPORT jlong JNICALL Java_JNIparasail_sw
  (JNIEnv *env, jobject this, jbyteArray s1, jbyteArray s2, jint open, jint extend, jlong matrix)
{
    jbyte *s1b = (*env)->GetByteArrayElements(env, s1, NULL);
    jbyte *s2b = (*env)->GetByteArrayElements(env, s2, NULL);
    jsize s1Len = (*env)->GetArrayLength(env, s1);
    jsize s2Len = (*env)->GetArrayLength(env, s2);

    parasail_result_t *result = parasail_sw(s1b, s1Len, s2b, s2Len, open, extend, &parasail_blosum62);
    jlong ret = result->score;
    parasail_result_free(result);

    (*env)->ReleaseByteArrayElements(env, s2, s2b, JNI_ABORT);
    (*env)->ReleaseByteArrayElements(env, s1, s1b, JNI_ABORT);

    return ret;
}

