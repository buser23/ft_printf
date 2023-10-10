/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:41:09 by bsalgado          #+#    #+#             */
/*   Updated: 2023/10/11 00:41:50 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	****************************** flags_nbr() ************************
	The function is designed to process a numeric parameter (param) and 
	update elements in an integer array (flags). It also 
	returns an integer value.

	n = ft_atoi(param);
	This line uses a custom function ft_atoi to convert the string param 
	into an integer and store it in the variable n.

    i = ft_intlen(n, 10) - 1;
	This line calculates the number of digits in the integer n using the 
	ft_intlen function (not provided in the code snippet). The second 
	argument 10 indicates that the function should count the number of base-10 
	digits in the number n. The result is stored in the variable i, and since 
	the indexing of digits starts from 0, the function subtracts 1 from i.

    if (flags[5]) flags[6] = n; else flags[7] = n;: This conditional 
	statement checks the value of flags[5]. If flags[5] is non-zero 
	(evaluates to true), it updates flags[6] with the value of n. Otherwise, 
	it updates flags[7] with the value of n. The function does not provide 
	information on the purpose of flags[5], flags[6], or flags[7].

    return (i);: Finally, the function returns the value of i, which 
	represents the number of digits in the integer n.

	
	****************************** check_flags() ************************
	This function seems to be designed to process a string (param) and 
	identify specific flags used in formatting strings, updating the 
	corresponding elements in the flags array accordingly. The purpose of 
	these flags and their usage may be clearer with additional context 
	and the implementation of the ft_strchr and flags_nbr functions.

	cflags = " +#-0.";
	This line initializes a character array cflags with some specific 
	characters (' ', '+', '#', '-', '0', '.'). These characters 
	represent various flags used in formatting strings.

    j = 8; while (j) flags[--j] = 0;
	This loop sets all elements of the flags integer array to zero. 
	The array has eight elements, indexed from 0 to 7.

    while (param[*k] && !ft_strchr("%csdixXup", param[*k]))
	This loop iterates over the characters in the param string until 
	it encounters a character that is present in the string 
	"%csdixXup" or reaches the end of the param string. It uses 
	the ft_strchr function (not provided in the code snippet) to 
	check for the presence of a specific character in the string.

    Inside the loop:
    a. j = 0; while (cflags[j]): Two nested loops are used to 
	iterate over the characters in cflags and param respectively.
    b. if (param[*k] == cflags[j]) flags[j] = 1;: If the character 
	in param at the current index (*k) matches the character in 
	cflags at index j, then the corresponding element in the flags 
	array is set to 1. This indicates that the flag is present 
	in the param string.

    if (param[*k] >= '1' && param[*k] <= '9') *k += 
	flags_nbr(&param[*k], flags);
	If the current character in param is a digit between '1' and '9', 
	it calls the flags_nbr function to process the numeric 
	parameter and update elements in the flags array. The value 
	of *k is then incremented based on the result returned by 
	flags_nbr. The purpose of this logic is not entirely clear 
	without the definition of flags_nbr and more context.

    (*k)++;
	After processing the current character in param, the *k 
	index is incremented to move to the next character.

    return (flags);
	Finally, the function returns a pointer to the flags 
	array, which would allow the calling code to access 
	the updated flag information.


	*************************** check_conversion() *****************
	This function, which seems to be a part of a larger program 
	that deals with formatting and printing various data types. 
	The function takes a single character param, a variable 
	argument list ap (of type va_list), and a pointer to an integer 
	array flags.

	if (!(param)) return (0);
	If param is a null terminator (end of the string), the 
	function returns 0. This is a check to handle the end 
	of the format string.

    if (param == '%') return (write(1, "%", 1));
	If param is a percent sign '%', it returns the result 
	of writing a single '%' character to the standard output 
	(file descriptor 1). This means that when the format specifier 
	encountered is '%%', it prints a single '%' character.

    if (param == 'c') return (print_chr(va_arg(ap, int), flags));
	If param is 'c', it extracts the next argument from the variable 
	argument list ap as an integer (va_arg(ap, int)), and then calls 
	the print_chr function passing the integer and the flags array. 
	This function seems to handle printing a character.

    if (param == 's') return (print_str(va_arg(ap, char *), flags));
	If param is 's', it extracts the next argument from ap as a 
	pointer to a character (va_arg(ap, char *)), and then calls the 
	print_str function passing the pointer and the flags array. 
	This function seems to handle printing a string.

    if (param == 'd' || param == 'i') return 
	(print_nbr(va_arg(ap, int), flags));
	If param is 'd' or 'i', it extracts the next argument from 
	ap as an integer (va_arg(ap, int)), and then calls the 
	print_nbr function passing the integer and the flags array. 
	This function seems to handle printing signed integers.

    if (param == 'x' || param == 'X') return 
	(print_hex(va_arg(ap, unsigned int), flags, param));
	If param is 'x' or 'X', it extracts the next argument from 
	ap as an unsigned integer (va_arg(ap, unsigned int)). 
	It then calls the print_hex function passing the unsigned integer, 
	the flags array, and the character param ('x' or 'X'). 
	This function seems to handle printing hexadecimal numbers.

    if (param == 'u') 
	return (print_unsigned(va_arg(ap, unsigned int), flags));
	If param is 'u', it extracts the next argument from ap 
	as an unsigned integer (va_arg(ap, unsigned int)), and 
	then calls the print_unsigned function passing the unsigned 
	integer and the flags array. This function seems to handle 
	printing unsigned integers.

    if (param == 'p') return 
	(print_pointer(va_arg(ap, unsigned long long), flags));
	If param is 'p', it extracts the next argument from ap 
	as an unsigned long long integer (va_arg(ap, unsigned long long)), 
	and then calls the print_pointer function passing the 
	unsigned long long integer and the flags array. This 
	function seems to handle printing pointers.

    If none of the above conditions are met 
	(unrecognized conversion specifier), the function returns 0.

	The check_conversion function is responsible for routing 
	the format specifier character to the appropriate print function 
	based on the data type specified by that character. The 
	actual printing of each data type and how the flags array 
	affects the formatting seems to be implemented in separate 
	functions (print_chr, print_str, print_nbr, print_hex, 
	print_unsigned, and print_pointer), which are called within this function.

	Please note that the actual behavior and correctness of this 
	function depend on the implementations of the functions 
	it calls (print_chr, print_str, etc.) and how the flags array 
	is used within those functions. Without access to the complete 
	code and definitions of these functions, it's challenging to 
	provide a more detailed analysis.

	*************************** ft_printf() *****************
	The ft_printf function is an implementation of the printf 
	function in C. It is responsible for formatting and printing 
	output to the standard output based on the given format string 
	param. The function uses variable-length argument lists (va_list) 
	to handle a variable number of arguments.

	int ft_printf(const char *param, ...)
	The function definition indicates that ft_printf takes 
	a format string param and a variable number of arguments.

    int count, k, flags[8]; va_list ap;
	The function declares several variables: count to keep track 
	of the number of characters printed, k as an index for iterating 
	through the param string, flags as an array to hold flags for 
	formatting, and ap as a variable of type va_list to handle 
	the variable arguments.

    va_start(ap, param);
	The va_start macro initializes the ap variable to handle the 
	variable arguments based on the param format string.

    count = 0; k = 0;
	Initialize the count and k variables to zero.

    while (param[k]) { ... }
	This loop iterates through the param format string until it 
	reaches the null terminator (\0), indicating the end of the string.

    Inside the loop:
    a. if (param[k] == '%' && param[k + 1]) { ... }
	When a '%' character is encountered and the next character 
	exists (param[k + 1]), it means that a format specifier is 
	present, so the code inside the if block is executed.

    b. k++;
	Increment k to move past the '%' character.

    c. check_flags(param, flags, &k);
	The check_flags function is called to handle flags in the format 
	specifier. It updates the flags array based on the characters 
	in the format specifier string. The &k is passed as an argument 
	to check_flags to update the index k after processing 
	numeric parameters.

    d. count += check_conversion(param[k], ap, flags);
	The check_conversion function is called to handle the conversion 
	specifier, which starts after the '%'. It processes the conversion 
	specifier, extracts the appropriate argument from the ap variable 
	argument list, and prints the formatted output. The count variable is 
	updated with the number of characters printed during this conversion.

    If the current character is not '%', the else block is executed:
    else count += write(1, &param[k], 1);
	It simply writes the current character to the standard output and 
	increments the count variable by 1.

    k++;
	Increment k to move to the next character in the format string.

    va_end(ap);
	The va_end macro is used to clean up the variable 
	argument list after processing.

    return count;
	Finally, the function returns the total number of characters 
	printed during the formatting process.

	This implementation of ft_printf is responsible for handling 
	format specifiers, flags, and variable arguments, and it 
	delegates the actual printing and formatting tasks to other 
	functions (check_flags and check_conversion), which have been 
	explained in a previous response. The ft_printf function can 
	handle various format specifiers such as %c, 
	%s, %d, %i, %x, %X, %u, %p, and the special case %%. 
	The actual output behavior will depend on the format 
	string, the arguments passed, and the implementation 
	of the respective conversion functions.

*/

