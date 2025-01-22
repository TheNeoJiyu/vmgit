/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:06:29 by antolefe          #+#    #+#             */
/*   Updated: 2025/01/22 14:08:11 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define _POSIX_C_SOURCE 200809L
# define BUSY 1

# include "../Libft/libft.h"
# include <errno.h>
# include <limits.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>

void	handler(int signo, siginfo_t *info, void *more_info);
void	signal_handler(int signo);
void	setup_signal_handler(void);
void	send_bit(char c, int bit, pid_t server_pid);
void	send_char(char c, pid_t server);
void	setup_signal(int signo, void *handler, int use_siginfo);
void	send_signal(pid_t pid, int signo);

#endif