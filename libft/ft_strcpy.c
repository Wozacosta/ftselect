/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <srabah-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 07:55:20 by srabah-m          #+#    #+#             */
/*   Updated: 2014/01/12 07:55:25 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

char	*ft_strcpy(char *dst, const char *src)
{
	char	*dst_or;

	dst_or = dst;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (dst_or);
}
