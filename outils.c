/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:39:19 by hsharame          #+#    #+#             */
/*   Updated: 2024/08/20 14:39:33 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_argv(int argc, char *argv[], int fd)
{
	if (fd < 0)
		return (0);
	if (!check_extension(argv[1], ".ber"))
		return (0);
	if (argc != 2)
		return (0);
	return (1);
}

int	check_extension(char *filename, char *extension)
{
	int	i;
	int	j;

	i = ft_strlen(filename) - 1;
	j = 3;
	while (j >= 0)
	{
		if (filename[i] != extension[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}

int	count_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		free(line);
	}
	return (count);
}

void	ft_loop(char *line, int fd)
{
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
	}
}
