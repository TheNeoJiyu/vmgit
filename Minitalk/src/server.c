/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:03:59 by antolefe          #+#    #+#             */
/*   Updated: 2025/01/22 16:50:15 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handler(int signo, siginfo_t *info, void *more_info)
{
	static char		c;
	static int		bit;
	static pid_t	client;

	(void)more_info;
	if (info->si_pid)
		client = info->si_pid;
	if (SIGUSR1 == signo)
		c |= (0b10000000 >> bit);
	else if (SIGUSR2 == signo)
		c &= ~(0b10000000 >> bit);
	++bit;
	if (CHAR_BIT == bit)
	{
		bit = 0;
		if ('\0' == c)
		{
			write(STDOUT_FILENO, "\n", 1);
			send_signal(client, SIGUSR2);
			return ;
		}
		write(STDOUT_FILENO, &c, 1);
	}
	kill(client, SIGUSR1);
}

int	main(void)
{
	ft_printf("Server PID=%d\n", getpid());
	setup_signal(SIGUSR1, handler, true);
	setup_signal(SIGUSR2, handler, true);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
