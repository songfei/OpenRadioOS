#include <stdio.h>
#include <SDL.h>

#include <FreeRTOS.h>
#include <task.h>
#include <ui/types/color.h>

#include <node_list.h>

#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 128
#define SCREEN_SCALE 4

uint16_t frameBuffer[SCREEN_WIDTH * SCREEN_HEIGHT];

static const char* task1Name = "Task1 is running\n";
static const char* task2Name = "Task2 is running\n";

_Noreturn void vTaskFunction(void* params) {
    char* taskName = (char*) params;
    for(;;) {
        printf("%s", taskName);
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}

int main() {

    GColor red =  n_GColorFromRGB(255, 0, 128);

    printf("%d %d %d\n", red.r, red.g, red.b);

    xTaskCreate(vTaskFunction, "Task1", 1000, (void*)task1Name, 1, NULL);
    xTaskCreate(vTaskFunction, "Task2", 1000, (void*)task2Name, 1, NULL);

    vTaskStartScheduler();
//    memset(frameBuffer, 0xff, SCREEN_WIDTH * SCREEN_HEIGHT * 2);

//    frameBuffer[1000] = 0xffff;
//
//    printf("Hello, World!\n");
//
//    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
//        printf("init sdl error\n");
//    }
//    SDL_Window *window = SDL_CreateWindow("Hello SDL world!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
//                                          SCREEN_WIDTH * SCREEN_SCALE, SCREEN_HEIGHT * SCREEN_SCALE, SDL_WINDOW_ALLOW_HIGHDPI);
//    if (NULL == window) {
//        printf("create window error\n");
//    }
//
//    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//    if(NULL == renderer) {
//        printf("create renderer error\n");
//    }
//
//    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB565, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);
//    if(NULL == texture) {
//        printf("create texture error\n");
//    }
//
//    SDL_Event windowEvent;
//    while(1) {
//        if (SDL_WaitEvent(&windowEvent)) {
////            printf("event %u\n", windowEvent.type);
//            if (SDL_QUIT == windowEvent.type) {
//                printf("quit\n");
//                break;
//            }
//            else if(SDL_KEYDOWN == windowEvent.type){
//                printf("key down: %d\n", windowEvent.key.keysym.sym);
//            }
//
//            SDL_UpdateTexture(texture, NULL, (void*)frameBuffer, SCREEN_WIDTH * 2);
//            SDL_RenderCopy(renderer, texture, NULL, NULL);
//            SDL_RenderPresent(renderer);
//        }
//    }
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//
//    printf("Finish!\n");
    return 0;
}
