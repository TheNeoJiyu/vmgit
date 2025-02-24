/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:23:51 by antolefe          #+#    #+#             */
/*   Updated: 2025/02/23 12:43:32 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
    int i = 7;
    
    while (i >= 0)
    {
        if(octet & (1 << i))
            write(1, "1", 1);
        else
            write(1, "0", 1);
        i--;
    }
}

unsigned char	swap_bits(unsigned char octet)
{
    return(octet >> 4 | octet << 4);
}

int	main(void)
{
	unsigned char octet = 0xAB; // 10101011 en binaire
	write(1, "Avant swap : ", 13);
	print_bits(octet);
	write(1, "\n", 1);

	octet = swap_bits(octet);
	write(1, "Après swap : ", 13);
	print_bits(octet);
	write(1, "\n", 1);
	
	return (0);
}