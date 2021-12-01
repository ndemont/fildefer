/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:36:45 by ndemont           #+#    #+#             */
/*   Updated: 2021/12/01 09:31:57 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cpy_join(char *cat, char const *s1, char const *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		cat[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		cat[i] = *s2;
		i++;
		s2++;
	}
	cat[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	cat = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!cat)
		return (0);
	ft_cpy_join(cat, s1, s2);
	return (cat);
}
