
project(simple_json)

set(HEDEAR_FILES SimpleJson.h)
set(SOURCE_FILES SimpleJson.cpp)

add_library(libsimplejson STATIC ${SOURCE_FILES})
target_include_directories(libsimplejson PUBLIC .)

add_executable(simple_json ${SOURCE_FILES} main.cpp)

target_link_libraries(simple_json libsimplejson)
