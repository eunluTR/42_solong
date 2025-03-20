NAME 			= so_long

CC				= cc
CFLAGS			= -Wall -Wextra -Werror

SRC_FILES 		= get_next_line.c \
				  get_next_line_utils.c \
				  map.c \
				  main.c \
				  error.c \
				  control.c \
				  

OBJ_FILES		= $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES) 
	$(MAKE) -C libft
	$(MAKE) -C libft bonus
	$(CC) $(CFLAGS) $(OBJ_FILES) ./libft/libft.a -o $(NAME)

clean:
	rm -f $(OBJ_FILES)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
