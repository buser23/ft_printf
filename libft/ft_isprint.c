/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:59:32 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:29:08 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

  	1 - The function ft_isprint takes an integer c as an argument, 
	representing the character to be checked.

  	2 - It checks if the value of c is greater than 31 and less than 127. 
	This range represents the printable ASCII characters.

  	3 - If c falls within the printable ASCII range, the code returns 1, 
	indicating that the character is a printable character.

  	4 - If c is outside the printable ASCII range, the code returns 0, 
	indicating that the character is not a printable character.

*/

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (1);
	return (0);
}

/*
int	main(void)
{
	char name;

	name = 'b';

	printf("\n\t>>> USING ft_isprint() <<<\n\n");
	printf("Sending \'%c\' : %d\n", name, ft_isprint(name));

	if (ft_isprint(name))
		printf("The char \'%c\' is a printable character.\n", name);
	else
		printf("The char \'%c\' is not a printable character.\n", name);
}
*/
