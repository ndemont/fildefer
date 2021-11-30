/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:59:44 by ndemont           #+#    #+#             */
/*   Updated: 2021/11/30 21:01:25 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//void	rotation(t_wireframe, float direction)
//{
//		int	x;
//	int	y;

//	y = 0;
//	while (y < w->y_len)
//	{
//		x = 0;
//		while (x < (int)w->x_len)
//		{
//			w->map[y][x].x = (w->map[y][x].x * cosf(45.0)) - (w->map[y][x].y * sinf(45.0));
//			w->map[y][x].y = (w->map[y][x].x * sinf(45.0)) + (w->map[y][x].y * cosf(45.0));
//			update_limits(w, w->map[y][x].x, w->map[y][x].y, w->map[y][x].z);
//			x++;
//		}
//		y++;
//	}
//	center_map(w);
//}