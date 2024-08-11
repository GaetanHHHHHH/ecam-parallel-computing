#include "Object.h"
#include <raymath.h>
#include <iostream>
#include <rlgl.h>
#include <rlgl.h>

Object::Object() {
    position = {0.0f, 0.0f, 0.0f};
    originalPosition = {0.0f, 0.0f, 0.0f};
    rotation =  {0.0f, 0.0f, 0.0f};
    speed = {0.01f, 0.01f, 0.01f};
    acceleration = {0.0f, -0.01f, 0.0f};
    Fresult = {1.0f, 1.0f, 1.0f};
    mass =(float)(1000/5.0f);
    size = {10.0f, 10.0f, 10.0f};
    scale = {1.0f, 1.0f, 1.0f};
}

void Object::add(Object* obj) {
    children.push_back(obj);
}


void Object::render() {
    rlPushMatrix();
    rlTranslatef(position.x, position.y, position.z);
    //rlMultMatrixf(MatrixToFloatV(MatrixRotateXYZ(rotation)).v);
    rlRotatef(rotation.x*180/PI, 1.0f, 0.0f, 0.0f);
    rlRotatef(rotation.y*180/PI, 0.0f, 1.0f, 0.0f);
    rlRotatef(rotation.z*180/PI, 0.0f, 0.0f, 1.0f);
    rlScalef(scale.x, scale.y, scale.z);
    //DrawSphere({0.5f,5.0f,0.5f}, 1.0, PURPLE);
    draw();
    for(Object* obj : children) {
        obj->render();
    }
    rlPopMatrix();
}

void Object::draw() {}

void Object::translate(float x, float y, float z) {
    
}

void Object::rotateX(float value) {
    rotation.x += value;
}

void Object::rotateY(float value) {
    rotation.y += value;
}

void Object::rotateZ(float value) {
    rotation.z += value;
}

void Object::speedX(float value) {
    speed.x += value;
}

void Object::speedY(float value) {
    speed.y += value;
}

void Object::speedZ(float value) {
    speed.z += value;
}

void Object::scaleX(float value) {
    size = Vector3Multiply(size, {value, value, value});
}

Matrix Object::getTransform() {
    Matrix matScale = MatrixScale(size.x, size.y, size.z);
    Matrix matRotation = MatrixRotateXYZ(rotation);
    Matrix matTranslation = MatrixTranslate(position.x, position.y, position.z);

    Matrix matTransform = MatrixMultiply(MatrixMultiply(matScale, matRotation), matTranslation);

    return matTransform;
}

