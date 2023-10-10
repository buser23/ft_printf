/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:23:48 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:54:19 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The ft_putchar_fd function takes a character c and a file descriptor fd 
	as arguments, and writes the character to the specified file descriptor.

	The function simply calls the write system call with the file descriptor 
	and a pointer to the character to be written. The write call writes a 
	single byte to the file descriptor, which corresponds to the 
	given character.

    1 - The function takes two parameters: c, which represents the 
	character to be written, and fd, which is the file descriptor 
	specifying where to write the character.

    2 - It calls the write function, which is a low-level system 
	call used for writing data to a file descriptor.

    3 - The write function takes three arguments: the file descriptor fd, 
	a pointer to the data to be written (in this case, the address of c), 
	and the number of bytes to write (in this case, 1 byte 
	for a single character).

    4 - By passing the address of c (&c) to the write function, 
	the function writes the character c to the specified 
	file descriptor.

	In summary, the ft_putchar_fd function writes a single character 
	to a specified file descriptor using the write function.
	
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
int	main(void)
{
	int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    char c = 'A';
    ft_putchar_fd(c, fd);

    close(fd);
    return 0;	
}
*/