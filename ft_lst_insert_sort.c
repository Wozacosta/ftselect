/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_insert_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <srabah-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 08:01:20 by srabah-m          #+#    #+#             */
/*   Updated: 2014/01/12 08:01:40 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_select.h>

static int	ft_lis_compare(const void *p1, const void *p2);

void		ft_lst_insert_sort(t_lst **lst, const void *content)
{
	t_lst	*next;
	t_lst	*prev;
	t_lst	*node;

	node = ft_lst_new(content);
	if (!*lst)
	{
		*lst = node;
		return ;
	}
	next = *lst;
	prev = NULL;
	while (next && (ft_lis_compare(content, next->content) > 0))
	{
		prev = next;
		next = next->next;
	}
	node->prev = prev;
	node->next = next;
	if (prev)
		prev->next = node;
	else
		*lst = node;
	if (next)
		next->prev = node;
}

static int	ft_lis_compare(const void *p1, const void *p2)
{
	char	*s1;
	char	*s2;

	s1 = ((t_arg *)p1)->name;
	s2 = ((t_arg *)p2)->name;
	return (ft_strcmp(s1, s2));
}
