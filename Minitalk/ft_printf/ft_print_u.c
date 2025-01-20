/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:43:04 by antolefe          #+#    #+#             */
/*   Updated: 2024/08/26 15:13:39 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_u(unsigned int n, int *output)
{
	if (n >= 10)
		ft_print_u(n / 10, output);
	ft_putchar_fd(n % 10 + '0', 1);
	(*output)++;
}
