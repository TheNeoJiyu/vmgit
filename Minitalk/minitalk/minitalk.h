/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:06:29 by antolefe          #+#    #+#             */
/*   Updated: 2025/01/20 18:06:18 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../ft_printf/ft_printf.h"
# include "../Libft/libft.h"

enum
{
    READY,
    BUSY,
};

void    handler(int signo, siginfo_t *info, void *more_info);
void    ack_handler(int signo);
void    end_handler(int signo);
void    send_char(char c, pid_t kingKai);
void    Signal(int, void *, bool);
void    Kill(pid_t pid, int signo);

#endif