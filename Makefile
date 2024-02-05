# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 22:40:58 by chhoflac          #+#    #+#              #
#    Updated: 2024/02/05 11:26:19 by chhoflac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF = printf/libftprintf.a  

SRCS =  client.c \
		server.c \
		ft_atoi.c \

OBJS = $(SRCS:.c=.o)

NAME = minitalk

CFLAGS = -Werror -Wextra -Wall

CC = cc

RM = rm -f

SERVER = server

CLIENT = client

all : $(NAME)

$(CLIENT) : $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o client

$(SERVER) : $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o server

$(NAME) : $(CLIENT) $(SERVER) 
 
clean :
	$(RM) $(OBJS)
	$(MAKE) -C printf clean

fclean : clean
	$(RM) $(CLIENT) $(SERVER)
	$(MAKE) -C printf fclean

$(PRINTF) :
	$(MAKE) -C printf

re : fclean all

.PHONY : all clean fclean re 