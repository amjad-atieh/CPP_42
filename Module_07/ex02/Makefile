OBJS_DIR = obj

SRCS = main
SRCS := $(addsuffix .cpp, $(SRCS))

HEADERS = Array.hpp

OBJS = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Array

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: %.cpp $(HEADERS) | $(OBJS_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
			mkdir -p $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
