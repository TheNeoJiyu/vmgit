/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:43:53 by antolefe          #+#    #+#             */
/*   Updated: 2025/02/23 14:58:33 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	free_all(t_list **lst)
{
	t_list	*tmp;
	t_list	*next;

	if (!lst || !*lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->content)
			free(tmp->content);
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}

void	print_list(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		if (tmp->content)
			write(STDOUT_FILENO, (char *)tmp->content, 1);
		tmp = tmp->next;
	}
	write(STDOUT_FILENO, "\n", 1);
}
