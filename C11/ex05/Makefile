# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mousabir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/03 17:54:24 by mousabir          #+#    #+#              #
#    Updated: 2026/08/04 08:25:26 by mousabir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all : do-op

CFLAS = -Wall -Wextra -Werror 
CC = cc
NAME = do-op
sr = do-op.c operations.c utils.c
$(NAME) :
	$(CC) $(CFLAS) $(sr) -o $(NAME)
clean :
	rm -f *.o
fclean : clean
	rm -f $(NAME)
re : fclean all
