/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:42:23 by hsharame          #+#    #+#             */
/*   Updated: 2024/08/21 13:42:35 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_and_exit(t_data *data, char *error)
{
	free_ressources(data);
	ft_printf("Error\n%s\n", error);
	exit(1);
}

void	free_ressources(t_data *data)
{
	int	i;

	i = 0;
	if (data->images)
	{
		while (i < 5 && data->images[i])
		{
			mlx_destroy_image(data->mlx, data->images[i]);
			i++;
		}
		free(data->images);
	}
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map)
		free_map(data->map, data->map_height);
}

void	free_map(char **map, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (map[i] != NULL)
			free(map[i]);
		i++;
	}
	free(map);
}

int	close_window(t_data *data)
{
	free_ressources(data);
	exit(0);
}
