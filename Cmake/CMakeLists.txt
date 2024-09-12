cmake_minimum_required(VERSION 3.19)

project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Задайте URL архива и путь назначения
set(SDL2_name "SDL2-2.0.8")
set(SDL2_zip_URL "https://sourceforge.net/projects/libsdl/files/SDL/2.0.8/SDL2-2.0.8.zip/download")
set(SDL2_zip_path "${CMAKE_SOURCE_DIR}/bin/${SDL2_name}.zip")
set(SDL2_out_path "${CMAKE_BINARY_DIR}/${SDL2_name}")

# Делаем папку bin
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Качаем архив с SDL2
file(DOWNLOAD ${SDL2_zip_URL} ${SDL2_zip_path}
     STATUS status
     SHOW_PROGRESS)
# Распаковываем его
file(ARCHIVE_EXTRACT INPUT ${SDL2_zip_path} DESTINATION ${SDL2_out_path})

# --
file(GLOB_RECURSE srcs
   "${CMAKE_SOURCE_DIR}/src/*.h"
   "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

# Поиск SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${srcs})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_directory_properties(PROPERTIES VS_STARTUP_PROJECT ${PROJECT_NAME})
