
project(value)

set(HEDEAR_FILES Value.h)
set(SOURCE_FILES Value.cpp)

add_library(libvalue STATIC ${SOURCE_FILES})
target_include_directories(libvalue PUBLIC .)

add_executable(value ${SOURCE_FILES} main.cpp)

target_link_libraries(value libvalue)
