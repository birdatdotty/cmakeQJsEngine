cmake_minimum_required(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(Deps LANGUAGES CXX)

find_package(Qt5 COMPONENTS Core REQUIRED)

add_library(${PROJECT_NAME} STATIC
	Deps.cpp
	Dll.cc
)
#set_target_properties(Deps PROPERTIES PUBLIC_HEADER "Deps.h;Dll.h")
set_target_properties(Deps PROPERTIES PUBLIC_HEADER "Deps.h")

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core)

install(TARGETS Deps
	DESTINATION lib
	PUBLIC_HEADER DESTINATION include)
