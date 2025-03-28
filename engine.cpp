#include <\Users\DAIWIK\Development\CPP Projects\SDL_Learning\engine.h>
#include <SDL.h>
#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <map>
#include <format>
#include <string>
//#include <bits/stdc++.h>
using namespace std;

//All maps and dicts
std::map<std::string, vector<RectData>> rectangles;
std::map<std::string, SDL_Surface*> surfaces;

//All variables and assignments
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Surface* defaultSurface = NULL;
int frameDelay = 0;
int frameTime;
Uint32 frameStart;

//Functions

// Convert user string to SDL Scancode
SDL_Scancode getScancodeFromString(const std::string & key) {
    // Numbers
    if (key == "0") return SDL_SCANCODE_0;
    if (key == "1") return SDL_SCANCODE_1;
    if (key == "2") return SDL_SCANCODE_2;
    if (key == "3") return SDL_SCANCODE_3;
    if (key == "4") return SDL_SCANCODE_4;
    if (key == "5") return SDL_SCANCODE_5;
    if (key == "6") return SDL_SCANCODE_6;
    if (key == "7") return SDL_SCANCODE_7;
    if (key == "8") return SDL_SCANCODE_8;
    if (key == "9") return SDL_SCANCODE_9;
    if (key == "KP_ENTER") return SDL_SCANCODE_KP_ENTER;
    if (key == "KP_PLUS") return SDL_SCANCODE_KP_PLUS;
    if (key == "KP_MINUS") return SDL_SCANCODE_KP_MINUS;
    if (key == "KP_MULTIPLY") return SDL_SCANCODE_KP_MULTIPLY;
    if (key == "KP_DIVIDE") return SDL_SCANCODE_KP_DIVIDE;
    if (key == "KP_PERIOD") return SDL_SCANCODE_KP_PERIOD;

    //Other Keys
    if (key == "UP") return SDL_SCANCODE_UP;
    if (key == "DOWN") return SDL_SCANCODE_DOWN;
    if (key == "LEFT") return SDL_SCANCODE_LEFT;
    if (key == "RIGHT") return SDL_SCANCODE_RIGHT;
    if (key == "SPACE") return SDL_SCANCODE_SPACE;
    if (key == "ENTER") return SDL_SCANCODE_RETURN;
    if (key == "ESCAPE") return SDL_SCANCODE_ESCAPE;
    if (key == "TAB") return SDL_SCANCODE_TAB;
    if (key == "BACKSPACE") return SDL_SCANCODE_BACKSPACE;
    if (key == "DELETE") return SDL_SCANCODE_DELETE;
    if (key == "L_SHIFT") return SDL_SCANCODE_LSHIFT;
    if (key == "L_CTRL") return SDL_SCANCODE_LCTRL;
    if (key == "L_ALT") return SDL_SCANCODE_LALT;
    if (key == "LGUI") return SDL_SCANCODE_LGUI; // Windows / Command key (Mac)
    if (key == "RGUI") return SDL_SCANCODE_RGUI;
    if (key == "R_SHIFT") return SDL_SCANCODE_RSHIFT;
    if (key == "R_CTRL") return SDL_SCANCODE_RCTRL;
    if (key == "R_ALT") return SDL_SCANCODE_RALT;
    if (key == "CAPSLOCK") return SDL_SCANCODE_CAPSLOCK;

    if (key == "PRINTSCREEN") return SDL_SCANCODE_PRINTSCREEN;
    if (key == "SCROLLLOCK") return SDL_SCANCODE_SCROLLLOCK;
    if (key == "PAUSE") return SDL_SCANCODE_PAUSE;
    if (key == "INSERT") return SDL_SCANCODE_INSERT;
    if (key == "HOME") return SDL_SCANCODE_HOME;
    if (key == "END") return SDL_SCANCODE_END;
    if (key == "PAGEUP") return SDL_SCANCODE_PAGEUP;
    if (key == "PAGEDOWN") return SDL_SCANCODE_PAGEDOWN;

    //Operators
    //if (key == "!") return SDL_SCANCODE_KP_EXCLAIM;     // Shift + 1
    if (key == "@") return SDL_SCANCODE_KP_AT;          // Shift + 2
    if (key == "#") return SDL_SCANCODE_KP_HASH;        // Shift + 3
    //if (key == "$") return SDL_SCANCODE_KP_DOLLAR;      // Shift + 4
    if (key == "%") return SDL_SCANCODE_KP_PERCENT;     // Shift + 5
    //if (key == "^") return SDL_SCANCODE__CARET;       // Shift + 6
    if (key == "&") return SDL_SCANCODE_KP_AMPERSAND;   // Shift + 7
    //if (key == "*") return SDL_SCANCODE_KP_ASTERISK;    // Shift + 8
    if (key == "(") return SDL_SCANCODE_KP_LEFTPAREN;   // Shift + 9
    if (key == ")") return SDL_SCANCODE_KP_RIGHTPAREN;
    if (key == "-") return SDL_SCANCODE_MINUS;
    if (key == "=") return SDL_SCANCODE_EQUALS;
    if (key == "[") return SDL_SCANCODE_LEFTBRACKET;
    if (key == "]") return SDL_SCANCODE_RIGHTBRACKET;
    if (key == "\\") return SDL_SCANCODE_BACKSLASH;
    if (key == ";") return SDL_SCANCODE_SEMICOLON;
    if (key == "'") return SDL_SCANCODE_APOSTROPHE;
    if (key == ",") return SDL_SCANCODE_COMMA;
    if (key == ".") return SDL_SCANCODE_PERIOD;
    if (key == "/") return SDL_SCANCODE_SLASH;
    if (key == "`") return SDL_SCANCODE_GRAVE;

    //Function Keys
    if (key == "F1") return SDL_SCANCODE_F1;
    if (key == "F2") return SDL_SCANCODE_F2;
    if (key == "F3") return SDL_SCANCODE_F3;
    if (key == "F4") return SDL_SCANCODE_F4;
    if (key == "F5") return SDL_SCANCODE_F5;
    if (key == "F6") return SDL_SCANCODE_F6;
    if (key == "F7") return SDL_SCANCODE_F7;
    if (key == "F8") return SDL_SCANCODE_F8;
    if (key == "F9") return SDL_SCANCODE_F9;
    if (key == "F10") return SDL_SCANCODE_F10;
    if (key == "F11") return SDL_SCANCODE_F11;
    if (key == "F12") return SDL_SCANCODE_F12;

    //Capital Letters
    if (key == "A") return SDL_SCANCODE_A;
    if (key == "B") return SDL_SCANCODE_B;
    if (key == "C") return SDL_SCANCODE_C;
    if (key == "D") return SDL_SCANCODE_D;
    if (key == "E") return SDL_SCANCODE_E;
    if (key == "F") return SDL_SCANCODE_F;
    if (key == "G") return SDL_SCANCODE_G;
    if (key == "H") return SDL_SCANCODE_H;
    if (key == "I") return SDL_SCANCODE_I;
    if (key == "J") return SDL_SCANCODE_J;
    if (key == "K") return SDL_SCANCODE_K;
    if (key == "L") return SDL_SCANCODE_L;
    if (key == "M") return SDL_SCANCODE_M;
    if (key == "N") return SDL_SCANCODE_N;
    if (key == "O") return SDL_SCANCODE_O;
    if (key == "P") return SDL_SCANCODE_P;
    if (key == "Q") return SDL_SCANCODE_Q;
    if (key == "R") return SDL_SCANCODE_R;
    if (key == "S") return SDL_SCANCODE_S;
    if (key == "T") return SDL_SCANCODE_T;
    if (key == "U") return SDL_SCANCODE_U;
    if (key == "V") return SDL_SCANCODE_V;
    if (key == "W") return SDL_SCANCODE_W;
    if (key == "X") return SDL_SCANCODE_X;
    if (key == "Y") return SDL_SCANCODE_Y;
    if (key == "Z") return SDL_SCANCODE_Z;
    // Small letters
    if (key == "a") return SDL_SCANCODE_A;
    if (key == "b") return SDL_SCANCODE_B;
    if (key == "c") return SDL_SCANCODE_C;
    if (key == "d") return SDL_SCANCODE_D;
    if (key == "e") return SDL_SCANCODE_E;
    if (key == "f") return SDL_SCANCODE_F;
    if (key == "g") return SDL_SCANCODE_G;
    if (key == "h") return SDL_SCANCODE_H;
    if (key == "i") return SDL_SCANCODE_I;
    if (key == "j") return SDL_SCANCODE_J;
    if (key == "k") return SDL_SCANCODE_K;
    if (key == "l") return SDL_SCANCODE_L;
    if (key == "m") return SDL_SCANCODE_M;
    if (key == "n") return SDL_SCANCODE_N;
    if (key == "o") return SDL_SCANCODE_O;
    if (key == "p") return SDL_SCANCODE_P;
    if (key == "q") return SDL_SCANCODE_Q;
    if (key == "r") return SDL_SCANCODE_R;
    if (key == "s") return SDL_SCANCODE_S;
    if (key == "t") return SDL_SCANCODE_T;
    if (key == "u") return SDL_SCANCODE_U;
    if (key == "v") return SDL_SCANCODE_V;
    if (key == "w") return SDL_SCANCODE_W;
    if (key == "x") return SDL_SCANCODE_X;
    if (key == "y") return SDL_SCANCODE_Y;
    if (key == "z") return SDL_SCANCODE_Z;

    return SDL_SCANCODE_UNKNOWN; // If invalid input
}
//void createSurface(const std::string& name, int width, int height, int depth) {
//    SDL_Surface* newSurface = SDL_CreateRGBSurface(0, width, height, depth, 0, 0, 0, 0);
//    //SDL_SetSurfaceBlendMode(newSurface, SDL_BLENDMODE_BLEND);
//    if (newSurface) {
//        surfaces[name] = newSurface;
//        SDL_BlitSurface(newSurface, NULL, defaultSurface, NULL);
//        SDL_UpdateWindowSurface(window);
//    }
//    else {
//        printf("Failed to create surface: %s\n", SDL_GetError());
//    }
//}


