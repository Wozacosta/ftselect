/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <srabah-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 04:30:07 by srabah-m          #+#    #+#             */
/*   Updated: 2014/01/12 07:52:46 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_select.h>

int			ft_select(int ac, char **av, char **env)
{
	t_term_env	*terminal;

	if (ac < 2)
		ft_fatal("Not enough arguments\n");
	if (!(terminal = (t_term_env*)malloc(sizeof(t_term_env))))
		ft_fatal("Couldn't malloc t_term_env *terminal");
	ft_load_term(terminal, env);
	ft_parse(terminal, av + 1, ac - 1);
	ft_get_term(terminal);
	ft_signal();
	ft_display(terminal);
	return (EXIT_SUCCESS);
}

t_term_env	*ft_get_term(t_term_env *term)
{
	static t_term_env	*glob_term;

	if (term == NULL)
		return (glob_term);
	else
		glob_term = term;
	return (glob_term);
}
