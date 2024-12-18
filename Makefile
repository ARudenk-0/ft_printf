# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 19:35:46 by arudenko          #+#    #+#              #
#    Updated: 2024/12/18 23:15:02 by arudenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Source files
SRCS		= ft_printf.c ft_printf_utils.c ft_printf_spec_print.c ft_printf_flags_functions.c

# Object files
OBJS		= $(SRCS:.c=.o)

# Compiler and flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# Library name
NAME		= libftprintf.a

# Path to libft
LIBFT		= libft/libft.a
# LIBFT_OBJS := $(shell find libft -name "*.o")

# Rules
all:		$(NAME)

# Compile the ft_printf library
$(NAME):	$(OBJS) $(LIBFT)
			make -C libft
			cp libft/libft.a .
			ar -x libft.a
			ar rcs $(NAME) $(OBJS) *.o
			$(RM) *.o libft.a

# Compile libft if necessary
# $(LIBFT):
# 			make -C libft

# Clean only ft_printf object files
clean:
			$(RM) $(OBJS)
			make clean -C libft

# Clean all generated files
fclean:		clean
			$(RM) $(NAME)
			make fclean -C libft

# Recompile everything
re:			fclean all

# Debugging info
debug:
			@echo "SRCS = $(SRCS)"
			@echo "OBJS = $(OBJS)"
			@echo "LIBFT_OBJS = $(LIBFT_OBJS)"

# Phony targets
.PHONY:		all clean fclean re debug