/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_keys_special.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <srabah-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 08:00:34 by srabah-m          #+#    #+#             */
/*   Updated: 2014/01/12 08:00:48 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_select.h>

void	handle_key_space(t_term_env *term)
{
	t_arg	*arg;

	arg = (t_arg *)term->current->content;
	arg->selected = !arg->selected;
	if (arg->selected)
		handle_key_down(term);
	else
	{
		ft_draw_arg(term, arg);
		ft_set_cursor(term, arg->x, arg->y);
	}
}

void	handle_key_return(t_term_env *term)
{
	t_lst	*args;
	t_arg	*arg;
	char	space;
	int		writen;

	args = term->args;
	tputs(tgetstr("cl", NULL), 1, &ft_putc);
	space = ' ';
	writen = 0;
	while (args)
	{
		arg = (t_arg *)args->content;
		if (arg->selected)
		{
			if (writen)
				write(1, &space, 1);
			writen = 1;
			write(1, arg->name, arg->len);
		}
		args = args->next;
	}
	ft_exit(EXIT_SUCCESS);
}

void	handle_key_delete(t_term_env *term)
{
	t_lst	*current;

	current = term->current;
	if (current->prev)
		current->prev->next = current->next;
	else
		term->args = current->next;
	if (current->next)
		current->next->prev = current->prev;
	tputs(tgetstr("cl", NULL), 1, &ft_putc);
	if (ft_lst_length(term->args) == 0)
		ft_exit_success(term);
	if (current->next)
		term->current = current->next;
	else if (current->prev)
		term->current = current->prev;
	term->nb_arg--;
	free((t_arg *)current->content);
	free(current);
	ft_set_cursor(term, 0, 0);
	ft_draw(term);
	ft_set_cursor_current(term);
}

void	handle_key_escape(t_term_env *term)
{
	ft_exit_success(term);
}

