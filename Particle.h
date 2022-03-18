#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace fgias {

// the only difference between class and struct: 
// instance vairables are public by default
struct Particle { 
    double m_x; // these are public
    double m_y;

    double m_speed;
    double m_direction;
public:
    Particle();
    void update();
};

}

#endif