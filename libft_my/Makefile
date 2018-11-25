# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olbondar <olbondar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/02 14:28:57 by olbondar          #+#    #+#              #
#    Updated: 2018/11/25 16:27:09 by olbondar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -c -Wall -Wextra -Werror
SRC = ft_atoi.c \
		ft_bzero.c \
		ft_clamp.c \
		ft_countwords.c \
		ft_isalnum.c \
		ft_isalnumstr.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isdigitstr.c \
		ft_islower.c \
		ft_isprint.c \
		ft_isupper.c \
		ft_itoa.c \
		ft_lstadd_back.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_max.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_min.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strlen_ch.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line.c \
		vector_add.c \
		vector_clamp.c \
		vector_cross.c \
		vector_distance.c \
		vector_divide.c \
		vector_length.c \
		vector_multiply.c \
		vector_normalization.c \
		vector_op_add.c \
		vector_op_divide.c \
		vector_op_multiply.c \
		vector_reflect.c \
		vector_scalar_multiply.c \
		vector_substract.c \
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mLibft is built.\033[0m"

.c.o:
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: @fclean all

.PHONY: all clean fclean re
