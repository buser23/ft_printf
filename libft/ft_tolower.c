/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:06:02 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:33:29 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The ft_tolower function is a standard library function in C 
	that converts a given uppercase character to its 
	corresponding lowercase character.

	1 - The function ft_tolower takes an integer c as an argument, 
	representing the character to be converted.

    2 - It checks if the value of c falls within the ASCII range of 
	uppercase letters ('A' to 'Z').

    3 - If c is an uppercase letter, the code adds 32 to its value to obtain 
	the corresponding lowercase letter in the ASCII table. This conversion is 
	done by adding the ASCII difference between uppercase and lowercase letters.

    4 - If c is not an uppercase letter, it means it is either already a 
	lowercase letter or not an alphabetical character. In such cases, 
	the original value of c is returned as it is.

    5 - The function returns the converted lowercase character or the o
	riginal value of c.

*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

/*
int	main(void)
{
    char c = 'B';
    char c_converted = ft_tolower(c);

    printf("Original character: %c\n", c);
    printf("Lowercase character: %c\n", c_converted);

    return 0;
}
*/