/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:26:56 by ndemont           #+#    #+#             */
/*   Updated: 2021/11/30 21:01:13 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_hook_map(t_wireframe *w, float zoom)
{
	int	x;
	int	y;

	y = 0;
	while (y < w->y_len)
	{
		x = 0;
		while (x < (int)w->x_len)
		{
			reset_center(w, x, y, zoom);
			w->map[y][x].x = (w->map[y][x].x * cosf(45.0)) - (w->map[y][x].y * sinf(45.0));
			w->map[y][x].y = (w->map[y][x].x * sinf(45.0)) + (w->map[y][x].y * cosf(45.0));
			//w->map[y][x].x *= zoom;
			//w->map[y][x].y *= zoom;
			update_limits(w, w->map[y][x].x, w->map[y][x].y, w->map[y][x].z);
			x++;
		}
		y++;
	}
	center_map(w);
}

static void	ft_print_zoom(t_wireframe *w, int x, float zoom)
{
	w->window.img_ptr = mlx_new_image(w->window.mlx_ptr, WIDTH, HEIGHT);
	w->window.data_addr = mlx_get_data_addr(w->window.img_ptr, \
	&(w->window.bits_per_pixel), &(w->window.size), &(w->window.endian));
	w->x_center = WIDTH / 2;
	w->y_center = HEIGHT / 2;
	zoom_hook_map(w, zoom);
	center_map(w);
	fill_window(w);
	display_window(w);
}

void	zoom(int keycode, t_wireframe *w)
{
	if (keycode == ZOOM_IN)
		ft_print_zoom(w, 0, 1.1);
	if (keycode == ZOOM_OUT)
		ft_print_zoom(w, 0, 0.9);
}
