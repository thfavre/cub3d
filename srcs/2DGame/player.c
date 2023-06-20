#include "draw.h"
#include "vector2.h"

#include "2DGame.h"
#include "keycodes.h"

// ---- FOR MAKE THE PLAYER ALIVE ----//
void	move_player(bool *keypressed, t_player *player, t_obstacles obstacles, float dt);

void	update_player(t_img *img, bool *keypressed, t_player *player, t_obstacles obstacles, float dt)
{
	move_player(keypressed, player, obstacles, dt);
	draw_rect(img, (t_rect){player->pos.x, player->pos.y, player->size, player->size}, C_GOLD3);
}

// returns true if the two rect collide
bool	collide_rect(t_rect rect1, t_rect rect2)
{
	if (rect1.pos.x < rect2.pos.x + rect2.size.x &&
		rect1.pos.x + rect1.size.x > rect2.pos.x &&
		rect1.pos.y < rect2.pos.y + rect2.size.y &&
		rect1.pos.y + rect1.size.y > rect2.pos.y)
		return (true);
	return (false);
}


void	move_player(bool *keypressed, t_player *player, t_obstacles obstacles, float dt)
{
	int		i;
	// move y
	if (keypressed[K_W])
		player->pos.y -= player->moving_speed * dt;
	else if (keypressed[K_S])
		player->pos.y += player->moving_speed * dt;
	// check collision y
	i = 0;
	while (i < obstacles.number)
	{
		if (collide_rect((t_rect){player->pos.x, player->pos.y, player->size, player->size}, obstacles.rects[i]))
		{
			if (player->pos.y < obstacles.rects[i].pos.y)
				player->pos.y = obstacles.rects[i].pos.y - player->size;
			else
				player->pos.y = obstacles.rects[i].pos.y + obstacles.rects[i].size.y;
		}
		i++;
	}
	// move x
	if (keypressed[K_A])
		player->pos.x -= player->moving_speed * dt;
	else if (keypressed[K_D])
		player->pos.x += player->moving_speed * dt;
	// check collision x
	i = 0;
	while (i < obstacles.number)
	{
		if (collide_rect((t_rect){player->pos.x, player->pos.y, player->size, player->size}, obstacles.rects[i]))
		{
			if (player->pos.x < obstacles.rects[i].pos.x)
				player->pos.x = obstacles.rects[i].pos.x - player->size;
			else
				player->pos.x = obstacles.rects[i].pos.x + obstacles.rects[i].size.x;
		}
		i++;
	}
}

// ---- FOR INITIALIZING THE PLAYER ----//

t_vector2	get_player_starting_cell(char **map)
{
	t_vector2	cell_pos;
	char		type;

	cell_pos.y = 0;
	while (map[cell_pos.y])
	{
		cell_pos.x = 0;
		while (map[cell_pos.y][cell_pos.x])
		{
			type = map[cell_pos.y][cell_pos.x];
			if (type == 'N' || type == 'S' || type == 'E' || type == 'W')
				return (cell_pos);
			cell_pos.x++;
		}
		cell_pos.y++;
	}
	printf("The player has no starting position, this code should never be executed...\n");
	return (cell_pos);
}


void	init_player(t_player *player, char **map)
{
	t_vector2	starting_cell;

	starting_cell = get_player_starting_cell(map);
	player->pos = (t_fvector2){starting_cell.x * CELL_SIZE, starting_cell.y * CELL_SIZE};
	player->size = CELL_SIZE * 0.75;
	player->moving_speed = 500; // use the dt in move_player to make it framerate independent
}



