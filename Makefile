# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 19:35:46 by arudenko          #+#    #+#              #
#    Updated: 2024/12/27 18:18:48 by arudenko         ###   ########.fr        #
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
SRC				=	ft_printf.c ft_printf_utils.c ft_printf_char_utils.c ft_printf_spec_print.c ft_printf_flags_functions.c ft_printf_initializing.c ft_printf_num.c ft_printf_precision.c ft_printf_ltoa_signed.c ft_printf_ltoa_unsigned.c ft_printf_ltoa_utils.c ft_printf_ltoa_signed_utils.c ft_printf_flags_functions_utils.c

# Object files
OBJS			=	$(SRC:.c=.o)

# Path to libft
LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

# Default rule
all: $(NAME)

bonus:				all

# Create the combined library
$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) x $(LIBFT)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) *.o
	$(RM) *.o
	$(RM) $(LIBFT_PATH)/*.o  
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
.PHONY: all bonus clean fclean re