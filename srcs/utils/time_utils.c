#include <time.h>

double	get_elapsed_time(void)
{
	double	currentTime;
	double	elapsed_time;
	static	double previousTime = 0;

	currentTime = (double)clock() / CLOCKS_PER_SEC;
	elapsed_time = currentTime - previousTime;
	previousTime = currentTime;
	return (elapsed_time);
}

int	get_avrage_fps(float dt)
{
	static int		frames = 0;
	static float	elapsed_time = 0;
	static int		avrage_fps = 0;

	frames++;
	elapsed_time += dt;
	if (elapsed_time >= 1)
	{
		avrage_fps = frames;
		frames = 0;
		elapsed_time = 0;
		printf("FPS: %d\n", avrage_fps); // TODO remove
	}
	return (avrage_fps);
}
