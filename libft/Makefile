# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/17 20:58:57 by cmissy            #+#    #+#              #
#    Updated: 2020/01/31 16:29:26 by cmissy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strsplit.c \
	ft_itoa.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putendl.c \
	ft_putnbr.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_n_len.c \
	ft_num_w.c \
	ft_push_w.c \
	ft_lstpush.c \
	ft_lstlen.c \
	ft_realloc.c \
	ft_isspace.c \
	get_next_line.c \
	ft_strjoin_free.c \
	ft_max.c \
	ft_all_isdigit.c\
	ft_swap.c\

OBJECTS = $(SRCS:.c=.o)

INCLUDES = ./

HEADER = ./libft.h

.PHONY: all clean fclean re reclean

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

./%.o: ./%.c $(HEADER)
	gcc -Wall -Wextra -Werror -g -I $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
