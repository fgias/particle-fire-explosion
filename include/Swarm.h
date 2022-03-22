#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace fgias {

class Swarm {
public:
    static const int N_PARTICLES_MAX = 100;
    static int N_PARTICLES_CURR;
private:
    Particle* m_pParticles; // const pointer to a particle
public:
    Swarm();
    virtual ~Swarm();
    Particle* getParticles() {return m_pParticles;};
    void update();
};

}

#endif