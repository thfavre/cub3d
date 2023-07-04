#include "draw.h"
#include "color.h"
#include "game2d.h"

// void	zoom_minimap(t_data *data, t_minimap *minimap);
void	draw_player(t_data *data, t_player *player, t_minimap *minimap);

void	draw_minimap(t_data *data, char **map, t_minimap minimap)
{
	int		x;
	int		y;
	t_rect	current_rect;

	// draw_rect(&data->img, (t_rect){minimap.offset.x,
		// minimap.offset.y, minimap.size.x, minimap.size.y}, 0xDDE6ED);
	// zoom_minimap(data, &minimap);
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			current_rect = (t_rect){x * (data->game2d.size_block.x
					* minimap.scale) + minimap.offset.x, y
				* (data->game2d.size_block.y * minimap.scale)
				+ minimap.offset.y, data->game2d.size_block.x
				* minimap.scale, data->game2d.size_block.x * minimap.scale};
			if (map[y][x] == '1')
				draw_rect(&data->img, current_rect, 0x27374D);
			else if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
			|| map[y][x] == 'E' || map[y][x] == 'W')
				draw_rect(&data->img, current_rect, 0xDDE6ED);
		}
	}
	draw_player(data, &data->game2d.player, &data->game2d.minimap);
}

void	draw_player(t_data *data, t_player *player, t_minimap *minimap)
{
	t_rect	current_rect;

	current_rect = (t_rect){player->pos.x * minimap->scale
		+ minimap->offset.x, player->pos.y * minimap->scale
		+ minimap->offset.y, player->size.x * minimap->scale,
		player->size.y * minimap->scale};
	draw_rect(&data->img, current_rect, 0x526D82);
	t_vector2	start_pos = (t_vector2){(player->pos.x + player->size.x / 2) * minimap->scale
		+ minimap->offset.x, (player->pos.y  + player->size.x / 2) * minimap->scale
			+ minimap->offset.y};
	t_vector2	end_pos = (t_vector2){start_pos.x + cos(player->angle) * 50 * minimap->scale, start_pos.y - sin(player->angle) * 50 * minimap->scale};
	draw_line(&data->img, start_pos, end_pos, 0x00ffff, 5 * minimap->scale);
}
