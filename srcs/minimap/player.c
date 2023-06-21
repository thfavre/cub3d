#include "draw.h"
#include "color.h"
#include "game2d.h"
#include "keycodes.h"

void	update_player(t_data *data, t_game *game)
{
	t_rect	current_rect;

	current_rect = (t_rect){game->player.pos.x
		+ game->minimap.offset.x, game->player.pos.y
		+ game->minimap.offset.y, game->player.size, game->player.size};
	draw_rect(&data->img, current_rect, C_GREEN);

	if (data->key_pressed[K_W])
		game->player.pos.y -= game->player.speed * data->dt;
	if (data->key_pressed[K_S])
		game->player.pos.y += game->player.speed * data->dt;
	if (data->key_pressed[K_A])
		game->player.pos.x -= game->player.speed * data->dt;
	if (data->key_pressed[K_D])
		game->player.pos.x += game->player.speed * data->dt;
}

