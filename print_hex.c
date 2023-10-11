/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:46:59 by bsalgado          #+#    #+#             */
/*   Updated: 2023/10/11 19:41:54 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	************************* print_nbr_right() **************************
	The print_nbr_right function appears to handle the right-justified 
	printing of an unsigned integer nbr in hexadecimal format based on 
	the provided flags and the character c.

	int print_nbr_right(unsigned int nbr, int *flags, const char c)
	The function takes three arguments: an unsigned integer nbr to be 
	printed, a pointer to an integer array flags representing various 
	formatting flags, and a character c.

    int i = 0; int j = 0;
	Two variables i and j are initialized to zero. These variables are 
	used to track the number of characters written for space 
	padding (i) and '0' padding (j).

    while (i < flags[7]) i += write(1, " ", 1);
	This loop writes space characters to the standard output until 
	the number of characters written (i) reaches the value stored 
	in flags[7]. The value of flags[7] seems to represent the field 
	width for the hexadecimal string.

    if (flags[2])
	If the flags[2] is non-zero, it means the '0' flag is specified. 
	This flag indicates that leading zeros should be added to the 
	hexadecimal representation. The function writes a single '0' 
	character to the standard output to indicate the prefix of 
	the hexadecimal representation.

    flags[2] = write(1, "0", 1);
	The number of characters written for the '0' prefix is 
	stored in flags[2].

    flags[2] += write(1, &c, 1);
	The character c is written to the standard output. It is used 
	as a prefix before the actual hexadecimal representation 
	(e.g., 'x' for "0x", 'X' for "0X").

    while (j < flags[6]) j += write(1, "0", 1);
	This loop writes '0' characters to the standard output until 
	the number of characters written (j) reaches the value stored 
	in flags[6]. The value of flags[6] seems to represent the 
	minimum width of the hexadecimal string, and '0' characters 
	are added to pad the string on the left with zeros.

    if (flags[5] < 2) ft_puthex_fd(nbr, c, 1);
	If the flag at index 5 in the flags array is less than 2 
	(indicating no zero-padding), the unsigned integer nbr is 
	printed to the standard output in hexadecimal format using 
	the ft_puthex_fd function. The character c is also provided 
	to determine whether to use lowercasbft

	The print_nbr_right function is designed to handle right-justified 
	printing of an unsigned integer in hexadecimal format with optional 
	space padding, '0' padding, and a customizable prefix based 
	on the values stored in the flags array and the character c. 
	The exact behavior and formatting will depend on the specific 
	values in the flags array and the context in which this function 
	is used within the larger program. The implementation of the 
	ft_puthex_fd function, which is not provided in the code 
	snippet, will also affect the actual output.


	************************* print_nbr_left() **************************
	The print_nbr_left function is another version of the previous 
	print_nbr_left function. It handles the left-justified printing of an 
	unsigned integer nbr in hexadecimal format based on the provided 
	flags and the character c.

	int print_nbr_left(unsigned int nbr, int *flags, const char c)
	The function takes three arguments: an unsigned integer nbr to be 
	printed, a pointer to an integer array flags representing various 
	formatting flags, and a character c.

    int i = 0; int j = 0;
	Two variables i and j are initialized to zero. These variables 
	are used to track the number of characters written for space 
	padding (i) and '0' padding (j).

    if (flags[2])
	If the flags[2] is non-zero, it means the '0' flag is specified. 
	This flag indicates that leading zeros should be added to the 
	hexadecimal representation. The function writes a single '0' 
	character to the standard output to indicate the prefix of 
	the hexadecimal representation.

    flags[2] = write(1, "0", 1);
	The number of characters written for the '0' prefix 
	is stored in flags[2].

    flags[2] += write(1, &c, 1);
	The character c is written to the standard output. It is 
	used as a prefix before the actual hexadecimal 
	representation (e.g., 'x' for "0x", 'X' for "0X").

    while (j < flags[6]) j += write(1, "0", 1);
	This loop writes '0' characters to the standard output until 
	the number of characters written (j) reaches the value stored 
	in flags[6]. The value of flags[6] seems to represent the 
	minimum width of the hexadecimal string, and '0' characters 
	are added to pad the string on the left with zeros.

    if (flags[5] < 2) ft_puthex_fd(nbr, c, 1);
	If the flag at index 5 in the flags array is less than 2 
	(indicating no zero-padding), the unsigned integer nbr 
	is printed to the standard output in hexadecimal format 
	using the ft_puthex_fd function. The character c is also 
	provided to determine whether to use lowercase ('a'-'f') 
	or uppercase ('A'-'F') letters in the hexadecimal representation.

    while (i < flags[7]) i += write(1, " ", 1);
	This loop writes space characters to the standard output 
	until the number of characters written (i) reaches the 
	value stored in flags[7]. The value of flags[7] seems to 
	represent the field width for the hexadecimal string.

    The function returns the total number of characters 
	written, which is the sum of the characters printed for 
	space padding (i), '0' padding (j), and the characters 
	written for the prefix ('0' and c) if the '0' flag is 
	specified (flags[2]).

	The print_nbr_left function is designed to handle 
	left-justified printing of an unsigned integer in hexadecimal 
	format with optional space padding, '0' padding, and a 
	customizable prefix based on the values stored in the flags 
	array and the character c. The exact behavior and formatting 
	will depend on the specific values in the flags array and 
	the context in which this function is used within the larger 
	program. The implementation of the ft_puthex_fd function, 
	which is not provided in the code snippet, will also affect 
	the actual output.

	************************* print_hex() **************************
	int print_hex(unsigned int nbr, int *flags, const char c)
	The function takes three arguments: an unsigned integer nbr 
	to be printed, a pointer to an integer array flags representing 
	various formatting flags, and a character c.

    int len = ft_intlen(nbr, 16);
	The function ft_intlen is assumed to calculate the number of 
	digits in the unsigned integer nbr when represented in base 16 
	(hexadecimal). It determines the length of the hexadecimal string.

    if (!nbr) flags[2] = 0;
	If the unsigned integer nbr is zero, the '0' flag (flags[2]) 
	is set to 0. This is done to handle a special case where the 
	number is zero, and the '0' flag is specified, which means the 
	prefix '0x' should not be added.

    if (flags[5] && !flags[6] && !nbr) flags[5] += len--;
	This conditional block handles a special case where the precision 
	flag (flags[5]) is specified, but the width flag (flags[6]) 
	is not, and the number nbr is zero. It increases the precision 
	by the length of the hexadecimal string minus one (len--) to 
	handle zero padding.

    if (flags[4] && !flags[5])
	This conditional block handles the case when the '0' flag (flags[4]) 
	is specified, but the precision flag (flags[5]) is not. In this 
	case, it treats the width flag (flags[6]) as the precision and 
	sets the width flag to zero.

    The function calculates the remaining width available for the 
	hexadecimal string after considering the width of flags and the 
	length of the hexadecimal string. This is done for both 
	left-justified and right-justified printing, based on the 
	flags[3] value.

    If left-justified printing is chosen (flags[3] is true), 
	the function returns the result of len + print_nbr_left(nbr, flags, c). 
	It passes the unsigned integer nbr, the flags, and the character 
	c (indicating the prefix) to the print_nbr_left function.

    If right-justified printing is chosen (flags[3] is false), 
	the function returns the result of len + 
	print_nbr_right(nbr, flags, c). It passes the unsigned integer nbr, 
	the flags, and the character c (indicating the prefix) 
	to the print_nbr_right function.

	The print_hex function is designed to handle the printing of an 
	unsigned integer in hexadecimal format with optional space padding, 
	'0' padding, and a customizable prefix based on the values stored 
	in the flags array and the character c. The exact behavior and 
	formatting will depend on the specific values in the flags 
	array and the context in which this function is used within 
	the larger program. The correctness of the output will also 
	depend on the proper implementation of the ft_intlen, 
	print_nbr_left, and print_nbr_right functions, which are 
	not provided in the code snippet.


*/

