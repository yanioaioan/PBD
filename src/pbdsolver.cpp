#include "pbdsolver.h"
#include <iostream>

PBDSolver::PBDSolver()
{
    initSolver();
}

PBDSolver::~PBDSolver()
{

}

void PBDSolver::initSolver()
{
    timestep= 0.01;
    numberOfTotalParticles=2;
    gravity.set(0,-9.81,0);


    for(int i=0;i<numberOfTotalParticles;i++)
    {
        std::unique_ptr<Particle> p(new Particle);//(ngl::Vec3(i,0,0), ngl::Vec3(0,-9.81,0));
        ngl::Vec3 pos;
        if (i!=0)
        {
            pos.set(0.0, -i/5.0 ,0.0);
        }
        p->m_currentPos.set(pos);

        ngl::Vec3 tmpVel=gravity*timestep;

        p->m_currentVel.set(tmpVel);
        m_particles.push_back(std::move(p));
    }
}

//computer dx1 and dx2 for interacting particles
void PBDSolver::computeDistanceConstraint(const  ngl::Vec3 &p1 , const ngl::Vec3 &p2)
{
    float distanceFromEachother=0.2;
    ngl::Vec3 normVec=(p1-p2);normVec.normalize();

    ngl::Vec3 dx1= - 1/2 * (normVec- distanceFromEachother) * (p1-p2)/normVec;

    ngl::Vec3 dx2=   1/2 * (normVec- distanceFromEachother) * (p1-p2)/normVec;


}


void PBDSolver::solve()
{

    std::cout<<"solve"<<std::endl;

    //check ground collision (suppose we 've got an infinite ground)
    if()



    //euler integration
    for(auto &p:m_particles)
    {
        p->m_currentPos = p->m_currentPos + p->m_currentVel*timestep;
    }

}
