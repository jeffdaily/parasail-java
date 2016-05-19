PROJECT( parasail-java )

CMAKE_MINIMUM_REQUIRED( VERSION 3.1 )

SET( CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH} )

FIND_PACKAGE(Java COMPONENTS Development REQUIRED)
FIND_PACKAGE(JNI REQUIRED)
INCLUDE(UseJava)

IF (NOT JAVA_FOUND)
    MESSAGE (SEND_ERROR "Java not found")
ENDIF()

IF (NOT JNI_FOUND)
    MESSAGE (SEND_ERROR "Java JNI headers not found")
ENDIF()

# compile JNIparasail.java to class file
ADD_JAR(JNIparasail JNIparasail.java)
GET_TARGET_PROPERTY(_jarFile JNIparasail JAR_FILE)
GET_TARGET_PROPERTY(_classDir JNIparasail CLASSDIR)

# generate JNIparasail.h stub
SET (_stubDir "${CMAKE_CURRENT_BINARY_DIR}")
ADD_CUSTOM_COMMAND(
    OUTPUT JNIparasail.h
    COMMAND ${Java_JAVAH_EXECUTABLE} -verbose
        -classpath ${_classDir}
        -d ${_stubDir}
        -jni JNIparasail
    )

# generate libparasail.jnilib
INCLUDE_DIRECTORIES(${JAVA_INCLUDE_PATH} ${_classDir} ${_stubDir})
ADD_LIBRARY(parasail MODULE parasail.c JNIparasail.h)
SET_TARGET_PROPERTIES(parasail PROPERTIES SUFFIX ".jnilib")
TARGET_LINK_LIBRARIES(parasail ${JNI_LIBRARIES})

