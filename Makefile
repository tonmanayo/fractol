NAME = fractol
SRC = main.c \
	  mandle.c \
	  hooks.c \
	  julia.c
	
LIBDIR = libft
LIB = libft/libft.a
FLAG = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME):
	@make -C $(LIBDIR)
	@gcc $(FLAGS) -o $(NAME) $(SRC) $(LIB) -L/usr/X11/lib -lmlx -lXext -lX11 -lm -g 

clean:
	 @make clean -C $(LIBDIR)

fclean:	clean
	@make fclean -C $(LIBDIR)
	@rm -rf $(NAME)

re: fclean all
