/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:18:56 by ndemont           #+#    #+#             */
/*   Updated: 2021/11/26 12:21:44 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_window(t_wireframe *wireframe)
{
	mlx_put_image_to_window(wireframe->window.mlx_ptr, wireframe->window.win_ptr, wireframe->window.img_ptr, 0, 0);
	mlx_loop(wireframe->window.mlx_ptr);
}

void	fill_window(t_wireframe *w)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (y < w->y_len)
	{
		x = 0;
		while (x < w->x_len)
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
