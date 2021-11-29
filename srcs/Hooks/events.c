/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:37:19 by ndemont           #+#    #+#             */
/*   Updated: 2021/11/29 14:39:01 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_event(int keycode, t_wireframe *w)
{
	if (!ft_close_win(keycode, w))
		exit(0);
	coordinates(keycode, w);
	zoom(keycode, w);
	altitude(keycode, w);
	return (1);
}
