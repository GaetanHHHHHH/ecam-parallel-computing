#include "Object.h"
#include "Particule.h"

#define WIDTH 10
#define HEIGHT 10
#define Xbase 0.01f

class SystemParticule : public Object {
    private :
        Particule** particules;
    public : 
        SystemParticule();
        ~SystemParticule();
        void draw();
        void update();
        void updateSpeedAndPosition();
        void computeSprings();        
};