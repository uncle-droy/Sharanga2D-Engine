#include <\Users\DAIWIK\Development\CPP Projects\SDL_Learning\engine.h>
#include <SDL.h>
#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <format>
#include <string>
#include "keybinds.h"

//#include <bits/stdc++.h>
using namespace std;
Uint32 lastFrameTime;
float deltaTime;

//All maps and dicts
//std::map<std::string, vector<RectData>> rectangles;
std::map<std::string, vector<SpriteData>> spritesMap;
//std::map<std::string, SDL_Surface*> surfaces;

//All variables and assignments
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Surface* defaultSurface = NULL;
int frameDelay = 0;
int frameTime;
Uint32 frameStart;

//Functions


// Sprites

// load sprite into memory
void loadSprite(std::string name, bool visible, const char* filepath, SDL_Rect image_load_part, SDL_FRect screen_render_part, int depth, float angle) {
    spritesMap[name].push_back({ filepath, image_load_part, screen_render_part, visible, depth, angle });
}
// Draw every sprites as per depth order at once
void renderAllSprites() {
    //std::cout << "Total Sprites: " << spritesMap.size() << std::endl;
    std::vector<std::pair<int, std::string>> drawQueue;

    // Step 1: Gather all (drawOrder, name) pairs
    for (const auto& pair : spritesMap) {
        if (!pair.second.empty()) {
            drawQueue.push_back({ pair.second[0].depth, pair.first });
        }
    }

    // Step 2: Draw in order of least drawOrder first
    while (!drawQueue.empty()) {
        // Find the rectangle with the lowest drawOrder
        auto minIt = std::min_element(drawQueue.begin(), drawQueue.end(),
            [](const auto& a, const auto& b) {
                return a.first < b.first;
            });

        std::string minName = minIt->second;
        drawQueue.erase(minIt); // Remove from the list

        // Draw all rectangles belonging to this name
        for (const auto& sprite : spritesMap[minName]) {

            //std::cout << rect.surface + minName + "\n"; //Debug the z order
            if (sprite.visible) {
				render2dSprite(sprite.filepath, sprite.screen_render_part, sprite.angle );
            }
        }
    }
}

// Render a single sprite
void render2dSprite(const char* filepath, SDL_FRect screen_render_part, float angle) {
		// Render the sprite
    SDL_Surface* tempSurface = SDL_LoadBMP(filepath, "rb");
    SDL_Texture* spriteTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    SDL_FPoint* center = NULL;
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    //SDL_RenderCopyF(renderer, spriteTexture, &image_load_part, &screen_render_part);
    SDL_RenderCopyExF(renderer, spriteTexture, NULL, &screen_render_part, angle, center, SDL_FLIP_NONE);
    SDL_DestroyTexture(spriteTexture);
}


bool isRunning = true;
bool initEngine(const char* TITLE, int SCREEN_WIDTH, int SCREEN_HEIGHT, bool USE_HARDWARE_ACCELERATION) {
    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        //Create window
        window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        

        if (window == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }
        else {
            lastFrameTime = SDL_GetTicks();
            if (USE_HARDWARE_ACCELERATION) { renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); }
            else { renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE); }
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            defaultSurface = SDL_GetWindowSurface(window);
            //surfaces["default"] = defaultSurface;
        }
    }
	return true;
	isRunning = false;
}


// Draw and update the screen

void setFrameRate(int fps) {
    if (fps > 0)
        frameDelay = 1000 / fps;
    else
        frameDelay = 0; // No delay, runs as fast as possible
}

void updateScreen(){
    
    //SDL_UpdateWindowSurface(window);
    
    frameStart = SDL_GetTicks();
    SDL_RenderPresent(renderer);
    
    
}

void forceFrameLimit() {
    int frameTime = SDL_GetTicks() - frameStart;
    if (frameDelay > 0 && frameTime < frameDelay) {
        SDL_Delay((Uint32)(frameDelay - frameTime));
    }
}

//Check for key presses

