/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:00:27 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:29:43 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The  ft_memset() function fills the first n bytes of the 
	memory area pointed to by s with the constant byte c.
	We use this function before a operation, is like a memory "reset".

	It is commonly used to initialize a memory block to a 
	specific value, such as initializing an array to zero or filling a 
	buffer with a specific byte value.

	1 - The function ft_memset takes three arguments: a pointer s to 
	the memory block, an integer c representing the value to be set, 
	and a size_t n indicating the number of bytes to be set.

  	2 - It declares a local variable p as an unsigned char pointer 
	and initializes it with the value of s. This pointer p will be 
	used to iterate over the memory block.

  	3 - The code enters a while loop that continues until n is greater 
	than 0. This loop will set the value of c in each byte of the 
	memory block.

  	4 - Inside the loop, the value of c is cast to an unsigned char 
	and assigned to the memory location pointed to by p. 
	The pointer p is then incremented to point to the next byte.

  	5 - After the loop completes, the original pointer s is returned.
		
*/

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n-- > 0)
		*p++ = (unsigned char) c;
	return (s);
}

/*
int	main(void)
{
	char str[] = "Bruno";

	printf("\n\t>>> USING ft_memset() <<<\n\n");
	printf("String Before: %s\n", str);
	ft_memset(str, '@', 5);
    printf("String After: %s\n", str);
	return (0);
}
*/