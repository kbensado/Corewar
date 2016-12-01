# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/21 02:48:50 by kbensado          #+#    #+#              #
#    Updated: 2016/10/09 21:07:08 by niborrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc

NAME =		asm

CFLAGS =	-Wall -Werror -Wextra

SRC =		list.c main.c launch.c scan.c create.c ft_strsplit2.c set_data.c error.c error2.c parse.c parser.c print.c macro.c macro2.c macro3.c \

OBJ =		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):		$(OBJ)
			@make -C libft
			@make -C ft_printf
			@$(CC) $(CFLAGS) -I libft -c $(SRC)
			@$(CC) $(CFLAGS) -I ft_printf -c $(SRC)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft -lft -L ft_printf -lftprintf
			@echo ... Compilation of THE_asm DONE !

clean:
			@rm -rf $(OBJ)
			@make clean -C libft
			@make clean -C ft_printf
			@echo ... Objects clean in THE_asm !

fclean:		clean
			@rm -rf $(NAME)
			@make fclean -C libft
			@make fclean -C ft_printf
			@echo ... Name clean in THE_asm !

re:			fclean all
			@echo ... THE_asm retry !


.PHONY: all, re, fclean, clean
