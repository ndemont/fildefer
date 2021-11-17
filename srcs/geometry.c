#include "fdf.h"

t_point	create_point(t_wireframe *wireframe, float x, float y, float z)
{
	float	angle_h;
	float	angle_v;
	t_point	point;

	point.x = x + (WIDTH / 2);
	point.y = z + (HEIGHT/ 2);
	point.z = 0;
	return (point);
}

void	fill_window(t_wireframe *wireframe)
{
	int		y;
	int		x;
	int		pixel;
	t_point	point;
	
	y = 0;
	while (y < wireframe->y_len)
	{
		x = 0;
		while (x < wireframe->x_len)
		{
			point = create_point(wireframe, x, y, wireframe->altitudes[y][x]);
			pixel = (point.x * point.y) * 4;
			wireframe->data_addr[pixel + 2] = 155;
			wireframe->data_addr[pixel + 1] = 155;
			wireframe->data_addr[pixel + 0] = 155;
			x++;
		}
		y++;
	}
}