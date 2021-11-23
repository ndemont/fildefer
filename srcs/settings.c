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
	printf("x moved\n");
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