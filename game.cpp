#include <\Users\DAIWIK\Development\CPP Projects\SDL_Learning\engine.h>
#include <random>
#include <chrono>
#include <thread>

#include <functional>
using namespace std;

int enemy_number = 1;
int score = 0;
float angle = 0;
float vel = 5.0;
std::string enemy_str = "enemy" + std::to_string(enemy_number);
float dt;
double c;

int getRandomNumber(int min, int max) {
    std::random_device rd;  // Obtain a random seed
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_int_distribution<int> distrib(min, max); // Define range
    return distrib(gen);
}


int main(int argc, char* argv[]) {

    if (!initEngine("My Fruit Basket", 800, 550, true)) return -1;
	bool running = true;

    int random_x_coord = getRandomNumber(50, 750);
    std::cout<< "created first enemy" + enemy_str;
    enemy_number++;
    

    //Render the rectangle

	Entity overlapper = createEntity();
	reg.transformComponents[overlapper] = { 120, 120, 0 };
	reg.rectShapeComponents[overlapper] = { 50, 50, {0, 255, 0}, 2, true };

	Entity player = createEntity();
	reg.transformComponents[player] = { 100, 100, 0 };
    reg.rectShapeComponents[player] = { 50, 50, {255, 0, 0, 255}, 1, true};
    reg.velocityComponents[player] = { 0, 0 };
    reg.accelerationComponents[player] = { 0, 9.8 };
    
    
    loadSprite("basket", true, "assets/basket2.bmp", { 0, 0, 32, 32 }, { 100, 100, 32, 32 }, 1, 45);
    
    while (running)
    {
        running = processInput();
		
        if (KeyDown("RCTRL")) {
            printf("Right pressed\n");
            //setRectPos("player", pos.first, pos.second);
        }
        renderRectShape(reg);
        //c += 0.1f;
		dt = getDeltaTime();
        updateMovement(dt, reg);
        std::cout << dt;
        printf("\n");

        renderAllSprites();
        updateKeyStates();
        setFrameRate(60);
        updateScreen();
        forceFrameLimit();
        
    }
	shutdownEngine();
  return 0;
} 