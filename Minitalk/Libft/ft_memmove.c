/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:28:52 by antolefe          #+#    #+#             */
/*   Updated: 2024/06/05 15:01:31 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	unsigned char	*cpysrc;
	unsigned char	*cpydest;

	cpysrc = (unsigned char *)src;
	cpydest = (unsigned char *)dest;
	if (cpydest == cpysrc || n == 0)
		return (dest);
	if (cpydest < cpysrc)
	{
		while (n--)
			*cpydest++ = *cpysrc++;
	}
	else
	{
		cpysrc += n;
		cpydest += n;
		while (n--)
			*(--cpydest) = *(--cpysrc);
	}
	return (dest);
}
