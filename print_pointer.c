/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:49:41 by bsalgado          #+#    #+#             */
/*   Updated: 2023/10/11 00:50:19 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	************************* first_nibble() **************************
	The first_nibble function appears to be a utility function that 
	calculates the position of the first non-zero nibble in a given 
	unsigned long long integer addr.

	A nibble is a four-bit hexadecimal digit (half a byte). The 
	function iterates through the bits of the addr variable, starting 
	from the most significant bit (leftmost) and moving towards the least 
	significant bit (rightmost). It checks each four-bit group (nibble) 
	and counts how many nibbles are zero until it finds the first 
	non-zero nibble.

	int first_nibble(unsigned long long addr)
	The function takes an unsigned long long integer addr as its argument.

    int i = sizeof(addr) * 2 - 1;
	The variable i is initialized to represent the index of the most 
	significant nibble (four-bit group) in the addr integer. sizeof(addr) 
	returns the size (in bytes) of the unsigned long long integer, and 
	sizeof(addr) * 2 represents the total number of nibbles in the integer 
	(since each byte has two nibbles).

    int hex = 0;
	The variable hex is initialized to zero. It will be used to store 
	the value of the current nibble.

    int count = -1;
	The variable count is initialized to -1. It will be used to keep 
	track of the number of zero nibbles encountered before finding 
	the first non-zero nibble.

    The while loop continues until the first non-zero nibble is 
	found (hex becomes non-zero).
        hex = (addr >> (i * 4)) & 0xf;
		The expression (addr >> (i * 4)) shifts the bits of addr to 
		the right by i * 4 positions, effectively extracting the next 
		nibble from the most significant side. The & 0xf operation 
		masks the result to retain only the four bits representing 
		the value of the nibble.
        i--;
		The index i is decremented to move to the next nibble.

    Inside the loop, the count variable is incremented, keeping track 
	of the number of zero nibbles encountered.

    Once a non-zero nibble is found, the loop terminates, and the 
	function returns the value of count, which represents the position 
	of the first non-zero nibble in the addr integer. The position is 
	counted from the most significant nibble side (leftmost), with 
	the most significant nibble having a position of 0.

	The first_nibble function is a useful utility function when 
	working with memory addresses or other hexadecimal values. It 
	can help determine the leading zero nibbles in a memory 
	address, which can be helpful for various purposes in 
	computer programming.


	************************* print_pointer() **************************
	The print_pointer function appears to handle the printing of a 
	memory address (pointer) based on the provided flags. It converts 
	the memory address to a hexadecimal string and formats it with the 
	appropriate padding and precision options.

	int print_pointer(unsigned long long addr, int *flags)
	The function takes two arguments: an unsigned long long 
	integer addr representing the memory address and a pointer 
	to an integer array flags representing various formatting flags.

    if (!addr) return (print_str("(nil)", flags));
	If the memory address addr is zero (NULL pointer), the 
	function returns the result of printing the string "(nil)" 
	with the given flags. This handles the special case where a 
	NULL pointer is passed as the memory address to be printed.

    int size = sizeof(addr) * 2 - first_nibble(addr) + 2;
	The variable size is calculated to determine the size of 
	the hexadecimal string needed to represent the memory address. 
	It is based on the size of the addr variable (number of bytes) 
	multiplied by 2 (to account for two nibbles per byte), minus 
	the position of the first non-zero nibble (calculated using 
	the first_nibble function), plus 2 (to account for the "0x" 
	prefix in the final string).

    char *hex = malloc(size + 1);
	A character pointer hex is declared, and memory is 
	dynamically allocated to store the hexadecimal string 
	representation of the memory address. The size + 1 
	accounts for the null terminator.

    if (!hex) return (0);
	If the memory allocation fails (if hex is NULL), the 
	function returns 0, indicating an error.

    hex[size] = '\0';
	The null terminator is added at the end of the hex string 
	to properly terminate it.

    The function then constructs the hexadecimal string representation 
	of the memory address by iterating through the memory address and 
	converting each nibble to its hexadecimal representation. 
	The HEXBASE is assumed to be a predefined array of 
	characters containing the hexadecimal digits (0-9 and A-F).

    ft_memcpy(hex, "0x", 2);
	The "0x" prefix is added at the beginning of the 
	hex string to represent a memory address in the standard format.

    The function then prints the hex string using the 
	print_str function, which was described in a previous code snippet.

    free(hex);
	The dynamically allocated memory for the hex string is 
	freed to avoid memory leaks.

    The function returns the result of the print_str function, 
	which represents the total number of characters written for 
	the memory address representation.

	The print_pointer function is designed to handle the printing 
	of memory addresses (pointers) with various formatting options 
	specified through the flags array. The actual behavior and 
	formatting will depend on the values in the flags array and 
	the implementation of the first_nibble, ft_memcpy, and 
	print_str functions, which are not provided in the code snippet.

*/

static int	first_nibble(unsigned long long addr)
{
	int	i;
	int	hex;
	int	count;

	count = -1;
	i = sizeof(addr) * 2 - 1;
	hex = 0;
	while (!hex)
	{
		hex = (addr >> (i * 4)) & 0xf;
		i--;
		count++;
	}
	return (count);
}

int	print_pointer(unsigned long long addr, int *flags)
{
	int		nibble;
	int		size;
	int		i;
	char	*hex;

	if (!addr)
		return (print_str("(nil)", flags));
	size = sizeof(addr) * 2 - first_nibble(addr) + 2;
	hex = malloc(size + 1);
	if (!hex)
		return (0);
	hex[size] = '\0';
	i = size - 2;
	while (i--)
	{
		nibble = (addr >> (i * 4)) & 0xf;
		hex[size - 1 - i] = HEXBASE[nibble];
	}
	ft_memcpy(hex, "0x", 2);
	i = print_str(hex, flags);
	free (hex);
	return (i);
}
