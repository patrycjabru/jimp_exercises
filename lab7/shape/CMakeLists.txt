
project(shape)

set(HEDEAR_FILES Shape.h)
set(SOURCE_FILES Shape.cpp)

add_library(libshape STATIC ${SOURCE_FILES})
target_include_directories(libshape PUBLIC .)

add_executable(shape ${SOURCE_FILES} main.cpp)

target_link_libraries(shape libshape)
