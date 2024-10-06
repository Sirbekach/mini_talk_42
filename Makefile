# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 14:57:42 by ybekach           #+#    #+#              #
#    Updated: 2024/09/25 16:00:14 by ybekach          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = server
NAME1 = client 
LIBFT = libft/libft.a

all: libft server client 

$(NAME): server.c
	$(CC) $(CFLAGS) server.c $(LIBFT) -o $(NAME)

$(NAME1): client.c
	$(CC) $(CFLAGS) client.c $(LIBFT) -o $(NAME1)

libft: 
	make -C libft all

clean:
	rm -f server.o client.o
	make -C libft clean
	
fclean: clean
	rm -f server client
	make -C libft fclean

re: fclean all

.PHONY: all libft clean fclean re