cmake_minimum_required(VERSION 3.10)

project(fakeit)

include(GNUInstallDirs)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/${CMAKE_PROJECT_NAME})

FILE(GLOB_RECURSE files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/../single_header ${CMAKE_CURRENT_SOURCE_DIR}/../single_header/fakeit.hpp)
foreach(file ${files})
	get_filename_component(dir ${file} DIRECTORY)
	FILE(GENERATE OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/include/${CMAKE_PROJECT_NAME}/${dir}.hpp INPUT ${CMAKE_CURRENT_SOURCE_DIR}/../single_header/${file})
endforeach()

add_library(fakeit INTERFACE)
target_include_directories(fakeit
	INTERFACE		
		$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(TARGETS fakeit
		EXPORT ${CMAKE_PROJECT_NAME}-targets
		)
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/${CMAKE_PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
export(TARGETS fakeit APPEND FILE ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake)	

install(EXPORT ${CMAKE_PROJECT_NAME}-targets FILE ${CMAKE_PROJECT_NAME}Config.cmake DESTINATION ${CMAKE_INSTALL_LIBDIR}/${CMAKE_PROJECT_NAME}/cmake)
export(PACKAGE ${CMAKE_PROJECT_NAME})
