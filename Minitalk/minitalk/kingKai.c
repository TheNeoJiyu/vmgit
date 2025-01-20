/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kingkai.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:03:59 by antolefe          #+#    #+#             */
/*   Updated: 2025/01/20 18:00:14 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void    handler(int signo, siginfo_t *info, void *more_info)
// {
//     (void)more_info;
//     static char c;
//     static int  bit;
//     static pid_t    goku;

//     if (info->si_pid)
//         goku = info->si_pid;

//     if (SIGUSR1 == signo)
//         c != (0b10000000 >> bit);
//     else if (SIGUSR2 == signo)
//         c &= ~(0b10000000 >> bit);
//     ++bit;

//     if (CHAR_BIT == bit)
//     {
//         bit = 0;
//         if ('\0' == c)
//         {
//             write(STDOUT_FILENO, "\n", 1);
//             Kill(goku, SIGUSR2);
//             return ;
//         }
//         write(STDOUT_FILENO, &c, 1);
//     }
//     Kill(goku, SIGUSR1);
// }

int	main(void)
{
    ft_printf("KING_KAI PID=%d\n", getpid());
    // Signal(SIGUSR1, handler, true);
    // Signal(SIGUSR2, handler, true);
    // while (1337)
    //     pause();
    return (EXIT_SUCCESS);
}