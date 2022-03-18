#include <stdlib.h>
#include <math.h>
#include "Particle.h"

namespace fgias {

Particle::Particle(): m_x(0), m_y(0) {
    m_direction = (2 * M_PI * rand())/RAND_MAX;
    m_speed = (0.01 * rand())/RAND_MAX;
}

void Particle::update() {

    double xspeed = m_speed * cos(m_direction);
    double yspeed = m_speed * sin(m_direction);

    m_x += xspeed;
    m_y += yspeed;

}

}
