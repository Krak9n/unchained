cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 23)

project(unchained)

find_package(glfw3 REQUIRED)
find_package(Freetype REQUIRED)
find_package(OpenGL REQUIRED)

add_library(glad include/glad/src/glad.c)

set(CMAKE_CXX_FLAGS
	"-I/usr/include/freetype2 -I/usr/include/libpng16 -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl"
)

set(SOURCES
	src/main.cpp
	src/pipeline/Shader.cpp
	src/pipeline/Text.cpp
	src/pipeline/Video.cpp
	src/text/TextRendering.cpp
	src/window/window.cpp
	src/screenshots/img_s.cpp
)

add_executable(${PROJECT_NAME}
	${SOURCES}
)

target_include_directories(${PROJECT_NAME}
	PRIVATE
		src/
		include/glad/include/
)
target_link_libraries(${PROJECT_NAME}
	PRIVATE
		OpenGL::GL
		glad
		glfw
		Freetype::Freetype
)
