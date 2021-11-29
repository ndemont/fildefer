#include "fdf.h"

static void	ft_print_w(t_wireframe *w, int x, int shift)
{
	w->window.img_ptr = mlx_new_image(w->window.mlx_ptr, WIDTH, HEIGHT);
	w->window.data_addr = mlx_get_data_addr(w->window.img_ptr, &(w->window.bits_per_pixel), &(w->window.size), &(w->window.endian));
	if (x)
		move_x(w, shift);
	else
		move_y(w, shift);
	fill_window(w);
	display_window(w);
}

static void	ft_print_zoom(t_wireframe *w, int x, float zoom)
{
	w->window.img_ptr = mlx_new_image(w->window.mlx_ptr, WIDTH, HEIGHT);
	w->window.data_addr = mlx_get_data_addr(w->window.img_ptr, &(w->window.bits_per_pixel), &(w->window.size), &(w->window.endian));
	w->x_center = WIDTH / 2;
	w->y_center = HEIGHT / 2;
	zoom2_map(w, zoom);
	center_map(w);
	fill_window(w);
	display_window(w);
}

int	ft_event(int keycode, t_wireframe *w)
{
	if (!ft_close_win(keycode, w))
	{
		printf("keycode = %d\n", keycode);
		exit(0);
	}
	ft_move_cam(keycode, w);
	return (1);
}

void	ft_move_cam(int keycode, t_wireframe *w)
{
	printf("keycode = %d\n", keycode);
	if (keycode == MOVE_L)
	{
		printf("keycode = %d\n", keycode);
		ft_print_w(w, 1, 10);
	}
	if (keycode == MOVE_R)
	{
		printf("keycode = %d\n", keycode);
		ft_print_w(w, 1, -10);
	}
	if (keycode == MOVE_F)
	{
		printf("keycode = %d\n", keycode);
		ft_print_w(w, 0, 10);
	}
	if (keycode == MOVE_B)
	{
		printf("keycode = %d\n", keycode);
		ft_print_w(w, 0, -10);
	}
	if (keycode == ZOOM_IN)
	{
		printf("keycode = %d\n", keycode);
		ft_print_zoom(w, 0, 1.1);
	}
	if (keycode == ZOOM_OUT)
	{
		printf("keycode = %d\n", keycode);
		ft_print_zoom(w, 0, 0.9);
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