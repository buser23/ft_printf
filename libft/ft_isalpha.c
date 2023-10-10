/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:59:53 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:28:06 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	1 - The function ft_isalpha takes an integer c as an argument, 
	representing the character to be checked.

  	2 - It checks if the value of c falls within the ASCII range of lowercase 
	letters ('a' to 'z') or the ASCII range of uppercase letters ('A' to 'Z').

  	3 - If c is an alphabetic character, the code returns 1, indicating 
	that the character is an alphabet.

  	4 - If c is not an alphabetic character, the code returns 0, indicating 
	that the character is not an alphabet.

	5 - This implementation of isalpha checks if a character is an alphabetic 
	character by comparing its value to the ASCII ranges of lowercase and 
	uppercase letters. It returns 1 if the character 
	is an alphabet and 0 otherwise.

*/

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/*
int	main(void)
{
	char	name;

	name = 'b';
	
	printf("\n\t>>> USING ft_isalpha() <<<\n\n");
	printf("Sending \'%c\' : %d\n", name, ft_isalpha(name));

	if (ft_isalpha(name))
		printf("The char \'%c\' is alphabetic.\n", name);
	else
		printf("The char \'%c\' is not alphabetic.\n", name);
}
*/