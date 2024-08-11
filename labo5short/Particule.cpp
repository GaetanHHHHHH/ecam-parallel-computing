#include "Particule.h"
#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>
#include <iostream>
#include <stdlib.h> 
#include <cstdlib>  

//constructeur de particules
Particule::Particule(){

}

//méthode qui met à jour la position de la particule en fonction
//de sa vitesse
void Particule::updatePosition(){
    float time = GetFrameTime();
    this->position = Vector3Add(this->position,Vector3Scale(this->speed,time));
}

//méthode qui met à jour la vitesse d'une particule en fonction
//de la résultante des forces s'appliquant dessus
void Particule::updateSpeed(){
    //getting de tile interval since previous frame
    float time = GetFrameTime();
    //turning the total force into acceleration thanks to the mass
    Vector3 acc = Vector3Scale(this->Fresult,((float)(1.0/this->mass)));
    this->acceleration = Vector3Add(this->acceleration,acc);
    this->acceleration = Vector3Subtract(this->acceleration,{0.0f,1.0f,0.0f});
    this->speed = Vector3Add(this->speed, Vector3Scale(this->acceleration,time));
}

void Particule::draw(){
    DrawSphere(this->position, 0.03, ORANGE);
}

void Particule::setPositionAndSpeed(Vector3 Position, Vector3 Speed){
    this->position = Position;
    this->speed = Speed;
}
void Particule::groundCollision(){
    if(this->position.y <= 0.0){
        this->position.y = 0.0f;
        this->speed = Vector3Reflect(this->speed, {0.0f, 1.0f, 0.0f});
    }
}
void Particule::sphereCollision(float Width, float Height){
    //center of sphere
    Vector3 center = {Width/20,5.0f,Height/20};
    Vector3 ray = Vector3Subtract(this->position, center);
    float length_ray = Vector3Length(ray);
            if(length_ray<=1.0f){
                std::cout << "Force :"<<this->Fresult.x << " || " <<this->Fresult.y<< " || " <<this->Fresult.z<<std::endl;
                //setting the speedof the particle to zero
                this->speed = {0.0f, 0.0f, 0.0f};
                //this->acceleration = {0.0f, 0.0f, 0.0f};
                //updating the position of the particle
                //Vector3 unitRay = Vector3Scale(ray,(1.0/length_ray));
                //Vector3 repopsitionement = Vector3Scale(unitRay,1.0);
                //replacing the particle position
                //this->position = Vector3Add(center,repopsitionement);
            }
}

void Particule::spring(Particule comp, float k){
    /*
    on définit un vecteur allant de la particule de comparaison vers celle 
    pour laquelle on calcule le ressort 
    */
    Vector3 v = Vector3Subtract(this->position,comp.position);
    //on prend la norme de ce vecteur 
    float norme_v = Vector3Length(v);
    /*
    on prend le vecteur unitaire du vecteur v afin d'être certain d'exercer la 
    force du ressort dans le bon axe
    */
    Vector3 unit_v = Vector3Scale(v,(1.0f/norme_v));
    /*
    On calcule la distance originelle entre ces deux particules afin de la comparer
    avec la distance actuelle
    */
    //on construit le vecteur u qui va de la position originelle de comp
    //vers la position originelle de la particuke pour laquelle on calcule le ressort
    Vector3 u = Vector3Subtract(this->originalPosition,comp.originalPosition);
    //on prend la norme de ce vecteur
    float norme_u = Vector3Length(u);
    //on teste si la distance actuelle est plus grande, plus petite ou égale 
    //à la distance originelle
    float delta_d = norme_u - norme_v;
    //sur base de ce delta dist on calcule la norme de la force grâce au k
    //le signe donnera le sens et la direction sera donnée grâce au vecteur 
    //unitaire v
    float f = -k*delta_d;
    if(f<10 && f>-10){
        //pour créer le vecteur force, on multiplie le vecteur unitaire de v
        //par la valeur de force calculée.
        Vector3 force = Vector3Scale(unit_v, f);
        force = Vector3Negate(force);
        //on ajoute à la force résultante de la particule la force de ce ressort
        this->Fresult = Vector3Add(this->Fresult,force);
    }
}
;


