/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <srabah-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 07:56:23 by srabah-m          #+#    #+#             */
/*   Updated: 2014/01/12 07:57:09 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H

# include <libft.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>

# define FT_SELECT_H
# define FT_MARGIN_LEFT	0
# define FT_MARGIN		6
# define MAX_ARG_LEN 128




typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct	s_pos
{
	int	c;
	int	l;
}				t_pos;

typedef struct	s_arg
{
	char	name[MAX_ARG_LEN];
	int		len;
	int		selected;
	int		x;
	int		y;
}				t_arg;

typedef struct	s_term_env
{
	t_pos	size;
	t_pos	disp;
	t_coord	cursor;
	t_lst	*args;
	t_lst	*current;
	int		len_max;
	int		nb_arg;
	int		fd;
}				t_term_env;

typedef void (*func_key)(t_term_env *);

typedef struct	s_key
{
	int			key;
	func_key	func;
}				t_key;

t_term_env	*ft_get_term(t_term_env *term);
int			ft_select(int ac, char **av, char **env);
void		ft_signal(void);
void		ft_load_term(t_term_env *terminal, char **env);
void		ft_restore_term(void);
void		ft_exit(int status);
void		ft_exit_success(t_term_env *term);
void		ft_parse(t_term_env *terminal, char **args, int ac);
t_arg		*ft_nodarg_create(char *arg_name, t_term_env *term);
void		ft_lst_insert_sort(t_lst **lst, const void *content);
void		ft_display(t_term_env *terminal);
int			ft_get_dimensions(t_term_env *term);
void		ft_draw(t_term_env *term);
void		ft_draw_args(t_term_env *term);
void		ft_draw_arg(t_term_env *term, t_arg *arg);
void		ft_set_cursor(t_term_env *term, int x, int y);
void		ft_set_cursor_current(t_term_env *term);
int			ft_putc(int c);
void		ft_clear(void);
void		ft_handle_keys(t_term_env *term, int key);
void		handle_key_up(t_term_env *term);
void		handle_key_right(t_term_env *term);
void		handle_key_down(t_term_env *term);
void		handle_key_left(t_term_env *term);
void		handle_key_space(t_term_env *term);
void		handle_key_return(t_term_env *term);
void		handle_key_delete(t_term_env *term);
void		handle_key_escape(t_term_env *term);
void		ft_fatal_restore(t_term_env *term, char *error);
void		ft_free_mem(t_term_env *term);

#endif /* !FT_SELECT_H */
