#include <iostream>
#include <SDL.h>
#include <math.h>
#include "Screen.h"
using namespace std;
using namespace fgias;

int main() {

    Screen screen;

    if (screen.init() == false) {
        cout << "Error initializing SDL." << endl;
    }

    while (true) {
        // draw particles
        int elapsed = SDL_GetTicks();
        unsigned char red = (1 + sin(elapsed * 0.001)) * 128; 
        // declare it as `unsigned char` (cast) in order to discard decimal part 
        // and restrict max value to 255

        unsigned char green = (1 + sin(elapsed * 0.002)) * 128; 
        unsigned char blue = (1 + sin(elapsed * 0.003)) * 128; 

        for (int y=0; y<Screen::SCREEN_HEIGHT; y++) {
            for (int x=0; x<Screen::SCREEN_WIDTH; x++) {
                screen.setPixel(x, y, red, green, blue);
            }
        }
        
        // update screen
        screen.update();

        // check for events
        if (screen.processEvents() == false) {
            break;
        }
    };  

    screen.close();

    return 0;
}


/* 

to run:

clear;
g++ main.cpp Screen.cpp -Wall -g -c -I /opt/local/include/SDL2 -D_THREAD_SAFE; 
g++ main.o Screen.o -o exec -lm -L /opt/local/lib -lSDL2;
./exec

*/