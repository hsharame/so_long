/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:50:46 by hsharame          #+#    #+#             */
/*   Updated: 2024/08/28 18:50:58 by hsharame         ###   ########.fr       */
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

	(keycode = 119 || keycode == 65362) - w/Up
	(keycode = 97 || keycode == 653621) - a/Left
	(keycode = 115 || keycode == 65364) - s/Down
	(keycode = 100 || keycode == 65363) - d/Right
*/

int	ft_keypress(int keycode, t_data *data)
{
	if (keycode == 65307 || keycode == 113)
		finish(data, 0);
	else if (keycode == 119 || keycode == 65362)
		move_player(data, 0, -1);
	else if (keycode == 97 || keycode == 65361)
		move_player(data, -1, 0);
	else if (keycode == 115 || keycode == 65364)
		move_player(data, 0, 1);
	else if (keycode == 100 || keycode == 65363)
		move_player(data, 1, 0);
	return (0);
}

void	finish(t_data *data, int win)
{
	if (win)
		ft_printf("Congratulation!\n");
	else
		ft_printf("Game over :(\n");
	free_ressources(data);
	exit (0);
}

void	move_player(t_data *data, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = data->x_player + x;
	new_y = data->y_player + y;
	if (data->map[new_y][new_x] == '1' || (data->map[new_y][new_x] == 'E' &&
		data->collectible != 0))
		return ;
	else
	{
		if (data->map[new_y][new_x] == 'C')
			data->collectible--;
		if (data->map[new_y][new_x] == 'E' && data->collectible == 0)
			finish(data, 1);
		data->map[data->y_player][data->x_player] = '0';
		data->x_player = new_x;
		data->y_player = new_y;
		data->map[new_y][new_x] = 'P';
		data->count++;
		ft_printf("Total movement count: %d\n", data->count);
		put_image(data);
	}
}
