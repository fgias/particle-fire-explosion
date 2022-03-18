#include "Swarm.h"

namespace fgias {

Swarm::Swarm() {
    m_pParticles = new Particle[N_PARTICLES];
}

Swarm::~Swarm() {
    delete [] m_pParticles;
}

void Swarm::update() {
    for (int i=0; i<N_PARTICLES; i++) {
        m_pParticles[i].update();
    }
}

}
