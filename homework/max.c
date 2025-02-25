/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:03:17 by antolefe          #+#    #+#             */
/*   Updated: 2025/02/21 14:43:57 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		max(int* tab, unsigned int len)
{
    unsigned int i;
    int res;

    i = 1;
    res = tab[0];
    if ((len == 0) || (!tab))
        return (0);
    while (i < len)
    {
        if (res < tab[i])
            res = tab[i];
        i++;
    }
    return (res);
}

int main()
{
    int tab[256] = {5, 3, 6, 8, 9};

    printf("res =%d\n", max(tab, 5));
}