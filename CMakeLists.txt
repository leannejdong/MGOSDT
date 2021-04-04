project(gosdt)
cmake_minimum_required(VERSION 3.8.0 FATAL_ERROR)

list(APPEND CMAKE_MODULE_PATH "/usr/share/cmake/Modules")
find_package(TBB COMPONENTS tbbmalloc tbbmalloc_proxy tbb_preview)

enable_testing()

#add_compile_options(-pg)

add_compile_options(-std=c++17 -O2 -g -Wall -Wextra -pedantic -Wmissing-include-dirs -Wformat=2 -Wunused -Wcast-align -Wnon-virtual-dtor -Woverloaded-virtual)
#add_compile_options(-Werror -fdiagnostics-color=auto)
add_compile_options(-fdiagnostics-color=auto)
#add_compile_options(-g -fsanitize=address -fno-omit-frame-pointer)
add_link_options(-g -fsanitize=address)

add_library(${PROJECT_NAME}_lib 
	src/types.hpp 
	src/integrity_violation.hpp 
	src/optimizer/diagnosis/false_convergence.hpp 
	src/optimizer/diagnosis/non_convergence.hpp 
	src/optimizer/diagnosis/trace.hpp 
	src/optimizer/diagnosis/tree.hpp 
	src/optimizer/dispatch/dispatch.hpp 
	src/optimizer/extraction/models.hpp 
	src/bitmask.cpp 
	src/bitmask.hpp 
	src/configuration.cpp 
	src/configuration.hpp 
	src/task.cpp 
	src/task.hpp 
	src/message.cpp 
	src/message.hpp 
	src/tile.cpp 
	src/tile.hpp 
	src/graph.cpp 
	src/graph.hpp 
	src/queue.cpp 
	src/queue.hpp 
	src/model.cpp 
	src/model.hpp 
	src/encoder.cpp 
	src/encoder.hpp 
	src/index.cpp 
	src/index.hpp 
	src/dataset.cpp 
	src/dataset.hpp 
	src/optimizer.cpp 
	src/optimizer.hpp 
	src/state.cpp 
	src/state.hpp 
	src/local_state.cpp 
	src/local_state.hpp 
	src/gosdt.cpp 
	src/gosdt.hpp 
)

target_link_libraries(${PROJECT_NAME}_lib
	PUBLIC 
		tbb
		tbbmalloc
		pthread
		gmp
)

target_include_directories(${PROJECT_NAME}_lib
	PUBLIC 
		include
)

add_executable(${PROJECT_NAME}
	src/main.hpp
	src/main.cpp 
)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_SOURCE_DIR}/${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} 
	PRIVATE 
		${PROJECT_NAME}_lib
)

add_executable(${PROJECT_NAME}_test 
	test/test_bitmask.hpp 
	test/test_index.hpp 
	test/test_queue.hpp 
	test/test_consistency.hpp 
	test/main.cpp
)

set_target_properties(${PROJECT_NAME}_test PROPERTIES OUTPUT_NAME ${PROJECT_SOURCE_DIR}/${PROJECT_NAME}_test)

target_link_libraries(${PROJECT_NAME}_test
	PRIVATE 
		${PROJECT_NAME}_lib
)

add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_SOURCE_DIR}/${PROJECT_NAME}_test WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

if (${CMAKE_SIZEOF_VOID_P} EQUAL 4)
   set(TARGETBITS 32)
else()
   set(TARGETBITS 64)
endif()

message("")
message("${PROJECT_NAME} configured to run on:  ${CMAKE_SYSTEM_NAME} ${TARGETBITS} bit, ${CMAKE_BUILD_TYPE} Mode")
message("${PROJECT_NAME} will be built in:      ${CMAKE_BINARY_DIR}")
message("${PROJECT_NAME} will be installed in:  ${CMAKE_INSTALL_PREFIX}")
message("\n")
