/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:53:48 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:33:18 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The ft_toupper() function is a standard library function in C that converts 
	a given lowercase character to its corresponding uppercase character, 
	if it exists. 

	1 - The function ft_toupper takes an integer c as an argument, 
	representing the character to be converted.

    2 - It checks if the value of c falls within the ASCII range of 
	lowercase letters ('a' to 'z').

    3 - If c is a lowercase letter, the code subtracts 32 from its value 
	to obtain the corresponding uppercase letter in the ASCII table. 
	This conversion is done by subtracting the ASCII difference 
	between lowercase and uppercase letters.

    4 - If c is not a lowercase letter, it means it is either already 
	an uppercase letter or not an alphabetical character. In such cases, 
	the original value of c is returned as it is.

    5 - The function returns the converted uppercase character or 
	the original value of c.

*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

/*
int	main(void)
{
    char c = 'b';
    char c_converted = ft_toupper(c);

    printf("Original character: %c\n", c);
    printf("Uppercase character: %c\n", c_converted);

    return 0;
}
*/