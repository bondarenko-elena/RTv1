# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olbondar <olbondar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/02 14:28:57 by olbondar          #+#    #+#              #
#    Updated: 2018/12/08 17:13:47 by olbondar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := RTv1

SRC := display.c \
		fresher.c \
		gets.c \
		gets_p2.c \
		hooks.c \
		init_env.c \
		inter.c \
		light.c \
		light_p2.c \
		main.c \
		object.c \
		parser.c \
		pixel.c \
		reader.c \
		shadows.c \

CC := gcc
SRC := $(addprefix srcs/,$(SRC))
OBJ := $(SRC:.c=.o)
HEADLIB := libft/
HEADMLX := /usr/local/include
CFLAGS := -Wall -Wextra -Werror
LIBMLX := /usr/local/lib
FRAMEWS := -lmlx -framework OpenGL -framework AppKit

all: create_lib $(NAME)

create_lib:
	@make -C libft

$(NAME): $(OBJ)
	@CC -o $(NAME) $(OBJ) libft/libft.a -L $(LIBMLX) $(FRAMEWS)
	@echo "\033[32mRTv1 is ready.\033[0m"

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $< -I $(HEADLIB) -I $(HEADMLX) -I includes

clean:
	@rm -rf $(OBJ)
	@echo "\033[32mOK.\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft

re: fclean all
	@echo "\033[32mOK.\033[0m"

.PHONY: create_lib all clean fclean re
