/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:27:36 by antolefe          #+#    #+#             */
/*   Updated: 2025/02/23 12:37:41 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    inter(char *s1, char *s2)
{
    int i = 0;
    
    int seen[256] = {0};

    while (s1[i])
    {
        j = 0;
        while (s2[j])
        {
            if(s1[i] == s2[j] && !seen[(unsigned char) s1[i]]);
            {
                write(1, &s1[i], 1);
                seen[(unsigned char) s1[i]] = 1;
                break ;
            }
            j++;
        }
        i++;
    }
}
































void    inter(char *s1, char *s2)
{
    int i;
    int j;
    int seen[256] = {0};
    
    i = 0;
    while (s1[i])
    {
        j = 0;
        while (s2[j])
        {
            if(s1[i] == s2[j] && !seen[(unsigned char) s1[i]])
            {
                write(1, &s1[i], 1);
                seen[(unsigned char) s1[i]] = 1;
                break;
            }
            j++;
        }
        i++;
    }
}















// void    inter(char *s1, char *s2)
// {
//     int i;
//     int j;
//     int seen[256] = {0};

//     i = 0;
//     while (s1[i])
//     {
//         j = 0;
//         while (s2[j])
//         {
//             if(s1[i] == s2[j] && !seen[(unsigned char) s1[i]])
//             {
//                 write(1, &s1[i], 1);
//                 seen[(unsigned char) s1[i]] = 1;
//                 break;
//             }
//             j++;
//         }
//         i++;
//     }
// }


int main(int ac, char **av)
{
    char    *s1;
    char    *s2;

    s1 = av[1];
    s2 = av[2];
    if(ac == 3)
        inter(s1, s2);
    write(1, "\n", 1);
}
