#include "fdf.h"

static void		ft_print_w(t_wireframe *w)
{
	printf("printing new wind\n");
	printf("w->mlx_ptr = %p\n", w->mlx_ptr);
	w->img_ptr = mlx_new_image(w->mlx_ptr, WIDTH, HEIGHT);
	printf("1\n");
	w->data_addr = (unsigned char *)mlx_get_data_addr(w->img_ptr, &(w->bits_per_pixel), &(w->size), &(w->endian));
	printf("2\n");
	
	move_x(w, 10);
	printf("3\n");
	
	fill_window2(w);
	printf("4\n");
	
	display_window(w);
}

int				ft_event(int keycode, t_wireframe *w)
{
	if (!ft_close_win(keycode, w))
	{
    	printf("keycode = %d\n", keycode);
		exit(0);
	}
	ft_move_cam(keycode, w);
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
		//move_x(w, -10);
		ft_print_w(w);
	}
	if (keycode == MOVE_F)
	{
    	printf("keycode = %d\n", keycode);
		//move_y(w, 10);
		ft_print_w(w);
	}
	if (keycode == MOVE_B)
	{
		//move_y(w, -10);
   		printf("keycode = %d\n", keycode);
		ft_print_w(w);
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