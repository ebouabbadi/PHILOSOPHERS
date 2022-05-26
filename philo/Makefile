# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 10:15:35 by ebouabba          #+#    #+#              #
#    Updated: 2022/05/26 18:37:26 by ebouabba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
RED = \033[1;31m
GREEN = \033[1;36m
SRC_FILE =	philo.c  philo_utils1.c philo_utils2.c

OBJ_FILE = $(SRC_FILE:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ_FILE) philo.h
	@$(CC)  $(OBJ_FILE) -lpthread -o $(NAME)
	@echo "$(GREEN)--> Compiled success"

%.o: %.c
	@$(CC)  -c $< -o $@

clean:
	@$(RM) $(OBJ_FILE)
	@echo "$(RED)--> Object files cleaned"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)--> Name cleaned"

re: fclean all

.PHONY: all clean fclean re