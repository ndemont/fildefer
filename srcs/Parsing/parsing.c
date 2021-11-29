/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:24:46 by ndemont           #+#    #+#             */
/*   Updated: 2021/11/29 14:45:18 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_limits(t_wireframe *w, float x, float y, float z)
{
	if (x > w->max.x)
		w->max.x = x;
	if (y > w->max.y)
		w->max.y = y;
	if (z > w->max.z)
		w->max.z = z;
	if (x < w->min.x)
		w->min.x = x;
	if (y < w->min.y)
		w->min.y = y;
	if (z < w->min.z)
		w->min.z = z;
}

int	fill_map(t_wireframe *w, char *line, int y)
{
	int	i;
	int	x;

	if (y < w->y_len)
	{
		w->map[y] = (t_point *)malloc(sizeof(t_point) * w->x_len);
		if (!w->map[y])
			return (0);
	}
	else
		return (1);
	i = 0;
	x = 0;
	while (line && line[i])
	{
		if (line[i] > 32 && line[i] < 127)
		{
			w->map[y][x].z = (float)ft_atoi(&line[i]);
			w->map[y][x].x = (float)(sqrtf(2.0) / 2.0) *((float)x - (float)y);
			w->map[y][x].y = (float)(sqrtf(2.0 / 3.0) * (w->map[y][x].z * 0.3)) - (((-1.0) / sqrtf(6.0)) * ((float)x + (float)y));
			update_limits(w, w->map[y][x].x, w->map[y][x].y, w->map[y][x].z);
			x++;
			while (line && line[i] > 32 && line[i] < 127)
				i++;
		}
		if (line[i])
			i++;
	}
	return (1);
}

int	read_file(char *file, t_wireframe *w)
{
	char	*line;
	int		fd;
	int		y;
	int		ret;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free_wireframe(w, 2);
		return (0);
	}
	y = 0;
	w->map = (t_point **)malloc(sizeof(t_point *) * w->y_len);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0 || !line)
		{
			free(line);
			return (0);
		}
		if (!fill_map(w, line, y))
			return (0);
		free(line);
		y++;
	}
	return (1);
}

int	parsing(char *file, t_wireframe *wireframe)
{
	char		*content;
	int			ret;

	init_wireframe(wireframe);
	if (!(get_dimensions(file, wireframe)))
	{
		free_wireframe(wireframe, 79);
		return (0);
	}
	if (!read_file(file, wireframe))
	{
		free_wireframe(wireframe, 79);
		return (0);
	}
	return (1);
}
