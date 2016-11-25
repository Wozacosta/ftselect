/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <srabah-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 08:00:53 by srabah-m          #+#    #+#             */
/*   Updated: 2014/01/12 08:01:16 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void	ft_raw_mode(void);
static void	ft_load_exit(t_term_env *terminal, char *message);

void		ft_load_term(t_term_env *terminal, char **env)
{
	char	buffer[2048];
	int		ret;

	if (!env || !env[0])
		ft_load_exit(terminal, "ERROR: No environment !\n");
	ret = tgetent(buffer, getenv("TERM"));
	if (ret < 0)
		ft_load_exit(terminal, "Couldn't access the termcap database\n");
	else if (ret == 0)
		ft_load_exit(terminal, "Terminal type is not defined\n");
	ft_raw_mode();
	terminal->size.c = tgetnum("co");
	terminal->size.l = tgetnum("li");
}

static void	ft_load_exit(t_term_env *terminal, char *message)
{
	free(terminal);
	ft_fatal(message);
}

static void	ft_raw_mode(void)
{
	struct termios	term;

	tcgetattr(2, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(2, TCSANOW, &term);
}
