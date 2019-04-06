NAME = [name].a

SRC =   [src/*]

OFILES = $(SRC:.c=.o)

FLAGS = -c -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) $(SRC)
		@ar -rcs $(NAME) $(OFILES)

clean:
		@rm -rf $(OFILES)

fclean: clean
		@rm -rf $(NAME)

re: fclean
	        @make
