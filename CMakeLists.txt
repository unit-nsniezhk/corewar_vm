cmake_minimum_required(VERSION 3.13)

project(corewar_vm)

set(CMAKE_C_STANDARD 99)

set(FRAMEWORKS_DIR /Users/dderevyn/Library/Frameworks/)

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
        PUBLIC includes/
        PUBLIC includes/parse/
        PUBLIC libft/includes/
        PUBLIC includes/op/
        PUBLIC includes/vis/
        PUBLIC ${FRAMEWORKS_DIR}SDL2.framework/Headers
        PUBLIC ${FRAMEWORKS_DIR}SDL2_image.framework/Headers
        PUBLIC ${FRAMEWORKS_DIR}SDL2_ttf.framework/Headers
        PUBLIC ${FRAMEWORKS_DIR}SDL2_mixer.framework/Headers)

target_link_directories(corewar
        PUBLIC libft/)

target_link_libraries(corewar
        libft.a
        "-F ${FRAMEWORKS_DIR} -framework SDL2"
        "-F ${FRAMEWORKS_DIR} -framework SDL2_image"
        "-F ${FRAMEWORKS_DIR} -framework SDL2_ttf"
        "-F ${FRAMEWORKS_DIR} -framework SDL2_mixer")
