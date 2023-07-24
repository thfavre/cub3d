#include "draw.h"
#include "color.h"
#include "game2d.h"
#include "keycodes.h"

void	move_player(t_data *data, t_player *player);
void	rotate_player(t_data *data, t_player *player);

void	update_player(t_data *data, t_player *player)
{
	move_player(data, player);
	rotate_player(data, player);
}

void	move_player(t_data *data, t_player *player)
{
	double	distance;

	distance = player->speed * data->dt;
	if (data->key_pressed[K_W])
		player->fpos.y -= sin(player->angle) * distance;
	if (data->key_pressed[K_S])
		player->fpos.y += sin(player->angle) * distance;
	if (data->key_pressed[K_A])
		player->fpos.y -= sin(player->angle + M_PI_2) * distance;
	if (data->key_pressed[K_D])
		player->fpos.y += sin(player->angle + M_PI_2) * distance;
	check_collisions_y(&data->game2d, player);
	if (data->key_pressed[K_W])
		player->fpos.x += cos(player->angle) * distance;
	if (data->key_pressed[K_S])
		player->fpos.x -= cos(player->angle) * distance;
	if (data->key_pressed[K_A])
		player->fpos.x += cos(player->angle + M_PI_2) * distance;
	if (data->key_pressed[K_D])
		player->fpos.x -= cos(player->angle + M_PI_2) * distance;
	check_collisions_x(&data->game2d, player);
	player->pos.x = (int)player->fpos.x;
	player->pos.y = (int)player->fpos.y;
}

void	rotate_player(t_data *data, t_player *player)
{
	if (data->key_pressed[K_RIGHT])
	{
		player->angle -= PLAYER_ROTATE_SPEED * data->dt;
		if (player->angle < 0)
			player->angle += 2 * M_PI;
	}
	if (data->key_pressed[K_LEFT])
	{
		player->angle += PLAYER_ROTATE_SPEED * data->dt;
		if (player->angle > 2 * M_PI)
			player->angle -= 2 * M_PI;
	}
}
