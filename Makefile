# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/15 15:17:43 by hagoodwi          #+#    #+#              #
#    Updated: 2020/11/15 15:26:37 by hagoodwi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG	=	-g -Wall -Wextra -Werror
NAME	=	hagoodwi.filler
SRC_DIR	=	./src/
OBJ_DIR =	./obj/
INC_DIR	=	./inc/
HEAD	=	./inc/filler.h

LIB_INC	=	-I ./libft/ -I ./inc/
LIB_BIN	=	-L ./libft -lft

CFILES	=	main.c			\
			calc_coords.c	\
			calc_heat_map.c	\
			free.c			\
			init.c			\
			parse_board.c	\
			parse_player.c	\
			parse_size.c	\
			parse_token.c

SRC		=	$(addprefix $(SRC_DIR), $(CFILES))

OFILES	=	$(patsubst %.c, %.o, $(CFILES))
OBJ		=	$(addprefix $(OBJ_DIR), $(OFILES))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	make -C ./libft
	gcc $(FLAG) $(LIB_INC) $(LIB_BIN) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEAD)
	gcc $(FLAG) $(LIB_INC) -o $@ -c $<;

clean:
	make clean -C ./libft
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all