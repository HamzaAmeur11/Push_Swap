# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hameur <hameur@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 01:51:41 by hameur            #+#    #+#              #
#    Updated: 2022/06/25 20:39:51 by hameur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#_________Makefile________________________________
NAME = push_swap

BNS = checker

CC = gcc

INC = push_swap

FLAGS = -Wall -Wextra -Werror -g

HEADER = push_swap.h
BNS_HEADER = checker.h

SRC =	push_swap.c \
		stock_args/read_args.c \
		stacks/stack_new.c \
		stacks/stack_del.c \
		operations/operation_b.c \
		operations/operation_a.c \
		push_swap_utils.c \
		push_swap_utils2.c \
		sort/sort.c \
		sort/sort_big.c \
			  

OBJS = $(SRC:.c=.o)

BNS_SRC = 	checker.c\
			stock_args/read_args.c \
			stacks/stack_new.c \
			stacks/stack_del.c \
			operations/operation_b.c \
			operations/operation_a.c \
			operations/operations.c \
			push_swap_utils.c \
			push_swap_utils2.c \
			sort/sort.c \
			sort/sort_big.c \
			get_next_line/ft_putnbr_fd.c \
			get_next_line/ft_putstr_fd.c \
			get_next_line/ft_strdup.c \
			get_next_line/ft_strjoin.c \
			get_next_line/get_next_line.c \

BNS_OBJS = $(BNS_SRC:.c=.o)


###___Colors___###
RED= \033[0;31m
GREEN= \033[0;32m
YELLOW= \033[1;33m
WHITE= \033[0;37m

all : $(NAME)
	@echo "${YELLOW}Meking${GREEN} Push_Swap ${WHITE}..."
	
$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

bonus : $(BNS)
	@echo "${YELLOW}Meking${GREEN} Checker ${WHITE}Push_Swap ..."
	
$(BNS) : $(BNS_OBJS) 
	$(CC) $(FLAGS) $(BNS_OBJS) -o $(BNS)

clean : 
	@rm -rf $(OBJS) 
	@rm -rf $(BNS_OBJS)

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(BNS)

re : fclean all