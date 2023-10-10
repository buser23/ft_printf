/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:48:43 by bsalgado          #+#    #+#             */
/*   Updated: 2023/10/11 00:49:21 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	************************* print_nbr_right() **************************
	The print_nbr_right function seems to be a modified version of the 
	previous print_nbr_right function. It handles the right-justified 
	printing of a numeric string (nbr) based on the provided flags, and 
	it takes an additional parameter neg, which indicates whether the 
	numeric value is negative.

	int print_nbr_right(char *nbr, int *flags, int neg)
	The function takes three arguments: a pointer to a character 
	array nbr (presumably containing the numeric string to print), 
	a pointer to an integer array flags representing various formatting 
	flags, and an integer neg indicating whether the numeric 
	value is negative.

    int i = 0; int j = 0;
	Two variables i and j are initialized to zero. These 
	variables are used to track the number of characters written 
	for space padding (i) and '0' padding (j).

    while (i < flags[7]) i += write(1, " ", 1);
	This loop writes space characters to the standard output until 
	the number of characters written (i) reaches the value stored 
	in flags[7]. The value of flags[7] seems to represent the field 
	width for the numeric string.

    if (neg) flags[1] = write(1, "-", 1);
	If the neg parameter is non-zero (indicating a negative 
	numeric value), the minus sign '-' is written to the 
	standard output (file descriptor 1), and the flags[1] value 
	is updated to 1. The flags[1] indicates whether the string 
	should include a plus sign ('+'), space (' '), or neither.

    if (flags[1] && !neg) write(1, "+", 1);
	If the flags[1] is non-zero (indicating a plus sign is 
	required) and neg is zero (indicating a non-negative numeric 
	value), the plus sign '+' is written to the standard output.

    else if (flags[0] && !neg) flags[1] = write(1, " ", 1);
	If the flags[0] is non-zero (indicating a space should be 
	used for positive numbers) and neg is zero (indicating a 
	non-negative numeric value), a space character ' ' is 
	written to the standard output, and the flags[1] value 
	is updated to 1.

    while (j < flags[6]) j += write(1, "0", 1);
	This loop writes '0' characters to the standard output 
	until the number of characters written (j) reaches the 
	value stored in flags[6]. The value of flags[6] seems to 
	represent the minimum width of the numeric string, and '0' 
	characters are added to pad the string on the left with zeros.

    if (flags[5] < 2) ft_putstr_fd(nbr, 1);
	If the flag at index 5 in the flags array is less than 2 
	(indicating no zero-padding), the numeric string (nbr) is 
	printed to the standard output using the ft_putstr_fd function.

    free(nbr);
	The nbr string was likely dynamically allocated, so it 
	is freed to avoid memory leaks.

    return (i + j + flags[1]);
	The function returns the total number of characters written, 
	which is the sum of the characters printed for space padding 
	(i), '0' padding (j), and any additional characters introduced 
	by the plus sign or space for positive numbers (flags[1]).

	The print_nbr_right function appears to handle right-justified 
	printing of a numeric string with optional space padding, '0' 
	padding, and plus sign or space for positive numbers based on 
	the values stored in the flags array and the neg parameter. 
	The exact behavior and formatting may depend on the specific 
	values in the flags array and the context in which this 
	function is used within the larger program.


	************************* print_nbr_left() **************************
	The print_nbr_left function is another version of the previous 
	print_nbr_left function. It handles the left-justified printing 
	of a numeric string (nbr) based on the provided flags, and it 
	also takes an additional parameter neg, which indicates whether 
	the numeric value is negative.

	int print_nbr_left(char *nbr, int *flags, int neg)
	The function takes three arguments: a pointer to a character 
	array nbr (presumably containing the numeric string to print), 
	a pointer to an integer array flags representing various formatting 
	flags, and an integer neg indicating whether the numeric value is 
	negative.

    int i = 0; int j = 0;
	Two variables i and j are initialized to zero. These variables 
	are used to track the number of characters written for space 
	padding (i) and '0' padding (j).

    if (neg) flags[1] = write(1, "-", 1);
	If the neg parameter is non-zero (indicating a negative 
	numeric value), the minus sign '-' is written to the standard 
	output (file descriptor 1), and the flags[1] value is updated to 1. 
	The flags[1] indicates whether the string should include a plus 
	sign ('+'), space (' '), or neither.

    if (flags[1] && !neg) write(1, "+", 1);
	If the flags[1] is non-zero (indicating a plus sign is required) 
	and neg is zero (indicating a non-negative numeric value), 
	the plus sign '+' is written to the standard output.

    else if (flags[0] && !neg) flags[1] = write(1, " ", 1);
	If the flags[0] is non-zero (indicating a space should be used 
	for positive numbers) and neg is zero (indicating a non-negative 
	numeric value), a space character ' ' is written to the 
	standard output, and the flags[1] value is updated to 1.

    while (j < flags[6]) j += write(1, "0", 1);
	This loop writes '0' characters to the standard output until 
	the number of characters written (j) reaches the value stored 
	in flags[6]. The value of flags[6] seems to represent the minimum 
	width of the numeric string, and '0' characters are added to pad 
	the string on the left with zeros.

    if (flags[5] < 2) ft_putstr_fd(nbr, 1);
	If the flag at index 5 in the flags array is less than 2 
	(indicating no zero-padding), the numeric string (nbr) is 
	printed to the standard output using the ft_putstr_fd function.

    free(nbr);
	The nbr string was likely dynamically allocated, so it 
	is freed to avoid memory leaks.

    while (i < flags[7]) i += write(1, " ", 1);
	This loop writes space characters to the standard output 
	until the number of characters written (i) reaches the value 
	stored in flags[7]. The value of flags[7] seems to represent 
	the field width for the numeric string.

    return (i + j + flags[1]);
	The function returns the total number of characters written, 
	which is the sum of the characters printed for space 
	padding (i), '0' padding (j), and any additional characters 
	introduced by the plus sign or space for positive numbers 
	(flags[1]).

	The print_nbr_left function appears to handle left-justified 
	printing of a numeric string with optional space padding, '0' 
	padding, and plus sign or space for positive numbers based on 
	the values stored in the flags array and the neg parameter. 
	The exact behavior and formatting may depend on the specific 
	values in the flags array and the context in which this 
	function is used within the larger program.


	************************* print_nbr() **************************
	The print_nbr function handles the printing of an integer n based 
	on the provided flags. It calculates the necessary formatting and 
	padding options for the integer and then calls either 
	print_nbr_left or print_nbr_right to perform the actual printing, 
	depending on the value of the flag at index 3 in the flags array.

	int print_nbr(int n, int *flags)
	The function takes two arguments: an integer n to be printed 
	and a pointer to an integer array flags representing various 
	formatting flags.

    char *nbr = ft_itoapositive(n);
	The function ft_itoapositive is assumed to convert the integer 
	n to a positive string representation. It returns a pointer to 
	a character array containing the string representation of the 
	positive number.

    int len = ft_intlen(n, 10);
	The function ft_intlen is assumed to calculate the number of 
	digits in the integer n when represented in base 10. It determines 
	the length of the numeric string.

    bool neg = n < 0;
	The variable neg is a boolean flag that is set to true if the 
	integer n is negative.

    if (flags[5] && !flags[6] && !n) flags[5] += len--;
	This conditional block handles a special case where the precision 
	flag (flags[5]) is specified, but the width flag (flags[6]) 
	is not, and the number n is zero. It increases the precision 
	by the length of the numeric string minus one (len--) to handle 
	zero padding.

    if (flags[4] && !flags[5])
	This conditional block handles the case when the '0' flag 
	(flags[4]) is specified, but the precision flag (flags[5]) 
	is not. In this case, it treats the width flag (flags[6]) as 
	the precision and sets the width flag to zero.

    The function calculates the remaining width available 
	for the numeric string after considering the width of flags, 
	the sign character (if present), and the length of the numeric 
	string. This is done for both left-justified and 
	right-justified printing, based on the flags[3] value.

    If left-justified printing is chosen (flags[3] is true), 
	the function returns the result of len + print_nbr_left(nbr, 
	flags, neg). It passes the positive numeric string, the flags, 
	and the neg flag (indicating whether the number is negative) 
	to the print_nbr_left function.

    If right-justified printing is chosen (flags[3] is false), 
	the function returns the result of len + 
	print_nbr_right(nbr, flags, neg). It passes the positive 
	numeric string, the flags, and the neg flag to the 
	print_nbr_right function.

	The print_nbr function takes care of formatting the numeric 
	string and selecting the appropriate justification for the 
	output based on the provided flags. The actual printing is 
	delegated to the print_nbr_left or print_nbr_right function, 
	depending on the chosen justification. The correctness of the 
	output will depend on the proper implementation of the 
	ft_itoapositive, ft_intlen, print_nbr_left, and print_nbr_right 
	functions, which are not provided in the code snippet.

*/

