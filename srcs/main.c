#include "fdf.h"

void	init_window(t_wireframe *wireframe)
{
	wireframe->win_ptr = mlx_new_window(wireframe->mlx_ptr, WIDTH, HEIGHT, "fdf");
	wireframe->img_ptr = mlx_new_image(wireframe->mlx_ptr, WIDTH, HEIGHT);
	wireframe->data_addr = (unsigned char *)mlx_get_data_addr(wireframe->img_ptr, &(wireframe->bits_per_pixel), &(wireframe->size), &(wireframe->endian));
}

void	display_window(t_wireframe *wireframe)
{
	mlx_put_image_to_window(wireframe->mlx_ptr, wireframe->win_ptr, wireframe->img_ptr, 0, 0);
	mlx_loop(wireframe->mlx_ptr);
}

int main(int ac, char **av)
{
	t_wireframe *wireframe;

	wireframe = 0;
	if (ac != 2)
	{
		print_error(22);
		return (1);
	}
	wireframe = parsing(av[1]);
	if (!wireframe)
		return (1);
	init_window(wireframe);
	fill_window(wireframe);
	mlx_hook(wireframe->win_ptr, 2, 1L << 0, ft_event, &wireframe);
	if (!LINUX)
		mlx_hook(wireframe->win_ptr, 17, 1L << 17, ft_cross, &wireframe);
	else
		mlx_hook(wireframe->win_ptr, 33, 1L << 5, ft_cross, &wireframe);
	mlx_loop_hook(wireframe->mlx_ptr, ft_event, &wireframe);
	display_window(wireframe);
	return (0);
}