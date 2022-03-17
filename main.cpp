#include <iostream>
#include <SDL.h>
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
        for (int y=0; y<Screen::SCREEN_HEIGHT; y++) {
            for (int x=0; x<Screen::SCREEN_WIDTH; x++) {
                screen.setPixel(x, y, 128, 0, 255);
            }
        }
        
        screen.setPixel(400, 300, 255, 255, 255);

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