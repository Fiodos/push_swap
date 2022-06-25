# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fyuzhyk <fyuzhyk@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 10:34:41 by fyuzhyk           #+#    #+#              #
#    Updated: 2022/06/24 13:17:17 by fyuzhyk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
SRC_DIR = src
OBJ_DIR = .

CHECK = checker
PUSH = push_swap.o
PUSH_LIB = push_swap.a
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)
SRC_LIBFT = $(wildcard $(LIBFT_DIR)/*.c)
OBJ_LIBFT = $(SRC_LIBFT:$(LIBFT_DIR)/%.c=$(LIBFT_DIR)/%.o)

all: $(NAME)

bonus: $(PUSH_LIB)
	$(CC) $(CFLAGS) checker.c $(PUSH_LIB) -o $(CHECK)

$(NAME): $(PUSH_LIB)
	$(CC) $(CFLAGS) push_swap.c $(PUSH_LIB) -o $(NAME)

$(PUSH_LIB): $(OBJ) $(OBJ_LIBFT)
	ar rc $(PUSH_LIB) $(OBJ) $(OBJ_LIBFT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

fclean: clean
	rm -f $(NAME) $(PUSH_LIB) $(CHECK) libft/libft.a

clean:
	rm -f $(OBJ) $(OBJ_LIBFT)

re: fclean all
