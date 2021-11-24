#include "fdf.h"

void	fill_window(t_wireframe *w)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (y < w->y_len)
	{
		x = 0;
		while (x < w->x_len)
		{
			if (w->map[y][x].x >= 0 && w->map[y][x].x < WIDTH && w->map[y][x].y >= 0 && w->map[y][x].y < HEIGHT)
			{
				if (y < w->y_len - 1)
					draw_wire(w, w->map[y][x], w->map[y + 1][x]);
				if (x < w->x_len - 1)
					draw_wire(w, w->map[y][x], w->map[y][x + 1]);
				if (x == 4)
				{
					w->pixel.r = (char)0;
					w->pixel.g = (char)255;
					w->pixel.b = (char)0;
				}
				if (y == 2)
				{
					w->pixel.r = (char)0;
					w->pixel.g = (char)0;
					w->pixel.b = (char)255;
				}
				w->pixel.p = ((HEIGHT - ((int)w->map[y][x].y)) * w->window.size) + ((WIDTH - ((int)w->map[y][x].x)) * 4);
				//printf("\np = (%f,%f,%f)\n", w->map[y][x].x, w->map[y][x].y, w->map[y][x].z);
				//printf("pixel.p = %d\n", w->pixel.p);
				w->window.data_addr[w->pixel.p + 2] = w->pixel.r;
				w->window.data_addr[w->pixel.p + 1] = w->pixel.g;
				w->window.data_addr[w->pixel.p + 0] = w->pixel.b;
			}
			x++;
		}
		y++;
	}
}