/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 02:32:36 by antolefe          #+#    #+#             */
/*   Updated: 2025/02/25 02:32:36 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // For malloc

int *ft_range(int start, int end)
{
    int size;
    int *array;
    int i;

    // Calculate the size of the array
    if (start <= end)
        size = end - start + 1;
    else
        size = start - end + 1;

    // Allocate memory for the array
    array = (int *)malloc(size * sizeof(int));
    if (!array) // Check if malloc failed
        return (NULL);

    // Fill the array with consecutive values
    i = 0;
    if (start <= end)
    {
        while (start <= end)
        {
            array[i] = start;
            start++;
            i++;
        }
    }
    else
    {
        while (start >= end)
        {
            array[i] = start;
            start--;
            i++;
        }
    }

    // Return the pointer to the array
    return (array);
}
