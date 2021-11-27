/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dials.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:58:17 by ndemont           #+#    #+#             */
/*   Updated: 2021/11/27 12:59:09 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
