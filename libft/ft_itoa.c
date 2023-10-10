/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:19:17 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:51:13 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	It is a C function that takes an integer n as input and returns a 
	pointer to a string representation of that integer. The string is dynamically 
	allocated and must be freed by the caller.

	The function ft_intlen takes an integer n as input and returns the 
	number of digits in that integer. Here's a breakdown of how the 
	function works:

    1 - Declare an integer variable len and initialize it to 0.

    2 - Use a ternary operator !n to check if n is zero. If it 
	is, assign len the value of 1. Otherwise, assign it the 
	value of 0.

    3 - Start a loop that continues while n is not zero.

    4 - Inside the loop, divide n by 10 to remove the 
	rightmost digit.

    5 - Increment len by 1 to count the digit that 
	was just removed.

    6 - Repeat steps 3-5 until n becomes zero.

    7 - Return the value of len.

	In summary, the function ft_intlen calculates the number of digits 
	in an integer by iteratively dividing the integer by 10 and 
	counting the number of divisions performed.

	The function ft_itoa takes an integer n as input and converts it 
	into a string representation. Here's a breakdown 
	of how the function works:

    1 - Declare a character pointer c to store the 
	dynamically allocated string.

    2 - Declare a boolean variable sign to store 
	whether n is negative.

    3 - Calculate the length of the resulting string by 
	calling the ft_intlen function and adding 1 to 
	account for the sign if n is negative.

    4 - Allocate memory for the string c using malloc. 
	The size of the allocated memory is calculated as 
	(len + 1) to accommodate the characters of the 
	string plus the null character '\0' at the end.

    5 - Check if the memory allocation was successful. 
	If not, return NULL to indicate an error.

    6 - Assign the null character '\0' to the last 
	position in the string c to initialize it.

    7 - Check if n is negative using the sign variable. 
	If it is, set the first character of c as '-' 
	to indicate the negative sign.

    8 - Assign the last non-null character in the string 
	c as -(n % 10) + '0' to convert the rightmost digit of 
	n to a character. Then, update n to -(n / 10) to 
	remove the rightmost digit.

    9 - Start a loop that continues until the desired 
	length of the string is reached.

    10 - Inside the loop, assign the current non-null 
	character in the string c as n % 10 + '0' to convert 
	the rightmost digit of n to a character. Then, 
	update n to n / 10 to remove the rightmost digit.

    11 - Decrement the position len to move to the 
	next character in c.

    12 -Repeat steps 9-11 until the desired length 
	of the string is reached.

    13 - Return the dynamically allocated string c.

	In summary, the function ft_itoa converts an integer into a 
	string representation by iteratively dividing the integer 
	by 10 and converting the remainders to characters. 
	It handles negative numbers by adding a sign character 
	at the beginning of the string. The resulting string 
	is dynamically allocated and returned.

*/

static int	ft_intlen(int n)
{
	int	len;

	len = !n;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*c;
	bool	sign;
	int		len;

	sign = n < 0;
	len = ft_intlen(n) + sign;
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	c[len] = '\0';
	if (sign)
	{
		*c = '-';
		c[--len] = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (len-- - sign)
	{
		c[len] = n % 10 + '0';
		n = n / 10;
	}
	return (c);
}

/*
int	main(void)
{
	int	num = -12345;
    char *str = ft_itoa(num);
    if (str != NULL) 
	{
        printf("%d -> %s\n", num, str);
        free(str);
    }
    return 0;
}
*/