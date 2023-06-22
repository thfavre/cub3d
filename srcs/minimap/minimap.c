#include "draw.h"
#include "color.h"
#include "game2d.h"

void	zoom_minimap(t_data *data, t_minimap *minimap);

void	draw_minimap(t_data *data, char **map, t_minimap minimap)
{
	int		x;
	int		y;
	t_rect	current_rect;

	zoom_minimap(data, &minimap);
	draw_rect(&data->img, (t_rect){minimap.offset.x,
		minimap.offset.y, minimap.size.x, minimap.size.y}, 0x80808010);
	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			current_rect = (t_rect){(x * minimap.block)
				+ minimap.offset.x, (y * minimap.block)
				+ minimap.offset.y, minimap.block, minimap.block};
			if (map[y][x] == '1')
				draw_rect(&data->img, current_rect, C_BLACK);
			else if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
			|| map[y][x] == 'E' || map[y][x] == 'O')
				draw_rect(&data->img, current_rect, C_BLUE);
		}
	}
}

void	zoom_minimap(t_data *data, t_minimap *minimap) // TODO HOW TO ZOOM THE PLAYER
{
	if (data->key_pressed[K_Z] && minimap->size.x < SCREEN_WIDTH * 0.5)
	{
		minimap->size = (t_vector2){minimap->size.x * 2,
			minimap->size.y * 2};
		minimap->block *= 2;
	}
}
