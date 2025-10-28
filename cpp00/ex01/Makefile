CPP	=	c++
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	phonebook
SRC	=	$(shell find -name "*.cpp")
OBJ_D	= obj
OBJ	=	$(SRC:%.c=$(OBJ_D)/%.o)
$(OBJ_D)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ_D)

fclean: clean
	rm -f $(NAME)

re: fclean all