void createRectangles(std::string name, bool visible, float x, float y, float w, float h, int drawOrder, float angle, SDL_Color color) {
    if (rectangles.count(name) == 0) {
        rectangles[name] = {};
    }
    rectangles[name].push_back({visible, x, y, w, h, drawOrder, angle, color});
}

//Function to draw all rectangles when called from game loop
void drawAllRects() {

    //std::cout << "Total Rectangles: " << rectangles.size() << std::endl;
    std::vector<std::pair<int, std::string>> drawQueue;

    // Step 1: Gather all (drawOrder, name) pairs
    for (const auto& pair : rectangles) {
        if (!pair.second.empty()) {
            drawQueue.push_back({ pair.second[0].drawOrder, pair.first });
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
        for (const auto& rect : rectangles[minName]) {
            
            //std::cout << rect.surface + minName + "\n"; //Debug the z order
            if (rect.visible) {
				drawRect2d(rect.x, rect.y, rect.w, rect.h, rect.angle, rect.color);
            }
        }
    }
    //updateScreen();
    SDL_RenderPresent(renderer);
}

void drawRect2d(float x, float y, float w, float h, float angle, SDL_Color color) {

    /*SDL_FRect fillRect = { x, y, w, h };/
    SDL_SetSurfaceBlendMode(defaultSurface, SDL_BLENDMODE_BLEND);
    Uint32 mappedColor = SDL_MapRGBA(surface->format, color.r, color.g, color.b, color.a);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRectF(renderer, &fillRect);*/

    if (angle == 0.0) {
		SDL_FRect dstRect = { x, y, w, h };
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
		SDL_RenderFillRectF(renderer, &dstRect);
	}

    else {
        SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h);
        SDL_SetRenderTarget(renderer, texture);
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderClear(renderer);
        SDL_SetRenderTarget(renderer, NULL);
        SDL_FRect dstRect = { x, y, w, h };
        SDL_FPoint center = { w / 2, h / 2 }; // Rotation pivot (center of the rectangle)	
        SDL_RenderCopyExF(renderer, texture, NULL, &dstRect, angle, &center, SDL_FLIP_NONE);
        SDL_DestroyTexture(texture);
}
}

