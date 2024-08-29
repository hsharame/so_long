/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:18:42 by hsharame          #+#    #+#             */
/*   Updated: 2024/08/20 14:57:17 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *saved, char *buf)
{
	char	*temp;
	ssize_t	octets;

	octets = 1;
	while (!ft_newline(saved))
	{
		octets = read(fd, buf, BUFFER_SIZE);
		if (octets <= 0)
		{
			free(buf);
			if (octets < 0 || saved[0] == '\0')
			{
				free(saved);
				return (NULL);
			}
			return (saved);
		}
		buf[octets] = '\0';
		temp = ft_strjoin(saved, buf);
		free(saved);
		saved = temp;
	}
	free(buf);
	return (saved);
}

char	*ft_getline(char *saved)
{
	char	*line;
	size_t	j;

	j = 0;
	while (saved[j] != '\n' && saved[j] != '\0')
		j++;
	if (saved[j] == '\n')
		j++;
	line = ft_substr(saved, 0, j);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_conserve(char *saved)
{
	int		i;
	int		length;
	char	*stock;

	i = 0;
	while (saved[i] != '\n' && saved[i] != '\0')
		i++;
	if (saved[i] == '\n')
		i++;
	length = ft_strlen(saved) - i;
	stock = ft_substr(saved, i, length);
	if (!stock)
		return (NULL);
	free(saved);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char		*saved;
	char			*line;
	char			*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (!saved)
	{
		saved = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!saved)
			return (NULL);
		saved[0] = '\0';
	}
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	saved = ft_read(fd, saved, buf);
	if (saved != NULL && saved[0] != '\0')
	{
		line = ft_getline(saved);
		saved = ft_conserve(saved);
	}
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
