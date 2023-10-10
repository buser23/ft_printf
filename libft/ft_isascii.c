/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:59:43 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:28:56 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

  	1 - The function ft_isascii takes an integer c as an argument, 
	representing the character to be checked.

  	2 - It checks if the value of c is greater than or equal to 0 and less 
	than or equal to 127. This range represents the valid ASCII characters.

 	3 - If c falls within the valid ASCII range, the code returns 1, 
	indicating that the character is a valid ASCII character.

  	4 - If c is outside the valid ASCII range, the code returns 0, 
	indicating that the character is not a valid ASCII character.

	5 - This implementation of isascii checks if a character is within 
	the valid ASCII range by comparing its value to the range of 0 to 127. 
	It returns 1 if the character is a valid ASCII character and 0 otherwise.

*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
int	main(void)
{
	char	name;

	name = 'b';
	
	printf("\n\t>>> USING ft_isascii() <<<\n\n");
	printf("Sending \'%c\' : %d\n", name, ft_isascii(name));

	if (ft_isascii(name))
		printf("The char \'%c\' is from ascii table.\n", name);
	else
		printf("The char \'%c\' is not from ascii table.\n", name);
}
*/