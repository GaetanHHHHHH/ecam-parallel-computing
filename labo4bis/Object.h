#pragma once
#include <vector>
#include <raylib.h>

using namespace std;

class Object {
    private:
        vector<Object*> children;
        Vector3 rotation;
        Vector3 size;
        Vector3 scale;

    public :
        Vector3 accelerationGravity;
        Vector3 position;
        Vector3 speed;
        Object();
        void add(Object* obj);
        void render();
        virtual void draw();
        void translate(float x, float y, float z);
        void rotateX(float value);
        void rotateY(float value);
        void rotateZ(float value);
        void speedX(float value);
        void speedY(float value);
        void speedZ(float value);
        void scaleX(float value);
        Matrix getTransform();
};