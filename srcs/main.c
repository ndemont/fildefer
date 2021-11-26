/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:21:28 by ndemont           #+#    #+#             */
/*   Updated: 2021/11/26 12:24:33 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_wireframe	wireframe;

	if (ac != 2)
	{
		print_error(22);
		return (1);
	}
	if (!parsing(av[1], &wireframe))
		return (1);
	set_map(&wireframe);
	fill_window(&wireframe);
	display_window(&wireframe);
	return (0);
}
