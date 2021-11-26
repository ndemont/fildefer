/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wire.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:28:17 by ndemont           #+#    #+#             */
/*   Updated: 2021/11/26 12:29:30 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pixel(t_wireframe *w, t_point	p, char	*s)
{
	w->pixel.r = (char)255;
	w->pixel.g = (char)255;
	w->pixel.b = (char)255;
	color_pixel(w, p.z);
	w->pixel.p = ((HEIGHT - ((int)p.y)) * w->window.size) + ((WIDTH - ((int)p.x)) * 4);
	w->window.data_addr[w->pixel.p + 2] = w->pixel.r;
	w->window.data_addr[w->pixel.p + 1] = w->pixel.g;
	w->window.data_addr[w->pixel.p + 0] = w->pixel.b;
}

void	first_octant(t_wireframe *w, t_point p1, t_point p2)
{
	int		dx;
	int		dy;
	float	e;

	dx = (int)p2.x - (int)p1.x;
	dy = (int)p2.y - (int)p1.y;
	e = dx;
	dx = dx * 2 ;
	dy = dy * 2 ;
	while ((int)p1.x != (int)p2.x)
	{
		draw_pixel(w, p1, 0);
		e -= dy;
		if (e < 0)
		{
			p1.y += 1;
			e += dx;
		}
		p1.x += 1;
	}
}

void	second_octant(t_wireframe *w, t_point p1, t_point p2)
{
	int		dx;
	int		dy;
	float	e;

	dx = (int)p2.x - (int)p1.x;
	dy = (int)p2.y - (int)p1.y;
	e = dy;
	dy = dy * 2;
	dx = dx * 2;
	while ((int)p1.y != (int)p2.y)
	{
		draw_pixel(w, p1, 0);
		e -= dx;
		if (e < 0)
		{
			p1.x += 1;
			e += dy;
		}
		p1.y += 1;
	}
}

void	eighth_octant(t_wireframe *w, t_point p1, t_point p2)
{
	int		dx;
	int		dy;
	float	e;

	dx = (int)p2.x - (int)p1.x;
	dy = (int)p2.y - (int)p1.y;
	e = dx;
	dx = dx * 2;
	dy = dy * 2;
	while ((int)p1.x != (int)p2.x)
	{
		draw_pixel(w, p1, 0);
		e += dy;
		if (e < 0)
		{
			p1.y -= 1;
			e += dx;
		}
		p1.x += 1;
	}
}

void	seventh_octant(t_wireframe *w, t_point p1, t_point p2)
{
	int		dx;
	int		dy;
	float	e;

	dx = (int)p2.x - (int)p1.x;
	dy = (int)p2.y - (int)p1.y;
	e = dy;
	dy = dy * 2;
	dx = dx * 2;
	while ((int)p1.y != (int)p2.y)
	{
		draw_pixel(w, p1, 0);
		e += dx;
		if (e > 0)
		{
			p1.x += 1;
			e += dy;
		}
		p1.y -= 1;
	}
}

void	forth_octant(t_wireframe *w, t_point p1, t_point p2)
{
	int		dx;
	int		dy;
	float	e;

	dx = (int)p2.x - (int)p1.x;
	dy = (int)p2.y - (int)p1.y;
	e = dx;
	dy = dy * 2;
	dx = dx * 2;
	while ((int)p1.x != (int)p2.x)
	{
		draw_pixel(w, p1, 0);
		e += dy;
		if (e >= 0)
		{
			p1.y += 1;
			e += dx;
		}
		p1.x -= 1;
	}
}

void	third_octant(t_wireframe *w, t_point p1, t_point p2)
{
	int		dx;
	int		dy;
	float	e;

	dx = (int)p2.x - (int)p1.x;
	dy = (int)p2.y - (int)p1.y;
	e = dy;
	dy = dy * 2;
	dx = dx * 2;
	while ((int)p1.y != (int)p2.y)
	{
		draw_pixel(w, p1, 0);
		e += dx;
		if (e <= 0)
		{
			p1.x -= 1;
			e += dy;
		}
		p1.y += 1;
	}
}

void	fifth_octant(t_wireframe *w, t_point p1, t_point p2)
{
	int		dx;
	int		dy;
	float	e;

	dx = (int)p2.x - (int)p1.x;
	dy = (int)p2.y - (int)p1.y;
	e = dx;
	dx = dx * 2;
	dy = dy * 2;
	while ((int)p1.x != (int)p2.x)
	{
		draw_pixel(w, p1, 0);
		e -= dy;
		if (e >= 0)
		{
			p1.y -= 1;
			e += dx;
		}
		p1.x -= 1;
	}
}

void	sixth_octant(t_wireframe *w, t_point p1, t_point p2)
{
	int		dx;
	int		dy;
	float	e;

	dx = (int)p2.x - (int)p1.x;
	dy = (int)p2.y - (int)p1.y;
	e = dy;
	dx = dx * 2;
	dy = dy * 2;
	while ((int)p1.y != (int)p2.y)
	{
		draw_pixel(w, p1, 0);
		e -= dx;
		if (e >= 0)
		{
			p1.x -= 1;
			e += dy;
		}
		p1.y -= 1;
	}
}

void	first_dial(t_wireframe *w, t_point p1, t_point p2)
{
	int		dx;
	int		dy;

	dx = (int)p2.x - (int)p1.x;
	dy = (int)p2.y - (int)p1.y;
	if (dx >= dy)
		first_octant(w, p1, p2);
	else
		second_octant(w, p1, p2);
}

void	second_dial(t_wireframe *w, t_point p1, t_point p2)
{
	int		dx;
	int		dy;

	dx = (int)p2.x - (int)p1.x;
	dy = (int)p2.y - (int)p1.y;
	if (-dx >= dy)
		forth_octant(w, p1, p2);
	else
		third_octant(w, p1, p2);
}

void	third_dial(t_wireframe *w, t_point p1, t_point p2)
{
	int		dx;
	int		dy;

	dx = (int)p2.x - (int)p1.x;
	dy = (int)p2.y - (int)p1.y;
	if (dx <= dy)
		fifth_octant(w, p1, p2);
	else
		sixth_octant(w, p1, p2);
}

void	forth_dial(t_wireframe *w, t_point p1, t_point p2)
{
	int		dx;
	int		dy;

	dx = (int)p2.x - (int)p1.x;
	dy = (int)p2.y - (int)p1.y;
	if (dx >= -dy)
		eighth_octant(w, p1, p2);
	else
		seventh_octant(w, p1, p2);
}

void	linear_absciss(t_wireframe *w, t_point p1, t_point p2, int direction)
{
	while ((int)p1.y != (int)p2.y)
	{
		draw_pixel(w, p1, 0);
		p1.y += direction;
	}
}

void	linear_ordinate(t_wireframe *w, t_point p1, t_point p2, int direction)
{
	while ((int)p1.x != (int)p2.x)
	{
		draw_pixel(w, p1, 0);
		p1.x += direction;
	}
}

void	draw_wire(t_wireframe *w, t_point p1, t_point p2)
{
	int		dx;
	int		dy;
	float	e;

	dx = (int)p2.x - (int)p1.x;
	dy = (int)p2.y - (int)p1.y;
	if (dx != 0)
	{
		if (dx > 0)
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
		else
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
