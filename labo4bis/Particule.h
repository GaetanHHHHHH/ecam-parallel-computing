#pragma once
#include "Object.h"

class Particule : public Object {
    private:
        Mesh mesh;
        Material material;
    public:
        Particule();
        void updatePosition();
        virtual void draw();
        void Collision();
        void setRandomPositionAndSpeed();
        void withGravity();
};