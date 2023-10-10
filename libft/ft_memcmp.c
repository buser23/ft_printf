/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:46:54 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:37:36 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	ft_memcmp is a function in C that compares the first n bytes 
	of two memory areas pointed to by s1 and s2. 
	The s1 and s2 arguments are pointers to the memory areas to be compared, 
	and n specifies the number of bytes to compare.

	The function returns an integer value that indicates the relationship 
	between the two memory areas. If the first n bytes of the two memory 
	areas are equal, the function returns 0. If the first differing byte 
	in s1 is greater than the corresponding byte in s2, the function returns 
	a value greater than 0. If the first differing byte in s1 is less 
	than the corresponding byte in s2, the function returns a value less than 0.

	1 - It initializes two pointers, p1 and p2, to the memory blocks 
	s1 and s2, respectively. These pointers are declared as 
	const unsigned char * to ensure that comparisons are done correctly, 
	treating each byte as an unsigned character.

    2 - It enters a loop that iterates n times, decrementing n with 
	each iteration. This loop is responsible for comparing the memory 
	blocks byte by byte.

    3 - Inside the loop, it checks if the bytes pointed to by 
	p1 and p2 are different. If they are, it returns the difference 
	between the values of *p1 and *p2. This comparison uses the 
	ASCII value of the bytes, treating them as unsigned characters.

    4 - If the bytes are equal, it increments both p1 and p2 to 
	move to the next byte.

    5 - The loop continues until n reaches 0, meaning all specified 
	bytes have been compared.

    6 - If the loop completes without finding any differences, 
	it means the memory blocks are equal up to n bytes, 
	so it returns 0.

	By returning the difference between the bytes, the function 
	provides a negative value if s1 is less than s2, a positive 
	value if s1 is greater than s2, and 0 if the two memory 
	blocks are equal up to n bytes.

	Overall, the function performs a byte-by-byte comparison 
	of the memory blocks and returns the result based on the 
	first differing byte encountered or 0 if all bytes are equal.

*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = s1;
	p2 = s2;
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}

/*
int main(void) 
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 5, 4};
    int result;

    result = ft_memcmp(arr1, arr2, 20);

    if (result == 0) 
	{
        printf("Arrays arr1 and arr2 are equal\n");
    } 
	else 
	{
        printf("Arrays arr1 and arr2 are not equal\n");
    }
    return 0;
}
*/
