/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:12:40 by antolefe          #+#    #+#             */
/*   Updated: 2025/02/19 18:21:07 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int i;
    char    *str;

    
    str = av[1];
    i = 0;
    if (ac == 2)
    {
        while(str[i] != '\0')
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] += 32;
                write(1, "_", 1);
                write(1, &str[i], 1);
            }
            else
                write(1, &str[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}