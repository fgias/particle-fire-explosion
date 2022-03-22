#include "Swarm.h"

namespace fgias {

int Swarm::N_PARTICLES_CURR = 0;

Swarm::Swarm() {
    m_pParticles = new Particle[N_PARTICLES_MAX];
}

Swarm::~Swarm() {
    delete [] m_pParticles;
}

void Swarm::update() {
    for (int i=0; i<N_PARTICLES_CURR; i++) {
        m_pParticles[i].update();
    }
}

}
