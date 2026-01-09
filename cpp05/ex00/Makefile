CXX	=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
NAME	=	bureaucrat
SRC	=	$(shell find -name "*.cpp")
OBJ_D	= obj
OBJ	=	$(SRC:%.cpp=$(OBJ_D)/%.o)

$(OBJ_D)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_D)

fclean: clean
	rm -f $(NAME)

re: fclean all