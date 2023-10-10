/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:56:44 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:37:13 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The ft_memchr function searches the first n bytes of the memory block 
	pointed to by s for the first occurrence of the character c. 
	It takes three arguments:

    	s: A pointer to the memory block to search.
    	c: The character to search for.
    	n: The maximum number of bytes to search.

	The function returns a pointer to the byte that matches c, 
	or NULL if c is not found in the first n bytes of the memory block.

	1 - It initializes a pointer str to the memory block s. This pointer 
	is declared as const unsigned char * to ensure that comparisons are 
	done correctly, treating each byte as an unsigned character.

    2 - It enters a loop that iterates as long as n is greater than 0. 
	This loop is responsible for searching through the memory block.

    3 - Inside the loop, it checks if the byte pointed to by str is 
	equal to the character c. It does this by comparing *str 
	with (unsigned char)c. If a match is found, it means the
	character c is present in the memory block, so it 
	returns a pointer to that location.

    4 - If no match is found, it increments the str pointer to 
	move to the next byte and decrements n to keep track of the 
	remaining number of bytes to search.

    5 - The loop continues until either a match is found 
	or n becomes 0.

    6 - If the loop completes without finding a match 
	or if n is initially 0, it means the character c is 
	not present in the memory block, so it returns NULL.

	The returned pointer is cast to (void *) to maintain the 
	same function signature as the standard memchr function, 
	which returns a void * pointer. This allows the caller 
	to easily use the returned pointer in different contexts.

	Overall, the function performs a linear search through the 
	memory block, byte by byte, until it finds the specified 
	character or exhausts the given number of bytes.

*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;

	str = s;
	while (n > 0)
	{
		if (*str == (unsigned char)c)
			return ((void *)str);
		str++;
		n--;
	}
	return (NULL);
}

/*
int main(void) 
{
    char str[] = "Bruno";
    char *result = ft_memchr(str, 'r', 12);
    if (result != NULL) 
	{
        printf("Found 'r' at address %p\n", result);
    } 
	else 
	{
        printf("Did not find 'r'\n");
    }
    return 0;
}
*/