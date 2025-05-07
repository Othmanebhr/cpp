NAME = my_phone
SRC = srcs/
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

FILES = ${SRC}main.cpp \
		${SRC}contact.cpp \
		${SRC}add_contact.cpp \
		${SRC}Phonebook.cpp \
		${SRC}search_contact.cpp \

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