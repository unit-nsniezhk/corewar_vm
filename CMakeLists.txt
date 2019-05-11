cmake_minimum_required(VERSION 3.13)

project(corewar)

set(CMAKE_C_COMPILER clang)
set(CMAKE_C_STANDARD 99)

#TODO Dont forget to change the framework path for MacOS / library path for Linux
set(FRAMEWORK_PATH /Users/dderevyn/Library/Frameworks/)

set(LIBRARY_PATH /home/linuxbrew/.linuxbrew/lib)
set(LIBRARY_INCLUDE_PATH /home/linuxbrew/.linuxbrew/include)

set(INCLUDE_PATH include/)
set(SOURCE_PATH source/)
set(EXECUTABLE corewar)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${SOURCE_PATH}*.c)

add_executable(${EXECUTABLE}
		${SOURCES})

target_compile_options(${EXECUTABLE} PRIVATE -Wall -Wextra -Werror -Ofast)

target_include_directories(${EXECUTABLE}
		PRIVATE ${INCLUDE_PATH}
		PRIVATE ${INCLUDE_PATH}op/
		PRIVATE ${INCLUDE_PATH}parse/
		PRIVATE ${INCLUDE_PATH}vis/
		PRIVATE libft/include)

target_link_directories(${EXECUTABLE}
		PRIVATE libft/)

target_link_libraries(${EXECUTABLE}
		ft)

if (${CMAKE_SYSTEM_NAME} STREQUAL Darwin)

	target_include_directories(${EXECUTABLE}
			PRIVATE ${FRAMEWORK_PATH}SDL2.framework/Headers
			PRIVATE ${FRAMEWORK_PATH}SDL2_image.framework/Headers
			PRIVATE ${FRAMEWORK_PATH}SDL2_ttf.framework/Headers
			PRIVATE ${FRAMEWORK_PATH}SDL2_mixer.framework/Headers)

    target_link_libraries(${EXECUTABLE}
			"-F ${FRAMEWORK_PATH} -framework SDL2"
			"-F ${FRAMEWORK_PATH} -framework SDL2_image"
			"-F ${FRAMEWORK_PATH} -framework SDL2_ttf"
			"-F ${FRAMEWORK_PATH} -framework SDL2_mixer")

elseif(${CMAKE_SYSTEM_NAME} STREQUAL Linux)

	target_include_directories(${EXECUTABLE}
			PRIVATE ${LIBRARY_INCLUDE_PATH})

	target_link_directories(${EXECUTABLE}
			PRIVATE ${LIBRARY_PATH})

    target_link_libraries(${EXECUTABLE}
			SDL2
			SDL2_image
			SDL2_mixer
			SDL2_ttf)

endif()