CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = easyfind

all: $(NAME)

$(NAME): main.cpp easyfind.hpp easyfind.tpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(NAME)

clean:

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean
