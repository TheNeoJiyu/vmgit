/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:21:36 by antolefe          #+#    #+#             */
/*   Updated: 2024/05/31 16:24:44 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int arg)
{
	if (((arg >= 'a') && (arg <= 'z')) || ((arg >= 'A') && (arg <= 'Z'))
		|| ((arg >= '0') && (arg <= '9')))
		return (1);
	return (0);
}