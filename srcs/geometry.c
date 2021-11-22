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

int		create_mapping(t_wireframe *w, int x_shift, int y_shift)
{
	float	x;
	float	y;
	float	z;

	y = 0;
	w->x_max = w->x_len;
	w->y_max = w->y_len;
	while (y < w->y_len)
	{
		w->map[(int)y] = (t_point *)malloc(sizeof(t_point) * w->x_len);
		x = 0;
		while (x < w->x_len)
		{
			z = w->altitudes[(int)y][(int)x];
			w->map[(int)y][(int)x].z = z;
			w->map[(int)y][(int)x].x = (sqrtf(2.0) / 2.0) * (x - y);
			w->map[(int)y][(int)x].y = (sqrtf(2.0 / 3.0) * z) - (((-1.0) / sqrtf(6.0)) * (x + y));
			if (w->map[(int)y][(int)x].x > w->x_max)
				w->x_max = w->map[(int)y][(int)x].x;
			if (w->map[(int)y][(int)x].y > w->y_max)
				w->y_max = w->map[(int)y][(int)x].y;
			x++;
		}
		y++;
	}
	y = 0;
	while (y < w->y_len)
	{
		x = 0;
		while (x < w->x_len)
		{
			w->map[(int)y][(int)x].x = ((w->map[(int)y][(int)x].x / w->x_max) * WIDTH * 0.6) + x_shift;
			w->map[(int)y][(int)x].y = ((w->map[(int)y][(int)x].y / w->y_max) * HEIGHT * 0.6) + y_shift;
			x++;
		}
		y++;
	}
	return (1);
}


void	fill_window(t_wireframe *w)
{
	t_point	**map;
	int		x;
	int		y;
	int		i;

	create_mapping(w, X_SHIFT, Y_SHIFT);
	y = 0;
	while (y < w->y_len)
	{
		x = 0;
		while (x < w->y_len)
		{
			if (w->map[y][x].x >= 0 && w->map[y][x].x < WIDTH && w->map[y][x].y >= 0 && w->map[y][x].y < HEIGHT)
			{
				//if (y < w->y_len - 1)
				//	draw_wire(w, map[y][x], map[y + 1][x]);
				//if (x < w->x_len - 1)
				//	draw_wire(w, map[y][x], map[y][x + 1]);
				w->pixel.r = (char)255;
				w->pixel.g = (char)255;
				w->pixel.b = (char)255;
				//color_pixel(w, map[x][y].z);
				w->pixel.p = ((HEIGHT - (HEIGHT - (int)w->map[y][x].y) - 1) * w->window.size) + ((WIDTH - (WIDTH - (int)map[y][x].x)- 1) * 4);
				w->window.data_addr[w->pixel.p + 2] = w->pixel.r;
				w->window.data_addr[w->pixel.p + 1] = w->pixel.g;
				w->window.data_addr[w->pixel.p + 0] = w->pixel.b;
			}
			x++;
		}
		y++;
	}
}

void	fill_window2(t_wireframe *w)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	while (y < w->y_len)
	{
		x = 0;
		while (x < w->y_len)
		{
			if (w->map[y][x].x >= 0 && w->map[y][x].x < WIDTH && w->map[y][x].y >= 0 && w->map[y][x].y < HEIGHT)
			{
				w->pixel.r = (char)255;
				w->pixel.g = (char)255;
				w->pixel.b = (char)255;
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