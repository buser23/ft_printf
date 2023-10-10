/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:00:09 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:49:55 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The  bzero()  function  erases  the  data  in the n bytes of the memory
  	starting at the location pointed to by s, by writing zeros (bytes
	containing '\0') to that area.

	The function sets the first n bytes of the memory block pointed to 
	by s to the value 0 (i.e., the null byte).

	By convention, the ft_bzero function does not return a value; its 
	purpose is solely to modify the contents of the memory block pointed to by s. 
	The function is typically used to clear sensitive information 
	(such as passwords) from memory after they are no longer needed.

	In summary, the ft_bzero function is a convenient way to set a 
	block of memory to all zeros. It takes a pointer to the memory 
	block and the size of the block as arguments and modifies the 
	contents of the block to all zeros.

	1 - The function ft_bzero takes two arguments: a pointer s to 
	the memory block and a size_t n indicating the number of 
	bytes to set to zero.

  	2 - It calls the ft_memset function, passing s as the 
	pointer to the memory block, '\0' as the value to set 
	(which represents zero in ASCII), and n as the size 
	indicating the number of bytes to set.

  	3 - The ft_memset function then sets n bytes starting 
	from the address pointed to by s to the value '\0', 
	effectively setting the memory block to zero.

	4 - By utilizing the ft_memset function, the ft_bzero 
	function sets a block of memory to zero by setting 
	each byte to the value '\0'.

*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

/*
int	main(void)
{
	char str[] = "Bruno";

	printf("\n\t>>> USING ft_bzero() <<<\n\n");
	printf("String Before: %s\n", str);
	ft_bzero(str, 5);
    printf("String After: %s\n", str);
	return (0);
}
*/