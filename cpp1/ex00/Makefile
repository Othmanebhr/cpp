NAME = Zombie
SRC = main.cpp \
	newZombie.cpp \
	randomChump.cpp \
	Zombie.cpp 
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std+c++98
OBJ = $(SRC:.cpp =.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -r $(OBJ)

fclean: clean
	rm -r $(NAME)

re: fclean all

.PHONY: all clean fclean re

