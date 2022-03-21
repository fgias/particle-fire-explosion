#include <stdlib.h>
#include "Particle.h"
#include "Screen.h"

namespace fgias {

Particle::Particle() {
    init();
}

void Particle::init() {
    m_x = 0;
    m_y = 0;

    m_xspeed = (2.0 * rand()/RAND_MAX - 1) * 0.01;
    m_yspeed = (2.0 * rand()/RAND_MAX - 1) * 0.01;
}

void Particle::init(double x, double y) {
    m_x = x;
    m_y = y;

    m_xspeed = (2.0 * rand()/RAND_MAX - 1) * 0.01;
    m_yspeed = (2.0 * rand()/RAND_MAX - 1) * 0.01;
}

void Particle::update() {
    m_x += m_xspeed;
    m_y += m_yspeed;
    double R = ((double)Particle::RADIUS)/Screen::SCREEN_WIDTH;
    double ratio = ((double)Screen::SCREEN_HEIGHT)/Screen::SCREEN_WIDTH;

    if (m_x < -1.0 + R || m_x >= 1.0 - R) {
        m_xspeed = -m_xspeed;
    }
    
    if (m_y < -1.0 + R/ratio || m_y >= 1.0 - R/ratio) {
        m_yspeed = -m_yspeed;
    }

}

}
