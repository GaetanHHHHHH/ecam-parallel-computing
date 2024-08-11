#include "Particule.h"
#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>
#include <iostream>
#include <stdlib.h> 
#include <cstdlib>  

Particule::Particule() {
//     mesh = GenMeshSphere(1.0f, 8.0f, 8.0f);
//     material = LoadMaterialDefault();
}

//méthode qui permet de faire varier la position en fonction de la vitesse 
void Particule::updatePosition(){
    float time = GetFrameTime();
    this->position = Vector3Add(this->position, Vector3Multiply(this->speed,{time,time,time}));
    //std::cout << this->position.x << "   " << this->position.y << "    " <<this->position.z << std::endl;
    //std::cout << this->speed.x << "   " << this->speed.y << "    " <<this->speed.z << std::endl;
}

void Particule::Collision(){
    float xlimit = 5.0f;
    float ylimit = 5.0f;
    float zlimit = 5.0f;
    
    if(this->position.x >= xlimit-0.5f){
        Vector3 normale = {-1.0f,0.0f,0.0f};
        this->speed = Vector3Reflect(this->speed, normale);
    }
    if(this->position.y >= ylimit-0.5f){
        Vector3 normale = {0.0f,-1.0f,0.0f};
        this->speed = Vector3Reflect(this->speed, normale);
    }
    if(this->position.z >= zlimit-0.5f){
        Vector3 normale = {0.0f,0.0f,-1.0f};
        this->speed = Vector3Reflect(this->speed, normale);
    }
     if(this->position.x <= 0.5f){
        Vector3 normale = {1.0f,0.0f,0.0f};
        this->speed = Vector3Reflect(this->speed, normale);
    }
    if(this->position.y <= 0.5f){
        Vector3 normale = {0.0f,1.0f,0.0f};
        this->speed = Vector3Reflect(this->speed, normale);
    }
    if(this->position.z <= 0.5f){
        Vector3 normale = {0.0f,0.0f,1.0f};
        this->speed = Vector3Reflect(this->speed, normale);
    }
}

void Particule::setRandomPositionAndSpeed(){
      this->position.x = rand()%5;
      this->position.y = rand()%5;
      this->position.z = rand()%5;
      this->speed.x = rand()%5;
      this->speed.y = rand()%5;
      this->speed.z = rand()%5;
      std::cout << this->position.x << "  " << this->position.y << "  " << this->position.z << std::endl;
      std::cout << this->speed.x << "  " << this->speed.y << "  " << this->speed.z << std::endl;
}

void Particule::withGravity(){
    this->speed = Vector3Add(this->speed,Vector3Scale(this->accelerationGravity, GetFrameTime()));
}

void Particule::draw() {
    //std::cout << this->position.x << this->position.y << this->position.z << std::endl;  
    // this->position.x = 3.0f;
    // this->position.y = 4.0f;
    //this->position.z = 1.0f;
    DrawSphere(this->position, 0.1f, RED);
    // material.maps[MATERIAL_MAP_DIFFUSE].color = RED;
    // DrawMesh(mesh, material, matModel);
    // rlEnableWireMode();
    //     material.maps[MATERIAL_MAP_DIFFUSE].color = BLACK;
    //     DrawMesh(mesh, material, matModel); 
    // rlDisableWireMode();
}