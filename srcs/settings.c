#include "fdf.h"

void	set_map(t_wireframe *w)
{
	float zoom;

	zoom = set_zoom(w);
	zoom_map(w, zoom);

}

void	move_x(t_wireframe *w, int shift)
{
	int x;
	int y;

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
	int x;
	int y;

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

void	zoom(t_wireframe*w, int	zoom)
{
		int x;
	int y;

	y = 0;
	while (y < w->y_len)
	{
		x = 0;
		while (x < w->x_len)
		{
			w->map[y][x].x *= zoom;
			w->map[y][x].y *= zoom;
			if (w->map[y][x].x > w->x_max)
				w->x_max = w->map[y][x].x;
			if (w->map[y][x].y > w->y_max)
				w->y_max = w->map[y][x].y;
			x++;
		}
		y++;
	}
}

void	center_map(t_wireframe *w)
{
	float	x_coef;
	float	y_coef;
	int	x;
	int	y;

	w->x_center = w->x_min + ((w->x_max - w->x_min) / 2);
	w->y_center = w->y_min + ((w->y_max - w->y_min) / 2);
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

float	set_zoom(t_wireframe *w)
{
	float	x_coef;
	float	y_coef;

	x_coef = (WIDTH - 50.0) / (w->x_max - w->x_min);
	y_coef = (WIDTH - 50.0) / (w->y_max - w->y_min);
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
		while (x < w->x_len)
		{
			//printf("X = %f | Y = %f\n", w->map[y][x].x, w->map[y][x].y);
			w->map[y][x].x *= zoom;
			w->map[y][x].y *= zoom;
			//printf("X = %f | Y = %f\n\n", w->map[y][x].x, w->map[y][x].y);
			update_limits(w, w->map[y][x].x, w->map[y][x].y);
			x++;
		}
		y++;
	}
	center_map(w);
}

