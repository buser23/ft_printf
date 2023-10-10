/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:50:41 by bsalgado          #+#    #+#             */
/*   Updated: 2023/10/11 00:51:18 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*

	****************************** str_left() ************************
	The str_left function appears to handle the left-justified 
	printing of a string s based on the provided flags. 

	int str_left(char *s, int *flags): The function takes two arguments
	a pointer to a character array s (presumably containing the string to 
	print) and a pointer to an integer array flags representing various 
	formatting flags.

    int i = 0;
	A variable i is initialized to zero. This variable is used 
	to track the number of characters written for space padding.

    ft_putstr_fd(s, 1);
	The function ft_putstr_fd is assumed to print the string s to 
	the standard output (file descriptor 1). This means that the 
	string will be left-justified on the output.

    free(s);
	The s string was likely dynamically allocated, so it is 
	freed to avoid memory leaks.

    while (i < flags[7]) i += write(1, " ", 1);
	This loop writes space characters to the standard output until 
	the number of characters written (i) reaches the value stored 
	in flags[7]. The value of flags[7] seems to represent the 
	field width for the string.

    return (i);
	The function returns the total number of characters written, 
	which is the number of space characters written for padding.

	The str_left function appears to handle left-justified printing 
	of a string with optional space padding based on the value stored 
	in the flags array. The exact behavior and formatting may 
	depend on the specific value in the flags[7] field width and 
	the context in which this function is used within the larger 
	program.

	Please note that the correctness and completeness of the str_left 
	function depend on the proper initialization and allocation of 
	the s string and the correct implementation of the ft_putstr_fd 
	function (which is not provided in the code snippet).


	****************************** str_right() ************************
	The str_right function appears to handle the right-justified 
	printing of a string s based on the provided flags.

	int str_right(char *s, int *flags): 
	The function takes two arguments: a pointer to a character 
	array s (presumably containing the string to print) and a pointer 
	to an integer array flags representing various formatting flags.

    int i = 0;
	A variable i is initialized to zero. This variable is used to 
	track the number of characters written for space padding.

    while (i < flags[7]) i += write(1, " ", 1);
	This loop writes space characters to the standard output until 
	the number of characters written (i) reaches the value stored 
	in flags[7]. The value of flags[7] seems to represent the 
	field width for the string.

    ft_putstr_fd(s, 1);
	The function ft_putstr_fd is assumed to print the string s 
	to the standard output (file descriptor 1). This means that 
	the string will be right-justified on the output.

    free(s);
	The s string was likely dynamically allocated, so it 
	is freed to avoid memory leaks.

    return (i);
	The function returns the total number of characters written, 
	which is the number of space characters written for padding.

	The str_right function appears to handle right-justified 
	printing of a string with optional space padding based on 
	the value stored in the flags array. The exact behavior and 
	formatting may depend on the specific value in the flags[7] 
	field width and the context in which this function is used 
	within the larger program.

	Please note that the correctness and completeness of the 
	str_right function depend on the proper initialization and 
	allocation of the s string and the correct implementation of 
	the ft_putstr_fd function (which is not provided in 
	the code snippet).

	
	************************* print_str() *********************
	The print_str function appears to handle the printing 
	of a string s based on the provided flags.

	int print_str(char *s, int *flags)
	The function takes two arguments: a pointer to a character 
	array s (presumably containing the string to print) and a 
	pointer to an integer array flags representing various 
	formatting flags.

    if (flags[5] && flags[6] < 5 && !s) return 
	(print_str("", flags));
	This conditional check handles a special case. If 
	the flag at index 5 in the flags array is non-zero 
	(indicating a precision was specified), and the flag 
	at index 6 in the flags array is less than 5, and s is 
	a null pointer (NULL), it calls the print_str function 
	recursively with an empty string "". This is done to 
	print an empty string with the specified precision 
	(maximum number of characters to print).

    if (!s) return (print_str("(null)", flags));
	If s is a null pointer (NULL), the function returns the 
	result of printing the string "(null)" with the given 
	flags. This is to handle the case where a null pointer 
	is passed as the string to be printed.

    len = (int)ft_strlen(s);
	The length of the string s is calculated using the 
	ft_strlen function (not provided in the code snippet).

    if (flags[5] && len > flags[6]) len = flags[6];
	If the flag at index 5 in the flags array is non-zero 
	(indicating a precision was specified), and the length 
	of the string s is greater than the value stored 
	in flags[6] (which represents the precision), then 
	len is set to the value of flags[6]. This ensures 
	that the length of the string s does not exceed the 
	specified precision.

    s = ft_substr(s, 0, len);
	The function ft_substr is assumed to extract a 
	substring from the original string s starting from 
	index 0 and having a length of len. The variable s 
	is then updated to point to this newly extracted substring.

    flags[7] -= len;
	The field width stored in flags[7] is adjusted by 
	subtracting the length of the string s. This prepares 
	for space padding (if required) after the 
	string is printed.

    The function determines whether to perform left-justified 
	or right-justified printing based on the value of flags[3].
        if (flags[3])
		If the flag at index 3 in the flags array is non-zero, 
		left-justified printing is performed. The function 
		returns the sum of len (the length of the string) and 
		the result of str_left(s, flags) 
		(left-justified printing of the string).
        Otherwise, right-justified printing is performed. 
		The function returns the sum of len (the length of the 
		string) and the result of str_right(s, flags) 
		(right-justified printing of the string).

	The print_str function is designed to handle the printing 
	of strings with various formatting options specified through 
	the flags array. The actual behavior and formatting will 
	depend on the values in the flags array and the 
	implementation of the ft_strlen, ft_substr, str_left, 
	and str_right functions, which are not provided in the 
	code snippet.

	
*/

static int	str_left(char *s, int *flags)
{
	int	i;

	i = 0;
	ft_putstr_fd(s, 1);
	free (s);
	while (i < flags[7])
		i += write(1, " ", 1);
	return (i);
}

static int	str_right(char *s, int *flags)
{
	int	i;

	i = 0;
	while (i < flags[7])
		i += write(1, " ", 1);
	ft_putstr_fd(s, 1);
	free (s);
	return (i);
}

int	print_str(char *s, int *flags)
{
	int		len;

	if (flags[5] && flags[6] < 5 && !s)
		return (print_str("", flags));
	if (!s)
		return (print_str("(null)", flags));
	len = (int)ft_strlen(s);
	if (flags[5] && len > flags[6])
		len = flags[6];
	s = ft_substr(s, 0, len);
	flags[7] -= len;
	if (flags[3])
		return (len + str_left(s, flags));
	else
		return (len + str_right(s, flags));
}
