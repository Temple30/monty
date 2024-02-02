#include "monty.h"

/**
 * compare_strings - compares two strings.
 * @str1: first string
 * @str2: second string
 * Return: 0 if str1 and str2 are equal, 1 if str1 is greater, -1 if str2 is greater
 */
int compare_strings(char *str1, char *str2)
{
	int index;

	for (index = 0; str1[index] == str2[index] && str1[index]; index++)
		;

	if (str1[index] > str2[index])
		return 1;

	if (str1[index] < str2[index])
		return -1;

	return 0;
}

/**
 * char_in_string - searches if a char is inside a string.
 * @str: string to review
 * @c: char to find
 * Return: 1 if success, 0 if not
 */
int char_in_string(char *str, char c)
{
	int count = 0;

	while (str[count] != '\0')
	{
		if (str[count] == c)
		{
			break;
		}
		count++;
	}

	if (str[count] == c)
		return 1;
	else
		return 0;
}

/**
 * custom_strtok - function that cuts a string into tokens depending on delimiters.
 * @input_str: string to cut into parts
 * @delimiters: delimiters
 * Return: first partition
 */
char *custom_strtok(char *input_str, char *delimiters)
{
	static char *last_token;
	int i = 0, j = 0;

	if (!input_str)
		input_str = last_token;

	while (input_str[i] != '\0')
	{
		if (!char_in_string(delimiters, input_str[i]) && input_str[i + 1] == '\0')
		{
			last_token = input_str + i + 1;
			*last_token = '\0';
			input_str = input_str + j;
			return input_str;
		}
		else if (!char_in_string(delimiters, input_str[i]) && !char_in_string(delimiters, input_str[i + 1]))
			i++;
		else if (!char_in_string(delimiters, input_str[i]) && char_in_string(delimiters, input_str[i + 1]))
		{
			last_token = input_str + i + 1;
			*last_token = '\0';
			last_token++;
			input_str = input_str + j;
			return input_str;
		}
		else if (char_in_string(delimiters, input_str[i]))
		{
			j++;
			i++;
		}
	}
	return NULL;
}
