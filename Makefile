# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 13:53:36 by cbarbit           #+#    #+#              #
#    Updated: 2022/03/07 14:49:30 by cbarbit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

PRINTF_DIRECTORY = ft_printf

PRINTF_A = libftprintf.a

PRINTF_PATH = ft_printf/libftprintf.a

LIBFT_DIRECTORY = libft

LIBFT_A = libft.a

LIBFT_PATH = libft/libft.a

C_FILES = errors/args_are_valid.c \
			errors/handle_overflow.c \
			errors/compare_args_values.c \
			errors/argv1_is_valid.c \
			errors/manipulate_argv1.c \
			handle_tables/init.c \
			handle_tables/check_stack_a.c \
			instructions/push.c \
			instructions/reverse_rotate.c \
			instructions/rotate.c \
			instructions/swap.c \
			push_swap.c \
			algorithms/algorithm_of_three.c \
			algorithms/algorithm_of_five.c \
			algorithms/main_algorithm.c \


O_FILES = ${C_FILES:.c=.o}

all: ${NAME}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${O_FILES} ${PRINTF_A} ${LIBFT_A}
	@${CC} ${O_FILES} ${PRINTF_PATH} ${LIBFT_PATH} -o ${NAME}

${PRINTF_A}:
	@(cd ${PRINTF_DIRECTORY} && ${MAKE})
	@cp ${PRINTF_PATH} .

${LIBFT_A}:
	@(cd ${LIBFT_DIRECTORY} && ${MAKE})
	@cp ${LIBFT_PATH} .

clean :
	@${RM} ${O_FILES}

fclean: clean
	@${RM} ${NAME} ${PRINTF_A} ${LIBFT_A}
	@cd ${PRINTF_DIRECTORY} && ${MAKE} $@
	@cd ${LIBFT_DIRECTORY} && ${MAKE} $@

re: fclean all

.PHONY: all clean fclean re
