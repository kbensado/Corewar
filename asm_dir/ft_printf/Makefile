.SUFFIXES :

CFLAGS = 

NAME = libftprintf.a

SRC =	ft_atoi.c ft_isdigit.c ft_bzero.c ft_itoa.c ft_memdel.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlen.c ft_strlowcase.c ft_strrev.c ft_strupcase.c ft_printf.c ft_getpars.c ft_aff.c ft_aff_nb.c ft_aff2.c ft_llutoa.c ft_llongtoa.c ft_putwchar.c ft_convert.c ft_affconv.c ft_affconv2.c ft_getflag.c ft_aff_file.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ):
	@gcc $(CFLAGS) -c $(SRC)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean $(NAME) all