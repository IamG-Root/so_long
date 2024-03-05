# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scastagn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/02 11:58:56 by scastagn          #+#    #+#              #
#    Updated: 2023/03/02 11:59:01 by scastagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
OPTIONS = -c
SRCS = main.c check_map.c graphics.c controls.c utils.c get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
MINILIBX = /mlx
PRINTF = libftprintf.a

.o:.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all :		$(NAME)

$(NAME): $(OBJS)
	@make -C ./mlx
	@make -C ./ft_printf
	@cp ./mlx/libmlx.dylib .
	@cp ./ft_printf/libftprintf.a .
	$(CC) $(OBJS) -L . -lmlx -framework OpenGL -framework Appkit -o $(NAME) $(PRINTF) 

clean:
	@make -C ./mlx clean
	@make -C ./ft_printf clean
	${RM} ${OBJS}

fclean: clean
	rm -rf libmlx.dylib
	rm -rf libftprintf.a
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
