#include "draw.h"
#include "color.h"
#include "game2d.h"
#include "keycodes.h"

void	draw_player(t_data *data, t_game *game);
void	move_player(t_data *data, t_game *game);
void	check_collisions(t_data *data, t_game *game);

void	update_player(t_data *data, t_game *game)
{
	draw_player(data, game);
	move_player(data, game);
	check_collisions(data, game);
}

void	draw_player(t_data *data, t_game *game)
{
	t_rect	current_rect;

	current_rect = (t_rect){game->player.pos.x
		+ game->minimap.offset.x, game->player.pos.y
		+ game->minimap.offset.y, game->player.size, game->player.size};
	draw_rect(&data->img, current_rect, C_GREEN);
}

void	move_player(t_data *data, t_game *game)
{
	if (data->key_pressed[K_W])
		game->player.pos.y -= game->player.speed * data->dt;
	if (data->key_pressed[K_S])
		game->player.pos.y += game->player.speed * data->dt;
	if (data->key_pressed[K_A])
		game->player.pos.x -= game->player.speed * data->dt;
	if (data->key_pressed[K_D])
		game->player.pos.x += game->player.speed * data->dt;
}

void	check_collisions(t_data *data, t_game *game)
{
	t_vector2	player_pos;

	player_pos = (t_vector2){(int)game->player.pos.x / game->minimap.block,
		(int)game->player.pos.y / game->minimap.block};
	if (data->map[player_pos.y][player_pos.x - 1] == '1')
		if (game->player.pos.x < player_pos.x)
			game->player.pos.x = player_pos.x * game->minimap.block;
	if (data->map[player_pos.y][player_pos.x + 1] == '1')
		if (game->player.pos.x > player_pos.x)
			game->player.pos.x = player_pos.x * game->minimap.block;
	if (data->map[player_pos.y - 1][player_pos.x] == '1')
		if (game->player.pos.y > player_pos.y)
			game->player.pos.y = player_pos.y * game->minimap.block;
	if (data->map[player_pos.y + 1][player_pos.x] == '1')
		if (game->player.pos.y < player_pos.y)
			game->player.pos.y = player_pos.y * game->minimap.block;
}

