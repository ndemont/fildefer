#ifndef FDF_HPP
#define FDF_HPP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

typedef struct	s_wireframe
{
	int	x_len;
	int	y_len;
	int	**altitudes;
}				t_wireframe;

t_wireframe	*parsing(char *file);
t_wireframe	*free_wireframe(t_wireframe *wireframe, int errno);
void		print_error(int errno);

#endif