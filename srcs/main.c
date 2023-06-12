#include <stdio.h>

#include "mlx.h"
#include "data.h"

void	init(t_data data);

int	main()
{
	t_data	data;
	// void  *m = mlx_init();
	// void *win = mlx_new_window(m, 222, 222, "test");
	// mlx_loop(m);

	init(data);
	return (0);
}
