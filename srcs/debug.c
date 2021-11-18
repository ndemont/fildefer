#include "fdf.h"

void	print_z(t_wireframe *w)
{
	int x;
	int y;

	y = 0;
	printf("\n");
	while (y < w->y_len)
	{
		x = 0;
		while (x < w->x_len)
		{
			printf("%p ", &(w->altitudes[y][x]));
			printf("%d ", (int)w->altitudes[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}

}