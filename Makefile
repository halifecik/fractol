NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
UTILS_DIR = utils
INCLUDES = /printf

SRCS =	$(SRC_DIR)/actions.c \
		$(SRC_DIR)/colors.c \
		$(SRC_DIR)/fractals.c \
		$(SRC_DIR)/initialize.c \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/render.c \
		$(SRC_DIR)/utilities.c

UTILS = $(UTILS_DIR)/ft_memset.c \
		$(UTILS_DIR)/ft_strncmp.c \
		$(UTILS_DIR)$(INCLUDES)/printf.c \
		$(UTILS_DIR)$(INCLUDES)/printf_utils.c \

OBJS = $(SRCS:.c=.o) $(UTILS:.c=.o)

INCLUDES = -I$(SRC_DIR) -I$(UTILS_DIR)

RM = rm -f

COLOR_MAGENTA		=	\033[0;95m
COLOR_LIGHT_GREEN   =   \033[0;92m

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME)
	@echo "$(COLOR_LIGHT_GREEN)*MANDATORY fractol created successfully!"

clean:
	@echo "$(COLOR_MAGENTA)"
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all