#include "Swarm.h"

namespace fgias {

Swarm::Swarm() {
    m_pParticles = new Particle[N_PARTICLES];
}

Swarm::~Swarm() {
    delete [] m_pParticles;
}

}
