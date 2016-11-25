/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <srabah-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 04:42:28 by srabah-m          #+#    #+#             */
/*   Updated: 2014/01/12 07:58:01 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_select.h>

void	ft_display(t_term_env *term)
{
	t_arg	*arg;
	int		key;

	ft_draw(term);
	arg = (t_arg *)term->args->content;
	ft_set_cursor(term, arg->x, arg->y);
	while (42)
	{
		key = 0;
		read(0, &key, 4);
		ft_handle_keys(term, key);
	}
}

void	ft_draw(t_term_env *term)
{
	ft_clear();
	if (ft_get_dimensions(term))
	{
		ft_draw_args(term);
		if (!term->current)
			term->current = term->args;
	}
	else
	{
		ft_set_cursor(term, 0, 0);
		ft_putstr_fd("please expand your terminal\n", 2);
	}
}

void	ft_clear(void)
{
	char	*clearstr;

	clearstr = tgetstr("cl", NULL);
	tputs(clearstr, 1, ft_putc);
}
