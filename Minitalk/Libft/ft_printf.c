/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:34:56 by antolefe          #+#    #+#             */
/*   Updated: 2024/09/06 19:02:55 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_type(const char c, va_list value, int *output)
{
	if (c == 'c')
	{
		++(*output);
		ft_print_char(va_arg(value, int));
	}
	else if (c == 's')
		ft_print_str(va_arg(value, char *), output);
	else if (c == 'p')
		ft_print_ptr(va_arg(value, unsigned long long), output);
	else if (c == 'd' || c == 'i')
		ft_print_id(va_arg(value, int), output);
	else if (c == 'u')
		ft_print_u(va_arg(value, unsigned int), output);
	else if (c == 'x' || c == 'X')
		ft_print_hexa(va_arg(value, unsigned int), c, output);
	else if (c != 0)
		ft_print_char(c);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		output;

	va_start(args, str);
	output = 0;
	if (!str)
		return (va_end(args), -1);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
				output += ft_print_char('%');
			else
				print_type(*str, args, &output);
		}
		else
			output += ft_print_char(*str);
		str++;
	}
	va_end(args);
	return (output);
}

// int	main(void)
// {
// 	char	*str;

// 	int ret1, ret2;
// 	str = NULL;
// 	printf("Hello %c%c%c%c%c%c", 'w', 'o', 'r', 'l', 'd', '\n');
// 	ft_printf("Hello %c%c%c%c%c%c", 'w', 'o', 'r', 'l', 'd', '\n');
// 	printf("Hello %c %c %c %c %c %c", '1', '2', '3', '4', '5', '\n');
// 	ft_printf("Hello %c %c %c %c %c %c", '1', '2', '3', '4', '5', '\n');
// 	printf("salut %s", "ca va?\n");
// 	ft_printf("salut %s", "ca va?\n");
// 	printf("salut %s %s", "ca va?", "Oui et toi?\n");
// 	ft_printf("salut %s %s", "ca va?", "Oui et toi?\n");
// 	printf("les pointer %p %p %p %p %p %c", "19", "24", "168", "0", str, '\n');
// 	ft_printf("les pointer %p %p %p %p %p %c", "19", "24", "168", "0", str,
// 		'\n');
// 	printf("%d %d %d %i %i %i %c", 1, 125, 2147483647, -1, -125, -2147483647,
// 		'\n');
// 	ft_printf("%d %d %d %i %i %i %c", 1, 125, 2147483647, -1, -125, -2147483647,
// 		'\n');
// 	printf("%u %u %u %u %u %u %c", 1, 125, 2147483647, -1, -125, -2147483647,
// 		'\n');
// 	ft_printf("%u %u %u %u %u %u %c", 1, 125, 2147483647, -1, -125, -2147483647,
// 		'\n');
// 	printf("%x %x %x %X %X %X %c", 1, 125, 2147483647, -1, -125, -2147483647,
// 		'\n');
// 	ft_printf("%x %x %x %X %X %X %c", 1, 125, 2147483647, -1, -125, -2147483647,
// 		'\n');
// 	ret1 = ft_printf("Hello %c%c%c%c%c\n", 'w', 'o', 'r', 'l', 'd');
// 	ret2 = printf("Hello %c%c%c%c%c\n", 'w', 'o', 'r', 'l', 'd');
// 	printf("ft_printf: %d, printf: %d\n", ret1, ret2);
// 	ret1 = ft_printf("Hello %c %c %c %c %c\n", '1', '2', '3', '4', '5');
// 	ret2 = printf("Hello %c %c %c %c %c\n", '1', '2', '3', '4', '5');
// 	printf("ft_printf: %d, printf: %d\n", ret1, ret2);
// 	ret1 = ft_printf("salut %s\n", "ca va?");
// 	ret2 = printf("salut %s\n", "ca va?");
// 	printf("ft_printf: %d, printf: %d\n", ret1, ret2);
// 	ret1 = ft_printf("salut %s %s\n", "ca va?", "Oui et toi?");
// 	ret2 = printf("salut %s %s\n", "ca va?", "Oui et toi?");
// 	printf("ft_printf: %d, printf: %d\n", ret1, ret2);
// 	ret1 = ft_printf("les pointer %p %p %p %p %p\n", (void *)"14", (void *)"24",
// 			(void *)"168", (void *)"0", (void *)str);
// 	ret2 = printf("les pointer %p %p %p %p %p\n", (void *)"14", (void *)"24",
// 			(void *)"168", (void *)"0", (void *)str);
// 	printf("ft_printf: %d, printf: %d\n", ret1, ret2);
// 	ret1 = ft_printf("%d %d %d %i %i %i\n", 1, 125, 2147483647, -1, -125,
// 			-2147483647);
// 	ret2 = printf("%d %d %d %i %i %i\n", 1, 125, 2147483647, -1, -125,
// 			-2147483647);
// 	printf("ft_printf: %d, printf: %d\n", ret1, ret2);
// 	ret1 = ft_printf("%u %u %u %u %u %u\n", 1, 125, 2147483647, (unsigned)-1,
// 			(unsigned)-125, (unsigned)-2147483647);
// 	ret2 = printf("%u %u %u %u %u %u\n", 1, 125, 2147483647, (unsigned)-1,
// 			(unsigned)-125, (unsigned)-2147483647);
// 	printf("ft_printf: %d, printf: %d\n", ret1, ret2);
// 	ret1 = ft_printf("%x %x %x %X %X %X\n", 1, 125, 2147483647, (unsigned)-1,
// 			(unsigned)-125, (unsigned)-2147483647);
// 	ret2 = printf("%x %x %x %X %X %X\n", 1, 125, 2147483647, (unsigned)-1,
// 			(unsigned)-125, (unsigned)-2147483647);
// 	printf("ft_printf: %d, printf: %d\n", ret1, ret2);
// 	ret1 = ft_printf("nombre de caracteres print %x\n", 125);
// 	ret2 = printf("nombre de caracteres print %x\n", 125);
// 	printf("ft_printf: %d, printf: %d\n", ret1, ret2);
// 	return (0);
// }
