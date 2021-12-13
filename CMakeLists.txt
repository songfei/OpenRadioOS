cmake_minimum_required(VERSION 3.20)
project(test_sdl C)

set(CMAKE_C_STANDARD 99)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(src)
include_directories(src/core)

include_directories(src/ui)
include_directories(src/ui/layer)
include_directories(src/ui/types)
include_directories(src/ui/animation)

include_directories(lib/FreeRTOS/include)
include_directories(lib/FreeRTOS/portable/GCCPosix)

aux_source_directory(lib/FreeRTOS FreeRTOS_C_FILE_LIST)

set(FreeRTOS_C_PORT_FILE_LIST
        lib/FreeRTOS/portable/GCCPosix/port.c
        lib/FreeRTOS/portable/GCCPosix/portmacro.h
        lib/FreeRTOS/portable/GCCPosix/utils/wait_for_event.c
        lib/FreeRTOS/portable/MemMang/heap_4.c
        src/FreeRTOS.c)

set(CORE_FILE_LIST
        src/core/node_list.h
        src/core/log.h
        src/core/log.c
        )

set(UI_FILE_LIST
        src/ui/ui.h
        src/ui/utils.h
        src/ui/types/color.h
        src/ui/types/colors.h
        src/ui/types/cornermask.h
        src/ui/types/point.h
        src/ui/types/rect.c
        src/ui/types/rect.h
        src/ui/types/size.h
        src/ui/types/context.h
        src/ui/types/context.c
        src/ui/layer/layer.h
        src/ui/layer/layer.c
        src/ui/animation/animation.h
        src/ui/animation/animation.c
        src/ui/animation/property_animation.h
        src/ui/animation/property_animation.c
        src/ui/window.h
        src/ui/window.c
        )

add_executable(test_sdl ${FreeRTOS_C_FILE_LIST} ${FreeRTOS_C_PORT_FILE_LIST} ${CORE_FILE_LIST} ${UI_FILE_LIST} main.c)

target_link_libraries(test_sdl ${SDL2_LIBRARIES})