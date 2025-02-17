NAME = Convert
SRC = main.cpp ScalarConverter.cpp Data.cpp

OBJS = $(SRC:.cpp=.o)
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 

all: $(NAME)
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1m\033[1;33mCompilation finished \033[0m" 
	@echo "\033[1m\033[1;34mProgram is ready ./$(NAME)\033[0m" 

%.o: %.cpp
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@echo "\033[1m\033[4;32mObject files cleaned !\033[0m"


fclean: clean
	@rm -f $(NAME)
	@echo "\033[1m\033[4;32mAll files cleaned !\033[0m"


re: fclean all

.PHONY: all clean fclean
