# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 19:35:46 by arudenko          #+#    #+#              #
#    Updated: 2024/12/16 15:12:06 by arudenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c ft_printf_utils.c ft_printf_spec_print.c ft-printf_flags_functions.c
OBJS		= $(SRCS:.c=.o)

CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
NAME		= libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJ)

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re