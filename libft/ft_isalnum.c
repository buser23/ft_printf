/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:00:01 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:28:40 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

  	1 - The function ft_isalnum takes an integer c as an argument, 
	representing the character to be checked.

  	2 - It calls two helper functions, ft_isalpha and ft_isdigit, to check if 
	the character c is either an alphabetic character or a digit.

  	3 - If either ft_isalpha(c) or ft_isdigit(c) returns 1, indicating 
	that c is an alphabetic character or a digit, the code returns 1, 
	indicating that the character is an alphanumeric character.

  	4 - If both ft_isalpha(c) and ft_isdigit(c) return 0, indicating 
	that c is neither an alphabetic character nor a digit, the code returns 0, 
	indicating that the character is not an alphanumeric character.

	5 - This implementation of isalnum checks if a character is 
	an alphanumeric character by utilizing the ft_isalpha and ft_isdigit 
	helper functions. It returns 1 if the character is either an 
	alphabetic character or a digit, and 0 otherwise.

*/

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/*
int	main(void)
{
	char	name;

	name = 'b';
	
	printf("\n\t>>> USING ft_isalnum() <<<\n\n");
	printf("Sending \'%c\' : %d\n", name, ft_isalnum(name));

	if (ft_isalnum(name))
		printf("The char \'%c\' is alphanumeric.\n", name);
	else
		printf("The char \'%c\' is not alphanumeric.\n", name);
}
*/