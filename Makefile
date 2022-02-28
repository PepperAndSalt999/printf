GCC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = ./include/ft_printf.h

NAME = libftprintf.a

OBJECTS = ./srcs/ft_printf.o \
		./srcs/convert.o 

.PHONY: all fclean clean re

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C ./libft
	cp ./libft/libft.a ./libftprintf.a
	ar cr $@ $^

$(OBJECTS): $(HEADER)

clean:
	rm -f $(OBJECTS) && make clean -C ./libft/

fclean: clean
	rm -f $(NAME) && make fclean -C ./libft/

re:	fclean all
