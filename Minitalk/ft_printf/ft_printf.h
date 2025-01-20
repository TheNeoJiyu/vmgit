/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:32:43 by antolefe          #+#    #+#             */
/*   Updated: 2024/08/26 15:15:12 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	ft_putchar_fd(char c, int fd);
int		ft_print_char(int c);
int		ft_print_str(char *str, int *output);
int		get_len(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_print_id(int n, int *output);
size_t	ft_ptrlen(unsigned long long n);
void	ft_putptr(unsigned long long n);
void	ft_print_ptr(unsigned long long n, int *output);
void	ft_print_u(unsigned int n, int *output);
size_t	ft_hexlen(unsigned int value);
void	ft_puthex(unsigned int n, const char c);
void	ft_print_hexa(unsigned int value, const char c, int *output);
void	print_type(const char c, va_list value, int *output);
int		ft_printf(const char *str, ...);

#endif
