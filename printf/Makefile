# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 23:48:15 by jkarosas          #+#    #+#              #
#    Updated: 2021/12/24 01:14:17 by jkarosas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= 	ft_handle_c.c ft_handle_d.c ft_handle_i.c \
				ft_handle_p.c ft_handle_s.c ft_handle_u.c \
				ft_handle_x.c ft_handle_percent.c \
				ft_printf.c

OBJS		= ${SRCS:.c=.o}


CC			= gcc
RM			= rm -f
AR			= ar rc

CFLAGS		= -Wall -Wextra -Werror

NAME		= libftprintf.a

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		$(NAME)

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
