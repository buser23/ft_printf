/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:11:09 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:38:32 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The ft_strnstr function searches for the first occurrence of the string 
	little in the string big, up to a maximum of len characters. 
	It takes three arguments:

    	big: A pointer to the string to search.
    	little: A pointer to the string to search for.
    	len: The maximum number of characters to search.

	The function returns a pointer to the first occurrence of the string 
	little in the string big, or NULL if little 
	is not found in the first len characters of big.

	1 - It first checks if little is an empty string (i.e., its first 
	character is the null terminator '\0'). If it is, it means the substring 
	is empty, and according to the function's behavior, it should return 
	a pointer to the start of the larger string big.

    2 - It initializes two variables, i and j, to keep track of the 
	indices in the big and little strings, respectively.

    3 - It enters a loop that iterates as long as the character at 
	index i in big is not the null terminator '\0' and i is less than len. 
	This loop is responsible for traversing the big string.

    4 - Inside the outer loop, it initializes j to 0, which represents 
	the starting index of the little string.

    5 - It enters an inner loop that compares characters from big and 
	little as long as the characters are equal, the character at 
	index i + j in big is not the null terminator '\0', and the sum 
	of i and j is less than len. This loop is responsible for comparing 
	the characters of the little string with the corresponding 
	characters in the big string.

    6 - Inside the inner loop, it checks if the character at 
	index j + 1 in little is the null terminator '\0'. If it is, 
	it means we have reached the end of the little string, and 
	we have found a match within the specified length. In that case, 
	it returns a pointer to the start of the match in big 
	by casting &big[i] to (char *).

    7 - If the characters are equal, it increments j to move to 
	the next character in little and continues the inner loop.

    8 - If the characters are not equal or if the loop condition 
	is no longer satisfied, it increments i to move to the next 
	character in big and continues the outer loop.

    9 - The outer loop continues until either a match is found, 
	the null terminator is reached in big, or the maximum 
	length len is reached.

    10 - If the outer loop completes without finding a match 
	or if len is initially 0, it means the substring 
	little is not found within the specified length in big, 
	so it returns NULL.

	The returned pointer points to the first occurrence of 
	the substring little within the larger string big up to 
	the specified maximum length len. If the substring is found, 
	it returns a pointer to the start of the match in big. 
	If the substring is not found within the specified length 
	or if len is initially 0, it returns NULL to indicate 
	that the substring is not present.

	Overall, the function performs a nested loop to compare 
	characters of big and little while considering the maximum 
	length len. It searches for the occurrence of little within 
	big and returns a pointer to the start of the match, 
	or NULL if the substring is not found.

*/

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] != '\0' && i + j < len)
		{
			if (!little[j + 1])
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
int main(void) 
{
    char str[] = "42 school is the best programming school in world";
    char *result = ft_strnstr(str, "best", 30);
    if (result != NULL) 
	{
        printf("Substring found: %s\n", result);
    } 
	else 
	{
        printf("Substring not found\n");
    }
    return 0;
}
*/