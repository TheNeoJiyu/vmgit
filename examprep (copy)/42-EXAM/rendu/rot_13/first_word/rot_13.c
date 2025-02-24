/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:05:17 by antolefe          #+#    #+#             */
/*   Updated: 2025/02/19 17:22:52 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

int main(int ac , char **av)
{
    int i;
    char    *str;

    str = av[1];
    i = 0;
    if (ac == 2)
    {
        while (str[i] != '\0')
        {
            if ((str[i] >= 'A' && str[i] <= 'M') || (str[i] >= 'a' && str[i] <= 'm'))
            {
                str[i] += 13;
                write(1, &str[i], 1);
            }
            else if ((str[i] >= 'N' && str[i] <= 'Z') || (str[i] >= 'n' && str[i] <= 'z'))
            {
                str[i] -= 13;
                write(1, &str[i], 1);
            }
            else
                write(1, &str[i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}
