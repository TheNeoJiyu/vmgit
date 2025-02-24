/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:54:02 by antolefe          #+#    #+#             */
/*   Updated: 2025/02/19 15:01:05 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}
char    *ft_strcpy(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    return (s1);
}

int main(int ac, char ** av)
{
    if (ac == 3)
    {
        ft_putstr(av[1]);
        ft_putstr(av[2]);
        ft_putstr("_______________");
        ft_strcpy(av[1], av[2]);
        ft_putstr(av[1]);
    }
}