static int	flags_nbr(const char *param, int *flags)
{
	int	i;
	int	n;

	n = ft_atoi(param);
	i = ft_intlen(n, 10) - 1;
	if (flags[5])
		flags[6] = n;
	else
		flags[7] = n;
	return (i);
}

static int	*check_flags(const char *param, int *flags, int *k)
{
	int		j;
	char	*cflags;

	cflags = " +#-0.";
	j = 8;
	while (j)
		flags[--j] = 0;
	while (param[*k] && !ft_strchr("%csdixXup", param[*k]))
	{
		j = 0;
		while (cflags[j])
		{
			if (param[*k] == cflags[j])
				flags[j] = 1;
			j++;
		}
		if (param[*k] >= '1' && param[*k] <= '9')
			*k += flags_nbr(&param[*k], flags);
		(*k)++;
	}
	return (flags);
}

static int	check_conversion(const char param, va_list ap, int *flags)
{
	if (!(param))
		return (0);
	if (param == '%')
		return (write(1, "%", 1));
	if (param == 'c')
		return (print_chr(va_arg(ap, int), flags));
	if (param == 's')
		return (print_str(va_arg(ap, char *), flags));
	if (param == 'd' || param == 'i')
		return (print_nbr(va_arg(ap, int), flags));
	if (param == 'x' || param == 'X')
		return (print_hex(va_arg(ap, unsigned int), flags, param));
	if (param == 'u')
		return (print_unsigned(va_arg(ap, unsigned int), flags));
	if (param == 'p')
		return (print_pointer(va_arg(ap, unsigned long long), flags));
	return (0);
}

int	ft_printf(const char *param, ...)
{
	int		count;
	int		k;
	int		flags[8];
	va_list	ap;

	va_start(ap, param);
	count = 0;
	k = 0;
	while (param[k])
	{
		if (param[k] == '%' && param[k + 1])
		{
			k++;
			check_flags(param, flags, &k);
			count += check_conversion(param[k], ap, flags);
		}
		else
			count += write(1, &param[k], 1);
		k++;
	}
	va_end(ap);
	return (count);
}
