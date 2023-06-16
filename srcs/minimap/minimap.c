#include "data.h"
#include "draw.h"

void	draw_minimap(t_img *img)
{
	t_minimap	minimap;
	t_player	player;
	int			height;
	int			width;

	height = -1;
	minimap = (t_minimap){20, 20, 8, 8};
	player = (t_player){0, 0, 8, 8, 4};
	while (++height < data->map.height) // TODO where is the height?
	{
		width = -1;
		while (++width < data->map.width) // TODO where is the width?
		{
			if (1)
			else if (0)
			else if (N, S, E, O)
			{
				//save the position
				// draw
			}
			else if (' ')

		}

	}
}

// position évolue chaque fois de 8.
// speed utile pour les hooks, pas pour le dessin
// voir comment on gère les espaces
