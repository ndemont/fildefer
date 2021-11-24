#include "fdf.h"

t_wireframe	*free_wireframe(t_wireframe *wireframe, int errno)
{
	int i;

	print_error(errno);
	if (wireframe->map)
	{
		i = 0;
		while (i < wireframe->y_len)
		{
			free(wireframe->map[i]);
			wireframe->map[i] = NULL;
			i++;
		}
		free(wireframe->map);
	}
	return (NULL);
}