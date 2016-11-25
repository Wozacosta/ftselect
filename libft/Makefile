# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srabah-m <srabah-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/12 07:56:02 by srabah-m          #+#    #+#              #
#    Updated: 2014/01/12 07:56:09 by srabah-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC	=	gcc

CFLAGS =	-Wall -Werror -Wextra

INC	=	-I ./includes

SRC	=	ft_error.c		\
	ft_putstr.c		\
	ft_strlen.c		\
	ft_strcpy.c		\
	ft_strcmp.c		\
	ft_lst_new.c	\
	ft_lst_length.c	\
	ft_minmax.c

OBJ	=	$(SRC:.c=.o)

NAME =	libft.a

all:	$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

%.o:	%.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INC)

clean:	
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
