/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:38:28 by despanol          #+#    #+#             */
/*   Updated: 2024/12/01 12:38:30 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	total_size;
	char	*ptr;
	size_t	i;

	total_size = count * size;
	result = malloc(total_size);
	if (!result)
		return (NULL);
	ptr = result;
	i = 0;
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	s1_len;
	size_t	s2_len;
	size_t	cont;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	cont = 0;
	new_string = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (new_string == NULL)
		return (NULL);
	while (s1 && s1[cont] != '\0')
	{
		new_string[cont] = s1[cont];
		cont++;
	}
	cont = 0;
	while (s2 && s2[cont] != '\0')
	{
		new_string[cont + s1_len] = s2[cont];
		cont++;
	}
	new_string[s1_len + s2_len] = '\0';
	return (new_string);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	str;
	size_t	lon;

	lon = 0;
	lon = ft_strlen(src);
	if (dst != NULL && dstsize != 0)
	{
		str = 0;
		while ((str < lon) && str < (dstsize - 1))
		{
			dst[str] = src[str];
			str++;
		}
		dst[str] = '\0';
	}
	return (lon);
}

size_t	ft_strlen(const char *str)
{
	size_t	strlen;

	strlen = 0;
	if (str == NULL)
		return (0);
	while (str[strlen] != '\0')
		strlen++;
	return (strlen);
}

void	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		size;
	int		i;

	size = ft_strlen(s1);
	ptr = malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[size] = '\0';
	return (ptr);
}
