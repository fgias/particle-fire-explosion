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

        for (int i=0; i<10; i++) {
            Particle particle = pParticles[i];
            double R = ((double)Particle::RADIUS)/Screen::SCREEN_WIDTH;
            for (int row=-Particle::RADIUS; row<=Particle::RADIUS; row++) {
                for (int col=-Particle::RADIUS; col<=Particle::RADIUS; col++) {
                    double x0 = particle.m_x;
                    double y0 = particle.m_y;
                    double currX = x0 + ((double)row)/Screen::SCREEN_WIDTH;
                    double currY = y0 + ((double)col)/Screen::SCREEN_HEIGHT;

                    if ((currX-x0)*(currX-x0) + (currY-y0)*(currY-y0)
                        < (R * R)) {
                            int x = (currX + 1) * 1/2 * Screen::SCREEN_WIDTH;
                            int y = (currY) * 1/2 * Screen::SCREEN_WIDTH + Screen::SCREEN_HEIGHT/2;
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
g++ main.cpp Screen.cpp Particle.cpp Swarm.cpp -Wall -g -c -I /opt/local/include/SDL2 -D_THREAD_SAFE; 
g++ main.o Screen.o Particle.o Swarm.o -o exec -lm -L /opt/local/lib -lSDL2;
./exec

*/