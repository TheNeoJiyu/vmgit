/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:16:04 by antolefe          #+#    #+#             */
/*   Updated: 2025/02/23 15:07:50 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static int	g_get_signal;

int	char_converter(char c, int pid)
{
	int	i;
	int	bit_i;

	bit_i = 7;
	while (bit_i >= 0)
	{
		i = 0;
		if ((c >> bit_i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_get_signal == 0)
		{
			if (i == 50)
			{
				ft_printf("Got no signal back.\n");
				exit(1);
			}
			i++;
			usleep(10000);
		}
		g_get_signal = 0;
		bit_i--;
	}
	return (0);
}

void	signal_handler_c(int signum)
{
	static int	i;

	g_get_signal = 1;
	if (signum == SIGUSR2)
		i++;
	else if (signum == SIGUSR1)
		ft_printf("Number of characters received : %d\n", i / 8);
}

int	main(int argc, char **argv)
{
	__pid_t				pid;
	struct sigaction	sa;
	int					i;

	if (argc < 2)
		return (ft_printf("Error PID is missing\n"), 0);
	if (argc == 2)
		return (ft_printf("Error need a third argument as message\n"), 0);
	if (argc > 3)
		return (ft_printf("Error you cannot send more than 1 message at once !\n"), 0);
	pid = (ft_atoi(argv[1]));
	if (pid < 0)
		return (ft_printf("Error incorrect PID\n"), 0);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = signal_handler_c;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Signal error. \n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Signal error. \n");
	i = 0;
	while (argv[2][i])
		char_converter(argv[2][i++], pid);
	char_converter('\0', pid);
	return (0);
}
