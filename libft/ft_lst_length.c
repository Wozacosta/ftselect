/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <srabah-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 07:54:03 by srabah-m          #+#    #+#             */
/*   Updated: 2014/01/12 08:09:36 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

int	ft_lst_length(const t_lst *list)
{
	int	len;

	if (!list)
		return (0);
	len = 1;
	while ((list = list->next) != 0)
		len++;
	return (len);
}
