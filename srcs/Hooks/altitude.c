/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altitude.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:22:59 by ndemont           #+#    #+#             */
/*   Updated: 2021/11/29 14:37:49 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_print_altitude(t_wireframe *w, float shift)
{
	w->window.img_ptr = mlx_new_image(w->window.mlx_ptr, WIDTH, HEIGHT);
	w->window.data_addr = mlx_get_data_addr(w->window.img_ptr, &(w->window.bits_per_pixel), &(w->window.size), &(w->window.endian));
	amplitude_map(w, shift);
	fill_window(w);
	display_window(w);
}

void	altitude(int keycode, t_wireframe *w)
{
	if (keycode == WIDE)
		ft_print_altitude(w, 0.1);
	if (keycode == NARROW)
		ft_print_altitude(w, -0.1);
}