static int	print_nbr_right(char *nbr, int *flags, int neg)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < flags[7])
		i += write(1, " ", 1);
	if (neg)
		flags[1] = write(1, "-", 1);
	if (flags[1] && !neg)
		write(1, "+", 1);
	else if (flags[0] && !neg)
		flags[1] = write(1, " ", 1);
	while (j < flags[6])
		j += write(1, "0", 1);
	if (flags[5] < 2)
		ft_putstr_fd(nbr, 1);
	free(nbr);
	return (i + j + flags[1]);
}

static int	print_nbr_left(char *nbr, int *flags, int neg)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (neg)
		flags[1] = write(1, "-", 1);
	if (flags[1] && !neg)
		write(1, "+", 1);
	else if (flags[0] && !neg)
		flags[1] = write(1, " ", 1);
	while (j < flags[6])
		j += write(1, "0", 1);
	if (flags[5] < 2)
		ft_putstr_fd(nbr, 1);
	free(nbr);
	while (i < flags[7])
		i += write(1, " ", 1);
	return (i + j + flags[1]);
}

int	print_nbr(int n, int *flags)
{
	int		len;
	bool	neg;
	char	*nbr;

	nbr = ft_itoapositive(n);
	len = ft_intlen(n, 10);
	neg = n < 0;
	if (flags[5] && !flags[6] && !n)
		flags[5] += len--;
	if (flags[4] && !flags[5])
	{
		flags[6] = flags[7];
		flags[7] = 0;
	}
	if (flags[6] > len)
		flags[7] -= flags[6] + flags[1] + flags[0] + neg;
	else
		flags[7] -= len + flags[1] + flags[0] + neg;
	if (flags[5])
		flags[6] -= flags[1] + flags[0] + len;
	else
		flags[6] -= flags[1] + flags[0] + len + neg;
	if (flags[3])
		return (len + print_nbr_left(nbr, flags, neg));
	return (len + print_nbr_right(nbr, flags, neg));
}
