#include "fdf.h"

void		color_pixel(t_wireframe *wireframe, float altitude)
{
	float	scale;
	float	coef;
	float	diff;
	float	limit;
	float	level;
	float	z_min;
	float	z_max;

	z_min = 0;
	z_max = 10;
	diff = z_max - z_min;
	level = altitude + diff;
	scale = diff / 4;
	if (altitude < (z_min + scale))
	{
		limit = z_min + scale + diff;
		coef = (limit * level) / 100;
		wireframe->pixel.r = (char)255;
		wireframe->pixel.g = (char)(255 * coef);
		wireframe->pixel.b = (char)0;
	}
	else if (altitude < (z_min + scale * 2))
	{
		limit = z_min + (scale * 2) + diff;
		coef = (limit * level) / 100;
		wireframe->pixel.r = (char)(255 * (1 - coef));
		wireframe->pixel.g = (char)255;
		wireframe->pixel.g = (char)0;
	}
	else if (altitude < (z_min + scale * 3))
	{
		limit = z_min + (scale * 3) + diff;
		coef = (limit * level) / 100;
		wireframe->pixel.r = (char)0;
		wireframe->pixel.g = (char)255;
		wireframe->pixel.g = (char)(255 * coef);
	}
	else
	{
		limit = z_min + (scale * 4) + diff;
		coef = (limit * level) / 100;
		wireframe->pixel.r = (char)0;
		wireframe->pixel.g = (char)(255 * (1 - coef));
		wireframe->pixel.g = (char)255;
	}
}

void	set_map(t_wireframe *w, float x_shift, float y_shift, float zoom)
{
	int	x;
	int	y;

	y = 0;
	while (y < w->y_len)
	{
		x = 0;
		while (x < w->y_len)
		{
			w->map[y][x].x = ((w->map[y][x].x / w->x_max) * WIDTH * zoom) + x_shift;
			w->map[y][x].y = ((w->map[y][x].y / w->y_max) * HEIGHT * zoom) + y_shift;
			if (w->map[y][x].x > w->x_max)
				w->x_max = w->map[y][x].x;
			if (w->map[y][x].y > w->y_max)
				w->y_max = w->map[y][x].y;
			x++;
		}
		y++;
	}
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
		while (x < w->y_len)
		{
			if (w->map[y][x].x >= 0 && w->map[y][x].x < WIDTH && w->map[y][x].y >= 0 && w->map[y][x].y < HEIGHT)
			{
				w->pixel.p = ((HEIGHT - (HEIGHT - (int)w->map[y][x].y) - 1) * w->window.size) + ((WIDTH - (WIDTH - (int)w->map[y][x].x)- 1) * 4);
				w->window.data_addr[w->pixel.p + 2] = w->pixel.r;
				w->window.data_addr[w->pixel.p + 1] = w->pixel.g;
				w->window.data_addr[w->pixel.p + 0] = w->pixel.b;
			}
			x++;
		}
		y++;
	}
}