#include <stdio.h>
#include <math.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

int worldMap[MAP_WIDTH][MAP_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 1, 1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 40
#define FOV_ANGLE 60

void raycast() {
    double playerX = 2.0;
    double playerY = 2.0;
    double playerAngle = 0.0;

    double angleStep = FOV_ANGLE / SCREEN_WIDTH;

    double rayAngle = playerAngle - (FOV_ANGLE / 2);

    int rayIndex = 0;
    while (rayIndex < SCREEN_WIDTH) {
        double rayDirX = cos(rayAngle * M_PI / 180);
        double rayDirY = sin(rayAngle * M_PI / 180);

        double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
        double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));

        int stepX, stepY;
        double sideDistX, sideDistY;

        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (playerX - (int)playerX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = ((int)playerX + 1 - playerX) * deltaDistX;
        }

        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (playerY - (int)playerY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = ((int)playerY + 1 - playerY) * deltaDistY;
        }

        int hit = 0;
        int mapX = (int)playerX;
        int mapY = (int)playerY;
        while (!hit) {
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
            }

            if (worldMap[mapX][mapY] == 1) {
                hit = 1;
            }
        }

        // Dessiner la colonne correspondante à rayIndex ici

        rayAngle += angleStep;
        rayIndex++;
    }
}

int main() {
    raycast();
    return 0;
}
