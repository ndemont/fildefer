#include "fdf.h"

static void	ft_print_w(t_wireframe *w)
{
	w->window.img_ptr = mlx_new_image(w->window.mlx_ptr, WIDTH, HEIGHT);
	w->window.data_addr = mlx_get_data_addr(w->window.img_ptr, &(w->window.bits_per_pixel), &(w->window.size), &(w->window.endian));
	move_x(w, 10);
	fill_window2(w);
	display_window(w);
}

int	ft_event(int keycode, t_wireframe *w)
{
	if (!ft_close_win(keycode, w))
	{
		printf("keycode = %d\n", keycode);
		exit(0);
	}
	//printf("keycode = %d\n", keycode);
	ft_move_cam(keycode, w);
	return (1);
}

void	ft_move_cam(int keycode, t_wireframe *w)
{
	if (keycode == MOVE_L)
	{
		printf("keycode = %d\n", keycode);
		//ft_print_w(w);
	}
	if (keycode == MOVE_R)
	{
		printf("keycode = %d\n", keycode);
		//ft_print_w(w);
	}
	if (keycode == MOVE_F)
	{
		printf("keycode = %d\n", keycode);
		//t_print_w(w);
	}
	if (keycode == MOVE_B)
	{
		printf("keycode = %d\n", keycode);
		//ft_print_w(w);
	}
}

int		ft_cross(int keycode, t_wireframe *w)
{
   	printf("keycode = %d\n", keycode);
	(void)keycode;
	(void)w;
	exit(0);
}

int		ft_close_win(int keycode, t_wireframe *w)
{
	(void)w;
	if (keycode == ESC)
		return (0);
	return (1);
}