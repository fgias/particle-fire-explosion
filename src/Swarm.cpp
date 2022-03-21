#include "Swarm.h"

namespace fgias {

Swarm::Swarm(): lastTime(0) {
    m_pParticles = new Particle[N_PARTICLES];
}

Swarm::~Swarm() {
    delete [] m_pParticles;
}

void Swarm::update(int elapsed) {
    int interval = elapsed - lastTime;

    for (int i=0; i<N_PARTICLES; i++) {
        m_pParticles[i].update(interval);
    }

    lastTime = elapsed;
}

}
