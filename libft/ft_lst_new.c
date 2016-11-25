/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <srabah-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 07:54:16 by srabah-m          #+#    #+#             */
/*   Updated: 2014/01/12 07:54:24 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

t_lst	*ft_lst_new(const void *content)
{
	t_lst	*element;

	if (!(element = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	element->content = (void *)content;
	element->prev = NULL;
	element->next = NULL;
	return (element);
}
