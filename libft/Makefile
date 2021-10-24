# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brattles <brattles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 20:25:41 by brattles          #+#    #+#              #
#    Updated: 2021/10/17 22:51:17 by brattles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:	all clean fclean re
.SUFFIXES:
.SUFFIXES: .c .o .h .d

NAME 	= libft.a

FUNCTIONS	= \
			  ft_bzero.c \
			  ft_memcpy.c \
			  ft_strlen.c \
			  ft_tolower.c \
			  ft_isalpha.c \
			  ft_isdigit.c \
			  ft_isascii.c \
			  ft_isalnum.c \
			  ft_strlcpy.c \
			  ft_strlcat.c \
			  ft_atoi.c \
			  ft_strchr.c \
			  ft_strcmp.c \
			  ft_strncmp.c \
			  ft_calloc.c \
			  ft_strdup.c \
			  ft_putchar_fd.c \
			  ft_putstr_fd.c \
			  ft_split.c \
			  ft_strtrim.c \
			  ft_substr.c \
			  ft_itoa.c \
			  ft_strjoin.c

OBJ		= $(patsubst %.c, %.o, $(FUNCTIONS))
D_FILE  = $(patsubst %.c, %.d, $(FUNCTIONS))

CFLAGS 	= -Wall -Wextra -Werror
CC		= gcc

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $?
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@ -MD

include $(wildcard $(D_FILE))

clean:
	rm -f $(OBJ)
	rm -f $(D_FILE)
fclean: clean
	rm -f $(NAME)
re: fclean all
