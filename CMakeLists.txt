PROJECT( parasail-java )

CMAKE_MINIMUM_REQUIRED( VERSION 3.1 )

SET( CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH} )

FIND_PACKAGE(Java COMPONENTS Development REQUIRED)
FIND_PACKAGE(JNI REQUIRED)
INCLUDE(UseJava)

# find parasail
INCLUDE(FindPackageHandleStandardArgs)
FIND_PATH(PARASAIL_INCLUDE_DIR parasail.h)
FIND_LIBRARY(PARASAIL_LIBRARY parasail)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(PARASAIL
    DEFAULT_MSG
    PARASAIL_INCLUDE_DIR
    PARASAIL_LIBRARY
)
MARK_AS_ADVANCED(PARASAIL_LIBRARY PARASAIL_INCLUDE_DIR)
IF(PARASAIL_FOUND)
    SET(PARASAIL_LIBRARIES    ${PARASAIL_LIBRARY})
    SET(PARASAIL_INCLUDE_DIRS ${PARASAIL_INCLUDE_DIR})
ELSE()
    MESSAGE (SEND_ERROR "parasail library not found")
ENDIF()

# compile JNIparasail.java to class file
ADD_JAR(parasail JNIparasail.java)
GET_TARGET_PROPERTY(_jarFile parasail JAR_FILE)
GET_TARGET_PROPERTY(_classDir parasail CLASSDIR)

# generate JNIparasail.h stub
SET (_stubDir "${CMAKE_CURRENT_BINARY_DIR}")
ADD_CUSTOM_COMMAND(
    OUTPUT JNIparasail.h
    COMMAND ${Java_JAVAH_EXECUTABLE} -verbose
        -classpath ${_classDir}
        -d ${_stubDir}
        -jni JNIparasail
    DEPENDS parasail.jar
    )

# generate parasail JNI module
INCLUDE_DIRECTORIES(
    ${JAVA_INCLUDE_PATH}
    ${JAVA_INCLUDE_PATH2}
    ${_classDir}
    ${_stubDir}
    ${PARASAIL_INCLUDE_DIRS})
ADD_LIBRARY(JNIparasail MODULE JNIparasail.c JNIparasail.h)
TARGET_LINK_LIBRARIES(JNIparasail ${JNI_LIBRARIES} ${PARASAIL_LIBRARIES})
## The library name expected by the JNI relative to the system:
##   MacOS  : libLIBRARY.jnilib
##   Windows: LIBRARY.dll
##   Linux  : libLIBRARY.so
##
## where LIBRARY is used in java to load the library:
##      System.loadLibrary("LIBRARY");
IF(APPLE)
  SET_TARGET_PROPERTIES(JNIparasail PROPERTIES PREFIX "lib" SUFFIX ".jnilib")
ELSEIF(WIN32)
  SET_TARGET_PROPERTIES(JNIparasail PROPERTIES PREFIX "" SUFFIX ".dll")
ELSEIF(UNIX)
  SET_TARGET_PROPERTIES(JNIparasail PROPERTIES PREFIX "lib" SUFFIX ".so")
ENDIF(APPLE)

ENABLE_TESTING()

# add test to run JNIparasail
ADD_TEST(NAME TestJNIparasail
    COMMAND ${Java_JAVA_EXECUTABLE}
    -Djava.library.path=${CMAKE_CURRENT_BINARY_DIR}
    -cp ${_jarFile} JNIparasail)
