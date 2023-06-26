#include "draw.h"
#include "color.h"
#include "game2d.h"
#include "keycodes.h"

void	draw_player(t_data *data, t_game *game);
void	move_player(t_data *data, t_game *game);
void	check_collisions_x(t_data *data, t_minimap *minimap, t_player *player);
void	check_collisions_y(t_data *data, t_minimap *minimap, t_player *player);
bool	collide_rect(t_rect rect1, t_rect rect2);

void	update_player(t_data *data, t_game *game)
{
	draw_player(data, game);
	move_player(data, game);
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
	check_collisions_y(data, &game->minimap, &game->player);
	if (data->key_pressed[K_A])
		game->player.pos.x -= game->player.speed * data->dt;
	if (data->key_pressed[K_D])
		game->player.pos.x += game->player.speed * data->dt;
	check_collisions_x(data, &game->minimap, &game->player);
}

void	check_collisions_x(t_data *data, t_minimap *minimap, t_player *player)
{
	int			i;

	i = -1;
	while (++i < minimap->walls_count)
	{
		if (collide_rect((t_rect){(int)player->pos.x, (int)player->pos.y,
				(int)player->size, (int)player->size}, minimap->walls[i].rect))
		{
			if (player->pos.x < minimap->walls[i].rect.pos.x)
				player->pos.x = minimap->walls[i].rect.pos.x - player->size;
			else
				player->pos.x = minimap->walls[i].rect.pos.x
					+ minimap->walls[i].rect.size.x;
		}
	}
}

void	check_collisions_y(t_data *data, t_minimap *minimap, t_player *player)
{
	int			i;

	i = -1;
	while (++i < minimap->walls_count)
	{
		if (collide_rect((t_rect){(int)player->pos.x, (int)player->pos.y,
				(int)player->size, (int)player->size}, minimap->walls[i].rect))
		{
			if (player->pos.y < minimap->walls[i].rect.pos.y)
				player->pos.y = minimap->walls[i].rect.pos.y - player->size;
			else
				player->pos.y = minimap->walls[i].rect.pos.y
					+ minimap->walls[i].rect.size.y;
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
