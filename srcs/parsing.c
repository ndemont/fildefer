#include "fdf.h"

int	open_file(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	return (fd);
}

int	get_dimensions(char *file, t_wireframe *wireframe)
{
	char	*line;
	int		ret;
	int		fd;
	int		i;


	fd = open_file(file);
	if (fd < 0)
	{
		free_wireframe(wireframe, 2);
		return (0);
	}
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0 || !line)
		{
			close(fd);
			free(line);
			return (0);
		}
		i = 0;
		if (line && line[0])
			wireframe->y_len++;
		if (!wireframe->x_len)
		{
			while (line && line[i])
			{
				if (line && line[i] > 32 && line[i] < 127)
				{
					wireframe->x_len++;
					while (line && line[i] > 32 && line[i] < 127)
						i++;
				}
				if (line[i])
					i++;
			}
		}
		free(line);
	}
	close(fd);
	return (1);
}


void	update_limits(t_wireframe *w, float x, float y)
{
	if (x > w->x_max)
		w->x_max = x;
	if (y > w->y_max)
		w->y_max = y;
	if (x < w->x_min)
		w->x_min = x;
	if (y < w->y_min)
		w->y_min = y;
}

int	fill_map(t_wireframe* w, char *line, int y)
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
			w->map[y][x].x = (float)(sqrtf(2.0) / 2.0) * ((float)x - (float)y);
			w->map[y][x].y = (float)(sqrtf(2.0 / 3.0) * (w->map[y][x].z * 0.3)) - (((-1.0) / sqrtf(6.0)) * ((float)x + (float)y));
			update_limits(w, w->map[y][x].x, w->map[y][x].y);
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
	static int turn = 0;
	char	*line;
	int		fd;
	int		y;
	int		ret;

	fd = open_file(file);
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