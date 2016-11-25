/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <srabah-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 08:02:00 by srabah-m          #+#    #+#             */
/*   Updated: 2014/01/12 08:02:07 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_select.h>

void	ft_parse(t_term_env *terminal, char **args, int ac)
{
	t_lst	*arg_lst;
	t_arg	*node;
	int		i;

	arg_lst = NULL;
	i = 0;
	while (i < ac)
	{
		node = ft_nodarg_create(args[i], terminal);
		ft_lst_insert_sort(&arg_lst, node);
		++i;
	}
	terminal->nb_arg = ac;
	terminal->args = arg_lst;
	terminal->current = arg_lst;
}
