#ifndef PBDSOLVER_H
#define PBDSOLVER_H

#include <particle.h>
#include <vector>
#include <memory>


class PBDSolver
{
public:
    PBDSolver();
    ~PBDSolver();

    void initSolver();
    void computeDistanceConstraint(const ngl::Vec3 &p1, const ngl::Vec3 &p2);
    void solve();

    std::vector< std::unique_ptr<Particle> > m_particles;

private:
    PBDSolver (const PBDSolver & solver){}
    int numberOfTotalParticles;
    float timestep;
    ngl::Vec3 gravity;
};

#endif // PBDSOLVER_H
