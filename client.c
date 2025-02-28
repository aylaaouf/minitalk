/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:00:13 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/02/28 16:58:30 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    parser(int ac, char **av)
{
    if (ac != 3)
    {
        ft_putstr_fd("Usage: ./client <server_pid> <message>\n", 2);
        exit(1);
    }
    int i;
    int pid;

    i = 0;
    pid = ft_atoi(av[1]);
    if (!av[2][0])
    {
        ft_putstr_fd("Error: Message cannot be empty\n", 2);
        exit(1);
    }
    while (av[1][i])
    {
        if (!ft_isdigit(av[1][i]) || pid <= 0)
        {
            ft_putstr_fd("Error: Invalid PID\n", 2);
            exit(1);
        }
        i++;
    }
}

void    encrypt(char c, int pid)
{
    int i;

    i = 7;
    while (i >= 0)
    {
        if ((c >> i) & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(500);
        i++;
    }
}

int main(int ac, char **av)
{
    int pid;
    char *msj;
    int i;

    pid = ft_atoi(av[1]);
    msj = av[2];
    i = 0;
    parser(ac, av);
    while (msj[i])
    {
        encrypt(msj[i], pid);
        i++;
    }
    encrypt('\0', pid);
}