/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_keys_arrows.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <srabah-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 07:59:51 by srabah-m          #+#    #+#             */
/*   Updated: 2014/01/12 08:09:04 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_select.h>

void	handle_key_left(t_term_env *term)
{
	int		i;
	t_lst	*args;
	t_arg	*old;
	t_arg	*new;

	args = term->current;
	old = (t_arg *)term->current->content;
	if (args)
	{
		i = 0;
		while (args->prev && i++ < term->disp.l)
			args = args->prev;
	}
	else
		args = term->args;
	term->current = args;
	new = (t_arg *)args->content;
	ft_draw_arg(term, old);
	ft_draw_arg(term, new);
	ft_set_cursor(term, new->x, new->y);
}

void	handle_key_down(t_term_env *term)
{
	t_lst	*args;
	t_arg	*old;
	t_arg	*new;

	args = term->current;
	old = (t_arg *)term->current->content;
	if (args)
	{
		if (args->next)
			args = args->next;
		else
			args = term->args;
	}
	else
		args = term->args;
	term->current = args;
	new = (t_arg *)args->content;
	ft_draw_arg(term, old);
	ft_draw_arg(term, new);
	ft_set_cursor(term, new->x, new->y);
}

void	handle_key_right(t_term_env *term)
{
	int		i;
	t_lst	*args;
	t_arg	*old;
	t_arg	*new;

	args = term->current;
	old = (t_arg *)term->current->content;
	if (args)
	{
		i = 0;
		while (args->next && i++ < term->disp.l)
			args = args->next;
	}
	else
		args = term->args;
	term->current = args;
	new = (t_arg *)args->content;
	ft_draw_arg(term, old);
	ft_draw_arg(term, new);
	ft_set_cursor(term, new->x, new->y);
}

void	handle_key_up(t_term_env *term)
{
	t_lst	*args;
	t_arg	*old;
	t_arg	*new;

	args = term->current;
	old = (t_arg *)term->current->content;
	if (args)
	{
		if (args->prev)
			args = args->prev;
		else
		{
			while (args->next)
				args = args->next;
		}
	}
	else
		args = term->args;
	term->current = args;
	new = (t_arg *)args->content;
	ft_draw_arg(term, old);
	ft_draw_arg(term, new);
	ft_set_cursor(term, new->x, new->y);
}
