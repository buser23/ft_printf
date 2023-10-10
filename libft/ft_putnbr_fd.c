/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:16:49 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:56:32 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The ft_putnbr_fd() function takes an integer n and a file descriptor fd as 
	input and writes the integer to the specified file descriptor. 

    1 - The function takes two parameters: n, which is the integer 
	to be written, and fd, which is the file descriptor specifying 
	where to write the integer.

    2 - It declares a long integer variable nb and assigns the 
	value of n to it. This is done to handle the case where 
	n is a negative number, as the function uses recursion.

    3 - It checks if n is negative. If n is negative, 
	it calls the ft_putchar_fd function with the '-' 
	character and the file descriptor fd to write the negative 
	sign to the specified file descriptor. It also assigns 
	the absolute value of n to nb.

    4 - It checks if nb is greater than 9. If nb is greater 
	than 9, it recursively calls the ft_putnbr_fd function 
	with nb / 10 and the file descriptor fd. This 
	effectively writes the remaining digits of the number in 
	reverse order, as the function is called before writing 
	the last digit.

    5 - After the recursive call (or if nb is not greater than 9), 
	it calls the ft_putchar_fd function with (nb % 10 + '0') and 
	the file descriptor fd to write the last digit of the number 
	as a character. This converts the last digit to its 
	corresponding character representation using the ASCII code.

	In summary, the ft_putnbr_fd function writes an integer to a specified 
	file descriptor by recursively writing the digits of the number in 
	reverse order. It handles negative numbers by writing a negative sign 
	before writing the absolute value of the number. The function uses the 
	ft_putchar_fd function to write individual characters to the file descriptor.
	
*/

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}

/*
int	main(void)
{
	int fd;
	
	fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
	{
		write(STDERR_FILENO, "Error: failed to open file\n", 27);
		return (1);
	}
	ft_putnbr_fd(-12345, fd);
	write(fd, "\n", 1);
	close(fd);
	return (0);
}
*/