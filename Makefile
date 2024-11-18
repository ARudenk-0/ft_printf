# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arudenko <arudenko@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 19:35:46 by arudenko          #+#    #+#              #
#    Updated: 2024/11/18 19:41:12 by arudenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=
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