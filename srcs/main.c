#include "fdf.h"

//void	init_window(t_wireframe *wireframe)
//{
//	wireframe->window.win_ptr = mlx_new_window(wireframe->window.mlx_ptr, WIDTH, HEIGHT, "fdf");
//	wireframe->window.img_ptr = mlx_new_image(wireframe->window.mlx_ptr, WIDTH, HEIGHT);
//	wireframe->window.data_addr = (unsigned char *)mlx_get_data_addr(wireframe->window.img_ptr, &(wireframe->window.bits_per_pixel), &(wireframe->window.size), &(wireframe->window.endian));
//}

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
	// init_window(&wireframe);
	// fill_window(&wireframe);
	// mlx_hook(&wireframe.window.win_ptr, 2, 1L << 0, ft_event, &wireframe);
	// if (!LINUX)
	// 	mlx_hook(&wireframe.window.win_ptr, 17, 1L << 17, ft_cross, &wireframe);
	// else
	// 	mlx_hook(&wireframe.window.win_ptr, 33, 1L << 5, ft_cross, &wireframe);
	// mlx_loop_hook(&wireframe.window.mlx_ptr, ft_event, &wireframe);
	// display_window(&wireframe);
	return (0);
}