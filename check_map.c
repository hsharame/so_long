/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:31:47 by hsharame          #+#    #+#             */
/*   Updated: 2024/08/20 13:32:04 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	y
	|
	|
	|
	|
	___________ x	
*/

void	flood_fill(char **map, t_data *data, int x, int y)
{
	if (x < 0 || y >= data->map_height || y < 0 || x >= data->map_length
		|| map[y][x] == 'V' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
		data->exit_found++;
	else if (map[y][x] == 'C')
		data->collected++;
	map[y][x] = 'V';
	flood_fill(map, data, x - 1, y);
	flood_fill(map, data, x + 1, y);
	flood_fill(map, data, x, y - 1);
	flood_fill(map, data, x, y + 1);
}

int	check_accessibility(t_data *data, char **map)
{
	find_coordinates_player(data, map);
	copy_map(data, map, data->map_height);
	flood_fill(map, data, data->x_player, data->y_player);
	if (data->collected != data->collectible || data->exit_found == 0)
		return (0);
	return (1);
}

int	check_size_map(int fd, t_data *data, char **map)
{
	char	*line;
	int		length;
	int		i;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map[i] = ft_strdup(line);
		length = ft_strlen(line) - 1;
		if (data->map_length <= 0)
			data->map_length = length;
		if (data->map_length != length)
		{
			free(line);
			ft_loop(line, fd);
			return (0);
		}
		free(line);
		i++;
	}
	return (1);
}

int	check_walls(t_data *data, char **map)
{
	int	i;

	i = 0;
	while (i < data->map_length)
	{
		if (map[0][i] != '1' || map[data->map_height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < data->map_height)
	{
		if (map[i][0] != '1' || map[i][data->map_length - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_elements(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_length)
		{
			if (map[i][j] == 'P')
				data->player++;
			else if (map[i][j] == 'E')
				data->exit++;
			else if (map[i][j] == 'C')
				data->collectible++;
			j++;
		}
		i++;
	}
	if (data->player != 1 || data->exit != 1 || data->collectible < 1)
		return (0);
	return (1);
}
