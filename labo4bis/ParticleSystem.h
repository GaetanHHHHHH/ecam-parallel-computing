#include "Object.h"
#include "Particule.h"

class ParticleSystem : public Object {
    private:
        Particule particules[10];
        bool gravity;
    public:
        ParticleSystem(bool gravity);
        void updateSystemAndCollide();
        virtual void draw();
};