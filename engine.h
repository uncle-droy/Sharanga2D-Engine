#ifndef ENGINE_H
#define ENGINE_H
#include <cstddef>
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

using Entity = std::size_t;

Entity createEntity();
extern Entity max_entity;



struct TransformComponent {
	float x, y;
	float rotation; // degrees
};

struct VelocityComponent {
	float vx, vy;
};

struct AccelerationComponent {
	float ax, ay;
};

struct RectShapeComponent {
	float width, height;
	SDL_Color color;
	int  drawOrder;
	bool visible;
};

struct registry {

	std::unordered_map<Entity, TransformComponent> transformComponents;
	std::unordered_map<Entity, VelocityComponent> velocityComponents;
	std::unordered_map<Entity, AccelerationComponent> accelerationComponents;
	
	std::unordered_map<Entity, RectShapeComponent> rectShapeComponents;
	std::vector<std::pair<Entity, RectShapeComponent*>> drawList;
};

extern registry reg;
void updateMovement(float deltaTime, registry& reg);
void renderRectShape(registry& reg);


// Function to create a new surface
extern std::map<std::string, SDL_Surface*> surfaces;
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

float getDeltaTime();

// Function to shut down the engine
void shutdownEngine();
void updateKeyStates();

#endif  // ENGINE_H