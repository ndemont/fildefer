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