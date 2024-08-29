/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:52:06 by hsharame          #+#    #+#             */
/*   Updated: 2024/08/27 18:52:19 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_coordinates_player(t_data *data, char **map)
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
			{
				data->x_player = j;
				data->y_player = i;
				return ;
			}
			else
				j++;
		}
		i++;
	}
}
