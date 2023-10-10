/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:44:53 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:36:34 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The function ft_strncmp compares up to n characters of the 
	null-terminated strings s1 and s2, and returns an integer 
	that indicates the result of the comparison. 
	It takes three arguments:

    	s1: A pointer to the first string to compare.
    	s2: A pointer to the second string to compare.
    	n: The maximum number of characters to compare.

	The function returns an integer that indicates the result 
	of the comparison. The possible return values are:

    	0:   The first n characters of s1 and s2 are equal.
    	< 0: The first character that differs between 
		     s1 and s2 has a lower value in s1 than in s2, 
			 or all n characters of s1 and s2 are equal 
			 but the length of s1 is less than the length of s2.
    	> 0: The first character that differs between 
		     s1 and s2 has a greater value in s1 than in s2, 
			 or all n characters of s1 and s2 are equal but 
			 the length of s1 is greater than the length of s2.
	
	1 - It first checks if n is zero. If it is, it means there 
	are no characters to compare, so it returns 0.

    2 - It initializes a variable i to keep track of the current 
	index in the strings.

    3 - It enters a loop that compares characters from s1 and s2 
	as long as the characters are not null terminators ('\0') and 
	the index i is less than n - 1. The condition 
	s1[i] != '\0' && s2[i] != '\0' ensures that the loop exits 
	if either of the strings reaches its end or if n - 1 
	characters have been compared.

    4 - Inside the loop, it checks if the characters at the current 
	index i are different. If they are, it returns the difference 
	between the ASCII values of the characters 
	(unsigned char)s1[i] - (unsigned char)s2[i]. 
	This comparison is case-sensitive.

    5 - If the characters are equal, it increments i to move to 
	the next character and continues the loop.

    6 - After the loop, if all characters have been compared 
	without finding any differences or if n - 1 characters have 
	been compared, it compares the final characters at index i. 
	It returns the difference between these characters.

	By returning the difference between the characters, the function 
	provides a negative value if s1 is less than s2, a 
	positive value if s1 is greater than s2, and 0 if the two 
	strings are equal up to n characters.

	It's important to note that this implementation uses 
	unsigned characters (unsigned char) to handle all 
	possible ASCII characters correctly, including those 
	with negative values.

*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
int main(void) 
{
    char str1[] = "Bruno";
    char str2[] = "Bruno Fernandes";
    int result = ft_strncmp(str1, str2, 5);
    if (result == 0) 
	{
        printf("The first 5 characters of the strings are equal\n");
    } 
	else if (result < 0) 
	{
        printf("The first 5 ch of str1 are less than the ch of str2\n");
    } 
	else 
	{
        printf("The first 5 ch of str1 are greater than the ch of str2\n");
    }
    return 0;
}
*/