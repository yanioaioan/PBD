#include "particle.h"
#include <iostream>

Particle::Particle()
{

}

Particle::Particle(ngl::Vec3 currentPos, ngl::Vec3 currentVel)
{
  m_currentPos=currentPos;
  m_currentVel=currentVel;
}

Particle::~Particle()
{

}


