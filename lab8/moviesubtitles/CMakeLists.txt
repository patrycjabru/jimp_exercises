
project(microdvd)

set(HEDEAR_FILES MovieSubtitles.h)
set(SOURCE_FILES MovieSubtitles.cpp)

add_library(libmicrodvd STATIC ${SOURCE_FILES})
target_include_directories(libmicrodvd PUBLIC .)

add_executable(microdvd ${SOURCE_FILES} main.cpp)

target_link_libraries(microdvd libmicrodvd)
