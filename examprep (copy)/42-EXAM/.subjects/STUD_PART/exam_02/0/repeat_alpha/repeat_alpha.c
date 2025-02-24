/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:36:24 by galpers           #+#    #+#             */
/*   Updated: 2025/02/19 16:11:52 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void repeat_alpha(char *str)
{
    int i = 0;
    int repeat;
    
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            repeat = str[i] - 'A' + 1;
        else if (str[i] >= 'a' && str[i] <= 'z')
            repeat = str[i] - 'a' + 1;
        else
            repeat = 1;
        
        while (repeat--)
            write(1, &str[i], 1);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        repeat_alpha(av[1]);
    write(1, "\n", 1);
    return (0);
}
