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

        swarm.update(elapsed);

        unsigned char red = (1 + sin(elapsed * 0.0001)) * 128; 
        unsigned char green = (1 + sin(elapsed * 0.0002)) * 128; 
        unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128; 

        const Particle * const pParticles = swarm.getParticles();

        for (int i=0; i<Swarm::N_PARTICLES; i++) {
            Particle particle = pParticles[i];

            int x = (particle.m_x + 1) * 1/2 * Screen::SCREEN_WIDTH;
            int y = (particle.m_y) * 1/2 * Screen::SCREEN_WIDTH + Screen::SCREEN_HEIGHT/2;

            screen.setPixel(x, y, red, green, blue);
        }
        
        screen.boxBlur(); 

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

g++ ./src/main.cpp -Wall -g -c -I /opt/local/include/SDL2 -I ./include -D_THREAD_SAFE -o ./build/main.o;
g++ ./src/Screen.cpp -Wall -g -c -I /opt/local/include/SDL2 -I ./include -D_THREAD_SAFE -o ./build/Screen.o; 
g++ ./src/Particle.cpp -Wall -g -c -I /opt/local/include/SDL2 -I ./include -D_THREAD_SAFE -o ./build/Particle.o; 
g++ ./src/Swarm.cpp -Wall -g -c -I /opt/local/include/SDL2 -I ./include -D_THREAD_SAFE -o ./build/Swarm.o; 

g++ ./build/main.o ./build/Screen.o ./build/Particle.o ./build/Swarm.o -o ./bin/exec -lm -L /opt/local/lib -lSDL2;

./bin/exec

*/