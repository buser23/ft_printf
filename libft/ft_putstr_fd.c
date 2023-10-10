/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:46:39 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:54:32 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The ft_putstr_fd function takes a string s and a file descriptor fd 
	as arguments, and writes the string to the specified file descriptor.

	The function checks if the input string s is NULL, and returns immediately 
	if it is. Then, it iterates over each character in the string, and writes 
	each character to the file descriptor using the write system call. 
	The write call writes a single byte to the file descriptor, which 
	corresponds to the current character pointed to by s.

    1 - The function takes two parameters: s, which is a pointer to 
	the string to be written, and fd, which is the file descriptor 
	specifying where to write the string.

    2 - It checks if the pointer s is null. If s is null, indicating 
	an empty or uninitialized string, the function returns without 
	performing any operations.

    3 - The function enters a loop that continues until it reaches 
	the null character '\0', which marks the end of the string.

    4 - Inside the loop, it calls the write function, passing 
	the file descriptor fd, the pointer s, and the size of a 
	single character (1 byte) to write the current character 
	to the specified file descriptor.

    5 - After writing the character, it increments the pointer 
	s to move to the next character in the string.

    6 - The loop repeats until the null character '\0' is 
	encountered, indicating the end of the string.

	In summary, the ft_putstr_fd function writes a string to a specified 
	file descriptor by iterating through each character of the 
	string and using the write function to write each character to 
	the file descriptor. It handles the case of a null pointer by 
	checking if s is null before starting the loop.
	
*/

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}

/*
int	main(void)
{
	int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1)
    {
        write(STDERR_FILENO, "Error opening file\n", 19);
        return 1;
    }
    
    char *str = "Hello, world!";
    ft_putstr_fd(str, fd);
    
    close(fd);
    
    return 0;
}
*/