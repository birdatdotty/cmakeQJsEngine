cmake_minimum_required(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(Console LANGUAGES CXX)

find_package(Qt5 COMPONENTS Core REQUIRED)

add_library(${PROJECT_NAME} STATIC
	Console.cpp
)
set_target_properties(Console PROPERTIES PUBLIC_HEADER "Console.h")

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core)

install(TARGETS Console
       DESTINATION lib
       PUBLIC_HEADER DESTINATION include)
