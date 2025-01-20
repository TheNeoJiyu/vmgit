/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:43:01 by antolefe          #+#    #+#             */
/*   Updated: 2024/06/05 14:02:09 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t count)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (count--)
		*ptr++ = (unsigned char)c;
	return (b);
}
