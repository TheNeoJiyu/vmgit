/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antolefe <antolefe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 02:24:53 by antolefe          #+#    #+#             */
/*   Updated: 2025/02/25 02:24:53 by antolefe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;        // Index for iterating through the string
	int sign = 1;     // Sign of the result (1 for positive, -1 for negative)
	int result = 0;   // The final result

	// Skip whitespace characters (optional, depending on requirements)
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		   str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;

	// Handle the sign
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	// Convert characters to integers
	while (str[i])
	{
		int value; // Numeric value of the current character

		// Handle digits 0-9
		if (str[i] >= '0' && str[i] <= '9')
			value = str[i] - '0';
		// Handle lowercase letters a-f
		else if (str[i] >= 'a' && str[i] <= 'f')
			value = str[i] - 'a' + 10;
		// Handle uppercase letters A-F
		else if (str[i] >= 'A' && str[i] <= 'F')
			value = str[i] - 'A' + 10;
		// Invalid character for the base
		else
			break;

		// Check if the value is valid for the base
		if (value >= str_base)
			break;

		// Update the result
		result = result * str_base + value;
		i++;
	}

	// Apply the sign and return the result
	return (result * sign);
}
