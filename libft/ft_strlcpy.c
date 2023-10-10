/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:20:58 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:31:56 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	Copy a null-terminated string from a source string to a 
	destination string, while ensuring that the destination 
	string does not overflow.

	1 - The function ft_strlcpy takes three arguments: a pointer dest 
	to the destination string, a pointer src to the source string, 
	and a size_t size indicating the size of the destination buffer.

    2 - It declares a local variable i of type size_t and initializes 
	it with 0. This variable will be used as an index for iterating 
	over the characters of the source string.

    3 - The code checks if the size is greater than 0 to ensure that 
	there is space for at least one character in the destination string.

    4 - If size is greater than 0, the code enters a while loop that 
	copies each character from the source string to the destination 
	string until it encounters a null terminator ('\0') in the 
	source string or reaches size - 1 characters in the 
	destination string. It copies the character at index i from src 
	to dest using the assignment dest[i] = src[i].

    5 - After the loop completes, the code adds a null terminator ('\0') 
	to the last position in the destination string 
	to ensure proper termination.

    6 - Finally, the function returns the length of the source string 
	using the ft_strlen function. This return value represents the 
	length of the source string regardless of whether it was 
	truncated during the copy process.
	
*/

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

/*
int main(void) 
{
    char src[] = "Bruno";
    char dest[6];
    size_t len;

    len = ft_strlcpy(dest, src, sizeof(dest));

    printf("Source string: %s\n", src);
    printf("Destination string: %s\n", dest);
    printf("Length of source string: %zu\n", len);

    return 0;
}
*/