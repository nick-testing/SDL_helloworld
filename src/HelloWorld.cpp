#include "HelloWorld.h"
#include <SDL2/SDL.h>
#include <iostream>

HelloWorld::HelloWorld(): 
    window(nullptr), 
    screenSurface(nullptr), 
    helloWorldSurface(nullptr) {}

bool HelloWorld::Init() {
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL: Initialization failed. Error: " << SDL_GetError() << std::endl;
        success = false;
    } 
    else {
        // Create window
        window = SDL_CreateWindow("Hello World!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                  SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (!window) {
            std::cerr << "SDL: window creation failed. Error: " << SDL_GetError() << std::endl;
            SDL_Quit();
            success = false;
        }
        else {
            // Get window surface
            screenSurface = SDL_GetWindowSurface(window);
        }
    }

    return success;
}

bool HelloWorld::LoadMedia() {
    bool success = true;

    // Load image
    helloWorldSurface = SDL_LoadBMP("/assets/helloworld.bmp");
    if (!helloWorldSurface) {
        std::cerr << "SDL: window creation failed. Error: " << SDL_GetError() << std::endl;
        success = false;
    }

    return success;
}

void HelloWorld::Close() {
    // Deallocate surface
    SDL_FreeSurface(helloWorldSurface);
    helloWorldSurface = nullptr;
    
    // Destroy window
    SDL_DestroyWindow(window);
    window = nullptr;

    // Quit SDL subsystems
    SDL_Quit();
}

void HelloWorld::Run() {
    if (!Init()) {
        std:: cerr << "Initialization failed";
    }
    else {
        if (!LoadMedia()) {
            std::cerr << "Media loading failed" << std::endl;
        }
        else {
            // Apply the image
            SDL_BlitSurface(helloWorldSurface, nullptr, screenSurface, nullptr);

            SDL_UpdateWindowSurface(window);

            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }

        }
    }

    Close();
}