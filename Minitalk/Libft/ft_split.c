/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:41:23 by antolefe          #+#    #+#             */
/*   Updated: 2024/06/08 17:11:17 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *str, char c)
{
	size_t	count;

	if (!*str)
		return (0);
	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			count++;
		while (*str != c && *str)
			str++;
	}
	return (count);
}

static char	**ft_malloc_and_check(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	return (res);
}

static void	*ft_free(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free (str);
	return (NULL);
}

static size_t	ft_split_len(char const *s, char c)
{
	size_t	word_len;

	word_len = 0;
	if (!ft_strchr(s, c))
		word_len = ft_strlen(s);
	else
		word_len = ft_strchr(s, c) - s;
	return (word_len);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	word_len;
	int		i;

	res = ft_malloc_and_check(s, c);
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			word_len = ft_split_len(s, c);
			res[i] = ft_substr(s, 0, word_len);
			if (!res[i])
				return (ft_free(res, i));
			i++;
			s += word_len;
		}
	}
	res[i] = NULL;
	return (res);
}
