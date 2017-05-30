
project(vector)

set(HEDEAR_FILES Vector.h)
set(SOURCE_FILES Vector.cpp)

add_library(libvector STATIC ${SOURCE_FILES})
target_include_directories(libvector PUBLIC .)

add_executable(vector ${SOURCE_FILES} main.cpp)

target_link_libraries(vector libvector)
