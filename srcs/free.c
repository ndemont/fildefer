#include "fdf.h"

t_wireframe	*free_wireframe(t_wireframe *wireframe, int errno)
{
	int i;

	print_error(errno);
	if (wireframe)
	{
		if (wireframe->altitudes)
		{
			i = 0;
			while (i < wireframe->y_len)
			{
				free(wireframe->altitudes[i]);
				wireframe->altitudes[i] = NULL;
				i++;
			}
		}
		free(wireframe);
		wireframe = NULL;
	}
	return (NULL);
}