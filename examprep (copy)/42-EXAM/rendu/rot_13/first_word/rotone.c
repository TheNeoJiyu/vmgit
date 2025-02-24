/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:24:15 by antolefe          #+#    #+#             */
/*   Updated: 2025/02/19 17:30:15 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
    int i;
    char    *str;

    i = 0;
    str = av[1];
    if (ac == 2)
    {
        while (str[i] != '\0')
        {
            if((str[i] >= 'A' && str[i] <= 'Y') || (str[i] >= 'a' && str[i] <= 'y'))
            {
                str[i] += 1;
                write(1, &str[i], 1);
            }
            else if((str[i] == 'Z') || (str[i] == 'z'))
            {
                str[i] -= 25;
                write(1, &str[i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
}