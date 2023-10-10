/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoapositive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:40:04 by bsalgado          #+#    #+#             */
/*   Updated: 2023/10/11 00:40:41 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*

	************************* ft_itoapositive() **************************
	The ft_itoapositive function takes a long long integer n as input and 
	returns a dynamically allocated string (char*) containing the absolute 
	value of the integer as a null-terminated string.

	char *ft_itoapositive(long long n)
	The function takes a long long integer n as input and returns a char*.

    bool sign = n < 0;
	The function checks if the input n is negative or not and 
	stores the result in the boolean variable sign.

    long long len = ft_intlen(n, 10);
	The function ft_intlen is assumed to calculate the number of 
	digits in the long long integer n when represented in base 10 
	(decimal). It determines the length of the string needed to 
	represent the absolute value of n.

    c = (char *)malloc(sizeof(char) * (len + 1));
	The function allocates memory for the char array c to 
	hold the absolute value of n. The length of the array 
	is len + 1 to accommodate the null-terminator.

    if (!c) return (NULL);
	If the memory allocation fails (returns NULL), the 
	function returns NULL to indicate the failure.

    c[len] = '\0';
	The null-terminator is placed at the end of the char array 
	to make it a valid C-style string.

    if (sign) { ... }
	If n is negative, the function enters this block to 
	handle the special case of the negative sign.

    c[--len] = -(n % 10) + '0';
	The last character of the string (len - 1 index) is set 
	to the digit's absolute value in the ones' place by 
	performing -(n % 10) + '0'. This is done because n % 10 gives 
	the last digit of the negative number n, and we need 
	its absolute value.

    n = -(n / 10);
	The negative number n is updated by performing -(n / 10). 
	This is done to handle the remaining digits of the 
	absolute value of n since n was negative.

    The function enters a loop that fills the remaining 
	characters of the string with the absolute value of n.

    c[len] = n % 10 + '0';
	The character at index len - 1 (second-to-last digit of 
	the absolute value) is set to the corresponding digit 
	by performing n % 10 + '0'.

    n = n / 10;
	n is updated to the next digit in the absolute value 
	representation.

    The loop continues until len becomes 0.

    The function returns the dynamically allocated char array c, 
	which holds the absolute value of the input n as 
	a null-terminated string.

	It's important to note that this function correctly handles 
	the special case of negative numbers, and the returned string 
	contains the absolute value of the input n. The caller is 
	responsible for freeing the memory allocated for the returned 
	char array to avoid memory leaks.

*/

char	*ft_itoapositive(long long n)
{
	char		*c;
	bool		sign;
	long long	len;

	sign = n < 0;
	len = ft_intlen(n, 10);
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	c[len] = '\0';
	if (sign)
	{
		c[--len] = -(n % 10) + '0';
		n = -(n / 10);
	}
	while (len--)
	{
		c[len] = n % 10 + '0';
		n = n / 10;
	}
	return (c);
}
