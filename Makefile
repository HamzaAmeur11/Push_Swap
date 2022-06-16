# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hameur <hameur@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 01:51:41 by hameur            #+#    #+#              #
#    Updated: 2022/06/16 18:25:42 by hameur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#_________Makefile________________________________

NAME := Push_Swap

CC := cc

CFLAGS := -Wall -Wextra -Werror

SRC :=	push_swap.c \
		stock_args/read_args.c \
		stacks/stack_new.c \
		stacks/stack_del.c \
		operations/operation_b.c \
		operations/operation_a.c \
		push_swap_utils.c \
		sort/sort.c \
		sort/sort_big.c \

OBJ := $(SRC:.c=.o)


###___Colors___###
RED= \033[0;31m
GREEN= \033[0;32m
YELLOW= \033[1;33m
WHITE= \033[0;37m

all: $(NAME)
	@echo "${YELLOW}Meking${GREEN} Push_Swap ${WHITE}..."
	
$(NAME): $(SRC)
	$(CC) $(FLAGS) $^ -o $@ -g

%.o : %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@ 
	
clean:
	@rm -rf Push_Swap

fclean: clean
	@rm -rf $(OBJ)
	
re: fclean all