SRC_DIR = src
# HEADER_DIR = inc
OBJS_DIR = obj

SRCS = PhoneBook Contact
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
SRCS := $(addsuffix .cpp, $(SRCS))

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJS_DIR)/%.o)

# HEADERS = PhoneContacts
# HEADERS := $(addsuffix .hpp, $(HEADERS))
# HEADERS := $(addprefix $(HEADERS_DIR)/, $(HEADERS))

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = PhoneBook

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJS_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
			mkdir -p $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
