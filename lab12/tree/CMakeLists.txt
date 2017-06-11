
project(tree)

set(HEDEAR_FILES Tree.h)
set(SOURCE_FILES Tree.cpp)

add_library(libtree STATIC ${SOURCE_FILES})
target_include_directories(libtree PUBLIC .)

add_library(libtreeiterators STATIC TreeIterators.h ${SOURCE_FILES})
target_link_libraries(libtreeiterators libtree)
target_include_directories(libtree PUBLIC .)

add_executable(tree ${SOURCE_FILES} main.cpp TreeIterators.h Tree.h)

target_link_libraries(tree libtree)
