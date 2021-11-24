#include "fdf.h"

void	debug(t_wireframe *w)
{
	int x;
	int y;
	static int count = 0;

	y = 0;
	printf("\nCOUNT %d\n", count++);
	printf("\nx len %f\n", w->x_len);
	printf("\ny len %f\n", w->y_len);
	while (y < w->y_len)
	{
		x = 0;
		while (x < w->x_len)
		{
			//printf("x = %f | y = %f | z = %f\n", w->map[y][x].x, w->map[y][x].y, w->map[y][x].z);
			x++;
		}
		printf("\n");
		y++;
	}

}