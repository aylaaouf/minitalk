/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:15:50 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/03/01 18:58:27 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    signal_handler(int sig, siginfo_t *info, void *context)
{
    (void)context;
    static int  bit = 0;
    static char c = 0;

    if (sig == SIGUSR2)
        c = (c << 1);
    else if (sig == SIGUSR1)
        c = (c << 1) | 1;
    bit++;
    if (bit == 8)
    {
        if (c == '\0')
            kill(info->si_pid, SIGUSR1);
        write(1, &c, 1);
        c = 0;
        bit = 0;
    }
}

int main(int ac, char **av)
{
    (void)av;
    struct sigaction sa;
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
    printf("Server PID: %d\n", getpid());
    while (1)
        pause();
}