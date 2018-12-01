# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olbondar <olbondar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/02 14:28:57 by olbondar          #+#    #+#              #
#    Updated: 2018/11/11 12:03:55 by olbondar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= RTv1

NOC			= \033[0m
OKC			= \033[32m
ERC			= \033[31m
WAC			= \033[33m
TSC			= \033[94;1m

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
FRAMWRKS 	= -lmlx -framework OpenGL -framework AppKit

INC_PATH	= ./includes/
LFT_PATH	= ./libft/
MLX_PATH	= ./minilibx/
OBJ_PATH	= ./objs/
SRC_PATH	= ./srcs/

OBJECTS		= $(RESOURCES:.c=.o)
RESOURCES	= display.c \
				init_environment.c \
				hooks.c \
				inter.c \
				light.c \
				main.c \
				object.c \
				parser.c \
				pixel.c \
				reader.c \
				shadows.c \

INC_PFIX	= $(addprefix -I,$(INC_PATH))
OBJ_PFIX	= $(addprefix $(OBJ_PATH),$(OBJECTS))
SRC_PFIX	= $(addprefix $(SRC_PATH),$(RESOURCES))

all: $(NAME)

$(NAME): $(OBJ_PFIX)
	@echo
	@make -C $(LFT_PATH)
	@make -C $(MLX_PATH)
	@$(CC) -o $(NAME) $(OBJ_PFIX) -lm -L $(LFT_PATH) -L $(MLX_PATH) -lft $(FRAMWRKS)
	@echo "$(OKC)RTv1 is ready$(NOC)"


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC_PFIX) -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@make -C $(MLX_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "$(WAC)Removing RTv1 OBJECTS path$(NOC)"

fclean: clean
	@make -C $(LFT_PATH) fclean
	@make -C $(MLX_PATH) clean
	@rm -f $(NAME)
	@echo "$(WAC)Removing RTv1 executable$(NOC)"

re: fclean 
	$(MAKE) all

.PHONY: all, $(NAME), clean, fclean, re
