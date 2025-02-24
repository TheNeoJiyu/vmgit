/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:59:29 by antolefe          #+#    #+#             */
/*   Updated: 2025/02/21 15:12:40 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int first_word(char *str)
{
    int i;
    
    i = 0;
    while ((str[i] == ' ') || (str[i] == '\t'))
        i++;
    return (i);
}

int main(int ac, char **av)
{
    int i;
    char    *str;

    str = av[1];
    i = first_word(str);
    if (ac == 2)
    {
        while(str[i])
        {
            if ((str[i] == ' ') || (str[i] == '\t'))
            {
                if (((str[i + 1] != ' ') || (str[i + 1] != '\t')) && (str[i] != '\0'))
                {
                    write (1, " ", 1);
                    i++;
                }
            }
            if ((str[i] != ' ') || (str[i] != '\t'))
            {
                write(1, &str[i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
}