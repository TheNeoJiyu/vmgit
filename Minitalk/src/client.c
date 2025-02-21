/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:16:04 by antolefe          #+#    #+#             */
/*   Updated: 2025/02/21 17:37:39 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

volatile sig_atomic_t	g_ack_received = 0;

void	signal_handler(int signo)
{
	if (signo == SIGUSR1)
		g_ack_received = 1;
	else if (signo == SIGUSR2)
	{
		write(STDOUT_FILENO, "Message received\n", 17);
		exit(EXIT_SUCCESS);
	}
}

void	setup_signal_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if ((sigaction(SIGUSR1, &sa, NULL) == -1
			|| sigaction(SIGUSR2, &sa, NULL) == -1))
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
}

void	send_bit(char c, int bit, pid_t server_pid)
{
	int	signal_to_send;

	if ((c >> (7 - bit)) & 1)
		signal_to_send = SIGUSR1;
	else
		signal_to_send = SIGUSR2;
	if (kill(server_pid, signal_to_send) == -1)
	{
		perror("kill");
		exit(EXIT_FAILURE);
	}
	while (g_ack_received == 0)
		pause();
	g_ack_received = 0;
}

void	send_char(char c, pid_t server_pid)
{
	send_bit(c, 0, server_pid);
	send_bit(c, 1, server_pid);
	send_bit(c, 2, server_pid);
	send_bit(c, 3, server_pid);
	send_bit(c, 4, server_pid);
	send_bit(c, 5, server_pid);
	send_bit(c, 6, server_pid);
	send_bit(c, 7, server_pid);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*message;

	if (argc != 3)
	{
		write(STDERR_FILENO, "Usage: ./client [PID] \"message\"\n", 33);
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	if (kill(server_pid, 0) == -1)
	{
		perror("Invalid server PID");
		exit(EXIT_FAILURE);
	}
	setup_signal_handler();
	while (*message != '\0')
	{
		send_char(*message, server_pid);
		message++;
	}
	send_char('\0', server_pid);
	pause();
	return (EXIT_SUCCESS);
}