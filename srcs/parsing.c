#include "fdf.h"


int		count_x_len(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (++count);
}



int	open_file(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	return (fd);
}


int	get_dimensions(int fd, t_wireframe *wireframe)
{
	char	*line;
	int		ret;
	int		i;

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
		i = 0;
		while (line[i])
		{
			while (line[i] && line[i] != ' ')
				i++;
			wireframe->x_len++;
		}
		wireframe->y_len++;
		free(line);
	}
	return (1);
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
		w->map[y][x].y = i;
		w->map[y][x].x = x;
		w->map[y][x].z = (float)ft_atoi(&line[i]);
		while (line[i] && line[i] != ' ')
			i++;
		if (!line[i])
			return (1);
		i++;
		x++;
	}
	return (1);
}

int	read2_file(int fd, t_wireframe *w)
{
	char	*line;
	int		y;
	int		ret;

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

char	*read_file(int fd, t_wireframe *wireframe)
{
	char	*content;
	char	*tmp;
	char	*line;
	int		ret;

	ret = 1;
	content = NULL;
	line = NULL;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
		{
			if (line)
				free(line);
			return (content);
		}
		wireframe->y_len++;
		tmp = content;
		content = ft_strjoin(tmp, line);
		if (tmp)
			free(tmp);
		free(line);
		//printf("content	%p\n%s\n", content, content);
		tmp = content;
		content = ft_strjoin(tmp, "\n");
		if (tmp)
			free(tmp);
	}
	printf("content	%p\n", content);
	return (content);
}

int	check_file(char *content, t_wireframe *w)
{
	int		i;
	int		j;
	char	*tmp;

	w->altitudes = (float **)malloc(sizeof(float *) * w->y_len);
	if (!w->altitudes)
		return (0);
	w->x_len = count_x_len(content);
	i = 0;
	while (i < w->y_len)
	{
		w->altitudes[i] = (float *)malloc(sizeof(float) * w->x_len);
		if (!w->altitudes[i])
			return 0;
		j = 0;
		while (j < w->x_len && *content)
		{
			w->altitudes[i][j] = (float)ft_atoi(content);
			while (*content && *content != ' ' && *content != '\n')
				content++;
			content++;
			j++;
		}
		content--;
		i++;
	}
	return (1);
}

int	parsing(char *file, t_wireframe *wireframe)
{
	char		*content;
	int			ret;
	int			fd;

	init_wireframe(wireframe);
	fd = open_file(file);
	if (fd < 0)
	{
		free_wireframe(wireframe, 2);
		return (0);
	}
	if (!read2_file(fd, wireframe))
	{
		free_wireframe(wireframe, 79);
		return (0);
	}
	//if (!check_file(content, wireframe))
	//	return (0);
	return (1);
}