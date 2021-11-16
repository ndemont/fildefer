#include "fdf.h"

void	print_error(int errno)
{
	ft_putstr_fd("fdf: ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}