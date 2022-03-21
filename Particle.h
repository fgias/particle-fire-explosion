#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "Screen.h"

namespace fgias {

// the only difference between class and struct: 
// instance vairables are public by default
struct Particle { 

    static const int RADIUS = 50;

    double m_x; // these are public
    double m_y;

    double m_xspeed;
    double m_yspeed;
public:
    Particle();
    void update();
};

const double R = ((double)Particle::RADIUS)/Screen::SCREEN_WIDTH;

}

#endif