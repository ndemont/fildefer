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

void	init_wireframe(t_wireframe *wireframe)
{
	wireframe->x_len = 0;
	wireframe->y_len = 0;
	wireframe->altitudes = NULL;
	wireframe->mlx_ptr = mlx_init();
	printf("w->mlx_ptr = %p\n", wireframe->mlx_ptr);
	wireframe->win_ptr = NULL;
	wireframe->img_ptr = NULL;
	wireframe->size = 0;
	wireframe->endian = 0;
	wireframe->bits_per_pixel = 0;
	wireframe->data_addr = NULL;
	wireframe->x_shift = 500;
	wireframe->y_shift = 200;
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
	content = NULL;
	line = NULL;
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
		while (j < w->x_len)
		{
			w->altitudes[i][j] = (float)ft_atoi(content);
			while (*content && *content != ' ')
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
	content = read_file(fd, wireframe);
	if (!content)
	{
		free_wireframe(wireframe, 79);
		return (0);
	}
	if (!check_file(content, wireframe))
		return (0);
	return (1);
}