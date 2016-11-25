/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dimensions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <srabah-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 05:15:27 by srabah-m          #+#    #+#             */
/*   Updated: 2014/01/12 07:59:17 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_select.h>

int		ft_get_dimensions(t_term_env *term)
{
	struct winsize	size;
	t_lst			*args;
	int				len_max;

	if (ioctl(2, TIOCGWINSZ, &size) < 0)
		ft_fatal_restore(term, "TIOCGWINSZ error\n");
	term->size.c = size.ws_col;
	term->size.l = size.ws_row;
	args = term->args;
	len_max = 0;
	while (args)
	{
		if (((t_arg *)(args->content))->len > len_max)
			len_max = ((t_arg *)(args->content))->len;
		args = args->next;
	}
	term->len_max = len_max + FT_MARGIN;
	term->disp.c = term->nb_arg / term->size.l;
	term->disp.l = term->size.l;
	if ((term->disp.c + 1) * term->len_max > term->size.c)
		return (0);
	return (1);
}
