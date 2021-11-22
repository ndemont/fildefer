#include "fdf.h"

void	ft_new_img(t_wireframe *w)
{
	w->img_ptr = mlx_new_image(w->mlx_ptr, WIDTH, HEIGHT);
	w->data_addr = (unsigned char *)mlx_get_data_addr(w->img_ptr, &(w->bits_per_pixel), &(w->size), &(w->endian));
	fill_window(w);
}


static void		ft_print_w(t_wireframe *w)
{
	ft_new_img(w);
	display_window(w);
}

int				ft_event(int keycode, t_wireframe *w)
{
	if (!ft_close_win(keycode, w))
	{
		exit(0);
	}
	return (1);
}

void			ft_move_cam(int keycode, t_wireframe *w)
{
	if (keycode == MOVE_L)
	{
    	printf("keycode = %d\n", keycode);
		ft_print_w(w);
	}
	if (keycode == MOVE_R)
	{
   		printf("keycode = %d\n", keycode);
		ft_print_w(w);
	}
	if (keycode == MOVE_F)
	{
    	printf("keycode = %d\n", keycode);
		ft_print_w(w);
	}
	if (keycode == MOVE_B)
	{
   		printf("keycode = %d\n", keycode);
		ft_print_w(w);
	}
}

int		ft_cross(int keycode, t_wireframe *w)
{
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