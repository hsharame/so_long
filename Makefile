# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsharame <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/17 12:54:53 by hsharame          #+#    #+#              #
#    Updated: 2024/08/17 12:54:56 by hsharame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a
MLX_DIR = ./mlx/

SRCS = ./gnl/get_next_line_utils.c ./gnl/get_next_line.c so_long.c \
		initialization.c check_map.c outils.c free_and_errors.c \
		init_images.c player.c keypress.c
OBJS = $(SRCS:.c=.o)
MAKE_MLX = make -C $(MLX_DIR)

INCLUDES = -I./libft -I/ft_printf -I./mlx 
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
		$(MAKE_MLX)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_FLAGS) $(INCLUDES)

$(LIBFT):
		make -C ./libft

$(PRINTF):
		make -C ./ft_printf

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
		$(RM) $(OBJS)
		make -C ./libft clean
		make -C ./ft_printf clean

fclean: clean
		$(RM) $(NAME)
		make -C ./libft fclean
		make -C ./ft_printf fclean
		$(MAKE_MLX) clean

re: fclean all

./PHONY: all clean fclean re