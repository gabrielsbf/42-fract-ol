NAME = fractol

#DIRECTORIES
SRCS_DIR = ./srcs/

BUILD_DIR= ./build/

INCLUDES_DIR = ./includes/

MINILIBX_DIR = ./minilibx/

LIBFT_DIR = ./libft/

# COMPILATION
CC = cc

FLAGS = -Wall -Wextra -Werror

COMPILE = $(CC) $(FLAGS)

MINILIBX_ARGS = -lXext -lX11 -lm

#GETTING THE SOURCES OF THE PROJECT
RAW_SRCS = $(shell find $(SRCS_DIR))

SRCS = $(filter %.c, $(RAW_SRCS))

SRCS_OBJ = $(SRCS:%.c=$(BUILD_DIR)%.o)

#OTHER DEPENDENCIES
MINILIBX_A = $(MINILIBX_DIR)libmlx.a

LIBFT_A = $(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(LIBFT_A) $(MINILIBX_A) $(SRCS_OBJ)
	$(COMPILE) $(SRCS_OBJ) $(MINILIBX_A) $(MINILIBX_ARGS) $(LIBFT_A) -o $(NAME)

$(BUILD_DIR)%.o : %.c
	mkdir -p $(dir $@)
	$(COMPILE) -c $< -o $@

$(LIBFT_A):
	cd $(LIBFT_DIR) && make && cd ..

$(MINILIBX_A):
	cd $(MINILIBX_DIR) && make && cd ..

clean:
	rm -f $(SRCS_OBJ)
	cd $(LIBFT_DIR) && make clean && cd ..
	cd $(MINILIBX_DIR) && make clean && cd ..

fclean: clean
	rm -f $(NAME) $(LIBFT_A) $(MINILIBX_A)

re: fclean all

.PHONY: all object clean fclean re
