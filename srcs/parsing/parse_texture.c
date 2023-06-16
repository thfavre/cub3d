#include <stdbool.h>
#include <stdlib.h>

#include <mlx.h>
#include "libft.h"
#include "sprite.h"

void	free_split(char **split);


bool	parse_texture(void *mlx, char *line, t_sprite *sprite, char *expected_name)
{
	char	**splited_line;

	if (line == NULL)
		return (false);
	splited_line = ft_split(line, ' '); // free this when needed
	free(line);
	if (splited_line == NULL)
		return (false);
	if (ft_strcmp(splited_line[0], expected_name) != 0)
	{
		printf("Error, expected '%s' but got '%s'\n", expected_name, splited_line[0]);
		return (false);
	}
	if (splited_line[1] == NULL)
	{
		printf("Error, expected a path after '%s'\n", expected_name);
		return (false);
	}
	if (splited_line[1][ft_strlen(splited_line[1]) - 1] == '\n')
		splited_line[1][ft_strlen(splited_line[1]) - 1] = '\0';
	sprite->img = mlx_xpm_file_to_image(mlx, splited_line[1], &sprite->size.x, &sprite->size.y);
	if (sprite->img == NULL)
	{
		printf("Error, invalid path '%s'\n", splited_line[1]);
		return (false);
	}
	free_split(splited_line);
	return (true);
}
