/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:00:27 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/03/08 20:38:33 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + 48);
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static char	c = 0;
	static int	client_pid = 0;

	(void)context;
	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		bit = 0;
		c = 0;
	}
	if (sig == SIGUSR2)
		c = (c << 1);
	else if (sig == SIGUSR1)
		c = (c << 1) | 1;
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	long				pid;

	(void)av;
	pid = getpid();
	if (ac != 1)
	{
		ft_putstr_fd("Usage: ./server\n", 2);
		exit(1);
	}
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		pause();
}
