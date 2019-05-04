cmake_minimum_required(VERSION 3.13)

project(corewar_vm)

set(CMAKE_C_STANDARD 99)

AUX_SOURCE_DIRECTORY(sources SRCS)
AUX_SOURCE_DIRECTORY(sources/parse SRCSP)
AUX_SOURCE_DIRECTORY(sources/op LSRCS)
AUX_SOURCE_DIRECTORY(sources/vis VSRCS)

add_executable(corewar
        ${SRCS}
        ${LSRCS}
        ${SRCSP}
        ${VSRCS})

target_include_directories(corewar
        PUBLIC includes
        PUBLIC includes/parse
        PUBLIC libft/includes
        PUBLIC includes/op
        PUBLIC includes/vis
        PUBLIC libs/SDL2_ttf/includes
        PUBLIC libs/SDL2/includes)

target_link_directories(corewar
        PUBLIC libft
        PUBLIC libs/SDL2_ttf
        PUBLIC libs/SDL2)

target_link_libraries(corewar
        libft.a
        libSDL2-2.0.0.dylib
        libSDL2_ttf-2.0.0.dylib)

