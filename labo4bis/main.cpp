#include <raylib.h>
#include "rlgl.h"
#include "Object.h"
#include "Cube.h"
#include "ParticleSystem.h"

int main(void)
{
    const int screenWidth = 2000;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "LABO4 - Particules");

    Camera camera = { 0 };
    camera.position = (Vector3) { 20.0f, 20.0f, 20.0f };
    camera.target = (Vector3) { 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3) { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    //void SetCameraPanControl(int keyPan);                                   
    //oid SetCameraAltControl(int keyAlt);                                   
    SetCameraMode(camera, CAMERA_THIRD_PERSON); 
    SetTargetFPS(60);

    Object scene = Object();
    //Cube onMove = Cube();
    Cube container = Cube();
    ParticleSystem syst = ParticleSystem(true);
    scene.add(&container);
    scene.add(&syst);
    while (!WindowShouldClose())
    {
        UpdateCamera(&camera);
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(camera);
                DrawGrid(100, 1.0f);
                scene.render();
                syst.updateSystemAndCollide();
            EndMode3D();
            DrawFPS(1000, 1000);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}