/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <srabah-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 02:42:32 by srabah-m          #+#    #+#             */
/*   Updated: 2014/01/12 08:03:04 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_select.h>

static void	handle_signal_kill(int signo)
{
	(void)signo;
	ft_clear();
	ft_exit(EXIT_FAILURE);
}

static void	handle_signal_resize(int signo)
{
	t_term_env	*term;
	t_arg		*current_arg;

	term = ft_get_term(NULL);
	ft_draw(term);
	current_arg = (t_arg *)term->current->content;
	ft_set_cursor(term, current_arg->x, current_arg->y);
	(void)signo;
}

static void	handle_signal_tstop(int signo)
{
	struct termios	term;
	char			susp[2];

	ft_clear();
	tcgetattr(2, &term);
	susp[0] = term.c_cc[VSUSP];
	susp[1] = '\0';
	term.c_lflag |= (ICANON | ECHO);
	tcsetattr(2, TCSANOW, &term);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, susp);
	(void)signo;
}

static void	handle_signal_cont(int signo)
{
	struct termios	term;

	tcgetattr(2, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(2, TCSANOW, &term);
	handle_signal_resize(signo);
	signal(SIGTSTP, &handle_signal_tstop);
}

void		ft_signal(void)
{
	signal(SIGTERM, &handle_signal_kill);
	signal(SIGKILL, &handle_signal_kill);
	signal(SIGINT, &handle_signal_kill);
	signal(SIGCONT, &handle_signal_cont);
	signal(SIGTSTP, &handle_signal_tstop);
	signal(SIGWINCH, &handle_signal_resize);
}
