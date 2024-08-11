#include <raylib.h>
#include <rlgl.h>
#include "Particule.h"
#include "Object.h"
#include "SystemParticule.h"
#include <iostream>

int main(void)
{
    const int screenWidth = 1000;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "Particule buzz l'eclair");

    Camera camera = { 0 };
    camera.position = (Vector3) { 16.0f, 16.0f, 16.0f };
    camera.target = (Vector3) { 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3) { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    //void SetCameraPanControl(int keyPan);                                   
    //oid SetCameraAltControl(int keyAlt);                                   
    SetCameraMode(camera, CAMERA_THIRD_PERSON); 
    SetTargetFPS(60);
    Object scene = Object();
    SystemParticule tissu = SystemParticule();
    scene.add(&tissu);
    while (!WindowShouldClose())
    {
        UpdateCamera(&camera);
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode3D(camera);
                DrawGrid(100, 1.0f);
                scene.render();
            EndMode3D();
            DrawFPS(100, 100);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}