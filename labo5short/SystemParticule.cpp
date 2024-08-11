#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>
#include <iostream>
#include <stdlib.h> 
#include <cstdlib>  
#include "SystemParticule.h"
#include <math.h>


//constructeur de l'objet
SystemParticule::SystemParticule(){
    this->particules = new Particule* [WIDTH];
    for(int i = 0; i < WIDTH; i++){
        this->particules[i] = new Particule [HEIGHT];
        for(int j = 0; j < HEIGHT; j++){
            Vector3 position = {((float) (i / 10.0f)), 10.0f,  ((float) (j / 10.0f))};
            //(float)((rand()%5 +(-2))), (float)((rand()%5 +(-2))), (float)((rand()%5 +(-2)))
            Vector3 speed = {0.0f, 0.0f, 0.0f};
            //this->particules[i][j] = Particule();
            this->particules[i][j].setPositionAndSpeed(position, speed);
            this->particules[i][j].originalPosition = this->particules[i][j].position;
            this->particules[i][j].Fresult = {0.0f, 0.0f, 0.0f};
        }
    }
}
//destructeur de l'objet 
SystemParticule::~SystemParticule() {
    for(int i = 0; i < WIDTH; i++){
        delete[] this->particules[i];
    }
    delete[] this->particules;
}

void SystemParticule::draw(){
    update();
    for(int i = 0; i < WIDTH; i++){
        for (int j = 0; j<HEIGHT; j++){
            this->particules[i][j].draw();
        }    
    }
}

void SystemParticule::update(){
    computeSprings();
    for(int i = 0; i < WIDTH; i++){
        for(int j = 0; j < HEIGHT; j++){
            std::cout << "------------------------------------------------------------ " <<std::endl;
            std::cout << " index " << i << " || " << j << std::endl;
            this->particules[i][j].updateSpeed();
            this->particules[i][j].updatePosition();
            this->particules[i][j].sphereCollision(WIDTH, HEIGHT);
            this->particules[i][j].groundCollision();
        }
    }
}

void SystemParticule::computeSprings(){
    for (int i = 0; i < WIDTH; i++){
        for(int j = 0; j < HEIGHT; j++){
            Particule part = this->particules[i][j];
            for(int k = -2; k<=2 ; k++){
                for(int l = -2 ; l<=2 ; l++){
                    if((abs(k)+ abs(l))<=2 && (i + k)<WIDTH && (i + k)>=0 && (j + l)<HEIGHT && (j + l)>=0 && (abs(k)+abs(l))>0){
                        Particule part_comp = this->particules[i+k][j+l];
                        float coeff = 0.0f;
                        if(abs(k)+abs(l)== 1){
                            //cas des structural spring
                            coeff = 1.0f;
                        }
                        else{
                            if(abs(k) == 1 && abs(l) == 1){
                                // cas du shear spring
                                coeff = 0.9f;
                            }
                            else{
                                //cas des bend spring
                                coeff = 1.1f;
                            }
                        }
                        part.spring(part_comp, coeff);
                    }
                }
            }
            this->particules[i][j] = part;
        }
    }

}