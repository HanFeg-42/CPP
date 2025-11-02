CPP	=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
NAME	=	megaphone
SRC	=	megaphone.cpp
OBJ	=	megaphone.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all