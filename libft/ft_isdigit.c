/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:58:45 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:28:24 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

  	1 - The function ft_isdigit takes an integer c as an argument, 
	representing the character to be checked.

  	2 - It checks if the value of c falls within the ASCII range of decimal 
	digits ('0' to '9').

  	3 - If c is a decimal digit, the code returns 1, indicating that 
	the character is a digit.

  	4 - If c is not a decimal digit, the code returns 0, indicating that 
	the character is not a digit.

	5 - This implementation of isdigit checks if a character is a decimal 
	digit by comparing its value to the ASCII range of decimal digits. 
	It returns 1 if the character is a digit and 0 otherwise.

*/

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
int	main(void)
{
	char	name;

	name = 'b';
	
	printf("\n\t>>> USING ft_isdigit() <<<\n\n");
	printf("Sending \'%c\' : %d\n", name, ft_isdigit(name));

	if (ft_isdigit(name))
		printf("The char \'%c\' is numeric.\n", name);
	else
		printf("The char \'%c\' is not numeric.\n", name);
}
*/