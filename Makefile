NAME = fractol
SRC = main.c \
	  mandle.c \
	  hooks.c \
	  julia.c \
	  mandle3.c
			
	
LIBDIR = libft
LIB = libft/libft.a
FLAG = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME):
	@make -C $(LIBDIR)
	@gcc $(FLAGS) -o $(NAME) $(SRC) $(LIB) -lmlx -framework OpenGL -framework AppKit 

clean:
	 @make clean -C $(LIBDIR)

fclean:	clean
	@make fclean -C $(LIBDIR)
	@rm -rf $(NAME)

re: fclean all
