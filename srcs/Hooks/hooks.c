/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:36:09 by ndemont           #+#    #+#             */
/*   Updated: 2021/11/30 14:40:56 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_w(t_wireframe *w, int x, int shift)
{
	w->window.img_ptr = mlx_new_image(w->window.mlx_ptr, WIDTH, HEIGHT);
	w->window.data_addr = mlx_get_data_addr(w->window.img_ptr, \
	&(w->window.bits_per_pixel), &(w->window.size), &(w->window.endian));
	if (x)
		move_x(w, shift);
	else
		move_y(w, shift);
	fill_window(w);
	display_window(w);
}
