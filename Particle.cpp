#include <stdlib.h>
#include "Particle.h"

namespace fgias {

Particle::Particle() {
    m_x = 0;
    m_y = 0;

    m_xspeed = (2.0 * rand()/RAND_MAX - 1) * 0.07;
    m_yspeed = (2.0 * rand()/RAND_MAX - 1) * 0.07;
}

void Particle::update() {
    m_x += m_xspeed;
    m_y += m_yspeed;

    if (m_x < -1.0 || m_x >= 1.0) {
        m_xspeed = -m_xspeed;
    }
    if (m_y < -1.0 || m_y >= 1.0) {
        m_yspeed = -m_yspeed;
    }

}

}
