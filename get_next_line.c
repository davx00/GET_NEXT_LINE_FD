/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: despanol <despanol@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:38:05 by despanol          #+#    #+#             */
/*   Updated: 2024/12/11 19:31:00 by despanol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	contains_newline(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*previous_line(const char *c)
{
	char	*result;
	int		i;

	i = 0;
	if (!c)
		return (NULL);
	while (c[i] && c[i] != '\n')
		i++;
	result = ft_calloc(i + 2, sizeof(*result));
	if (!result)
		return (NULL);
	i = 0;
	while (c[i] && c[i] != '\n')
	{
		result[i] = c[i];
		i++;
	}
	if (c[i] == '\n')
		result[i] = '\n';
	return (result);
}

void	*read_line(int fd, char *keep)
{
	int		bytes_read;
	char	*bff;
	char	*tmp;

	bff = malloc(sizeof(*bff) * (BUFFER_SIZE + 1));
	if (!bff)
		return (free(keep), NULL);
	bytes_read = read(fd, bff, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		bff[bytes_read] = '\0';
		tmp = ft_strjoin(keep, bff);
		if (!tmp)
			return (free(bff), free(keep), NULL);
		free(keep);
		keep = tmp;
		if (contains_newline(bff))
			break ;
		bytes_read = read(fd, bff, BUFFER_SIZE);
	}
	if (bytes_read < 0)
		return (free(bff), free(keep), NULL);
	return (free(bff), keep);
}

char	*ft_update_static(const char *keep)
{
	int		count;
	char	*x;
	int		i;
	int		count2;

	if (!keep)
		return (NULL);
	count2 = 0;
	count = 0;
	while (keep[count] && keep[count] != '\n')
		count++;
	if (!keep[count])
		return (NULL);
	count++;
	count2 = ft_strlen(keep + count);
	x = ft_calloc(count2 + 1, sizeof(*x));
	if (!x)
		return (NULL);
	i = 0;
	while (i < count2)
	{
		x[i] = keep[count + i];
		i++;
	}
	return (x);
}

char	*get_next_line(int fd)
{
	static char	*keep;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = 0;
	keep = read_line(fd, keep);
	if (!keep)
		return (NULL);
	if (keep != NULL && *keep)
	{
		line = previous_line(keep);
		temp = keep;
		keep = ft_update_static(keep);
		free(temp);
	}
	if (!line || *line == '\0')
	{
		free(keep);
		keep = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
