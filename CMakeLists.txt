cmake_minimum_required(VERSION 3.13)
project(rpi_touch)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(CMAKE_CXX_STANDARD 17)

if(WIN32)
set(SDL2_PATH "D:\\C++\\SDL2-2.0.10\\x86_64-w64-mingw32")
set(SDL2_IMAGE_PATH "D:\\C++\\SDL2_image-2.0.5\\x86_64-w64-mingw32")
set(SDL2_TTF_PATH "D:\\C++\\SDL2_ttf-2.0.15\\x86_64-w64-mingw32")
ELSE()
    ENDIF()
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_executable(rpi_touch main.cpp Texture.cpp Texture.h Button.cpp Button.h)

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES})
