#include "fdf.h"


void    init_window(t_wireframe *w)
{
    w->window.size = 0;
    w->window.endian = 0;
    w->window.bits_per_pixel = 0;
    w->window.mlx_ptr = NULL;
    w->window.win_ptr = NULL;
    w->window.img_ptr = NULL;
    w->window.data_addr = NULL;
}


void	init_wireframe(t_wireframe *wireframe)
{
	init_window(wireframe);
	wireframe->x_len = 0;
	wireframe->y_len = 0;
	wireframe->altitudes = NULL;
	//wireframe->mlx_ptr = mlx_init();
}