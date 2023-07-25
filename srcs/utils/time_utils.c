#include <time.h>
#include "data.h"
#include "mlx.h"
#include "libft.h"
#include "draw.h"

double	get_delta_time(void) // TODO fix this function ?
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


void	draw_fps(t_data *data)
{
	char	*fps_str;
	char	*str;
	int		avrage_fps;

	avrage_fps = get_avrage_fps(data->dt);
	fps_str = ft_itoa(avrage_fps);
	if (!fps_str)
		return ;
	str = ft_strjoin("FPS: ", fps_str);
	free(fps_str);
	if (!str)
		return ;
	mlx_string_put(data->mlx, data->win, 5, 15, C_WHITE, str);
	free(str);
}
