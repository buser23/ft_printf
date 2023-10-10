/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:38:59 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:33:00 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The ft_strlcat() function is used to concatenate a null-terminated 
	string from a source string to a destination string, while ensuring 
	that the destination string does not overflow.

	1 - The function header defines the function, which takes in 
	three arguments: a pointer to the destination string, a 
	pointer to the source string, and the size of the destination 
	buffer. The function returns a size_t, which represents the 
	length of the resulting string that would have been created 
	without the size restrictions.

	2 - Declare four variables that will be used throughout the function: 
	i, a counter variable; dest_len and src_len, which will hold the lengths 
	of the dest and src strings, respectively; and sum, which will hold 
	the sum of dest_len and src_len.

	3 - Initialize the counter i and the sum sum to zero.

	4 - Use the ft_strlen function to calculate the lengths of 
	the dest and src strings and assign them to the variables 
	dest_len and src_len.

	5 - The if statement checks if there is enough space in the 
	destination buffer to append the entire src string. 
	If there is, sum is set to the sum of dest_len and src_len. 
	If there is not enough space, the function returns the sum of 
	src_len and size, as this is the maximum number of characters 
	that can be copied into dest.

	6 - The while loop appends the src string to the end of the 
	dest string. It copies characters from src to dest until it 
	reaches the end of src, or until the destination buffer is full. 
	Note that dest_len + 1 is used to ensure that there is enough 
	space in the buffer for the null terminator.

	7 - Adds a null terminating character to the end of the 
	resulting string.

	8 - Finally, the function returns the value of sum, which 
	represents the total length of the string that would have 
	been created if there were no size restrictions.

*/

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;
	size_t	sum;

	i = 0;
	sum = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size > dest_len)
		sum = dest_len + src_len;
	else
		return (src_len + size);
	while (src[i] != '\0' && (dest_len + 1) < size)
		dest[dest_len++] = src[i++];
	dest[dest_len] = '\0';
	return (sum);
}

/*
int	main(void)
{
    char dest[20] = "Bruno ";
    char src[] = "Fernandes";
    size_t total_length;

    total_length = ft_strlcat(dest, src, 16);

    printf("Concatenated string: %s\n", dest);
    printf("Total length: %lu\n", total_length);

    return 0;
}
*/
