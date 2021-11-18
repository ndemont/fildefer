#include "fdf.h"
t_point	v_dot_v(t_point v1, t_point v2)
{
	t_point v3;

	v3.x = v1.y * v2.z - v1.z * v2.y;
	v3.y = v1.z * v2.x - v1.x * v2.z;
	v3.z = v1.x * v2.y - v1.y * v2.x;
	return (v3);
}

t_point	v_mult_m(t_point v, t_matrix m)
{
	t_point new;

	new.x = (m.r1.x * v.x) + (m.r2.x * v.y);
	new.x = new.x + (m.r3.x * v.z);
	new.y = (m.r1.y * v.x) + (m.r2.y * v.y);
	new.y = new.y + (m.r3.y * v.z);
	new.z = (m.r1.z * v.x) + (m.r2.z * v.y);
	new.z = new.z + (m.r3.z * v.z);
	return (new);
}

t_point	v_minus_v(t_point v1, t_point v2)
{
	t_point v3;

	v3.x = v1.x - v2.x;
	v3.y = v1.y - v2.y;
	v3.z = v1.z - v2.z;
	return (v3);
}

t_point	init_point(float x, float y, float z)
{
	t_point new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);

}

t_point	v_minus_i(t_point v, float i)
{
	t_point v3;

	v3.x = v.x - i;
	v3.y = v.y - i;
	v3.z = v.z - i;
	return (v3);
}

t_point	v_mult_i(t_point v, float i)
{
	t_point v3;

	v3.x = v.x * i;
	v3.y = v.y * i;
	v3.z = v.z * i;
	return (v3);
}

t_point	v_div_i(t_point v, float i)
{
	t_point v3;

	v3.x = v.x / i;
	v3.y = v.y / i;
	v3.z = v.z / i;
	return (v3);
}

t_point	v_plus_i(t_point v, float i)
{
	t_point v3;

	v3.x = v.x + i;
	v3.y = v.y + i;
	v3.z = v.z + i;
	return (v3);
}


float		get_norme_2(t_point v)
{
	float rslt;

	rslt = powf(v.x, 2) + powf(v.y, 2) + powf(v.z, 2);
	return (rslt);
}

void		normalize(t_point *v)
{
	float	norm;

	norm = sqrt(get_norme_2(*v));
	v->x = v->x / norm;
	v->y = v->y / norm;
	v->z = v->z / norm;
}

t_point	get_normalized(t_point v)
{
	normalize(&v);
	return (v);
}

t_matrix	rotation_matrix(t_point c)
{
	t_matrix matrix;
	t_point forward;
	t_point right;
	t_point up;

	forward = get_normalized(v_mult_i(c, -1));
	if ((int)forward.y == 1 || (int)forward.y == -1)
		right = get_normalized(init_point(1, 0, 0));
	else
		right = get_normalized(init_point(0, 1, 0));
	right = v_dot_v(right, forward);
	up = v_dot_v(forward, right);
	matrix.r1 = right;
	matrix.r2 = up;
	matrix.r3 = forward;
	return (matrix);
}


int		color_pixel(t_wireframe *wireframe, float altitude)
{
	float	scale;
	float	coef;
	float	diff;
	float	limit;
	float	level;

	diff = wireframe->z_min - wireframe->z_max;
	level = altitude + diff;
	scale = (wireframe->z_max - wireframe->z_min) / 4;
	if (altitude < (wireframe->z_min + scale))
	{
		limit = wireframe->z_min + scale + diff;
		coef = (limit * level) / 100;
		wireframe->pixel.r = (char)255;
		wireframe->pixel.g = (char)(255 * coef);
		wireframe->pixel.b = (char)0;
	}
	else if (altitude < (wireframe->z_min + scale * 2))
	{
		limit = wireframe->z_min + (scale * 2) + diff;
		coef = (limit * level) / 100;
		wireframe->pixel.r = (char)(255 * (1 - coef));
		wireframe->pixel.g = (char)255;
		wireframe->pixel.g = (char)0;
	}
	else if (altitude < (wireframe->z_min + scale * 3))
	{
		limit = wireframe->z_min + (scale * 3) + diff;
		coef = (limit * level) / 100;
		wireframe->pixel.r = (char)0;
		wireframe->pixel.g = (char)255;
		wireframe->pixel.g = (char)(255 * coef);
	}
	else
	{
		limit = wireframe->z_min + (scale * 4) + diff;
		coef = (limit * level) / 100;
		wireframe->pixel.r = (char)0;
		wireframe->pixel.g = (char)(255 * (1 - coef));
		wireframe->pixel.g = (char)255;
	}
	return (1);
}

void	create_pixel(t_wireframe *w, int x, int y)
{
	int	z;
	int	i;
	int	j;

	z = w->altitudes[y][x];
	i = (sqrt(2) / 2) * (x - y);
	j = (sqrt(2 / 3) * z) - (((-1) / sqrt(6)) * (x + y));
	i = i * 100;
	j = j * 100;
	printf("x = %d\n", i);
	printf("y = %d\n\n", j);
	//color_pixel(w, z);
	w->pixel.p = ((HEIGHT - j - 1) * w->size) + ((WIDTH - i - 1) * 4);
	w->pixel.r = (char)255;
	w->pixel.g = (char)255;
	w->pixel.b = (char)255;
	w->data_addr[w->pixel.p + 2] = w->pixel.r;
	w->data_addr[w->pixel.p + 1] = w->pixel.g;
	w->data_addr[w->pixel.p + 0] = w->pixel.b;
}

t_point	*create_mapping(t_wireframe *w)
{
	t_point	*map;
	int		i;
	float	x;
	float	y;
	int		z;
	float		max_x;
	float		max_y;

	i = 0;
	y = 0;
	max_x = w->x_len;
	max_y = w->y_len;
	printf("x len = %d\n", w->x_len);
	printf("y len = %d\n", w->y_len);
	map = malloc(sizeof(t_point) * (w->x_len * w->y_len));
	while (y < w->y_len)
	{
		x = 0;
		while (x < w->x_len)
		{
			z = w->altitudes[(int)y][(int)x];
			map[i].x = (sqrt(2) / 2) * (x - y) + 5;
			map[i].y = (sqrt(2 / 3) * z) - (((-1) / sqrt(6)) * (x + y));
			printf("POINT: x = %f | y = %f      ", x, y);
			printf("POINT: x = %f | y = %f\n", map[i].x, map[i].y);
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
			map[i].x = (map[i].x / max_x) * WIDTH;
			map[i].y = (map[i].y / max_y) * HEIGHT;
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
					w->pixel.p = ((HEIGHT - y - 1) * w->size) + ((WIDTH - x - 1) * 4);
					w->data_addr[w->pixel.p + 2] = 255;
					w->data_addr[w->pixel.p + 1] = 125;
					w->data_addr[w->pixel.p + 0] = 125;
				}
				i++;
			}
			x++;
		}
		y++;
	}
}