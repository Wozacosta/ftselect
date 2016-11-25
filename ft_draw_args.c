/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <srabah-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 04:42:07 by srabah-m          #+#    #+#             */
/*   Updated: 2014/01/12 07:58:41 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_select.h>

void	ft_draw_args(t_term_env *term)
{
	t_lst	*args;
	t_arg	*arg;
	int		col;
	int		lin;

	ft_putstr_fd("Choose the commands you wish to select :\n", 2);
	args = term->args;
	col = 0;
	while (col <= term->disp.c)
	{
		lin = 1;
		while (lin < term->disp.l)
		{
			if (!args)
				return ;
			arg = (t_arg *)(args->content);
			arg->x = col * term->len_max + 3;
			arg->y = lin;
			ft_draw_arg(term, arg);
			args = args->next;
			lin++;
		}
		col++;
	}
}

void	ft_draw_arg(t_term_env *term, t_arg *arg)
{
	ft_set_cursor(term, arg->x - 3, arg->y);
	ft_putstr_fd("  [", 2);
	if (arg->selected)
		ft_putstr_fd("X", 2);
	else
		ft_putstr_fd(" ", 2);
	ft_putstr_fd("] ", 2);
	if (term->current->content == arg)
		ft_putstr_fd(tgetstr("us", NULL), 2);
	if (arg->selected)
		ft_putstr_fd(tgetstr("so", NULL), 2);
	ft_putstr_fd(arg->name, 2);
	if (arg->selected)
		ft_putstr_fd(tgetstr("se", NULL), 2);
	if (term->current->content == arg)
		ft_putstr_fd(tgetstr("ue", NULL), 2);
}
