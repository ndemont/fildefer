/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:21:28 by ndemont           #+#    #+#             */
/*   Updated: 2021/11/29 11:26:02 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_wireframe	w;

	if (ac != 2)
	{
		print_error(22);
		return (1);
	}
	if (!parsing(av[1], &w))
		return (1);
	set_map(&w);
	fill_window(&w);
	mlx_hook(w.window.win_ptr, 2, 1L << 0, ft_event, &w);
	if (!LINUX)
		mlx_hook(w.window.win_ptr, 17, 1L << 17, ft_cross, &w);
	else
		mlx_hook(w.window.win_ptr, 33, 1L << 5, ft_cross, &w);
	display_window(&w);
	return (0);
}
