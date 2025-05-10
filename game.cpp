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
    createRectangles(enemy_str, true, random_x_coord, -50.0, 50.0, 50.0, 2, 0, { 255, 50, 0, 255 });
    enemy_number++;
    
    createRectangles("bg", true, 0.0, 0.0, 800.0, 550.0, 0, 0, { 80, 150, 255, 255 });
    createRectangles("player",  true, 355.0, 400.0, 90.0, 90.0, 3, angle, { 30, 255, 60, 100 });
    loadSprite("basket", true, "assets/basket2.bmp", { 0, 0, 32, 32 }, { 100, 100, 32, 32 }, 1, 45);
    
    while (running)
    {
        running = processInput();
		
        if (KeyDown("RCTRL")) {
            //printf("Right pressed\n");
            std::pair<float, float> pos = getRectPosition("player");
            pos.first += 20;
            setRectPos("player", pos.first, pos.second);
        }

        else if (KeyDown("LCTRL")) {
            //printf("Left pressed\n");
            std::pair<float, float> pos = getRectPosition("player");
            pos.first -= 20;
            setRectPos("player", pos.first, pos.second);
        }
		else if (KeyDown("LSHIFT")) 
        {
            angle--;
            rotateRect("player", angle);
            printf("rotating");
        }
		else if (KeyDown("RSHIFT")) {
			angle++;
			rotateRect("player", angle);
			printf("rotating");
		}
        else if (KeyDown("SPACE"))
        {
            vel=0;
        }
		else if (KeyUp("SPACE"))
        {
            vel = 5.0;
			std::cout << countTotalRectangles() << std::endl;
        }

        for (int i = 1; i <= 100; i++) {
            enemy_str = "enemy" + std::to_string(i);
            std::pair<float, float> e_pos = getRectPosition(enemy_str);
            std::pair<float, float> p_pos = getRectPosition("player");
            e_pos.second += vel;
            setRectPos(enemy_str, e_pos.first, e_pos.second);

			if (e_pos.second > 550.0) {
                //float random_x_coord = getRandomNumber(50, 750);
                score--;
				removeRectPerm(enemy_str);
			}
			if (e_pos.first + 50.0 >= p_pos.first and e_pos.first <= p_pos.first + 90.0 and e_pos.second + 50.0 >= p_pos.second and e_pos.second <= p_pos.second + 90.0) {
                score++;
                removeRectPerm(enemy_str);
				printf("Score: %d\n", score);
				//break;
			}

            if (e_pos.second == 50.0 and enemy_number >= 1) {
                enemy_number++;
                enemy_str = "enemy" + std::to_string(enemy_number);
                float random_x_coord = getRandomNumber(50, 750);
                //std::cout << "\ncreating enemy at: " + enemy_str << std::endl;
                //std::cout << enemy_number << std::endl;
                //printf("\n");
                createRectangles(enemy_str, true, random_x_coord, -50.0, 50.0, 50.0, 2, 0, { 255, 50, 0, 255 });
				
            }
            if (enemy_number == 100) {
				enemy_number = 1;
                enemy_str = "enemy" + std::to_string(enemy_number);
                float random_x_coord = getRandomNumber(50, 750);
				createRectangles(enemy_str, true, random_x_coord, -50.0, 50.0, 50.0, 2, 0, { 255, 50, 0, 255 });
                printf("enemy number reset");
            }
            if (countTotalRectangles() >= 55) {
                removeRectPerm("player");
                running = false;
                printf("\n\n\n____________________Game Over____________________\n\n\n");
				break;
            }
		}
		
        drawAllRects();
        renderAllSprites();
        updateKeyStates();
        setFrameRate(60);
        updateScreen();
        forceFrameLimit();
        
    }
	shutdownEngine();
  return 0;
} 