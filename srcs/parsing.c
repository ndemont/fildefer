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
	line = NULL;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
		{
			close(fd);
			free(line);
			return (0);
		}
		i = 0;
		if (!wireframe->x_len)
		{
			while (line[i])
			{
				if (line[i] > 32 && line[i] < 127)
				{
					wireframe->x_len++;
					while (line[i] > 32 && line[i] < 127)
						i++;
				}
				i++;
			}
		}
		wireframe->y_len++;
		free(line);
	}
	wireframe->y_len--;
	printf("x len = %f\n", wireframe->x_len);
	printf("y len = %f\n", wireframe->y_len);
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

	w->map[y] = (t_point *)malloc(sizeof(t_point) * w->x_len);
	if (!w->map[y])
		return (0);
	i = 0;
	x = 0;
	while (line[i])
	{
		w->map[y][x].z = (float)ft_atoi(&line[i]);
		//printf("X = %d | Y = %d | Z = %f\n", x, y, w->map[y][x].z);
		w->map[y][x].x = (float)(sqrtf(2.0) / 2.0) * ((float)x - (float)y);
		w->map[y][x].y = (float)(sqrtf(2.0 / 3.0) * w->map[y][x].z) - (((-1.0) / sqrtf(6.0)) * ((float)x + (float)y));
		//printf("X = %f | Y = %f | Z = %f\n", w->map[y][x].x, w->map[y][x].y, w->map[y][x].z);
		update_limits(w, w->map[y][x].x, w->map[y][x].y);
		while (line[i] && line[i] != ' ')
			i++;
		if (!line[i])
			return (1);
		i++;
		x++;
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
	w->map = (t_point **)malloc(sizeof(t_point *) * (w->y_len));
	ret = 1;
	line = NULL;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
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
		printf("Wrong Dimensions\n");
		free_wireframe(wireframe, 79);
		return (0);
	}
	if (!read_file(file, wireframe))
	{
		printf("Wrong Reading\n");
		free_wireframe(wireframe, 79);
		return (0);
	}
	debug(wireframe);
	return (1);
}