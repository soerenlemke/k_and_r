cmake_minimum_required(VERSION 4.1)
project(k_and_r C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(kandr_common_flags INTERFACE)

target_compile_options(kandr_common_flags INTERFACE
        -Wall
        -Wextra
        -Werror
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

        $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANG_AND_ID:C,GNU,Clang>>:-fsanitize=address,undefined>
)

target_link_options(kandr_common_flags INTERFACE
        $<$<AND:$<CONFIG:Debug>,$<COMPILE_LANG_AND_ID:C,GNU,Clang>>:-fsanitize=address,undefined>
)

function(kandr_add_exe name source)
    add_executable(${name} ${source})
    target_link_libraries(${name} PRIVATE kandr_common_flags)
endfunction()

kandr_add_exe(ch01_ex01 chap01/ex01_01.c)
kandr_add_exe(ch01_ex02 chap01/ex01_02.c)
kandr_add_exe(ch01_ex03 chap01/ex01_03.c)
kandr_add_exe(ch01_ex04 chap01/ex01_04.c)
kandr_add_exe(ch01_ex05 chap01/ex01_05.c)
kandr_add_exe(ch01_ex06 chap01/ex01_06.c)
kandr_add_exe(ch01_ex07 chap01/ex01_07.c)
kandr_add_exe(ch01_ex08 chap01/ex01_08.c)