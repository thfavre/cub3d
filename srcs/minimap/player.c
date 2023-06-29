#include "draw.h"
#include "color.h"
#include "game2d.h"
#include "keycodes.h"

void	move_player(t_data *data, t_player *player);
void	check_collisions_x(t_game2d *game2d, t_player *player);
void	check_collisions_y(t_game2d *game2d, t_player *player);
bool	collide_rect(t_rect rect1, t_rect rect2);

void	update_player(t_data *data, t_player *player)
{
	move_player(data, player);
}

void	move_player(t_data *data, t_player *player)
{
	if (data->key_pressed[K_W])
		player->pos.y -= player->speed * data->dt;
	if (data->key_pressed[K_S])
		player->pos.y += player->speed * data->dt;
	check_collisions_y(&data->game2d, player);
	if (data->key_pressed[K_A])
		player->pos.x -= player->speed * data->dt;
	if (data->key_pressed[K_D])
		player->pos.x += player->speed * data->dt;
	check_collisions_x(&data->game2d, player);
}

void	check_collisions_x(t_game2d *game2d, t_player *player)
{
	int			i;

	i = -1;
	while (++i < game2d->walls_count)
	{
		if (collide_rect((t_rect){(int)player->pos.x, (int)player->pos.y,
				(int)player->size.x, (int)player->size.y},
			game2d->walls[i].rect))
		{
			if (player->pos.x < game2d->walls[i].rect.pos.x)
				player->pos.x = game2d->walls[i].rect.pos.x - player->size.x;
			else
				player->pos.x = game2d->walls[i].rect.pos.x
					+ game2d->walls[i].rect.size.x;
		}
	}
}

void	check_collisions_y(t_game2d *game2d, t_player *player)
{
	int			i;

	i = -1;
	while (++i < game2d->walls_count)
	{
		if (collide_rect((t_rect){(int)player->pos.x, (int)player->pos.y,
				player->size.x, player->size.y},
			game2d->walls[i].rect))
		{
			if (player->pos.y < game2d->walls[i].rect.pos.y)
				player->pos.y = game2d->walls[i].rect.pos.y - player->size.y;
			else
				player->pos.y = game2d->walls[i].rect.pos.y
					+ game2d->walls[i].rect.size.y;
		}
	}
}

bool	collide_rect(t_rect rect1, t_rect rect2)
{
	if (rect1.pos.x < rect2.pos.x + rect2.size.x
		&& rect1.pos.x + rect1.size.x > rect2.pos.x
		&& rect1.pos.y < rect2.pos.y + rect2.size.y
		&& rect1.pos.y + rect1.size.y > rect2.pos.y)
		return (true);
	return (false);
}
