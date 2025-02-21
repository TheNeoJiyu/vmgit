/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:03:59 by antolefe          #+#    #+#             */
/*   Updated: 2025/02/21 20:01:57 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static t_client	*clients = NULL;

static t_client	*get_client(pid_t pid)
{
	t_client	*tmp = clients;

	while (tmp)
	{
		if (tmp->pid == pid)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = malloc(sizeof(t_client));
	if (!tmp)
		return (NULL);
	tmp->pid = pid;
	tmp->c = 0;
	tmp->bit = 0;
	tmp->next = clients;
	clients = tmp;
	return (tmp);
}

static void	remove_client(pid_t pid)
{
	t_client	*prev = NULL;
	t_client	*tmp = clients;

	while (tmp)
	{
		if (tmp->pid == pid)
		{
			if (prev)
				prev->next = tmp->next;
			else
				clients = tmp->next;
			free(tmp);
			return;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

void	handler(int signo, siginfo_t *info, void *more_info)
{
	t_client	*client;

	(void)more_info;
	if (!info || info->si_pid <= 0 || !(client = get_client(info->si_pid)))
		return;
	if (signo == SIGUSR1)
		client->c |= (0b10000000 >> client->bit);
	else
		client->c &= ~(0b10000000 >> client->bit);
	if (++client->bit == 8)
	{
		write(STDOUT_FILENO, &client->c, 1);
		if (!client->c)
		{
			write(STDOUT_FILENO, "\n", 1);
			kill(client->pid, SIGUSR2);
			remove_client(client->pid);
		}
		client->bit = 0;
	}
	kill(client->pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction sa;

	printf("Server PID=%d\n", getpid());
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
