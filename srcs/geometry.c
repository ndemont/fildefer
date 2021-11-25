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
			}
			x++;
		}
		y++;
	}
}