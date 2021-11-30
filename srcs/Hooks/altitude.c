/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altitude.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:22:59 by ndemont           #+#    #+#             */
/*   Updated: 2021/11/30 15:19:19 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	amplitude_map(t_wireframe *w, float zoom)
{
	int	x;
	int	y;

	y = 0;
	while (y < w->y_len)
	{
		x = 0;
		while (x < (int)w->x_len)
		{
			w->map[y][x].y += w->map[y][x].z * zoom;
			x++;
		}
		y++;
	}
}

static void	ft_print_altitude(t_wireframe *w, float shift)
{
	w->window.img_ptr = mlx_new_image(w->window.mlx_ptr, WIDTH, HEIGHT);
	w->window.data_addr = mlx_get_data_addr(w->window.img_ptr, \
	&(w->window.bits_per_pixel), &(w->window.size), &(w->window.endian));
	amplitude_map(w, shift);
	fill_window(w);
	display_window(w);
}

void	altitude(int keycode, t_wireframe *w)
{
	if (keycode == WIDE)
		ft_print_altitude(w, 0.1);
	if (keycode == NARROW)
		ft_print_altitude(w, -0.1);
}
