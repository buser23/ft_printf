/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:20:58 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:38:52 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*

	1 - It initializes two variables, sign and result. sign represents the 
	sign of the resulting integer (positive or negative), and result will 
	hold the converted integer value.

    2 - The function begins by skipping any leading whitespace characters 
	by incrementing the nptr pointer. These characters include ASCII 
	characters with decimal values between 9 and 13 (inclusive) and 
	the space character ' '.

    3 - It checks if the current character pointed to by nptr is a 
	minus sign '-' or a plus sign '+'. If a minus sign is encountered, 
	the sign variable is set to -1 to indicate a negative value. 
	The nptr pointer is then incremented.

    4 - Next, the function enters a loop that continues as long as 
	the current character pointed to by nptr is a digit between 
	'0' and '9'. In each iteration, it multiplies the result by 10 
	to shift the existing digits one place to the left and adds 
	the value of the current digit by subtracting the character '0'. 
	This converts the character representation of the digit to its 
	corresponding integer value. The nptr pointer is then incremented 
	to move to the next digit.

    5 - Once all digits have been processed, the function returns 
	the final result multiplied by the sign to account for the 
	desired sign of the integer.

	The function successfully converts the given string of 
	digits to its corresponding integer value, taking into account 
	leading whitespace characters and an optional sign.

*/

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
	{
		nptr++;
	}
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
		{
			sign = -1;
		}
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = (result * 10) + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}

/*
int	main(void)
{
	char str[] = "-----1234ab567";
	int num = ft_atoi(str);
	printf("Result: %d\n", num);
	
	return (0);
}
*/