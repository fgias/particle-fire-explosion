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

        screen.clear();
        swarm.update();

        unsigned char red = (1 + sin(elapsed * 0.0001)) * 128; 
        unsigned char green = (1 + sin(elapsed * 0.0002)) * 128; 
        unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128; 

        Particle * pParticles = swarm.getParticles();
        screen.m_screen_particles = pParticles;

        for (int i=0; i<swarm.N_PARTICLES_CURR; i++) {
            Particle particle = pParticles[i];
            double R = ((double)Particle::RADIUS)/Screen::SCREEN_WIDTH;
            for (int row=-Particle::RADIUS; row<=Particle::RADIUS; row++) {
                for (int col=-Particle::RADIUS; col<=Particle::RADIUS; col++) {
                    double x0 = particle.m_x;
                    double y0 = particle.m_y;
                    double currX = x0 + ((double)row)/Screen::SCREEN_WIDTH;
                    double currY = y0 + ((double)col)/Screen::SCREEN_HEIGHT;
                    double ratio = ((double)Screen::SCREEN_HEIGHT)/Screen::SCREEN_WIDTH;

                    if ((currX-x0)*(currX-x0) + ratio * ratio * (currY-y0)*(currY-y0)
                        < (R * R)) {
                            int x = (currX + 1) * 1/2 * Screen::SCREEN_WIDTH;
                            int y = (currY + 1) * 1/2 * Screen::SCREEN_HEIGHT;
                            screen.setPixel(x, y, red, green, blue);
                    };


                }
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

g++ ./src/main.cpp -Wall -g -c -I /opt/local/include/SDL2 -I ./include -D_THREAD_SAFE -o ./build/main.o;
g++ ./src/Screen.cpp -Wall -g -c -I /opt/local/include/SDL2 -I ./include -D_THREAD_SAFE -o ./build/Screen.o; 
g++ ./src/Particle.cpp -Wall -g -c -I /opt/local/include/SDL2 -I ./include -D_THREAD_SAFE -o ./build/Particle.o; 
g++ ./src/Swarm.cpp -Wall -g -c -I /opt/local/include/SDL2 -I ./include -D_THREAD_SAFE -o ./build/Swarm.o; 

g++ ./build/main.o ./build/Screen.o ./build/Particle.o ./build/Swarm.o -o ./bin/exec -lm -L /opt/local/lib -lSDL2;

./bin/exec

*/