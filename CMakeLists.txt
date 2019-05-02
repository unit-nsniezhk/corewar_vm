cmake_minimum_required(VERSION 3.13)

project(corewar_vm)

set(CMAKE_C_STANDARD 99)

AUX_SOURCE_DIRECTORY(sources SRCS)
AUX_SOURCE_DIRECTORY(sources/parse SRCSP)
AUX_SOURCE_DIRECTORY(sources/op LSRCS)

add_executable(corewar
        ${SRCS}
        ${LSRCS}
        ${SRCSP})

target_include_directories(corewar
        PUBLIC includes
        PUBLIC includes/parse
        PUBLIC libft/includes
        PUBLIC includes/op)

target_link_directories(corewar
        PUBLIC libft)

target_link_libraries(corewar libft.a)

