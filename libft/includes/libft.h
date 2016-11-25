/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <srabah-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 07:55:43 by srabah-m          #+#    #+#             */
/*   Updated: 2014/01/12 07:55:53 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_h

# include <stdlib.h>

void	ft_error(char const *message);
void	ft_fatal(char const *message);

size_t	ft_strlen(const char *s);

void	ft_putstr(const char *s);
void	ft_putstr_fd(const char *s, int fd);

int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strcpy(char *dst, const char *src);

typedef struct		s_lst
{
	void			*content;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;

t_lst	*ft_lst_new(const void *content);
int		ft_lst_length(const t_lst *list);

int		ft_max(int a, int b);
int		ft_min(int a, int b);

#endif /* !LIBFT_H */
