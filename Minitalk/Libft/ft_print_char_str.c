/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:14:26 by antolefe          #+#    #+#             */
/*   Updated: 2025/01/21 16:31:06 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str, int *output)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*output) += 6;
		return (6);
	}
	while (str[i])
	{
		ft_print_char(str[i]);
		i++;
		(*output)++;
	}
	return (i);
}
