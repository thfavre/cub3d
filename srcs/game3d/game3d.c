// #include "game3d.h"
#include "vector2.h"
#include "draw.h"
#include "data.h" // for SCREEN_WIDTH, SCREEN_HEIGHT
#include "mlx.h"

void	game3d(void *img, char **worldMap, bool *key_pressed, void *win, void *mlx)
{

	static t_fvector2	pos = {5, 5};
	static t_fvector2	dir = {-1, 0};
	static t_fvector2	plane = {0, 0.66};

	double moveSpeed = 0.1;
	if (key_pressed[K_W])
	{
		if (worldMap[(int)(pos.x + dir.x * moveSpeed)][(int)pos.y] == '0')
			pos.x += dir.x * moveSpeed;
		if (worldMap[(int)pos.x][(int)(pos.y + dir.y * moveSpeed)] == '0')
			pos.y += dir.y * moveSpeed;
	}
	if (key_pressed[K_S])
	{
		if (worldMap[(int)(pos.x - dir.x * moveSpeed)][(int)pos.y] == '0')
			pos.x -= dir.x * moveSpeed;
		if (worldMap[(int)pos.x][(int)(pos.y - dir.y * moveSpeed)] == '0')
			pos.y -= dir.y * moveSpeed;
	}


	float rotSpeed = 0.03;
	if (key_pressed[K_D])
	{
		double oldDirX = dir.x;
		dir.x = dir.x * cos(-rotSpeed) - dir.y * sin(-rotSpeed);
		dir.y = oldDirX * sin(-rotSpeed) + dir.y * cos(-rotSpeed);
		double oldPlaneX = plane.x;
		plane.x = plane.x * cos(-rotSpeed) - plane.y * sin(-rotSpeed);
		plane.y = oldPlaneX * sin(-rotSpeed) + plane.y * cos(-rotSpeed);
	}
	if (key_pressed[K_A])
	{
		double oldDirX = dir.x;
		dir.x = dir.x * cos(rotSpeed) - dir.y * sin(rotSpeed);
		dir.y = oldDirX * sin(rotSpeed) + dir.y * cos(rotSpeed);
		double oldPlaneX = plane.x;
		plane.x = plane.x * cos(rotSpeed) - plane.y * sin(rotSpeed);
		plane.y = oldPlaneX * sin(rotSpeed) + plane.y * cos(rotSpeed);
	}
	int x = -1;
	while (++x < SCREEN_WIDTH)
	{
		float cameraX = 2 * x / (float)SCREEN_WIDTH - 1;  // x-coordinate in camera space
		t_fvector2 rayDir = {dir.x + plane.x * cameraX, dir.y + plane.y * cameraX};

		t_vector2 map = {(int)pos.x, (int)pos.y};

		t_fvector2 sideDist;
		t_fvector2 deltaDist = {fabs(1 / rayDir.x), fabs(1 / rayDir.y)};
		float perpWallDist;

		t_vector2 step;
		int side;

		if (rayDir.x < 0)
		{
			step.x = -1;
			sideDist.x = (pos.x - map.x) * deltaDist.x;
		}
		else
		{
			step.x = 1;
			sideDist.x = (map.x + 1.0 - pos.x) * deltaDist.x;
		}
		if (rayDir.y < 0)
		{
			step.y = -1;
			sideDist.y = (pos.y - map.y) * deltaDist.y;
		}
		else
		{
			step.y = 1;
			sideDist.y = (map.y + 1.0 - pos.y) * deltaDist.y;
		}

		int hit = 0;
		while (hit == 0)
		{
			if (sideDist.x < sideDist.y)
			{
				sideDist.x += deltaDist.x;
				map.x += step.x;
				side = 0;
			}
			else
			{
				sideDist.y += deltaDist.y;
				map.y += step.y;
				side = 1;
			}
			if (worldMap[map.x][map.y] > '0')
				hit = 1;
		}

		if (side == 0)
			perpWallDist = (map.x - pos.x + (1 - step.x) / 2) / rayDir.x;
		else
			perpWallDist = (map.y - pos.y + (1 - step.y) / 2) / rayDir.y;

		int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

		int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
		if(drawEnd >= SCREEN_HEIGHT)
			drawEnd = SCREEN_HEIGHT - 1;

		int color = 0x00FF00;
		if (worldMap[map.x][map.y] == '1')
			color = 0xFF0000;
		if (side == 1)
			color = color / 3;
		draw_line(img, (t_vector2){x, drawStart}, (t_vector2){x, drawEnd}, color, 1);
	}

}
