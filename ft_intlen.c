/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:38:02 by bsalgado          #+#    #+#             */
/*   Updated: 2023/10/11 00:39:42 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*

	************************* ft_intlen() **************************
	The ft_intlen function calculates the length of an integer n when 
	represented in a given base. It returns the number of digits 
	required to represent n in that base.

	int ft_intlen(long long n, int base)
	The function takes two arguments: a long long integer n and 
	an integer base.

    int len = !n;
	The len variable is initialized to 1 if n is zero (to handle 
	the case of n being zero) and 0 otherwise.

    while (n) { ... }
	This is a loop that executes as long as n is not equal to zero.

    n /= base;
	In each iteration of the loop, n is divided by the base. This 
	operation effectively shifts the digits of n one position to 
	the right in the given base. For example, in base 10, n /= 10 
	effectively removes the rightmost digit of n.

    len++;
	In each iteration of the loop, the len variable is incremented. 
	This accounts for the number of digits in the representation 
	of n in the given base.

    After the loop, the function returns the value of len, 
	representing the number of digits required to represent 
	n in the given base.

	The ft_intlen function can be used to calculate the number 
	of digits in an integer when represented in any base. It is 
	a helpful utility function often used in custom 
	implementations of number-to-string conversion functions 
	for various bases (e.g., decimal, hexadecimal, binary, etc.). 
	The correctness of the output will depend on the valid 
	input for n and the base provided to the function.


*/

int	ft_intlen(long long n, int base)
{
	int	len;

	len = !n;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}
