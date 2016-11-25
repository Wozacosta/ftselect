/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <srabah-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 07:53:48 by srabah-m          #+#    #+#             */
/*   Updated: 2014/01/12 07:53:58 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_error(char const *message)
{
	ft_putstr_fd("Error: ", 2);
	write(2, message, ft_strlen(message));
}

void	ft_fatal(char const *message)
{
	ft_error(message);
	exit(EXIT_FAILURE);
}
