/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tastybao <tastybao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 21:15:13 by tastybao          #+#    #+#             */
/*   Updated: 2023/07/26 21:15:14 by tastybao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "game2d.h"

bool	collide_rect(t_rect rect1, t_rect rect2);

void	check_collisions_x(t_game2d *game2d, t_player *player)
{
	int			i;

	i = -1;
	while (++i < game2d->walls_count)
	{
		if (collide_rect((t_rect){(int)player->fpos.x, (int)player->fpos.y,
				(int)player->size.x, (int)player->size.y},
			game2d->walls[i].rect))
		{
			if (player->fpos.x < game2d->walls[i].rect.pos.x)
				player->fpos.x = game2d->walls[i].rect.pos.x - player->size.x;
			else
				player->fpos.x = game2d->walls[i].rect.pos.x
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
		if (collide_rect((t_rect){(int)player->fpos.x, (int)player->fpos.y,
				player->size.x, player->size.y},
			game2d->walls[i].rect))
		{
			if (player->fpos.y < game2d->walls[i].rect.pos.y)
				player->fpos.y = game2d->walls[i].rect.pos.y - player->size.y;
			else
				player->fpos.y = game2d->walls[i].rect.pos.y
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
