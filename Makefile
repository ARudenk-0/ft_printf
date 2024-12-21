# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 19:35:46 by arudenko          #+#    #+#              #
#    Updated: 2024/12/21 20:59:52 by arudenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library name
NAME			=	libftprintf.a

# Compiler and flags
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

# Source files
SRC				=	ft_printf.c ft_printf_char_utils.c ft_printf_spec_print.c ft_printf_flags_functions.c ft_printf_initializing.c ft_printf_num.c

# Object files
OBJS			=	$(SRC:.c=.o)

# Path to libft
LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

# Default rule
all: $(NAME)

# Create the combined library
$(NAME): $(OBJS) $(LIBFT)
	@echo "Creating $(NAME) with linked libft..."
	cp $(LIBFT) $(NAME)                    # Copy libft.a to libftprintf.a
	$(AR) x $(LIBFT)                       # Extract object files from libft.a
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) *.o   # Add ft_printf objects and extracted libft objects to libftprintf.a
	$(RM) *.o                              # Remove temporary object files from libft

# Rule for object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# $< The name of the first prerequisite.
# $@ The file name of the target of the rule.

# Compile libft
$(LIBFT):
	@echo "Compiling libft..."
	make -C $(LIBFT_PATH)

# Clean up object files
clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_PATH) clean

# Full cleanup
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re

# # Source files for ft_printf
# SRCS		= ft_printf.c ft_printf_utils.c ft_printf_spec_print.c ft_printf_flags_functions.c

# # Object files
# OBJS		= $(SRCS:.c=.o)

# # Compiler and flags
# CC			= cc
# CFLAGS		= -Wall -Wextra -Werror

# # Library name
# NAME		= libftprintf.a

# # Path to libft
# LIBFT		= libft/libft.a

# # Rules
# all:		$(NAME)

# # Compile the ft_printf library
# $(NAME):	$(OBJS) $(LIBFT)
# 			ar rcs $(NAME) $(OBJS)
# 			ar rcs $(NAME) $(LIBFT)

# # Compile libft if necessary
# $(LIBFT):
# 			make -C libft

# # Clean only ft_printf object files
# clean:
# 			$(RM) $(OBJS)
# 			make clean -C libft

# # Clean all generated files
# fclean:		clean
# 			$(RM) $(NAME)
# 			make fclean -C libft

# # Recompile everything
# re:			fclean all

# # Debugging info
# debug:
# 			@echo "SRCS = $(SRCS)"
# 			@echo "OBJS = $(OBJS)"
# 			@echo "LIBFT_OBJS = $(LIBFT_OBJS)"

# # Phony targets
# .PHONY:		all clean fclean re debug