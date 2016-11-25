/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <srabah-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 07:59:22 by srabah-m          #+#    #+#             */
/*   Updated: 2014/01/12 07:59:43 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_select.h>

void	ft_handle_keys(t_term_env *term, int key)
{
	int				i;
	static t_key	keys[] = {
		{4283163, &handle_key_up}, {4414235, &handle_key_right},
		{4348699, &handle_key_down}, {4479771, &handle_key_left},
		{(int)' ', &handle_key_space}, {(int)'\n', &handle_key_return},
		{2117294875, &handle_key_delete}, {127, &handle_key_delete},
		{27, &handle_key_escape}, {(int)'h', &handle_key_left},
		{(int)'j', &handle_key_down}, {(int)'k', &handle_key_up},
		{(int)'l', &handle_key_right}};

	i = -1;
	while (keys[++i].key)
	{
		if (key == keys[i].key)
		{
			(*keys[i].func)(term);
			return ;
		}
	}
	return ;
}
