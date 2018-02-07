cmake_minimum_required(VERSION 3.1.0)

project(xadc_test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra -Werror -Wcast-qual -Wconversion -Wunreachable-code -Wmissing-noreturn -Wshadow -Wfatal-errors")

find_package(Threads REQUIRED)

include_directories(xadc_lib/include include)

file(GLOB LIB_SRC xadc_lib/src/*.c src/xadc_core.cpp)
add_library(xadc_core SHARED ${LIB_SRC})
target_link_libraries(xadc_core ${CMAKE_THREAD_LIBS_INIT})
install(TARGETS xadc_core DESTINATION lib)

install(DIRECTORY DESTINATION include/xadc)
install(FILES include/xadc_core.h DESTINATION include/xadc)

file(GLOB APP_SRC src/main.cpp)
add_executable(xadc_test ${APP_SRC})
target_link_libraries(xadc_test xadc_core)
install(TARGETS xadc_test DESTINATION bin)

# Cppcheck tests

file(GLOB APP_SRC ${APP_SRC} include/*.h)

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
set(INCLUDE_DIRECTORIES "")
foreach(dir ${dirs})
  list(APPEND INCLUDE_DIRECTORIES  " " -I${dir})
endforeach()

find_program(CPPCHECK_BIN cppcheck)
if(EXISTS ${CPPCHECK_BIN})
  add_custom_target(cppcheck
          COMMAND cppcheck
          --enable=all 
          --language=c++
          ${APP_SRC}
          ${INCLUDE_DIRECTORIES} 
          --suppress=missingIncludeSystem -v -q --error-exitcode=2
          --template='[{file}:{line}] [{severity},{id}] {message}'
  )

  add_dependencies(xadc_test cppcheck)
else()
  message(AUTHOR_WARNING "cppcheck is not installed, some checks will not be performed")
endif()


# clang-format

file(GLOB CLANG_FORMAT_FILE .clang-format)

find_program(CLANG_FORMAT clang-format) 
if(EXISTS ${CLANG_FORMAT})
  add_custom_target(clangformat
        COMMAND clang-format
        -style=file
        -assume-filename=${CLANG_FORMAT_FILE}
        -i
        ${APP_SRC}
  )

  add_dependencies(xadc_test clangformat)
else()
  message(AUTHOR_WARNING "clang-format is not installed, auto formating will not be performed")
endif()

