/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:26:56 by ndemont           #+#    #+#             */
/*   Updated: 2021/11/29 14:37:01 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_print_zoom(t_wireframe *w, int x, float zoom)
{
	w->window.img_ptr = mlx_new_image(w->window.mlx_ptr, WIDTH, HEIGHT);
	w->window.data_addr = mlx_get_data_addr(w->window.img_ptr, &(w->window.bits_per_pixel), &(w->window.size), &(w->window.endian));
	w->x_center = WIDTH / 2;
	w->y_center = HEIGHT / 2;
	zoom2_map(w, zoom);
	center_map(w);
	fill_window(w);
	display_window(w);
}

void	zoom(int keycode, t_wireframe *w)
{
	if (keycode == ZOOM_IN)
		ft_print_zoom(w, 0, 1.1);
	if (keycode == ZOOM_OUT)
		ft_print_zoom(w, 0, 0.9);
}
