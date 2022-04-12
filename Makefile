# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcerrito <dcerrito@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 08:06:16 by dcerrito          #+#    #+#              #
#    Updated: 2022/04/12 04:33:26 by dcerrito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
CC = gcc
PACK = ar rcs
FRM = rm -rf
CFLAGS = -Wall -Wextra -Werror
GNL_FILES = \
	get_next_line.c 	\
	get_next_line_utils.c \

GNL_OBJS = $(patsubst %.c, %.o, $(GNL_FILES))
$(NAME): $(GNL_OBJS)
	$(PACK) $(NAME) $(GNL_OBJS)
all: $(NAME)
clean:
	$(FRM) $(GNL_OBJS)
fclean: clean
	$(FRM) $(NAME)
re: fclean all
.PHONY: re clean fclean all