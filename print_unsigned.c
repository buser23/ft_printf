/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:51:42 by bsalgado          #+#    #+#             */
/*   Updated: 2023/10/11 19:41:35 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*

	****************************** print_nbr_right() ************************
	This function seems to be a part of the larger program responsible 
	for printing formatted output. It appears to handle the right-justified 
	printing of a numeric string (nbr) based on the provided flags. 
	Let's break down the function step by step:

	int print_nbr_right(char *nbr, int *flags)
	The function takes two arguments: a pointer to a character array 
	nbr (presumably containing the numeric string to print) and a 
	pointer to an integer array flags (representing various formatting flags).

    int i = 0; int j = 0;
	Two variables i and j are initialized to zero. These variables 
	are used for tracking the number of characters written.

    while (i < flags[7]) i += write(1, " ", 1);
	This loop writes space characters to the standard output until 
	the number of characters written (i) reaches the value stored 
	in flags[7]. The value of flags[7] seems to indicate the total 
	width or field width for the numeric string.

    while (j < flags[6]) j += write(1, "0", 1);: This loop writes '0' 
	characters to the standard output until the number of characters 
	written (j) reaches the value stored in flags[6]. The value of 
	flags[6] appears to represent the minimum width of the numeric 
	string, and '0' characters are added to pad the string on the 
	left with zeros.

    if (flags[5] < 2) ft_putstr_fd(nbr, 1);
	The condition flags[5] < 2 seems to check if the flag at 
	index 5 in the flags array is less than 2. If true, the 
	function ft_putstr_fd is called to print the numeric string 
	(nbr) to the standard output (file descriptor 1). 
	The ft_putstr_fd function is assumed to be responsible for 
	printing a string to the specified file descriptor.

    free(nbr);
	The nbr string was likely dynamically allocated, so 
	it is freed to avoid memory leaks.

    return (i + j);
	The function returns the total number of characters written, 
	which is the sum of the characters printed for space 
	padding (i) and '0' padding (j).

	The function print_nbr_right appears to handle right-justified 
	printing of a numeric string with optional space and '0' 
	padding based on the values stored in the flags array. 
	The exact behavior and formatting may depend on the 
	specific values in the flags array and the context in 
	which this function is used within the larger program.


	*************************** print_nbr_left() ***************
	This function appears to be another part of the larger 
	program responsible for printing formatted output. It seems 
	to handle the left-justified printing of a numeric 
	string (nbr) based on the provided flags. Let's break 
	down the function step by step:

	int print_nbr_left(char *nbr, int *flags)
	The function takes two arguments: a pointer to a 
	character array nbr (presumably containing the numeric string 
	to print) and a pointer to an integer array flags 
	(representing various formatting flags).

    int i = 0; int j = 0;
	Two variables i and j are initialized to zero. 
	These variables are used for tracking the number of 
	characters written.

    while (j < flags[6]) j += write(1, "0", 1);
	This loop writes '0' characters to the standard output 
	until the number of characters written (j) reaches 
	the value stored in flags[6]. The value of flags[6] 
	seems to represent the minimum width of the numeric 
	string, and '0' characters are added to pad the 
	string on the left with zeros.

    if (flags[5] < 2) ft_putstr_fd(nbr, 1);
	The condition flags[5] < 2 seems to check if the flag 
	at index 5 in the flags array is less than 2. If true, 
	the function ft_putstr_fd is called to print the numeric 
	string (nbr) to the standard output (file descriptor 1). 
	The ft_putstr_fd function is assumed to be responsible 
	for printing a string to the specified file descriptor.

    free(nbr);
	The nbr string was likely dynamically allocated, 
	so it is freed to avoid memory leaks.

    while (i < flags[7]) i += write(1, " ", 1);
	This loop writes space characters to the standard output 
	until the number of characters written (i) reaches the 
	value stored in flags[7]. The value of flags[7] seems 
	to indicate the total width or field width for the 
	numeric string.

    return (i + j);: The function returns the total 
	number of characters written, which is the sum of 
	the characters printed for '0' padding (j) and space 
	padding (i).

	The function print_nbr_left appears to handle 
	left-justified printing of a numeric string with optional 
	'0' padding and space padding based on the values stored 
	in the flags array. The exact behavior and formatting may 
	depend on the specific values in the flags array and the 
	context in which this function is used within 
	the larger program.

	Please note that the correctness and completeness of the 
	print_nbr_left function depend on the proper 
	initialization of the nbr string, the values of flags[5], 
	flags[6], and flags[7], and the correct implementation of 
	the ft_putstr_fd function (which is not provided in 
	the code snippet).


	*************************** print_unsigned() ***************
	This function appears to handle the printing of an unsigned 
	integer n based on the provided flags.

	int print_unsigned(unsigned int n, int *flags)
	The function takes two arguments: an unsigned integer n 
	to be printed and a pointer to an integer array flags 
	representing various formatting flags.

    char *nbr;
	A character pointer nbr is declared. It will be used to 
	store the string representation of the positive integer n.

    nbr = ft_itoapositive(n);
	The function ft_itoapositive is assumed to convert the 
	unsigned integer n into a string representation of its 
	positive value and return that string. The nbr pointer 
	is set to point to this string.

    int len = ft_intlen(n, 10);
	The function ft_intlen is assumed to calculate the 
	number of digits in the unsigned integer n when 
	represented in base 10. The result is stored 
	in the len variable.

    The following conditional checks handle special cases 
	related to the flags array:
        if (flags[5] && !flags[6] && !n)
		If the flag at index 5 in the flags array is non-zero 
		and both flags at indices 6 and 7 are zero (no precision 
		specified) and n is zero, then the flags[5] value is 
		incremented by len - 1. This indicates that zero-padding 
		should be added to the string.
        if (flags[4] && !flags[5]): 
		If the flag at index 4 in the flags array is non-zero 
		and the flag at index 5 is zero (no zero-padding specified), 
		then the value of flags[6] is set to the value stored in 
		flags[7], and flags[7] is set to zero. This indicates 
		that the field width should be set to the value 
		previously stored in flags[7].

    The following adjustments are made based on the flags:
        if (flags[6] > len)
		If the value stored in flags[6] (precision) is greater 
		than len, then flags[7] (field width) is decreased by 
		flags[6]. This ensures that the field width will be at 
		least flags[6] characters long.
        else
		Otherwise, flags[7] is decreased by len, indicating 
		that the field width will be at least len characters long.
        if (flags[5]): If the flag at index 5 in the flags 
		array is non-zero (indicating zero-padding), flags[6] 
		is decreased by len. Otherwise, flags[6] is decreased 
		by len as well (indicating space-padding).

    The function determines whether to perform left-justified 
	or right-justified printing based on the value of flags[3].
        if (flags[3]): If the flag at index 3 in the flags array 
		is non-zero, left-justified printing is performed. 
		The function returns the sum of len and the result 
		of print_nbr_left(nbr, flags).
        Otherwise, right-justified printing is performed. 
		The function returns the sum of len and the result 
		of print_nbr_right(nbr, flags).

	The print_unsigned function is designed to handle the 
	printing of unsigned integers with various formatting 
	options specified through the flags array. The actual 
	behavior and formatting will depend on the values in 
	the flags array and the implementation of the 
	ft_itoapositive, ft_intlen, print_nbr_left, and print_nbr_right 
	functions, which are not provided in the code snippet.

*/

static int	print_nbr_right(char *nbr, int *flags)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < flags[7])
		i += write(1, " ", 1);
	while (j < flags[6])
		j += write(1, "0", 1);
	if (flags[5] < 2)
		ft_putstr_fd(nbr, 1);
	free(nbr);
	return (i + j);
}

static int	print_nbr_left(char *nbr, int *flags)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < flags[6])
		j += write(1, "0", 1);
	if (flags[5] < 2)
		ft_putstr_fd(nbr, 1);
	free(nbr);
	while (i < flags[7])
		i += write(1, " ", 1);
	return (i + j);
}

int	print_unsigned(unsigned int n, int *flags)
{
	int		len;
	char	*nbr;

	nbr = ft_itoapositive(n);
	len = ft_intlen(n, 10);
	if (flags[5] && !flags[6] && !n)
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
		return (len + print_nbr_left(nbr, flags));
	return (len + print_nbr_right(nbr, flags));
}
