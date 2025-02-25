/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:58:44 by antolefe          #+#    #+#             */
/*   Updated: 2025/02/23 12:52:39 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
    int i;
    int j;
    int seen[256] = {0};
    
    i = 1;
    if (ac == 3)
    {
        while(i < 3)
        {
            j = 0;
            while(av[i][j] != '\0')
            {
                if (!seen[(unsigned char) av[i][j]])
                    write(1, &av[i][j], 1);
                seen[(unsigned char) av[i][j]] = 1;
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}




































// int main(int ac, char **av)
// {
//     int i;
//     int j;
//     int seen[256] = {0};
    
//     i = 1;
//     if (ac == 3)
//     {
//         while(i < 3)
//         {
//             j = 0;
//             while(av[i][j] != '\0')
//             {
//                 if(!seen[(unsigned char) av[i][j]])
//                 {
//                     write(1, &av[i][j], 1);
//                     seen[(unsigned char) av[i][j]] = 1;
//                 }
//                 j++;
//             }
//             i++;
//         }
//     }
//     write(1, "\n", 1);
// }