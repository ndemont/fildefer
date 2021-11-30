/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_half_octant.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:51:35 by ndemont           #+#    #+#             */
/*   Updated: 2021/11/30 11:55:10 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	first_octant(t_wireframe *w, t_point p1, t_point p2)
{
	t_point	pt;
	int		dx;
	int		dy;
	float	e;

	dx = (int)p2.x - (int)p1.x;
	dy = (int)p2.y - (int)p1.y;
	pt = p1;
	e = dx;
	dx = dx * 2 ;
	dy = dy * 2 ;
	//printf("P1(%f,%f,%f)\n", p1.x, p1.y, p1.z);
	//printf("P2(%f,%f,%f)\n", p2.x, p2.y, p2.z);
	while ((int)pt.x < (int)p2.x)
	{
		draw_pixel(w, p1, pt, p2);
		e -= dy;
		if (e < 0)
		{
			pt.y += 1;
			e += dx;
		}
		pt.x += 1;
	}
}

void	second_octant(t_wireframe *w, t_point p1, t_point p2)
{
	t_point	pt;
	int		dx;
	int		dy;
	float	e;

	pt = p1;
	dx = (int)p2.x - (int)p1.x;
	dy = (int)p2.y - (int)p1.y;
	e = dy;
	dy = dy * 2;
	dx = dx * 2;
	while ((int)pt.y < (int)p2.y)
	{
		draw_pixel(w, p1, pt, p2);
		e -= dx;
		if (e < 0)
		{
			pt.x += 1;
			e += dy;
		}
		pt.y += 1;
	}
}

void	third_octant(t_wireframe *w, t_point p1, t_point p2)
{
	t_point	pt;
	int		dx;
	int		dy;
	float	e;

	pt = p1;
	dx = (int)p2.x - (int)p1.x;
	dy = (int)p2.y - (int)p1.y;
	e = dy;
	dy = dy * 2;
	dx = dx * 2;
	while ((int)pt.y < (int)p2.y)
	{
		draw_pixel(w, p1, pt, p2);
		e += dx;
		if (e <= 0)
		{
			pt.x -= 1;
			e += dy;
		}
		pt.y += 1;
	}
}

void	forth_octant(t_wireframe *w, t_point p1, t_point p2)
{
	t_point	pt;
	int		dx;
	int		dy;
	float	e;

	pt = p1;
	dx = (int)p2.x - (int)p1.x;
	dy = (int)p2.y - (int)p1.y;
	e = dx;
	dy = dy * 2;
	dx = dx * 2;
	while ((int)pt.x > (int)p2.x)
	{
		draw_pixel(w, p1, pt, p2);
		e += dy;
		if (e >= 0)
		{
			pt.y += 1;
			e += dx;
		}
		pt.x -= 1;
	}
}
