/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alprival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 12:50:51 by alprival          #+#    #+#             */
/*   Updated: 2022/05/10 12:51:06 by alprival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	if (!s)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (unsigned char )c)
			return (str + i);
		i++;
	}
	if ((unsigned char )c == '\0')
		return (str + i);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		j;
	int		len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	i = -1;
	j = 0;
	tab = malloc(sizeof(char) * len + 1);
	if (!tab)
		return (NULL);
	while (s1 && s1[++i])
		tab[i] = s1[i];
	j = i - 1;
	i = -1;
	while (s2 && s2[++i])
		tab[++j] = s2[i];
	tab[j + 1] = 0;
	free(s1);
	return (tab);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*str;
	unsigned int		i;
	size_t				j;

	if (!s || !len)
		return (NULL);
	if (start > ft_strlen(s))
	{
		str = ft_calloc(1, sizeof(char));
		return (str);
	}
	else if (start + len < ft_strlen(s))
		str = ft_calloc((len + 1), sizeof(char));
	else
		str = ft_calloc((ft_strlen(s) - start + 1), sizeof(char));
	if (!str || !s)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (i >= start && j < len)
			str[j++] = s[i];
	}
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	int		i;
	int		len;

	if (nmemb > 2147483647 || size > 2147483647 || size * nmemb > 2147483647)
		return (0);
	len = (nmemb * size);
	i = 0;
	tab = malloc(len);
	if (!tab)
		return (0);
	while (i < len)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
