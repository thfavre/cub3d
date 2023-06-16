#include <stdlib.h>

void *free_map(char **map)
{
	int	i;

	if (map == NULL)
		return (NULL);
	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}
