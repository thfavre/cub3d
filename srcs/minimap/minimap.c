#include "data.h"
#include "draw.h"
#include "color.h"

char	**init_map(void);
// int		minimap_size(t_data *data);
// bool	register_player(t_data *data);

// void	minimap(t_data *data)
// {
// 	int		block;
// 	bool	flag;

// 	flag = false;
// 	block = minimap_size(data);
// 	if (!flag)
// 		flag = register_player(data);

// }

// int	minimap_size(t_data *data)
// {
// 	float	block;
// 	int		i;
// 	int		y;

// 	y = -1;
// 	while (map[++y])
// 		i++;
// 	block = (data->img.size.x / 6) / i;
// 	return (block);
// }

// bool	register_player(t_data *data)
// {
// 	t_player	player;

// }
void	draw_minimap(t_data *data)
{
	int	x;
	int	y;
	// char	**map; // TO DELETE

	// map = init_map(); // TO DELETE
	// while (map[++y][x])
	// {
	// 	x = -1;
	// 	while (map[y][++x])
	// 	{
	// 		if (map[y][x] == '1')
	// 			draw_rect(&data->img, (t_rect){(x + 1) * 60, (y + 1) * 60, 60, 60}, COLOR_BLACK);
	// 		else if (map[y][x] == '0')
	// 			draw_rect(&data->img, (t_rect){(x + 1) * 60, (y + 1) * 60, 60, 60}, COLOR_BLUE);
	// 		else if (map[y][x] == 'N' || map[y][x] == 'S'
	// 			|| map[y][x] == 'E' || map[y][x] == 'O')
	// 		{
	// 			draw_rect(&data->img, (t_rect){(x + 1) * 60, (y + 1) * 60, 60, 60}, COLOR_BLUE);
	// 			draw_rect(&data->img, (t_rect){(x + 1) * 60, (y + 1) * 60, 60, 60}, COLOR_RED);
	// 		}
	// 		else
	// 			draw_rect(&data->img, (t_rect){(x + 1) * 60, (y + 1) * 60, 60, 60}, COLOR_GRAY);
	// 	}
	// }
	// int	i = -1;
	// while (++i < 5)
	// 	free(map[i]);
	x = 0;
	y = 0;
	t_rect current_rect;
	// free(map);
	while (data->map[y][x])
	{

		while (data->map[y][x])
		{
			current_rect = (t_rect){(x + 1) * 20, (y + 1) * 20, 20, 20};
			printf("This is a test\n");
			if (data->map[y][x] == '1')
				draw_rect(&data->img, current_rect, C_BLACK);
			else if (data->map[y][x] == '0')
				draw_rect(&data->img, current_rect, C_BLUE);
			else if (data->map[y][x] == 'N' || data->map[y][x] == 'S'
				|| data->map[y][x] == 'E' || data->map[y][x] == 'O')
			{
				draw_rect(&data->img, current_rect, C_BLUE);
				draw_rect(&data->img, current_rect, C_RED);
			}
			else
			draw_rect(&data->img, (t_rect){(x + 1) * 20, (y + 1) * 20, 8, 8}, C_GRAY);
		x++;
		}
		x = 0;

		y++;
	}
}
