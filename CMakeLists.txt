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

SET (_binDir "${CMAKE_CURRENT_BINARY_DIR}")
SET (_pkgDir "${CMAKE_CURRENT_BINARY_DIR}/parasail")
SET (_srcDir "${CMAKE_CURRENT_SOURCE_DIR}/src/parasail")

ADD_CUSTOM_COMMAND(
    OUTPUT ${_pkgDir}/JNIparasail.class
    COMMAND ${Java_JAVAC_EXECUTABLE} -d ${_binDir} ${_srcDir}/JNIparasail.java
    MAIN_DEPENDENCY ${_srcDir}/JNIparasail.java
)

ADD_CUSTOM_COMMAND(
    OUTPUT ${_pkgDir}/Matrix.class
    COMMAND ${Java_JAVAC_EXECUTABLE} -d ${_binDir} ${_srcDir}/Matrix.java
    MAIN_DEPENDENCY ${_srcDir}/Matrix.java
    DEPENDS ${_pkgDir}/JNIparasail.class
)

ADD_CUSTOM_COMMAND(
    OUTPUT ${_pkgDir}/Result.class
    COMMAND ${Java_JAVAC_EXECUTABLE} -d ${_binDir} ${_srcDir}/Result.java
    MAIN_DEPENDENCY ${_srcDir}/Result.java
    DEPENDS ${_pkgDir}/JNIparasail.class
)

# generate JNIparasail.h stub
ADD_CUSTOM_COMMAND(
    OUTPUT parasail_JNIparasail.h
    COMMAND ${Java_JAVAH_EXECUTABLE} -verbose
        -classpath ${CMAKE_CURRENT_BINARY_DIR}
        -jni parasail.JNIparasail
    MAIN_DEPENDENCY parasail/JNIparasail.class
)

ADD_CUSTOM_TARGET(
    parasail.jar
    ALL
    ${Java_JAR_EXECUTABLE} -cf parasail.jar ${_pkgDir}
    DEPENDS ${_pkgDir}/JNIparasail.class
        ${_pkgDir}/Matrix.class
        ${_pkgDir}/Result.class
)

# generate parasail JNI module
INCLUDE_DIRECTORIES(
    ${JAVA_INCLUDE_PATH}
    ${JAVA_INCLUDE_PATH2}
    ${_binDir}
    ${PARASAIL_INCLUDE_DIRS})
ADD_LIBRARY(JNIparasail MODULE src/parasail/JNIparasail.c parasail_JNIparasail.h)
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
