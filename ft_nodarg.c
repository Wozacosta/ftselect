/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <srabah-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 08:01:44 by srabah-m          #+#    #+#             */
/*   Updated: 2014/01/12 08:01:56 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_select.h>

static void	ft_nodarg_exit(t_term_env *term, char *error);

t_arg		*ft_nodarg_create(char *arg_name, t_term_env *term)
{
	t_arg	*arg;
	int		len;

	if ((len = (int)ft_strlen(arg_name)) > MAX_ARG_LEN)
		ft_nodarg_exit(term, "Bad argument input\n");
	if (!(arg = (t_arg *)malloc(sizeof(t_arg))))
		ft_nodarg_exit(term, "Malloc failed to allocate\n");
	ft_strcpy(arg->name, arg_name);
	arg->len = len;
	arg->selected = 0;
	arg->x = 0;
	arg->y = 0;
	return (arg);
}

static void	ft_nodarg_exit(t_term_env *term, char *error)
{
	free(term);
	ft_restore_term();
	ft_fatal(error);
}
