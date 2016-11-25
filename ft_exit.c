/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <srabah-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 07:53:20 by srabah-m          #+#    #+#             */
/*   Updated: 2014/01/12 07:58:54 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_select.h>

void	ft_restore_term(void)
{
	struct termios	term;

	tcgetattr(2, &term);
	term.c_lflag |= (ICANON | ECHO);
	tcsetattr(2, TCSANOW, &term);
}

void	ft_exit(int status)
{
	ft_restore_term();
	exit(status);
}

void	ft_exit_success(t_term_env *term)
{
	ft_clear();
	ft_free_mem(term);
	ft_exit(EXIT_SUCCESS);
}

void	ft_free_mem(t_term_env *term)
{
	t_lst	*args;

	args = term->args;
	while (args)
	{
		term->args = args;
		free((t_arg*)args->content);
		args = args->next;
		free(term->args);
	}
	free(term);
}

void	ft_fatal_restore(t_term_env *term, char *error)
{
	t_lst	*args;

	args = term->args;
	while (args)
	{
		free(args->content);
		args = args->next;
	}
	free(term);
	ft_restore_term();
	ft_fatal(error);
}

