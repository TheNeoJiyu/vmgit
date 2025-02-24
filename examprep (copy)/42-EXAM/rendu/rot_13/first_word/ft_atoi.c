/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:39:25 by antolefe          #+#    #+#             */
/*   Updated: 2025/02/20 13:58:15 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_atoi(char *str)
{
    int i;
    int signe;
    int res;

    i = 0;
    signe = 1;
    while(str[i] == ' ' || str[i] == '\t')
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            signe = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - '0';
        i++;
    }
    return (res * signe);
}
int main(int ac, char **av)
{
    char *str;
    
    str = av[1];
    if (ac == 2)
    {
        printf("res 1 = %d\n", atoi(str));
        printf("res 2 = %d\n", ft_atoi(str));
    }
}