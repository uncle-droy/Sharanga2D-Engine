#ifndef ENGINE_H
#define ENGINE_H

// Include necessary libraries
#include <SDL.h>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

extern SDL_Window* window;
extern SDL_Surface* defaultSurface;
extern SDL_Renderer* renderer;
extern int frameDelay;
extern Uint32 frameStart;
extern int frameTime;

// Function prototypes

// Initialize the game engine
bool initEngine(const char* title, int SCREEN_WIDTH, int SCREEN_HEIGHT, bool USE_HARDWARE_ACCELERATION);

void setFrameRate(int fps);
void forceFrameLimit();
void updateScreen();

//create rectangle object and store in memory
void createRectangles(std::string name, bool alive, float x, float y, float w, float h, int drawOrder, float angle, SDL_Color color);

// Structure to hold rectangle data
struct RectData {
    bool visible;
    float x, y, w, h;
	int  drawOrder;
    float angle;
    SDL_Color color = { 255, 255, 255, 255 }; // Default: White
};

// Map to store rectangles with a unique identifier
extern std::map<std::string, std::vector<RectData>> rectangles;

// Function to draw all stored rectangles
void drawRect2d(float x, float y, float w, float h, float angle, SDL_Color color);

// Function to draw all rectangles when game loop will be called
void drawAllRects();

// Function to get a rectangle's properties
std::pair <float, float> getRectSize(std::string name); //Returns a (width, height) pair size of the rectangle
std::pair <float, float> getRectPosition(std::string name); //Returns a (x, y) pair coordinate of the rectangle

// Functions to manipulate rectangle's properties
void setRectSize(std::string name, float width, float heiht);
void setRectPos(std::string name, float x, float y);
void setRectColor(std::string name, SDL_Color color);
void setRectDrawOrder(std::string name, int drawOder);
// Rotate the rectangle, angle has to be in degrees

void rotateRect(std::string name, float angle);
void setRectVisibility(std::string name, bool visible);
void removeRectPerm(std::string name);

int countTotalRectangles();

// Function to create a new surface
//extern std::map<std::string, SDL_Surface*> surfaces;
//void createSurface(const std::string& name, int width, int height, int depth);

// Function to load a texture from a file (sprite rendering)
struct SpriteData {
	const char* filepath;
    SDL_Rect image_load_part;
    SDL_FRect screen_render_part;
    bool visible;
    int depth;
    float angle;
};
extern std::map<std::string, std::vector<SpriteData>> spritesMap;
void loadSprite(std::string name, bool visible, const char* filepath, SDL_Rect image_load_part, SDL_FRect screen_render_part, int depth, float angle);
void render2dSprite(const char* filepath, SDL_FRect screen_render_part, float angle);
void renderAllSprites();

// Function to handle keyboard input
extern std::unordered_map<int, bool> keyState;
extern std::unordered_map<int, bool> prevKeyState;
bool processInput();
bool KeyUp(const std::string& key);
bool KeyDown(const std::string& key);

// Function to shut down the engine
void shutdownEngine();
void updateKeyStates();


#endif  // ENGINE_H