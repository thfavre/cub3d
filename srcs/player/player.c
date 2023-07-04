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
		player->pos.y -= sin(player->angle) * distance;
	if (data->key_pressed[K_S])
		player->pos.y += sin(player->angle) * distance;
	if (data->key_pressed[K_A])
		player->pos.y -= sin(player->angle + M_PI_2) * distance;
	if (data->key_pressed[K_D])
		player->pos.y += sin(player->angle + M_PI_2) * distance;
	check_collisions_y(&data->game2d, player);
	if (data->key_pressed[K_W])
		player->pos.x += cos(player->angle) * distance;
	if (data->key_pressed[K_S])
		player->pos.x -= cos(player->angle) * distance;
	if (data->key_pressed[K_A])
		player->pos.x += cos(player->angle + M_PI_2) * distance;
	if (data->key_pressed[K_D])
		player->pos.x -= cos(player->angle + M_PI_2) * distance;
	check_collisions_x(&data->game2d, player);
}

void	rotate_player(t_data *data, t_player *player)
{
	if (data->key_pressed[K_LEFT])
	{
		player->angle -= 15 * data->dt;
		if (player->angle < 0)
			player->angle += 2 * M_PI;
	}
	if (data->key_pressed[K_RIGHT])
	{
		player->angle += 15 * data->dt;
		if (player->angle > 2 * M_PI)
			player->angle -= 2 * M_PI;
	}
}