std::unordered_map<int, bool> keyState;
std::unordered_map<int, bool> prevKeyState;
// Function to update the key states (call this once per frame)
bool processInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYUP) {
            keyState[event.key.keysym.scancode] = false;
            //std::cout << "Key Released: " << event.key.keysym.scancode << std::endl;
        }
        else if (event.type == SDL_KEYDOWN) {
            keyState[event.key.keysym.scancode] = true;
            //std::cout << "Key Pressed: " << event.key.keysym.scancode << std::endl;
        }
        if (event.type == SDL_QUIT) {

            return false; // Signal the user to stop the game loop
            printf("quitting");
        }
    }
	return true; // Continue running
}

bool KeyDown(const std::string& key) {
    int scancode = getScancodeFromString(key);
    return keyState[scancode];
}
bool KeyUp(const std::string& key) {
    int scancode = getScancodeFromString(key);
    if (prevKeyState.count(scancode) && keyState.count(scancode)) {
        return prevKeyState[scancode] && !keyState[scancode];  // Detect key release
    }

    return false;
}
void updateKeyStates() {
    prevKeyState = keyState;
}
void shutdownEngine() {
	//Destroy window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


using Entity = std::size_t;
Entity max_entity = 0;
Entity createEntity() {
    static Entity currentId = 0;
    max_entity = currentId;
    return currentId++;
}

registry reg;


void SortRectangles(registry& reg) {
    for (auto& pair : reg.rectShapeComponents) {
        Entity entity = pair.first;
        auto& rect = pair.second;
        reg.drawList.push_back({ entity, &rect });
    }

    std::sort(reg.drawList.begin(), reg.drawList.end(), [](auto& a, auto& b) {
        return a.second->drawOrder < b.second->drawOrder;
        });
}

void updateMovement(float deltaTime, registry& reg) {
    for (int entity = 1; entity <= max_entity; entity++) {
		if (reg.transformComponents.find(entity) != reg.transformComponents.end()
			and reg.velocityComponents.find(entity) != reg.velocityComponents.end()
            and reg.accelerationComponents.find(entity) == reg.accelerationComponents.end()) {
			auto& transform = reg.transformComponents[entity];
			auto& velocity = reg.velocityComponents[entity];
			transform.x += velocity.vx * deltaTime;
			transform.y += velocity.vy * deltaTime;
            //printf("Only velocity");
		}
        else if (reg.transformComponents.find(entity) != reg.transformComponents.end() and
            reg.velocityComponents.find(entity) != reg.velocityComponents.end() and
            reg.accelerationComponents.find(entity) != reg.accelerationComponents.end()) {
			auto& transform = reg.transformComponents[entity];
			auto& velocity = reg.velocityComponents[entity];
            auto& acceleration = reg.accelerationComponents[entity];
            //printf("Accelerated");

            transform.x += velocity.vx * deltaTime + 0.5 * acceleration.ax * deltaTime * deltaTime;
            transform.y += velocity.vy * deltaTime + 0.5 * acceleration.ay * deltaTime * deltaTime;

			velocity.vx += acceleration.ax * deltaTime;
			velocity.vy += acceleration.ay * deltaTime;

            std::cout << velocity.vx + velocity.vy;
            printf("\n");

        }
    }
}


void renderRectShape(registry& reg) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SortRectangles(reg);
    for (auto& pair : reg.drawList) {
        Entity entity = pair.first;
        if (reg.transformComponents.find(entity) != reg.transformComponents.end()) {
            auto& transform = reg.transformComponents[entity];
            auto& rect = reg.rectShapeComponents[entity];

            SDL_FRect dst = { transform.x, transform.y, rect.width, rect.height };
            SDL_SetRenderDrawColor(renderer, rect.color.r, rect.color.g, rect.color.b, rect.color.a);
                if (transform.rotation == 0.0) {
                    SDL_RenderFillRectF(renderer, &dst);
                }
                else {
                    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, (int)rect.width, (int)rect.height);
                    SDL_RenderClear(renderer);
                    SDL_SetRenderTarget(renderer, NULL);
                    SDL_FPoint center = { rect.width / 2, rect.height / 2 };
                    SDL_RenderCopyExF(renderer, texture, NULL, &dst, transform.rotation, &center, SDL_FLIP_NONE);
                    SDL_DestroyTexture(texture);

                }
        }
    }
}

float getDeltaTime() {
	Uint32 currentFrameTime = SDL_GetTicks();
	deltaTime = (currentFrameTime) / 1000.0f; // convert to seconds
	//lastFrameTime = currentFrameTime;
    return deltaTime;
}