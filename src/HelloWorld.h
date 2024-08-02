#ifndef HELLOWORLD_H
#define HELLOWORLD_H

typedef struct SDL_Window;
typedef struct SDL_Surface;

class HelloWorld {
    public:
        HelloWorld();
        void StartGame();

    private:
        // Window used for program rendering
        SDL_Window* gWindow;

        // Surface contained by the window
        SDL_Surface* gScreenSurface;

        // Image that will be shown on the screen
        SDL_Surface* gHelloWorld;

        bool Init();
        bool LoadMedia();
        void Close();

};

#endif