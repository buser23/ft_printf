/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:57:50 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 15:22:48 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	This function takes two arguments:

    	- s - a pointer to the string that you want to write to 
		the file descriptor.
    	- fd - an integer representing the file descriptor to 
		which you want to write the string.

    1 - The function takes two parameters: s, which is a pointer 
	to the string to be written, and fd, which is the file 
	descriptor specifying where to write the string.

    2 - It calculates the length of the string s using the 
	ft_strlen function and assigns the result to the variable len.

    3 - It calls the write function to write the entire 
	string s to the specified file descriptor fd. The write 
	function takes the file descriptor fd, the pointer s, 
	and the length len as arguments.

    4 - After writing the string, it calls the write 
	function again to write a newline character '\n' 
	to the file descriptor fd. This adds a newline at 
	the end of the written string.

	In summary, the ft_putendl_fd function writes a string to a 
	specified file descriptor, followed by a newline character. 
	It uses the write function to write the string and the 
	newline character separately. The length of the string is 
	calculated using ft_strlen.
	
*/

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
	write(fd, "\n", 1);
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
	ft_putendl_fd("Hello, world!", fd);
	close(fd);
	return (0);
}
*/