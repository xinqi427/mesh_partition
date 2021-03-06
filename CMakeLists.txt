##-------------------------------------------------------
##          
##                  Partition Tool Project
##
##                By Wenqing Wang
##
##                     02.2012        
##-------------------------------------------------------


cmake_minimum_required(VERSION 2.4.5)

SET (VERSION_MAJOR 4)
SET (VERSION_MINOR 0)
SET (VERSION_PATCH 0)

if(COMMAND cmake_policy)
      cmake_policy(SET CMP0003 NEW)
      cmake_policy(SET CMP0005 NEW)
endif(COMMAND cmake_policy)

IF (WIN32)
	SET ( CMAKE_CONFIGURATION_TYPES "Release;Debug" CACHE TYPE INTERNAL FORCE )
    ADD_DEFINITIONS(-DWIN)	
ENDIF (WIN32)

IF (UNIX)
	string( LENGTH "$ENV{DESTDIR}" DESTDIRLEN )
	IF ( ${DESTDIRLEN} GREATER 0 )
		message( STATUS "DESTDIR specified ($ENV{DESTDIR}). Overriding 
		CMAKE_INSTALL_PREFIX (${CMAKE_INSTALL_PREFIX})" )
		set( CMAKE_INSTALL_PREFIX "" CACHE PATH "Use DESTDIR instead of CMAKE_INSTALL_PREFIX" FORCE )
	ENDIF()
ENDIF (UNIX)

SET(PROJECT_NAME partmesh)
# Project name
PROJECT( ${PROJECT_NAME} )
INCLUDE( Cmake/base.cmake )

# Set build directories
# Binaries are created in /bin and libraries in /lib
SET( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )
SET( LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib )

# Relative paths are used in the created projects
# May not work correcty due to the CMake docs
#SET( CMAKE_USE_RELATIVE_PATHS TRUE )

IF (MSVC)
	ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS)
	ADD_DEFINITIONS(-D_CRT_NONSTDC_NO_WARNINGS)
ENDIF (MSVC)


### For GNU C/CXX.
IF(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_GNUCC)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ansi -Wall -Wextra")
        ADD_DEFINITIONS(
	)
ENDIF(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_GNUCC)

# Compile METIS
include(${CMAKE_SOURCE_DIR}/MetisSetup.cmake)

##Sow all compilation messages
SET( CMAKE_VERBOSE_MAKEFILE on )

INCLUDE_DIRECTORIES(
.
Mesh
)

ADD_SUBDIRECTORY( Mesh )
ADD_SUBDIRECTORY( METIS2ogs )



		


