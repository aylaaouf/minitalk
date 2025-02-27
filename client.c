/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:00:13 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/02/27 18:14:28 by aylaaouf         ###   ########.fr       */
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
        if (!ft_isdigit(av[1][i]) || pid < 0)
        {
            ft_putstr_fd("Error: Invalid PID\n", 2);
            exit(1);
        }
        i++;
    }
}

int main(int ac, char **av)
{
    parser(ac, av);
}