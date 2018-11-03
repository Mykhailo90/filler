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

NAME = "filler"

FLAFS = "-Wall -Wexta -Werror"

FT_PRINTF = libft/libftprintf.a

SRC =  ./SRC/main.c ./SRC/start_game.c ./SRC/init_game_param.c \
		./SRC/search_geimer.c ./SRC/find_place.c ./SRC/search_filler.c \
		./SRC/search_map.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ) : %.o: %.c
		@gcc $(FLAGS) -I ./SRC/ -I ./libft/ -o $@ -c $<

$(NAME): $(OBJ)
		@make -C libft/
		@gcc -o $(NAME) $(OBJ) $(FT_PRINTF)

#%.o: %.c
#	@gcc $(FLAGS) -o $@ -c $<

clean:
		@/bin/rm -f $(OBJ)
		@make -C libft/ clean

fclean: clean
		@/bin/rm -f $(NAME)
		@make -C libft/ fclean

re: fclean all

