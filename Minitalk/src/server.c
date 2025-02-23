/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:03:59 by antolefe          #+#    #+#             */
/*   Updated: 2025/02/23 15:07:10 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	binary_converter(int signum, char *binary)
{
	if (signum == SIGUSR1)
		*binary = (*binary << 1) | 1;
	else if (signum == SIGUSR2)
		*binary = *binary << 1;
}

int	make_message(t_list **msg, char c)
{
	t_list	*new;
	char	*c_adress;

	c_adress = malloc(sizeof(char));
	if (!c_adress)
		return (free_all(msg), ft_printf("Error Malloc fail\n"), 0);
	*c_adress = c;
	new = ft_lstnew(c_adress);
	if (!new)
	{
		free(c_adress);
		return (free_all(msg), ft_printf("Error new node fail\n"), 0);
	}
	if (!*msg)
		*msg = new;
	else
		ft_lstadd_back(msg, new);
	return (1);
}

void	signal_handler_s(int signum, siginfo_t *info, void *moreinfo)
{
	static int		pid;
	static int		i;
	static char		c;
	static t_list	*message;

	(void)moreinfo;
	if (pid == 0)
		pid = info->si_pid;
	binary_converter(signum, &c);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(pid, SIGUSR1);
			pid = 0;
			print_list(&message);
			free_all(&message);
			return ;
		}
		if (!(make_message(&message, c)))
			return ;
		c = 0;
	}
	kill(pid, SIGUSR2);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("Server PID == %d\n", pid);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = signal_handler_s;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Signal error. \n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Signal error. \n");
	while (1)
		pause();
	return (0);
}
