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

t_point	**create_mapping(t_wireframe *w)
{
	t_point	**map;
	float	x;
	float	y;
	float	z;
	float	square;

	y = 0;
	w->x_max = w->x_len;
	w->y_max = w->y_len;
	map = malloc(sizeof(t_point *) * (w->y_len));
	while (y < w->y_len)
	{
		map[(int)y] = malloc(sizeof(t_point) * w->x_len);
		x = 0;
		while (x < w->x_len)
		{
			z = w->altitudes[(int)y][(int)x];
			map[(int)y][(int)x].z = z;
			map[(int)y][(int)x].x = (sqrtf(2.0) / 2.0) * (x - y);
			map[(int)y][(int)x].y = (sqrtf(2.0 / 3.0) * z) - (((-1.0) / sqrtf(6.0)) * (x + y));
			if (map[(int)y][(int)x].x > w->x_max)
				w->x_max = map[(int)y][(int)x].x;
			if (map[(int)y][(int)x].y > w->y_max)
				w->y_max = map[(int)y][(int)x].y;
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
			map[(int)y][(int)x].x = ((map[(int)y][(int)x].x / w->x_max) * WIDTH * 0.6) + w->x_shift;
			map[(int)y][(int)x].y = ((map[(int)y][(int)x].y / w->y_max) * HEIGHT * 0.6) + w->y_shift;
			x++;
		}
		y++;
	}
	return (map);
}


void	fill_window(t_wireframe *w)
{
	t_point	**map;
	int		x;
	int		y;
	int		i;

	map = create_mapping(w);
	y = 0;
	while (y < w->y_len)
	{
		x = 0;
		while (x < w->y_len)
		{
			if (map[y][x].x >= 0 && map[y][x].x < WIDTH && map[y][x].y >= 0 && map[y][x].y < HEIGHT)
			{
				//if (y < w->y_len - 1)
				//	draw_wire(w, map[y][x], map[y + 1][x]);
				//if (x < w->x_len - 1)
				//	draw_wire(w, map[y][x], map[y][x + 1]);
				w->pixel.r = (char)255;
				w->pixel.g = (char)255;
				w->pixel.b = (char)255;
				//color_pixel(w, map[x][y].z);
				w->pixel.p = ((HEIGHT - (HEIGHT - (int)map[y][x].y) - 1) * w->size) + ((WIDTH - (WIDTH - (int)map[y][x].x)- 1) * 4);
				w->data_addr[w->pixel.p + 2] = w->pixel.r;
				w->data_addr[w->pixel.p + 1] = w->pixel.g;
				w->data_addr[w->pixel.p + 0] = w->pixel.b;
			}
			x++;
		}
		y++;
	}
}