/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:14:16 by bsalgado          #+#    #+#             */
/*   Updated: 2023/05/22 14:43:08 by bsalgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	ft_split():
		The function ft_split takes a string s and a character c as input 
		and splits the string into an array of words, where words are 
		delimited by the character c.

    	1 - Declare integer variables i and j and initialize them to 0. 
		These variables will be used to keep track of the current 
		positions in the input string and the array of words, respectively.

    	2 - Declare a double pointer words to store the dynamically 
		allocated array of strings.

    	3 - Allocate memory for the words array using malloc. 
		The size of the allocated memory is calculated as 
		(ft_count_words(s, c) + 1) to accommodate the number 
		of words plus a null pointer at the end.

    	4 - Check if the memory allocation was successful or 
		if the input string s is null. If either condition 
		is true, return NULL to indicate an error.

    	5 - Start a loop that continues until the end of the 
		input string is reached (indicated by the null 
		character '\0').

    	6 - Check if the current character in the input string 
		s[i] is not equal to the delimiter character c. If it's 
		not equal, it means we have encountered a word.

    	7 - Assign the result of ft_word_splitter function, 
		passing the address of s[i] and the delimiter 
		character c, to words[j]. This will store the dynamically 
		allocated string for the current word in the array words.

    	8 - Enter a nested loop that continues until either the 
		end of the input string is reached or the delimiter 
		character c is encountered. This loop is used to 
		skip over the characters of the current word.

    	9 - Increment i to move to the next character in the input 
		string.

    	10 - After the nested loop exits, increment j to move 
		to the next position in the array words.

    	11 - If the current character in the input string is the 
		delimiter character c, increment i to move to the next 
		character in the input string.

    	12 - Repeat steps 6-11 until the end of the input string 
		is reached.

    	13 - Assign a null pointer to the last position in the 
		array words to indicate the end of the array.

    	14 - Return the array of strings words.

		In summary, the function ft_split splits a string into an 
		array of words by iterating over the characters, using 
		ft_word_splitter to extract each word and dynamically 
		allocating memory for each word. The resulting array 
		of words is returned as a dynamically allocated array 
		of strings.

	ft_count_words:
		The function ft_count_words takes a string s and a character c as input 
		and counts the number of words in the string, where words are delimited by 
		the character c.

    	1 - Initialize two variables, i and words, to 0. These variables 
		will be used to keep track of the current position in the string 
		and the count of words, respectively.

    	2 - Start a loop that continues until the end of the string is 
		reached (indicated by the null character '\0').

    	3 - Check if the current character in the string, s[i], is 
		not equal to the delimiter character c. If it's not equal, 
		it means we have encountered a word.

    	4 - Increment the words counter by 1 to indicate that a 
		word has been found.

    	5 - Enter a nested loop that continues until either the end of 
		the string is reached or the delimiter character c is encountered. 
		This loop is used to skip over the characters of the current word.

    	6 - Increment i to move to the next character in the string.

    	7 - Once the nested loop exits, either because the end of the 
		string or the delimiter character is encountered, the control 
		returns to the outer loop.

    	8 - If the current character in the string is the delimiter 
		character c, increment i to move to the next character in the string.

    	9 - Repeat steps 3-8 until the end of the string is reached.

    	10 - Return the final count of words.

		In summary, the function counts the number of words in a string by 
		iterating over the characters and incrementing the count whenever a 
		non-delimiter character is encountered. It skips over 
		the characters of each word by using nested loops.

	ft_word_splitter:
		The function ft_word_splitter takes a string s and a character c as 
		input and returns a dynamically allocated string containing the 
		first word from the input string, delimited by the character c. 

    	1 - Declare a character pointer word to store the dynamically 
		allocated string.

    	2 - Declare an integer variable i and initialize it to 0. 
		This variable will be used to keep track of the current 
		position in the string.

    	3 - Start a loop that continues until either the end of 
		the string is reached (indicated by the null character '\0') 
		or the delimiter character c is encountered.

    	4 - Inside the loop, increment i to move to the next character 
		in the string.

    	5 - Allocate memory for the word string using malloc. The 
		size of the allocated memory is calculated as (i + 1) to 
		accommodate the characters of the word plus the null 
		character '\0' at the end.

    	6 - Check if the memory allocation was successful. 
		If not, return NULL to indicate an error.

    	7 - Reset i to 0 to start from the beginning of the string.

    	8 - Start another loop that continues until either the end of 
		the string is reached or the delimiter character c is encountered.

    	9 - Inside the loop, assign the current character from s to 
		the corresponding position in word.

    	10 - Increment both i and the pointer word to move to 
		the next character in s and word, respectively.

    	11 - After the loop exits, assign the null character '\0' 
		to the last position in word to terminate the string.

    	12 - Return the dynamically allocated word string.

		In summary, the function ft_word_splitter extracts the first 
		word from a string by iterating over the characters until 
		either the end of the string or the delimiter character is 
		encountered. It dynamically allocates memory for the word, 
		copies the characters from the input string, and returns 
		the resulting word as a dynamically allocated string.

*/

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}	
		else
			i++;
	}
	return (words);
}

static char	*ft_word_splitter(const char *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	word = (char *) malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**words;

	i = 0;
	j = 0;
	words = (char **) malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!words || !s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words[j] = ft_word_splitter(&s[i], c);
			while (s[i] != '\0' && s[i] != c)
				i++;
			j++;
		}
		else
			i++;
	}
	words[j] = 0;
	return (words);
}

/*
int	main(void)
{
	int i;
	char **words = ft_split("Hello,world!How,are,you?", ',');
    if (words)
    {	
		i = 0;
		while (words[i])
		{
            printf("%s\n", words[i]);
			i++;
        // output:	
        	// Hello
        	// world!How
        	// are
        	// you?
		}
    }
	free(words);
    return 0;
}
*/