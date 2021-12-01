/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndemont <ndemont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:28:52 by ndemont           #+#    #+#             */
/*   Updated: 2021/12/01 09:29:38 by ndemont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dup;
	size_t	i;
	size_t	size;

	if (!s)
		return (0);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (0);
	i = 0;
	size = ft_strlen(s);
	while (i < len && (start + i) < size)
	{
		dup[i] = s[start + i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
