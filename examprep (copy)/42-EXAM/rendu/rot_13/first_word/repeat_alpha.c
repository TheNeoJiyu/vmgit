/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:54:18 by antolefe          #+#    #+#             */
/*   Updated: 2025/02/20 12:46:26 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int i;
	int repeat;
	char *str;

	i = 0;
	str = av[1];
	if (ac == 2)
	{
		while (str[i])
		{
			repeat = 1;
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				repeat = str[i] - 'A' + 1;
			}
			else if (str[i] >= 'a' && str[i] <= 'z')
			{
				repeat = str[i] - 'a' + 1;
			}
			while (repeat--)
			{
				write(1, &str[i], 1);
			}
			i++;
		}
		write(1, "\n", 1);
	}
}