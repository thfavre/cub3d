#include <time.h>

double	get_delta_time(void) // TODO fix this function
{
	double	currentTime;
	double	delta_time;
	static	double previousTime = 0;

	currentTime = (double)clock() / CLOCKS_PER_SEC;
	delta_time = currentTime - previousTime;
	previousTime = currentTime;
	return (delta_time);
}

int	get_avrage_fps(float dt)
{
	static int		frames = 0;
	static float	elapsed_time = 0;
	static int		avrage_fps = 0;

	frames++;
	elapsed_time += dt;
	if (elapsed_time >= 0.2)
	{
		avrage_fps = frames / elapsed_time;
		frames = 0;
		elapsed_time = 0;
	}
	return (avrage_fps);
}
