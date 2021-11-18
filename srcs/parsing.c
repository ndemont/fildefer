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

t_wireframe	*init_wireframe(void)
{
	t_wireframe	*wireframe;

	wireframe = malloc(sizeof(t_wireframe));
	if (!wireframe)
		return wireframe;
	wireframe->x_len = 0;
	wireframe->y_len = 0;
	wireframe->altitudes = NULL;
	wireframe->mlx_ptr = mlx_init();
	wireframe->win_ptr = NULL;
	wireframe->img_ptr = NULL;
	wireframe->size = 0;
	wireframe->endian = 0;
	wireframe->bits_per_pixel = 0;
	wireframe->data_addr = NULL;
	wireframe->camera.origin.x = 0;
	wireframe->camera.origin.y = 0;
	wireframe->camera.origin.z = 0;
	wireframe->camera.direction.x = 0;
	wireframe->camera.direction.y = -1;
	wireframe->camera.direction.z = 0;
	return wireframe;
}


int	open_file(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	return (fd);
}

char	*read_file(int fd, t_wireframe *wireframe)
{
	char	*content;
	char	*tmp;
	char	*line;
	int		ret;

	ret = 1;
	content = 0;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
			return (content);
		wireframe->y_len++;
		tmp = content;
		content = ft_strjoin(content, line);
		free(tmp);
		tmp = content;
		content = ft_strjoin(content, "\n");
		free(tmp);
		free(line);
	}
	return (content);
}

int	check_file(char *content, t_wireframe *wireframe)
{
	int		i;
	int		j;
	char	*tmp;

	wireframe->altitudes = (int **)malloc(sizeof(int *) * wireframe->y_len);
	if (!wireframe->altitudes)
		return (0);
	wireframe->x_len = count_x_len(content);
	i = 0;
	while (i < wireframe->y_len)
	{
		j = 0;
		while (j < wireframe->x_len)
		{
			wireframe->altitudes[i] = malloc(sizeof(int) * wireframe->x_len);
			if (!wireframe->altitudes[i])
				return 0;
			wireframe->altitudes[i][j] = ft_atoi(content);
			while (*content && *content != ' ')
				content++;
			j++;
		}
		i++;
	}
	return (1);
}

t_wireframe	*parsing(char *file)
{
	t_wireframe	*wireframe;
	char		*content;
	int			ret;
	int			fd;

	wireframe = init_wireframe();
	if (!wireframe)
		return (free_wireframe(wireframe, 12));
	fd = open_file(file);
	if (fd < 0)
		return (free_wireframe(wireframe, 2));
	content = read_file(fd, wireframe);
	if (!content)
		return (free_wireframe(wireframe, 79));
	if (!check_file(content, wireframe))
		return (NULL);
	wireframe->camera.origin.x = wireframe->x_len / 2;
	wireframe->camera.origin.y = wireframe->y_len * 2;
	wireframe->camera.origin.z = 30;
	return (wireframe);
}