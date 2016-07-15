#ifndef PARTICLE_H
#define PARTICLE_H

#include <ngl/Vec3.h>

class Particle
{
public:
    Particle();
    Particle(ngl::Vec3 currentPos, ngl::Vec3 currentVel=ngl::Vec3(0,-9.81,0) );
    ~Particle();

    Particle (const Particle & particle){}

    ngl::Vec3 m_currentPos;
    ngl::Vec3 m_currentVel;

};

#endif // PARTICLE_H
