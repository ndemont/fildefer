/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:18:56 by ndemont           #+#    #+#             */
/*   Updated: 2021/11/30 14:41:32 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_window(t_wireframe *w)
{
	mlx_put_image_to_window(w->window.mlx_ptr, \
	w->window.win_ptr, w->window.img_ptr, 0, 0);
	mlx_loop(w->window.mlx_ptr);
}

void	fill_window(t_wireframe *w)
{
	int	x;
	int	y;

	y = 0;
	while (y < (int)w->y_len)
	{
		x = 0;
		while (x < (int)w->x_len)
		{
			if (w->map[y][x].x >= 0 && w->map[y][x].x < WIDTH)
			{
				if (w->map[y][x].y >= 0 && w->map[y][x].y < HEIGHT)
				{
					if (y < w->y_len - 1)
						draw_wire(w, w->map[y][x], w->map[y + 1][x]);
					if (x < w->x_len - 1)
						draw_wire(w, w->map[y][x], w->map[y][x + 1]);
				}
			}
			x++;
		}
		y++;
	}
}
