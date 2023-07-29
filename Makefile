# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarosas < jkarosas@student.42wolfsburg.de +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/13 21:52:13 by jkarosas          #+#    #+#              #
#    Updated: 2022/03/22 21:43:22 by jkarosas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT		= client
CLIENT_SRC	= ft_client/client.c ft_client/client_utils.c
CLIENT_OBJ	= ${CLIENT_SRC:.c=.o}

SERVER		= server
SERVER_SRC	= ft_server/server.c ft_server/server_utils.c
SERVER_OBJ	= ${SERVER_SRC:.c=.o}

PRNTF		= printf/libftprintf.a
INC			= -I ./ft_client -I ./ft_server -I ./printf

CC			= gcc
FLAGS		= -Wall -Wextra -Werror
RM			= rm -f

all:		${NAME}
		
${NAME}:	${CLIENT_OBJ} ${SERVER_OBJ}
			make -s -C printf
			${CC} ${FLAGS} ${CLIENT_OBJ} ${PRNTF} -o ${CLIENT}
			${CC} ${FLAGS} ${SERVER_OBJ} ${PRNTF} -o ${SERVER}

clean:
			make clean -s -C ./printf
			${RM} ${CLIENT_OBJ} ${SERVER_OBJ}

fclean:		clean
			make fclean -s -C ./printf
			${RM} ${CLIENT} ${SERVER}

re:			fclean all

.PHONY:	all clean fclean re