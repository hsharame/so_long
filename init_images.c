/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:11:31 by hsharame          #+#    #+#             */
/*   Updated: 2024/08/22 17:11:44 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**init_images(void)
{
	char	**res;

	res = (char **)malloc(sizeof(char *) * 6);
	if (!res)
		error_and_exit("Initialization failed");
	res[0] = "./textures/tile.xpm";
	res[1] = "./textures/cactus.xpm";
	res[2] = "./textures/planet.xpm";
	res[3] = "./textures/rabbit.xpm";
	res[4] = "./textures/ufo.xpm";
	return (res);
}

void	convert_to_images(t_data *data)
{
	char	**images;
	int		i;
	int		width;
	int		height;

	i = 0;
	width = 32;
	height = 32;
	images = init_images();
	data->images = (void **)malloc(sizeof(void *) * 6);
	while (i < 5)
	{
		data->images[i] = mlx_xpm_file_to_image(data->mlx, images[i], &width, &height);
		if (data->images[i] == NULL)
			error_and_exit("Failed to load image");
		i++;
	}
	free(images);
}

void	put_image(t_data *data)
{
	int		i;
	int		j;
	void	*image;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_length)
		{
			if (data->map[i][j] == '1')
				image = data->images[1];
			else if (data->map[i][j] == '0')
				image = data->images[0];
			else if (data->map[i][j] == 'C')
				image = data->images[3];
			else if (data->map[i][j] == 'E')
				image = data->images[2];
			else if (data->map[i][j] == 'P')
				image = data->images[4];
			mlx_put_image_to_window(data->mlx, data->mlx_win, image,
				j * 32, i * 32);
			j++;
		}
		i++;
	}
}
