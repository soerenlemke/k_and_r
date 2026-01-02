cmake_minimum_required(VERSION 4.1)
project(k_and_r C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

function(kandr_apply_common_c_flags tgt)
  target_compile_options(${tgt} PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Wshadow
    -Wconversion
    -Wsign-conversion
    -Wformat=2
    -Wundef
    -Wvla
    -Wstrict-prototypes
    -Wmissing-prototypes
    -Wbad-function-cast
    -Wcast-qual
    -Wcast-align
    -Wdouble-promotion

    $<$<CONFIG:Debug>:-O0 -g3 -fno-omit-frame-pointer>
    $<$<CONFIG:Release>:-O3 -DNDEBUG>
  )

  target_compile_options(${tgt} PRIVATE
    $<$<COMPILE_LANG_AND_ID:C,GNU,Clang>:-Werror>
  )

  target_compile_options(${tgt} PRIVATE
    $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANG_AND_ID:C,GNU,Clang>>:-fsanitize=address,undefined>
  )
  target_link_options(${tgt} PRIVATE
    $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANG_AND_ID:C,GNU,Clang>>:-fsanitize=address,undefined>
  )
endfunction()

add_executable(ch01_ex01 chap01/ex01_01.c)
kandr_apply_common_c_flags(ch01_ex01)

add_executable(ch01_ex02 chap01/ex01_02.c)
kandr_apply_common_c_flags(ch01_ex02)

add_executable(ch01_ex03 chap01/ex01_03.c)
kandr_apply_common_c_flags(ch01_ex03)