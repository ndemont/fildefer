#include "fdf.h"

t_img	ft_new_img(t_wireframe *w)
{
	t_img img;

	img.img_ptr = mlx_new_image(w->mlx_ptr, WIDTH, HEIGHT);
	s->data_addr = (unsigned char *)mlx_get_data_addr(img.img_ptr, &(w->bits_per_pixel), &(w->size), &(w->endian));
	fill_window(w)
	return (img);
}


static void		ft_print_w(t_wireframe *w)
{
	t_img image;

	image = ft_new_img(w);
	print_window(w->mlx_ptr, w->win_ptr, image.img_ptr);
}

// int				ft_apply_filter(int keycode, t_wireframe *w)
// {
// 	if (keycode == FILTER)
// 	{
// 		if (s->filter < 5)
// 			s->filter++;
// 		else
// 			s->filter = 0;
// 		ft_print_w(s);
// 	}
// 	return (1);
// }

int				ft_event(int keycode, t_wireframe *w)
{
	if (!ft_close_win(keycode, s))
	{
		free_scene(0, s);
		exit(0);
	}
	// ft_switch_cam(keycode, s);
	// ft_apply_filter(keycode, s);
	ft_move_cam(keycode, s);
	return (1);
}

void			ft_move_cam(int keycode, t_wireframe *w)
{
	if (keycode == MOVE_L)
	{
		s->cameras[s->cam_i].o.coord[0] = s->cameras[s->cam_i].o.coord[0] + 5;
		ft_print_w(s);
	}
	if (keycode == MOVE_R)
	{
		s->cameras[s->cam_i].o.coord[0] = s->cameras[s->cam_i].o.coord[0] - 5;
		ft_print_w(s);
	}
	if (keycode == MOVE_F)
	{
		s->cameras[s->cam_i].o.coord[2] = s->cameras[s->cam_i].o.coord[2] - 5;
		ft_print_w(s);
	}
	if (keycode == MOVE_B)
	{
		s->cameras[s->cam_i].o.coord[2] = s->cameras[s->cam_i].o.coord[2] + 5;
		ft_print_w(s);
	}
}