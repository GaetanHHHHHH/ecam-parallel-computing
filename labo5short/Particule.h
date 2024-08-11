#pragma once
#include "Object.h"

class Particule : public Object {
    private:
        Mesh mesh;
        Material material;
    public:
        Particule();
        void updatePosition();
        void updateSpeed();
        virtual void draw();
        void setPositionAndSpeed(Vector3 Position, Vector3 Speed);
        void groundCollision();
        void sphereCollision(float Width, float Height);
        void spring(Particule comp,float k);
};