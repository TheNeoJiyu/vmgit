/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:20:20 by antolefe          #+#    #+#             */
/*   Updated: 2024/06/08 17:35:50 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (*lst == 0)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		if (del)
			del((*lst)-> content);
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}