static int	print_nbr_right(unsigned int nbr, int *flags, const char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < flags[7])
		i += write(1, " ", 1);
	if (flags[2])
	{
		flags[2] = write(1, "0", 1);
		flags[2] += write(1, &c, 1);
	}
	while (j < flags[6])
		j += write(1, "0", 1);
	if (flags[5] < 2)
		ft_puthex_fd(nbr, c, 1);
	return (i + j + flags[2]);
}

static int	print_nbr_left(unsigned int nbr, int *flags, const char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (flags[2])
	{
		flags[2] = write(1, "0", 1);
		flags[2] += write(1, &c, 1);
	}
	while (j < flags[6])
		j += write(1, "0", 1);
	if (flags[5] < 2)
		ft_puthex_fd(nbr, c, 1);
	while (i < flags[7])
		i += write(1, " ", 1);
	return (i + j + flags[2]);
}

int	print_hex(unsigned int nbr, int *flags, const char c)
{
	int	len;

	len = ft_intlen(nbr, 16);
	if (!nbr)
		flags[2] = 0;
	if (flags[5] && !flags[6] && !nbr)
		flags[5] += len--;
	if (flags[4] && !flags[5])
	{
		flags[6] = flags[7];
		flags[7] = 0;
	}
	if (flags[6] > len)
		flags[7] -= flags[6];
	else
		flags[7] -= len ;
	if (flags[5])
		flags[6] -= len;
	else
		flags[6] -= len ;
	if (flags[3])
		return (len + print_nbr_left(nbr, flags, c));
	return (len + print_nbr_right(nbr, flags, c));
}
