/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylaaouf <aylaaouf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:00:27 by aylaaouf          #+#    #+#             */
/*   Updated: 2025/02/27 18:11:50 by aylaaouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int ac, char **av)
{
    (void)av;
    if (ac != 1)
    {
        ft_putstr_fd("Usage: ./server\n", 2);
        exit(1);
    }
    return (0);
}