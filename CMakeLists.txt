set( TARGET_LIB_NAME genome_islands )
set( Boost_NO_BOOST_CMAKE ON )

cmake_minimum_required( VERSION 2.8.0 )

project( ${TARGET_LIB_NAME} )

add_library(${TARGET_LIB_NAME} SHARED ${TARGET_LIB_NAME}.cpp)
message("${TARGET_LIB_NAME}.cpp\n")

set( PYTHON_LIBRARY /sw/comp/python/2.7.6_tintin/lib/libpython2.7.so )
set( PYTHON_INCLUDE_DIR /sw/comp/python/2.7.6_tintin/include/python.h )

find_package( PythonLibs 2.7.6 REQUIRED )
if( PYTHONLIBS_FOUND )
	include_directories(${PYTHON_INCLUDE_DIRS})
	target_link_libraries(${TARGET_LIB_NAME} ${PYTHON_LIBRARY_DIRS})
endif( PYTHONLIBS_FOUND )


find_package( Boost 1.59 REQUIRED )
if( Boost_FOUND )
	include_directories(${Boost_INCLUDE_DIRS})	
	target_link_libraries(${TARGET_LIB_NAME} ${Boost_LIBRARY_DIRS})
endif( Boost_FOUND )


