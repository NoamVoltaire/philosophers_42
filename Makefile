# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noam <noam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/10 16:59:21 by noam              #+#    #+#              #
#    Updated: 2024/08/23 15:33:08 by noam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror
VPATH = srcs/ srcs/args/ srcs/utils/ srcs/inits/ 

ARGS = args init_table
UTILS = ft_atoui get_time write_action
INITS = init_philos init_sticks

SRCS = $(addsuffix .c, $(ARGS))\
		$(addsuffix .c, $(UTILS))\
		$(addsuffix .c, $(INITS))\
		a_table.c\
		diner.c\
		main.c
# echo :
	# @echo $(SRCS)
	
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:%.c=%.o))

# echo :
	#  @echo $(OBJ)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -o $@ $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) -c $(FLAGS) -o $@ $<

.PHONY : all clean fclean re

all : $(OBJ_DIR) $(NAME)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all