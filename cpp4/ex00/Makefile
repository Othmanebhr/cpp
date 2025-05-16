NAME = Animals
SRC = srcs/
FILES = $(SRC)main.cpp \
		$(SRC)Animal.cpp \
		$(SRC)Cat.cpp \
		$(SRC)Dog.cpp \
		$(SRC)WrongAnimal.cpp \
		$(SRC)WrongCat.cpp
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
OBJ = $(FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re