
project(arrayfilling)

set(HEDEAR_FILES ArrayFilling.h)
set(SOURCE_FILES ArrayFilling.cpp)

add_library(libarrayfilling STATIC ${SOURCE_FILES})
target_include_directories(libarrayfilling PUBLIC .)

add_executable(arrayfilling ${SOURCE_FILES} main.cpp)

target_link_libraries(arrayfilling libarrayfilling)
