/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:00:35 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:30:35 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The ft_memmove function in C is similar to ft_memcpy, 
	but it guarantees correct behavior even if the source 
	and destination memory areas overlap. 

	In summary, the ft_memmove function is a standard library function in 
	C that is used to move a specified number of bytes from one memory 
	block to another. The function takes a pointer to the source memory 
	block, a pointer to the destination memory block, and the number 
	of bytes to be moved as arguments, and returns a pointer to the 
	destination memory block.

	1 - The function ft_memmove takes three arguments: a pointer dest to 
	the destination memory block, a pointer src to the source memory block, 
	and a size_t n indicating the number of bytes to be copied.

  	2 - It declares two local variables pdest and psrc as char pointers 
	and initializes them with the values of dest and src respectively. 
	These pointers will be used to iterate over the source and 
	destination memory blocks.

  	3 - It checks if both dest and src are NULL. If they are both NULL, 
	it returns NULL. This check is performed to handle cases where 
	the caller passes NULL pointers.

  	4 - The code checks if the destination memory block (pdest) 
	is located before the source memory block (psrc). 
	This check is done to determine the direction of the copy.

  	5 - If pdest is before psrc, it means the memory regions 
	do not overlap. In this case, the code enters a while loop 
	that copies each byte from the source memory block to the 
	destination memory block using the *pdest++ = *psrc++ assignment.

  	6 - If pdest is not before psrc, it means the memory 
	regions overlap. In this case, the code adjusts the pointers 
	to point to the end of the memory blocks. Then it enters a 
	while loop that copies each byte from the end of the 
	source memory block to the end of the destination memory 
	block using the *(--pdest) = *(--psrc) assignment.

  	7 - After the loop completes, the dest pointer is returned.

*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*pdest;
	const char	*psrc;

	if (dest == NULL && src == NULL)
		return (NULL);
	pdest = dest;
	psrc = src;
	if (pdest < psrc)
	{
		while (n--)
			*pdest++ = *psrc++;
	}
	else
	{
		pdest = pdest + n;
		psrc = psrc + n;
		while (n--)
			*(--pdest) = *(--psrc);
	}
	return (dest);
}

/*
int main(void) 
{
    char str[] = "memmove can be very useful......";
	printf("Before ft_memmove(): %s\n", str);
    ft_memmove(str + 20, str + 15, 11);
	printf("After ft_memmove(): %s\n", str);
    return 0;
}
*/