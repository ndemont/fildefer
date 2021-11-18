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

t_point	*create_mapping(t_wireframe *w)
{
	t_point	*map;
	int		i;
	float	x;
	float	y;
	float	z;
	float	max_x;
	float	max_y;
	float	square;

	i = 0;
	y = 0;
	max_x = w->x_len;
	max_y = w->y_len;
	map = malloc(sizeof(t_point) * (w->x_len * w->y_len));
	while (y < w->y_len)
	{
		x = 0;
		while (x < w->x_len)
		{
			z = w->altitudes[(int)y][(int)x];
			map[i].z = z;
			map[i].x = (sqrtf(2.0) / 2.0) * (x - y) + 5.0;
			map[i].y = (sqrtf(2.0 / 3.0) * z) - (((-1.0) / sqrtf(6.0)) * (x + y));
			if (map[i].x > max_x)
				max_x = map[i].x;
			if (map[i].y > max_y)
				max_y = map[i].y;
			i++;
			x++;
		}
		y++;
	}
	y = 0;
	i = 0;
	printf("x max = %f\n", max_x);
	printf("y max = %f\n", max_y);
	while (y < w->y_len)
	{
		x = 0;
		while (x < w->x_len)
		{
			//printf("POINT: x = %f | y = %f\n", map[i].x, map[i].y);
			map[i].x = ((map[i].x / max_x) * WIDTH * 0.8) + 170;
			map[i].y = ((map[i].y / max_y) * HEIGHT * 0.8) + 50;
			//printf("POINT: x = %f | y = %f\n\n", map[i].x, map[i].y);
			i++;
			x++;
		}
		y++;
	}
	return (map);
}


void	fill_window(t_wireframe *w)
{
	t_point	*map;
	float	altitude;
	int		x;
	int		y;
	int		i;

	map = create_mapping(w);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			i = 0;
			while (i < (w->x_len * w->y_len))
			{
				if (x == (int)map[i].x && y == (int)map[i].y)
				{
					altitude = map[i].z;
					color_pixel(w, map[i].z);
					w->pixel.p = ((HEIGHT - (HEIGHT - y) - 1) * w->size) + ((WIDTH - (WIDTH - x)- 1) * 4);
					w->data_addr[w->pixel.p + 2] = w->pixel.r;
					w->data_addr[w->pixel.p + 1] = w->pixel.g;
					w->data_addr[w->pixel.p + 0] = w->pixel.b;
					break ;
				}
				i++;
			}
			x++;
		}
		y++;
	}
}