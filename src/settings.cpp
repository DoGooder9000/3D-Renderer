#include "headers/settings.h"

const double PI = 3.141592653589;

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;
const char* WINDOW_TITLE = "3D Renderer in C";

const float FOV = PI/3;
const float fNear = 0.1;
const float fFar = 1000;
const float fAspectRatio = WINDOW_WIDTH / WINDOW_HEIGHT;

const float fFOVRad = 1.0f / tanf(FOV / 2);

float MoveSpeed = 1.f / 800.f;