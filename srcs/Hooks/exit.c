/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:36:33 by ndemont           #+#    #+#             */
/*   Updated: 2021/11/29 14:38:15 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_cross(int keycode, t_wireframe *w)
{
	printf("keycode = %d\n", keycode);
	(void)keycode;
	(void)w;
	exit(0);
}

int	ft_close_win(int keycode, t_wireframe *w)
{
	(void)w;
	if (keycode == ESC)
		return (0);
	return (1);
}
