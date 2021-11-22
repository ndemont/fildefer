#include "fdf.h"

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
			w->map[y][x].y *= zoom;
			w->map[y][x].y *= zoom;
			x++;
		}
		y++;
	}
}