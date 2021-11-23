#include "fdf.h"

void	display_window(t_wireframe *wireframe)
{
	mlx_put_image_to_window(wireframe->window.mlx_ptr, wireframe->window.win_ptr, wireframe->window.img_ptr, 0, 0);
	mlx_loop(wireframe->window.mlx_ptr);
}

int main(int ac, char **av)
{
	t_wireframe wireframe;

	if (ac != 2)
	{
		print_error(22);
		return (1);
	}
	if (!parsing(av[1], &wireframe))
		return (1);
	set_map(&wireframe, X_SHIFT, Y_SHIFT, ZOOM);
	fill_window(&wireframe);
	display_window(&wireframe);
	return (0);
}