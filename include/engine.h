#ifndef ENGINE_H
#define ENGINE_H

#include <SDL.h>
#include <iostream>

class Engine {
public:
    Engine();
    ~Engine();

    bool init(const char* title, int width, int height);
    void run();
    void shutdown();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;
};

#endif
