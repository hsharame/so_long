/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:52:12 by hsharame          #+#    #+#             */
/*   Updated: 2024/08/17 12:52:15 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define HEIGHT_MAX 
# define LENGTH_MAX

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		count;
	int		map_height;
	int		map_length;
	int		exit;
	int		player;
	int		x_player;
	int		y_player;
	int		collectible;
	int		collected;
	int		exit_found;
	void	**images;
}				t_data;

void	flood_fill(char **map, t_data *data, int x, int y);
int		check_accessibility(t_data *data, char **map);
int		check_size_map(int fd, t_data *data, char **map);
int		check_walls(t_data *data, char **map);
int		check_elements(t_data *data, char **map);

void	error_and_exit(t_data *data, char *error);
void	free_ressources(t_data *data);
void	free_map(char **map, int count);
int		close_window(t_data *data);

void	init_data(t_data *data);
void	init_game(t_data *data, int argc, char *argv[]);
void	init_map(int fd, t_data *data, char *file);
void	copy_map(t_data *data, char **map, int count);

int		check_argv(int argc, char *argv[], int fd);
int		check_extension(char *filename, char *extension);
int		count_lines(int fd);
void	ft_loop(char *line, int fd);

char	**init_images(void);
void	convert_to_images(t_data *data);
void	put_image(t_data *data);
void	choice_image(t_data *data, void *image, int *i, int *j);

void	find_coordinates_player(t_data *data, char **map);

int		ft_keypress(int keycode, t_data *data);
void	finish(t_data *data, int win);
void	move_player(t_data *data, int x, int y);

#endif
