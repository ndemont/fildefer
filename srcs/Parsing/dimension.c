/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:33:02 by ndemont           #+#    #+#             */
/*   Updated: 2021/11/30 19:31:37 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_absciss_len(t_wireframe *wireframe, char *line)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (line && line[i])
	{
		while (line && line[i])
		{
			if (line && line[i] > 32 && line[i] < 127)
			{
				tmp++;
				while (line && line[i] > 32 && line[i] < 127)
					i++;
			}
			if (line[i])
				i++;
		}
		if (wireframe->x_len != 0 && tmp != wireframe->x_len)
			return (0);
		wireframe->x_len = tmp;
	}
	return (1);
}

int	count_ordinate_len(int fd, t_wireframe *wireframe)
{
	char	*line;
	int		ret;

	ret = get_next_line(fd, &line);
	if (ret < 0 || !line)
	{
		close(fd);
		free(line);
		return (0);
	}
	if (line && line[0])
		wireframe->y_len++;
	if (!count_absciss_len(wireframe, line))
		return (-1);
	free(line);
	return (ret);
}

int	get_dimensions(char *file, t_wireframe *wireframe)
{
	int		ret;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free_wireframe(wireframe, 2);
		return (0);
	}
	ret = 1;
	while (ret > 0)
		ret = count_ordinate_len(fd, wireframe);
	if (ret < 0)
		return (0);
	close(fd);
	return (1);
}
