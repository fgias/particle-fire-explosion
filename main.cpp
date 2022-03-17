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
        // update particles
        // draw particles
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