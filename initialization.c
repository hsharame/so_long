/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:06:52 by hsharame          #+#    #+#             */
/*   Updated: 2024/08/20 13:07:11 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		error_and_exit(data, "MLX initialization failed");
	data->player = 0;
	data->mlx_win = NULL;
	data->exit = 0;
	data->collectible = 0;
	data->map_height = 0;
	data->map_length = 0;
	data->collected = 0;
	data->count = 0;
	data->x_player = 0;
	data->y_player = 0;
	data->exit_found = 0;
	data->images = NULL;
	data->map = NULL;
}

void	init_game(t_data *data, int argc, char *argv[])
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (!check_argv(argc, argv, fd))
	{
		close(fd);
		error_and_exit(data, "Input is invalid");
	}
	init_map(fd, data, argv[1]);
	close(fd);
	data->mlx_win = mlx_new_window(data->mlx, data->map_length * 32,
			data->map_height * 32, "so_long");
	if (!data->mlx_win)
		error_and_exit(data, "MLX window initialization failed");
}

void	copy_map(t_data *data, char **map, int count)
{
	int	i;

	i = 0;
	data->map = (char **)malloc(sizeof(char *) * count);
	if (!data->map)
		error_and_exit(data, "Memory allocation failed");
	while (i < count)
	{
		data->map[i] = ft_strdup(map[i]);
		if (!data->map[i])
		{
			free_map(data->map, i);
			error_and_exit(data, "Memory allocation failed");
		}
		i++;
	}
}

void	init_map(int fd, t_data *data, char *file)
{
	int		count;
	char	**map;

	count = count_lines(fd);
	data->map_height = count;
	map = (char **)ft_calloc(sizeof(char *), count);
	if (!map)
		return ;
	close(fd);
	fd = open(file, O_RDONLY);
	if (!check_size_map(fd, data, map)
		|| !check_walls(data, map) || !check_elements(data, map)
		|| !check_accessibility(data, map))
	{
		free_map(map, count);
		error_and_exit(data, "Map is invalid");
	}
	if (data->map_height < 3 || data->map_height > 60
		|| data->map_length > 33)
	{
		free_map(map, count);
		error_and_exit(data, "Map is too big or too small");
	}
	close(fd);
	free_map(map, count);
}
