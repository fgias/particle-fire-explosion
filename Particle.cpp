#include <stdlib.h>
#include "Particle.h"

namespace fgias {

Particle::Particle() {
    m_x = 0;
    m_y = 0;

    m_xspeed = (2.0 * rand()/RAND_MAX - 1) * 0.01;
    m_yspeed = (2.0 * rand()/RAND_MAX - 1) * 0.01;
}

void Particle::update() {
    m_x += m_xspeed;
    m_y += m_yspeed;

    if (m_x < -1.0 + R || m_x >= 1.0 - R) {
        m_xspeed = -m_xspeed;
    }

    double offset = ((double)Screen::SCREEN_WIDTH)/Screen::SCREEN_HEIGHT;
    offset = (((double)Screen::SCREEN_WIDTH) - (double)Screen::SCREEN_HEIGHT)/Screen::SCREEN_WIDTH;
    
    if (m_y < -1.0 + R + offset || m_y >= 1.0 - R - offset) {
        m_yspeed = -m_yspeed;
    }

}

}
