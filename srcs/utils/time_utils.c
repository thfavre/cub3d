#include <time.h>

double	get_elapsed_time(void)
{
	static clock_t	start_time = 0;
	double			elapsed_time;
	clock_t			current_time;

	current_time = clock(); // TODO is it autorized to use clock()?
	elapsed_time = (double)(current_time - start_time) / CLOCKS_PER_SEC;
	start_time = clock();
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
	}
	return (avrage_fps);
}
