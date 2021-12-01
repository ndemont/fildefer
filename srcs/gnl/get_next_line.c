/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 20:29:12 by ndemont           #+#    #+#             */
/*   Updated: 2021/12/01 10:59:37 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_line_found(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_fill_line(char **tab, char **line, int var)
{
	char	*tmp;
	int		size_tab;

	size_tab = ft_strlen(*tab + var + 1);
	*line = ft_substr(*tab, 0, var);
	if (size_tab == 0)
	{
		free(*tab);
		*tab = NULL;
		return (1);
	}
	tmp = ft_substr(*tab, var + 1, size_tab);
	free(*tab);
	*tab = tmp;
	return (1);
}

int	ft_check_all(char **tab, char **line, int ret)
{
	int		var;

	if (ret < 0)
		return (-1);
	var = ft_line_found(*tab);
	if (*tab && var >= 0)
		return (ft_fill_line(tab, line, var));
	else if (*tab)
	{
		*line = ft_strdup(*tab);
		free(*tab);
		*tab = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*tab = 0;
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	int			var;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (tab == 0)
			tab = ft_strdup("");
		tab = ft_strjoin(tab, buf);
		var = ft_line_found(tab);
		if (var >= 0)
			return (ft_fill_line(&tab, line, var));
	}
	return (ft_check_all(&tab, line, ret));
}
