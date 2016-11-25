# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srabah-m <srabah-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/12 07:56:14 by srabah-m          #+#    #+#              #
#    Updated: 2014/01/12 07:56:18 by srabah-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=	gcc

CFLAGS =	-Wall -Werror -Wextra
LDFLAGS	=	-L libft -L /usr/lib
LIB	=	-lft -ltermcap

INC	=	-I ./includes -I libft/includes/

SRC	=	main.c					\
		ft_select.c				\
		ft_load_term.c			\
		ft_exit.c				\
		ft_parse.c				\
		ft_nodarg.c				\
		ft_lst_insert_sort.c	\
		ft_display.c			\
		ft_get_dimensions.c		\
		ft_draw_args.c			\
		ft_putc.c				\
		ft_cursor.c				\
		ft_signal.c				\
		ft_handle_keys.c		\
		ft_handle_keys_arrows.c	\
		ft_handle_keys_special.c

OBJ	=	$(SRC:.c=.o)

NAME =	ft_select

all:	$(NAME)

$(NAME): lib	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LIB)

%.o:	%.c
	$(CC) -o $@ -c $< $(CFLAGS) $(INC)

lib:
	make -C libft/

libclean:
	make -C libft/ clean

libfclean:
	make -C libft/ fclean

clean:	libclean
	rm -f $(OBJ)

fclean:	clean libfclean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re lib libfclean
