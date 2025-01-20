/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:11:50 by antolefe          #+#    #+#             */
/*   Updated: 2024/06/08 16:27:29 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*cpy_substr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	cpy_substr = (char *)malloc((len + 1) * sizeof(char));
	if (!cpy_substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cpy_substr[i] = s[start + i];
		i++;
	}
	cpy_substr[i] = '\0';
	return (cpy_substr);
}
