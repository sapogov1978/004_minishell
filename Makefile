# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brattles <brattles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/03 22:04:05 by brattles          #+#    #+#              #
#    Updated: 2021/10/20 00:11:02 by brattles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minishell

CC			:= gcc
WFLAGS		:= -Wall -Wextra -Werror -MMD

INC_DIR		:= ./includes
OBJ_DIR		:= ./build
FT_DIR		:= ./libft

FUNCTIONS	=	a_main.c \
				b_shells_loop.c \
				c_parser.c \
				c_parser1.c \
				c_parser2.c \
				c_parser3.c \
				c_parser4.c \
				d_home_path.c \
				e_double_quotes.c \
				f_simple_quotes.c \
				g_dollars.c \
				h_slash.c \
				h_slash2.c \
				i_exec1.c \
				i_exec2.c \
				i_exec3.c \
				k_env_utils.c \
				k_free_utils.c \
				k_free_utils2.c \
				k_heredoc.c \
				k_lists_utils.c \
				k_pipesrch_utils.c \
				k_str_utils.c \
				k_split_ms.c \
				k_split_ms2.c \
				l_signals_handlers.c \
				builtins/cd.c \
				builtins/echo.c \
				builtins/env.c \
				builtins/exit.c \
				builtins/export.c \
				builtins/export2.c \
				builtins/pwd.c \
				builtins/unset.c

OBJ			:= $(FUNCTIONS:%.c=$(OBJ_DIR)/%.o)
DEP			:= $(OBJ:%.o=%.d)
CFLAGS		:= $(WFLAGS) -g

LFLAGS		:= -lft
FT_LIB		+= -L$(FT_DIR)

LIB			:= $(FT_LIB)
INC			:= -I$(FT_DIR) -I$(INC_DIR)

vpath %.c src

.PHONY:	all clean fclean re debug

all: m $(NAME)

$(NAME): $(OBJ)
	make -sC $(FT_DIR) all
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(INC) $(LFLAGS) -lreadline -o $(NAME)

-include $(DEP)
$(OBJ_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	make -sC $(FT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -sC $(FT_DIR) fclean
	rm -rf $(NAME)

re: fclean all

m:
	@echo "███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     "
	@echo "████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     "
	@echo "██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     "
	@echo "██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     "
	@echo "██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗"
	@echo "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝"
