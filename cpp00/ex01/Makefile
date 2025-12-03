CC	=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
NAME	=	phonebook
SRC	=	$(shell find -name "*.cpp")
OBJ_D	= obj
OBJ	=	$(SRC:%.cpp=$(OBJ_D)/%.o)

$(OBJ_D)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_D)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re