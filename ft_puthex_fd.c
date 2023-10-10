/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 00:43:02 by bsalgado          #+#    #+#             */
/*   Updated: 2023/10/11 00:43:44 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	
	************************* ft_puthex_fd() **************************
	The ft_puthex_fd function is a recursive function that prints an 
	unsigned integer num in hexadecimal format to a file descriptor 
	(fd). The function uses a character c to determine whether to use 
	lowercase ('a'-'f') or uppercase ('A'-'F') letters in the 
	hexadecimal representation.

	void ft_puthex_fd(unsigned int num, const char c, int fd)
	The function takes three arguments: an unsigned integer num to 
	be printed, a character c to determine the case of the hexadecimal 
	letters, and an integer fd representing the file descriptor to 
	which the output is written.

    if (num >= 16)
	The function checks if the value of num is greater than or equal 
	to 16. If true, it means there are more hexadecimal digits to 
	print, and the function should make a recursive call to itself.

    ft_puthex_fd(num / 16, c, fd);
	The function makes a recursive call to itself with the 
	integer division of num by 16. This call is used to print 
	the most significant digits of the hexadecimal representation.

    ft_puthex_fd(num % 16, c, fd);
	The function makes another recursive call to itself with 
	the remainder of the division of num by 16. This call is 
	used to print the least significant digit of the 
	hexadecimal representation.

    else
	If num is less than 16, the base case of the recursion is 
	reached, and the function proceeds to print the 
	hexadecimal digit.

    if (num <= 9)
	If the value of num is less than or equal to 9, it means 
	the digit is between 0 and 9 (inclusive).

    ft_putchar_fd(num + '0', fd);
	The function converts the numerical digit to its 
	corresponding character representation and writes it to the 
	file descriptor fd.

    else
	If num is greater than 9, it means the digit is between 
	10 and 15 (inclusive), representing the hexadecimal 
	letters 'a' to 'f' or 'A' to 'F' based on the character c.

    ft_putchar_fd(num - 33 + c, fd);
	The function performs the necessary calculation to convert 
	the numerical value to the corresponding hexadecimal 
	letter ('a'-'f' or 'A'-'F') based on the character c 
	and writes it to the file descriptor fd.

	The ft_puthex_fd function recursively prints an unsigned integer 
	num in hexadecimal format by dividing the number by 16 repeatedly 
	until all the digits are printed. It correctly handles the 
	conversion of numerical values to their corresponding 
	hexadecimal representations using the character c to 
	determine the case of the hexadecimal letters. The 
	function relies on the base case (num < 16) to terminate 
	the recursion. The exact output will depend on the specific 
	value of num and the character c passed as arguments to the function.


*/

void	ft_puthex_fd(unsigned int num, const char c, int fd)
{
	if (num >= 16)
	{
		ft_puthex_fd(num / 16, c, fd);
		ft_puthex_fd(num % 16, c, fd);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd(num + '0', fd);
		else
			ft_putchar_fd(num - 33 + c, fd);
	}
}