int countTotalRectangles() {
	return rectangles.size();
}

std::pair <float, float> getRectPosition(std::string name) {
	if (rectangles.count(name) == 0) {
		return { -1, -1 }; // Return (-1, -1) if rectangle not found
	}
	else {
		return { rectangles[name][0].x, rectangles[name][0].y };
	}
}

//get size of the recctangle
std::pair <float, float > getRectSize(std::string name) {
	if (rectangles.count(name) == 0) {
		return { -1, -1 }; // Return (-1, -1) if rectangle not found
	}
	else {
		return { rectangles[name][0].w, rectangles[name][0].h };
	}
}

void setRectPos(std::string name, float x, float y) {
	if (rectangles.count(name) == 0) {
		return; // Return if rectangle not found
	}
    else {
        rectangles[name][0].x = x;
        rectangles[name][0].y = y;
    }
  
}
void setRectSize(std::string name, float width, float height) {
    if (rectangles.count(name) == 0) {
        return; // Return if rectangle not found
    }
    else {
		rectangles[name][0].w = width;
        rectangles[name][0].h = height;
    }
}

void rotateRect(std::string name, float angle) {
	rectangles[name][0].angle = angle;
}

void setRectColor(std::string name, SDL_Color color) { // Angle in degrees

	if (rectangles.count(name) == 0) {
		return; // Return if rectangle not found
	}
	else {
		rectangles[name][0].color = color;
	}
}

void setRectDrawOrder(std::string name, int drawOrder) {
	if (rectangles.count(name) == 0) {
		return; // Return if rectangle not found
	}
    else {
		rectangles[name][0].drawOrder = drawOrder;
    }
}

void setRectVisibility(std::string name, bool visible) {
	if (rectangles.count(name) == 0) {
		return; // Return if rectangle not found
	}
	else {
		rectangles[name][0].visible = visible;
	}
}

void removeRectPerm(std::string name) {
	rectangles.erase(name);
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
            if (USE_HARDWARE_ACCELERATION) { renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); }
            else { renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE); }
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            defaultSurface = SDL_GetWindowSurface(window);
            surfaces["default"] = defaultSurface;
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

bool ifKeyDown(const std::string& key) {
    int scancode = getScancodeFromString(key);
    return keyState[scancode];
}
bool ifKeyUp(const std::string& key) {
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