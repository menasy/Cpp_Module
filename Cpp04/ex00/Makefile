NAME = Animal
SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp #WrongAnimal.cpp WrongCat.cpp

OBJS = $(SRC:.cpp=.o)
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 

all: $(NAME)
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o: %.cpp
	@$(CC) $(CFLAGS) -c -o $@ $<
clean:
	@rm -f $(OBJS)
fclean: clean
	@rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean


