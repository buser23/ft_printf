/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:45:58 by bsalgado          #+#    #+#             */
/*   Updated: 2023/10/11 00:46:38 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*

	************************* print_chr() **************************
	The print_chr function handles the printing of a single 
	character c based on the provided flags.

	int print_chr(char c, int *flags)
	The function takes two arguments: a character c to be printed 
	and a pointer to an integer array flags representing various 
	formatting flags.

    int i = 0;
	A variable i is initialized to zero. This variable is used to 
	track the number of characters written for space padding.

    if (flags[3])
	If the flags[3] is true, it means the 'left-justify' flag is 
	specified. In this case, the function writes the character c 
	to the standard output first, and then it writes space 
	characters to the standard output to pad the output on 
	the right until the total width (flags[7]) is reached.

    write(1, &c, 1);
	The character c is written to the standard output.

    while (i < flags[7] - 1) i += write(1, " ", 1);
	This loop writes space characters to the standard output 
	until the number of characters written (i) reaches the value 
	flags[7] - 1. The value of flags[7] seems to represent the 
	field width for the character.

    If the 'left-justify' flag is not specified (flags[3] is false), 
	the function writes space characters first to pad the output 
	on the left until the total width (flags[7]) is reached, 
	and then it writes the character c to the standard output.

    return (1 + i);
	The function returns the total number of characters written, 
	which is the sum of the character written for the 
	character c (1) and the characters written for space 
	padding (i).

	The print_chr function is designed to handle the printing of a 
	single character with optional space padding based on the 
	values stored in the flags array. The exact behavior and 
	formatting will depend on the specific value in the flags 
	array and the context in which this function is used within 
	the larger program. The correctness of the output will also 
	depend on the proper implementation of the write functions, 
	which are not provided in the code snippet.

*/

int	print_chr(char c, int *flags)
{
	int		i;

	i = 0;
	if (flags[3])
	{
		write(1, &c, 1);
		while (i < flags[7] - 1)
			i += write(1, " ", 1);
	}
	else
	{
		while (i < flags[7] - 1)
			i += write(1, " ", 1);
		write(1, &c, 1);
	}
	return (1 + i);
}
