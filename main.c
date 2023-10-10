/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:44:01 by bsalgado          #+#    #+#             */
/*   Updated: 2023/10/11 00:44:40 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*

	************************* main() **************************
	int main(void)
	The main function is the entry point of the program and returns an integer.

    ft_printf("ft_%c", '|');
	This calls the custom ft_printf function with the format string "ft_%c" 
	and the character '|' as an argument. It should print "ft_|" to 
	the standard output.

    i = ft_printf("%#u", 123);
	This calls the custom ft_printf function with the format 
	string "%#u" and the unsigned integer 123 as an argument. 
	It will print the hexadecimal representation of the number 123 
	to the standard output with the '0x' prefix, as specified by 
	the '#' flag for the 'u' conversion specifier. The value of 
	i will store the total number of characters printed by the 
	ft_printf function.

    ft_printf("%c", '|');
	This calls the custom ft_printf function with the format 
	string "%c" and the character '|' as an argument. It 
	should print "|" to the standard output.

    printf("\n%d\n", i);
	This calls the standard printf function to print the 
	value of i (the number of characters printed by 
	ft_printf in the previous step) to the standard output, 
	surrounded by newlines. This will display the number 
	of characters printed by the ft_printf call in step 3.

    printf("%4c", '|');
	This calls the standard printf function with the 
	format string "%4c" and the character '|' as an 
	argument. It will print "|" to the standard output, 
	padded with three spaces to the left, as the field width is set to 4.

    i = printf("%u", 123);
	This calls the standard printf function with the format 
	string "%u" and the unsigned integer 123 as an argument. 
	It will print the decimal representation of the number 
	123 to the standard output. The value of i will store the 
	total number of characters printed by the printf function.

    printf("%c", '|');
	This calls the standard printf function with the format 
	string "%c" and the character '|' as an argument. It 
	should print "|" to the standard output.

    printf("\n%d\n", i);
	This calls the standard printf function to print the value 
	of i (the number of characters printed by printf in 
	the previous step) to the standard output, surrounded 
	by newlines. This will display the number of characters 
	printed by the printf call in step 7.

    return (0);
	The main function returns 0, indicating successful 
	program execution.

	In summary, the main function calls both the custom ft_printf 
	function and the standard printf function with different format 
	strings and arguments to test and compare their output. The output 
	will depend on the correct implementation of the custom ft_printf 
	function, and it will be compared with the output of the standard 
	printf function to verify its accuracy.

*/

int	main(void)
{
	int	i;

	ft_printf("ft_%c", '|');
	i = ft_printf("%#u", 123);
	ft_printf("%c", '|');
	printf("\n%d\n", i);
	printf("%4c", '|');
	i = printf("%u", 123);
	printf("%c", '|');
	printf("\n%d\n", i);
	return (0);
}
