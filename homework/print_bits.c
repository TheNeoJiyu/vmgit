/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:08:17 by antolefe          #+#    #+#             */
/*   Updated: 2025/02/23 12:40:16 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


void    print_bits(unsigned char octet)
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















void    print_bits(unsigned char octet)
{
    int i = 7;
    
    while(i >= 0)
    {
        if(octet & (1 << i))
            write(1, "1", 1);
        else
            write(1, "0", 1);
        i--;
    }
}

// void    print_bits(unsigned char octet)
// {
//     int	i = 7;

// 	while (i >= 0) // Parcourt les bits de gauche à droite
// 	{
// 		if (octet & (1 << i))
// 			write(1, "1", 1);
// 		else
// 			write(1, "0", 1);
// 		i--;
// 	}
// }

int main (int argc, char **argv)
{
    unsigned char octet = '\0';

    if (argc == 2) 
    {
        octet = atoi(argv[1]);
        print_bits(octet);
        printf("\n");
    }
    return 0;

}