NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
UTILS_DIR = utils
INCLUDES = printf

MLX_DIR		= minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -lmlx -lXext -lX11 -lm

SRCS =	$(SRC_DIR)/actions.c \
		$(SRC_DIR)/colors.c \
		$(SRC_DIR)/fractals.c \
		$(SRC_DIR)/initialize.c \
		$(SRC_DIR)/main.c \
		$(SRC_DIR)/render.c \
		$(SRC_DIR)/utilities.c

UTILS = $(UTILS_DIR)/ft_memset.c \
		$(UTILS_DIR)/ft_strncmp.c \
		$(UTILS_DIR)/$(INCLUDES)/printf.c \
		$(UTILS_DIR)/$(INCLUDES)/printf_utils.c \

OBJS = $(SRCS:.c=.o) $(UTILS:.c=.o)

RM = rm -f

COLOR_MAGENTA		=	\033[0;95m
COLOR_LIGHT_GREEN   =   \033[0;92m

all: $(NAME)
$(NAME): $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(MLX_DIR) $(MLX_FLAGS) -o $(NAME)
	@echo "$(COLOR_LIGHT_GREEN)*MANDATORY fractol created successfully!"

$(MLX_LIB):
	make -C $(MLX_DIR)

clean:
	@echo "$(COLOR_MAGENTA)"
	$(RM) $(OBJS)
	make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME) $(MLX_LIB)

re: fclean all
