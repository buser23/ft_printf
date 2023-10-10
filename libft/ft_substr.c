/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:13:42 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:40:27 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*

	The purpose of this function is to extract a substring from the given string s, 
	starting from the index specified by start and continuing for a maximum 
	length of len characters. 

	1 - It first checks if the pointer s is NULL. If s is NULL, it returns 
	NULL to indicate an invalid input.

    2 - It calculates the length of the original string s using the 
	ft_strlen function.

    3 - It checks if the starting index start is beyond the length of 
	the string. If start is greater than the length of the string, 
	it means the substring is empty. In this case, it allocates 
	memory for a single character and assigns the null terminator '\0' 
	to create an empty string. Then it returns the pointer to the 
	empty string.

    4 - If the starting index is within the length of the string, 
	it proceeds to the next step.

    5 - It checks if the specified length len exceeds the remaining 
	length of the string from the starting index. If len is greater 
	than the remaining length, it adjusts len to be the remaining 
	length of the string.

    6 - It allocates memory for the substring based on the adjusted 
	length len plus one additional byte for the null terminator.

    7 - If the memory allocation is successful, it proceeds to 
	the next step.

    8 - It uses the ft_memcpy function to copy the desired substring 
	from the original string s starting at the specified index start 
	and with the adjusted length len. The copied substring is stored 
	in the allocated memory block substr.

    9 - Finally, it assigns the null terminator '\0' to the last 
	character of the substring to ensure proper string termination.

    10 - The function returns the pointer substr, which points to 
	the allocated memory block containing the extracted substring.

	The ft_substr function extracts a substring from the given 
	string starting at the specified index and with the specified 
	length. It handles boundary checks, memory allocation, 
	and copying of the substring.

*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	str_size;

	if (!s)
		return (NULL);
	str_size = ft_strlen(s);
	if (str_size < start)
	{
		substr = (char *)malloc(sizeof(char) * 1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (len > str_size - start)
		len = str_size - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	ft_memcpy(substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}

/*
int	main(void)
{
	char str[] = "Hello, world!";
    char *substr;

    substr = ft_substr(str, 0, 5);
    printf("%s\n", substr); // Output: Hello
    free(substr);
	
}
*/
