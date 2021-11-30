/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:20:21 by ndemont           #+#    #+#             */
/*   Updated: 2021/11/30 17:01:47 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_window(t_window *window)
{
	window->size = 0;
	window->endian = 0;
	window->bits_per_pixel = 0;
	window->win_ptr = mlx_new_window(window->mlx_ptr, WIDTH, HEIGHT, "fdf");
	window->img_ptr = mlx_new_image(window->mlx_ptr, WIDTH, HEIGHT);
	window->data_addr = mlx_get_data_addr(window->img_ptr,
			&(window->bits_per_pixel), &(window->size), &(window->endian));
}

void	init_pixel(t_pixel *pixel, int r, int g, int b)
{
	pixel->p = 0;
	pixel->r = r;
	pixel->g = g;
	pixel->b = b;
}

void	init_wireframe(t_wireframe *wireframe)
{
	wireframe->window.mlx_ptr = mlx_init();
	init_pixel(&wireframe->pixel, 255, 255, 255);
	wireframe->x_len = 0;
	wireframe->y_len = 0;
	wireframe->max.x = 0;
	wireframe->max.y = 0;
	wireframe->max.z = 0;
	wireframe->min.x = 0;
	wireframe->min.y = 0;
	wireframe->min.z = 0;
	wireframe->map = NULL;
}
