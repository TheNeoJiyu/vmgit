/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:06:29 by antolefe          #+#    #+#             */
/*   Updated: 2025/02/23 15:01:47 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define  _DEFAULT_SOURCE 500

# include "../Libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>

void	binary_converter(int signum, char *binary);
int		make_message(t_list **msg, char c);
void	signal_handler_s(int signum, siginfo_t *info, void *moreinfo);
int		char_converter(char c, int pid);
void	signal_handler_c(int signum);
void	free_all(t_list **lst);
void	print_list(t_list **lst);

#endif