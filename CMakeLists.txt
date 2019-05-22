cmake_minimum_required (VERSION 3.0)

project (TO_DO_LIST)


set(HEADER_FILES node.h heap.h)
add_library(node node.cpp ${HEADER_FILES})
add_library(heap heap.cpp ${HEADER_FILES})
add_executable(main main.cpp ${HEADER_FILES})
target_link_libraries(heap node)
target_link_libraries(main node)
target_link_libraries(main heap)
target_compile_options(main PRIVATE -std=c++0x -g -Wall)