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

int		near_inter(t_wireframe *w, t_pixel *pixel)
{
	float	distance;
	t_point	inter;
	int i;
	int j;
	j = 0;
	while (j < w->y_len)
	{
		i = 0;
		while (i < w->x_len)
		{
			inter.x = i - w->ray.origin.x;
			inter.y = j - w->ray.origin.y;
			inter.z = w->altitudes[j][i] - w->ray.origin.z;
			normalize(&inter);
			// printf("inter x	= %f - inter y	= %f - inter z	= %f\n", inter.x, inter.y, inter.z);
			// printf("ray x	= %f - ray y	= %f - ray z	= %f\n\n", w->ray.direction.x, w->ray.direction.y, w->ray.direction.z);
			if (inter.x == w->ray.direction.x && inter.y == w->ray.direction.y && inter.z == w->ray.direction.z)
			{
				pixel->r = (char)155;
				pixel->g = (char)155;
				pixel->b = (char)155;
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

void	create_pixel(t_wireframe *wireframe, int x, int y, t_matrix m)
{
	t_pixel	pixel;
	int		ret;

	wireframe->ray.direction.x = (x - (WIDTH / 2));
	wireframe->ray.direction.y = (y - (HEIGHT / 2));
	normalize(&(wireframe->ray.direction));
	wireframe->ray.direction = get_normalized(v_mult_m(wireframe->ray.direction, m));
	ret = near_inter(wireframe, &pixel);
	if (ret)
	{
		pixel.p = ((HEIGHT - y - 1) * wireframe->size);
		pixel.p += ((WIDTH - x - 1) * 4);
		wireframe->data_addr[pixel.p + 2] = pixel.r;
		wireframe->data_addr[pixel.p + 1] = pixel.g;
		wireframe->data_addr[pixel.p + 0] = pixel.b;
	}
}

void	fill_window(t_wireframe *wireframe)
{
	int			x;
	int			y;
	t_point		point;
	t_matrix	matrix;
	t_pixel	pixel;

	wireframe->ray.origin = wireframe->camera.origin;
	wireframe->ray.direction.z = -((WIDTH / (2 * (tan(FOV / 2)))));
	matrix = rotation_matrix(wireframe->camera.direction);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel.p = ((HEIGHT - y - 1) * wireframe->size);
			pixel.p += ((WIDTH - x - 1) * 4);
			wireframe->data_addr[pixel.p + 2] = 255;
			wireframe->data_addr[pixel.p + 1] = 0;
			wireframe->data_addr[pixel.p + 0] = 0;
			create_pixel(wireframe, x, y, matrix);
			x++;
		}
		y++;
	}
}