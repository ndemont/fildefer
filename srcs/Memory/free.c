/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:08:34 by ndemont           #+#    #+#             */
/*   Updated: 2021/11/26 12:18:49 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_wireframe	*free_wireframe(t_wireframe *wireframe, int errno)
{
	int	i;

	print_error(errno);
	if (wireframe->map)
	{
		i = 0;
		while (i < wireframe->y_len)
		{
			free(wireframe->map[i]);
			wireframe->map[i] = NULL;
			i++;
		}
		free(wireframe->map);
	}
	return (NULL);
}
