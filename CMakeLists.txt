cmake_minimum_required(VERSION 3.8)
project("robot-simulation")

set(MY_SOURCES
    "main.cpp"
    "point.cpp"
    "point_shape.cpp"
    "rnd.cpp"
	"triangulation.cpp"
	"line.cpp"
	"line_shape.cpp"
	"drawable.cpp"
)

set(MY_HEADERS
    "main.h"
    "point.h"
    "point_shape.h"
    "rnd.h"
	"triangulation.h"
	"line.h"
	"line_shape.h"
	"drawable.h"

	"circular_list.h"
	"shape.h"
)

if (WIN32)
    include_directories("include")
    link_directories("lib")
endif (WIN32)

add_executable("robot-simulation" ${MY_SOURCES} ${MY_HEADERS})

if (WIN32)
    target_link_libraries("robot-simulation" "freeglut")
	add_custom_command(TARGET "robot-simulation" POST_BUILD
		COMMAND ${CMAKE_COMMAND} "-E copy_directory"
			"${PROJECT_SOURCE_DIR}/dll"
			"$<TARGET_FILE_DIR:robot-simulation>")
endif (WIN32)

if (UNIX)
    target_link_libraries("robot-simulation" "GL" "GLU" "glut")
endif (UNIX)
