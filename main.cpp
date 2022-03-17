#include <iostream>
#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"
using namespace std;
using namespace fgias;

int main() {

    srand(time(NULL));

    Screen screen;

    if (screen.init() == false) {
        cout << "Error initializing SDL." << endl;
    }

    Swarm swarm;

    while (true) {
        // draw particles

        int elapsed = SDL_GetTicks();
        unsigned char red = (1 + sin(elapsed * 0.01)) * 128; 
        unsigned char green = (1 + sin(elapsed * 0.02)) * 128; 
        unsigned char blue = (1 + sin(elapsed * 0.03)) * 128; 

        const Particle * const pParticles = swarm.getParticles();

        for (int i=0; i<Swarm::N_PARTICLES; i++) {
            Particle particle = pParticles[i];

            int x = (particle.m_x + 1) * 1/2 * Screen::SCREEN_WIDTH;
            int y = (particle.m_y + 1) * 1/2 * Screen::SCREEN_HEIGHT;

            screen.setPixel(x, y, red, green, blue);
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
g++ main.cpp Screen.cpp Particle.cpp Swarm.cpp -Wall -g -c -I /opt/local/include/SDL2 -D_THREAD_SAFE; 
g++ main.o Screen.o Particle.o Swarm.o -o exec -lm -L /opt/local/lib -lSDL2;
./exec

*/