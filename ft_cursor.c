/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <srabah-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 07:57:19 by srabah-m          #+#    #+#             */
/*   Updated: 2014/01/12 07:57:26 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_set_cursor(t_term_env *term, int x, int y)
{
	tputs(tgoto(tgetstr("cm", NULL), x, y), 0, ft_putc);
	term->cursor.x = x;
	term->cursor.y = y;
}

void	ft_set_cursor_current(t_term_env *term)
{
	t_arg	*arg;

	arg = (t_arg *)term->current->content;
	ft_set_cursor(term, arg->x, arg->y);
}

