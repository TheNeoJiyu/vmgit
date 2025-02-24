/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:03:54 by antolefe          #+#    #+#             */
/*   Updated: 2025/02/19 14:31:12 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int ac, char **av)
{
    int i;
    
    i = 0;
    if (ac == 2)
    {
        while(av[1][i] == ' ' || av[1][i] == '\t')
        {
            i++;
        }
        while((av[1][i] != '\0') && (av[1][i] != ' ') && (av[1][i] != '\t'))
        {
            ft_putchar(av[1][i]);
            i++;
        }
    }
    ft_putchar('\n');
}