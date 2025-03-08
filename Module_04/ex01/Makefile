OBJS_DIR = obj

SRCS = main Animal Cat Dog WrongAnimal WrongCat Brain
SRCS := $(addsuffix .cpp, $(SRCS))

OBJS = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = animals

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
			mkdir -p $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re