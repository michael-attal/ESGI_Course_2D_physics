#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include "Body.h"
#include "MatMN.h"

class Constraint {
    public:
        Body* a;
        Body* b;

        virtual ~Constraint() = default;

        MatMN GetInvM() const;
        VecN GetVelocities() const;

        virtual void Solve() {}
};

class DistanceConstraint: public Constraint {
    // TODO:
    // MatMN jacobian;
    // void Solve() override;
};

class PenetrationConstraint: public Constraint {
    // TODO:
    // MatMN jacobian;
    // void Solve() override;
};

#endif
