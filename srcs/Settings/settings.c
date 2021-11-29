/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:26:39 by ndemont           #+#    #+#             */
/*   Updated: 2021/11/29 13:05:58 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_map(t_wireframe *w)
{
	float	zoom;

	zoom = set_zoom(w);
	zoom_map(w, zoom);
	w->x_center = w->min.x + ((w->max.x - w->min.x) / 2);
	w->y_center = w->min.y + ((w->max.y - w->min.y) / 2);
	center_map(w);
}

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

void	center_map(t_wireframe *w)
{
	float	x_coef;
	float	y_coef;
	int		x;
	int		y;

	x_coef = (WIDTH / 2) - w->x_center;
	y_coef = (HEIGHT / 2) - w->y_center;
	y = 0;
	while (y < w->y_len)
	{
		x = 0;
		while (x < w->x_len)
		{
			w->map[y][x].x += x_coef;
			w->map[y][x].y += y_coef;
			x++;
		}
		y++;
	}
}

void	reset_center(t_wireframe *w, int x, int y, float zoom)
{
	if ((int)(w->map[y][x].x) == (WIDTH / 2))
	{
		if ((int)(w->map[y][x].y) == (WIDTH / 2))
		{
			w->x_center = w->map[y][x].x * zoom;
			w->y_center = w->map[y][x].y * zoom;
		}
	}
}

float	set_zoom(t_wireframe *w)
{
	float	x_coef;
	float	y_coef;

	x_coef = (WIDTH - 50.0) / (w->max.x - w->min.x);
	y_coef = (WIDTH - 50.0) / (w->max.y - w->min.y);
	if (x_coef < y_coef)
		return (x_coef);
	else
		return (y_coef);
}

void	zoom_map(t_wireframe *w, float zoom)
{
	int	x;
	int	y;

	y = 0;
	while (y < w->y_len)
	{
		x = 0;
		while (x < (int)w->x_len)
		{
			w->map[y][x].x *= zoom;
			w->map[y][x].y *= zoom;
			update_limits(w, w->map[y][x].x, w->map[y][x].y, w->map[y][x].z);
			x++;
		}
		y++;
	}
}

void	zoom2_map(t_wireframe *w, float zoom)
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
			w->map[y][x].x *= zoom;
			w->map[y][x].y *= zoom;
			update_limits(w, w->map[y][x].x, w->map[y][x].y, w->map[y][x].z);
			x++;
		}
		y++;
	}
}

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
			//update_limits(w, w->map[y][x].x, w->map[y][x].y, w->map[y][x].z);
			x++;
		}
		y++;
	}
}
