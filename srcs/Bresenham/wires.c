/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wires.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:28:17 by ndemont           #+#    #+#             */
/*   Updated: 2021/11/27 13:03:33 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	linear_absciss(t_wireframe *w, t_point p1, t_point p2, int direction)
{
	while ((int)p1.y != (int)p2.y)
	{
		draw_pixel(w, p1, p1, p1);
		p1.y += direction;
	}
}

void	linear_ordinate(t_wireframe *w, t_point p1, t_point p2, int direction)
{
	while ((int)p1.x != (int)p2.x)
	{
		draw_pixel(w, p1, p1, p1);
		p1.x += direction;
	}
}

void	positive_absciss(t_wireframe *w, t_point p1, t_point p2, int dy)
{
	if (dy != 0)
	{
		if (dy > 0)
			first_dial(w, p1, p2);
		else
			forth_dial(w, p1, p2);
	}
	else
		linear_ordinate(w, p1, p2, 1);
}

void	negative_absciss(t_wireframe *w, t_point p1, t_point p2, int dy)
{
	if (dy != 0)
	{
		if (dy > 0)
			second_dial(w, p1, p2);
		else
			third_dial(w, p1, p2);
	}
	else
		linear_ordinate(w, p1, p2, -1);
}

void	draw_wire(t_wireframe *w, t_point p1, t_point p2)
{
	int		dx;
	int		dy;

	dx = (int)p2.x - (int)p1.x;
	dy = (int)p2.y - (int)p1.y;
	if (dx != 0)
	{
		if (dx > 0)
			positive_absciss(w, p1, p2, dy);
		else
			negative_absciss(w, p1, p2, dy);
	}
	else
	{
		if (dy != 0)
		{
			if (dy > 0)
				linear_absciss(w, p1, p2, 1);
			else
				linear_absciss(w, p1, p2, -1);
		}
	}
}
