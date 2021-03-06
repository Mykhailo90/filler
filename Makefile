#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msarapii <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/10 11:43:53 by msarapii          #+#    #+#              #
#    Updated: 2018/11/10 11:43:54 by msarapii         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = msarapii.filler

CC = gcc
FLAGS = -Wall -Wextra -Werror

OBJ_DIR		= ./objects
LIB_DIR		= ./libft
LIB_INC		= $(LIB_DIR)/includes
SRC_DIR 	= ./src
INCL_DIR 	= ./includes
SRC_NAME	= \
				main.c\
	  			parsing.c\
				validate.c\
				service.c\
	  			print.c

OBJ_NAME	= $(SRC_NAME:.c=.o)
OBJ 		= $(addprefix $(OBJ_DIR)/, $(OBJ_NAME))
SRC 		= $(addprefix $(SRC_DIR)/, $(SRC_NAME))

all: $(NAME) bonus

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compilling:$<"
	@$(CC) $(FLAGS) -I $(LIB_INC) -I $(INCL_DIR) -c $< -o $@

$(NAME):
	@echo "Compilling LIBFT"
	@make -C libft
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) $(OBJ)
	@echo "Create bot"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) -I $(LIB_INC) -L $(LIB_DIR) -lft
	@cp $(NAME) players/

clean:
	@echo "Cleaning LIBFT objects"
	@make -C libft clean
	@echo "Cleaning objects"
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Cleaning LIBFT exe"
	@make -C libft fclean
	@echo "Cleaning exe"
	@/bin/rm -f $(NAME)
	@/bin/rm -f players/$(NAME)
	@/bin/rm -f ./visualisation

re: fclean all

bonus:
	$(CC) $(FLAGS) ./src/bonus.c $(LIB_DIR)/libft.a -o visualisation