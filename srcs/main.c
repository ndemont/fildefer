#include "fdf.h"

int main(int ac, char **av)
{
	t_wireframe *wireframe;

	wireframe = 0;
	if (ac != 2)
	{
		print_error(22);
		return (1);
	}
	wireframe = parsing(av[1]);
	if (!wireframe)
		return (1);
	return (0);
}