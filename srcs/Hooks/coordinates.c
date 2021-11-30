/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:30:36 by ndemont           #+#    #+#             */
/*   Updated: 2021/11/30 15:19:44 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_x(t_wireframe *w, int shift)
{
	int	x;
	int	y;

	y = 0;
	while (y < w->y_len)
	{
		x = 0;
		while (x < w->x_len)
		{
			w->map[y][x].x += shift;
			x++;
		}
		y++;
	}
}

void	move_y(t_wireframe *w, int shift)
{
	int	x;
	int	y;

	y = 0;
	while (y < w->y_len)
	{
		x = 0;
		while (x < w->x_len)
		{
			w->map[y][x].y += shift;
			x++;
		}
		y++;
	}
}

void	coordinates(int keycode, t_wireframe *w)
{
	if (keycode == MOVE_L)
		ft_print_w(w, 1, 10);
	if (keycode == MOVE_R)
		ft_print_w(w, 1, -10);
	if (keycode == MOVE_U)
		ft_print_w(w, 0, 10);
	if (keycode == MOVE_D)
		ft_print_w(w, 0, -10);
}
