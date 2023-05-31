#include <stdio.h>
#include "libft.h"
#include "mlx.h"

int	main()
{
	printf("Hello World!\n");
	void *mlx = mlx_init();
	printf("Hello World!\n");
    void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window");
	printf("Hello World!\n");
    mlx_loop(mlx);

	return (0);
}
