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
float velocity = 5;

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
    //std::cout<< "created first enemy" + enemy_str;
    enemy_number++;


    //Render the rectangle
    Entity dum = createEntity();
    reg.transformComponents[dum] = { 100, 100, 0 };
    reg.rectShapeComponents[dum] = createRectShape(50, 50, { 255, 0, 0, 255 }, 1, true);
    reg.velocityComponents[dum] = { 2, 5 };
    //reg.accelerationComponents[dum] = { 0, 0 };

    Entity background = createEntity();
    reg.rectShapeComponents[background] = createRectShape(800, 550, { 120, 60, 255, 255 }, 0, true);
    reg.transformComponents[background] = { 0, 0, 10 };
    reg.velocityComponents[background] = { 3, 3 };
    //reg.accelerationComponents[background] = { 0, 0 };

    Entity o = createEntity();
    reg.rectShapeComponents[o] = createRectShape(50, 50, { 120, 250, 25, 255 }, 2, true);
    reg.transformComponents[o] = { 60, 60, 10 };
    reg.velocityComponents[o] = { 0, 0 };
    //reg.accelerationComponents[o] = { 0, 0 };

    loadSprite("basket", true, "assets/basket2.bmp", { 0, 0, 32, 32 }, { 100, 100, 32, 32 }, 1, 45);

    while (running)
    {
        running = processInput();

        if (KeyDown("A")) {
            //reg.transformComponents[o].x += 2;
            reg.velocityComponents[o].vx = -100;
            //reg.accelerationComponents[o].ax = 1;
            reg.transformComponents[o].rotation += 80;
            cout << reg.velocityComponents[o].vx;
            //printf("Down");
        }
        else if (KeyUp("A")) {
            //reg.accelerationComponents[o].ax = 0;
            reg.velocityComponents[o].vx = 0;
            //reg.accelerationComponents[o].ax = 0;
            //printf("up");
        }
        if (KeyDown("D")) {
            reg.velocityComponents[o].vx = 100;
            //reg.accelerationComponents[o].ax = -1;
            reg.transformComponents[o].rotation -= 80;
            cout << reg.velocityComponents[o].vx;
            //printf("Down");
        }
        else if (KeyUp("D")) {
            reg.velocityComponents[o].vx = 0;
            //reg.accelerationComponents[o].ax = 0;
            //printf("up");
        }

        /*if (reg.velocityComponents[player].vy >= 15) {
            reg.accelerationComponents.erase(player);
            reg.velocityComponents[player].vy = 0;

        }*/

        renderRectShape(reg);
        dt = getDeltaTime();
        updateMovement(dt, reg);

        renderAllSprites();
        updateKeyStates();
        setFrameRate(60);
        updateScreen();
        forceFrameLimit();

    }
    shutdownEngine();
    return 0;
}