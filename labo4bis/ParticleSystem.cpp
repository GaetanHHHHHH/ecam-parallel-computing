#include"ParticleSystem.h"
#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>
#include <iostream>
#include <stdlib.h> 
#include <cstdlib>  

//constructeur de l'objet 
//on crée des particules et on leur donne des vitesses et position aléatoire
ParticleSystem::ParticleSystem( bool gravity){
    this->gravity = gravity;
    for(int i = 0 ; i < 10 ; i++){
        Particule part = Particule();
        part.setRandomPositionAndSpeed();
        this->particules[i] = part;
    }
}

void ParticleSystem::updateSystemAndCollide(){
    for (int i = 0; i<10; i++){
        this->particules[i].updatePosition();
        this->particules[i].Collision();
        if(this->gravity){
            this->particules[i].withGravity();
        }
    }
}

void ParticleSystem::draw(){
    for(int i = 0; i < 10; i++){
        this->particules[i].draw();
    }
}






