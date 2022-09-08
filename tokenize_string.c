#include <stdlib.h>

/**
 * is_delim - checks if @c is a delimter
 * @c: character
 * @delim: array of delimiter(s)
 *
 * Return: 1 - success
 *         0 - failure
 */
int is_delim(char c, char *delim)
{
	int i = 0;

	while (delim[i])
	{
		if (delim[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * get_word_length - gets the word length of word in @str
 * @str: string
 * @delim: delimter(s)
 *
 * Return: word length
 */
int get_word_length(char *str, char *delim)
{
	int len = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delim))
			pending = 1;
		else if (pending)
		{
			len++;
		}
		if (len > 0 && is_delim(str[i], delim))
			break;
		i++;
	}
	return (len);
}

/**
 * get_word_count - gets the word count of a string
 * @str: string
 * @delim: delimter(s)
 *
 * Return: word count of the string
 */
int get_word_count(char *str, char *delim)
{
		int count = 0, pending = 1, i = 0;

		while (*(str + i))
		{
			if (is_delim(str[i], delim))
				pending = 1;
			else if (pending)
			{
				pending = 0;
				count++;
			}
			i++;
		}
		return (count);
}

/**
 * get_next_word - gets the next word in a string
 * @str: string
 * @delim: delimter(s)
 *
 * Return: pointer to the first char of next word
 */
char *get_next_word(char *str, char *delim)
{
	int pending = 0, i = 0;

	while (*(str + i))
	{
		if (is_delim(str[i], delim))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}

/**
 * strtow - separates a string into words
 * @str: string to separate
 * @delim: delimiter(s) uses to delimit words
 *
 * Return: array of pointers to each word
 */
char **strtow(char *str, char *delim)
{
	char **words = NULL;
	int count, len, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	count = get_word_count(str, delim);
	if (count == 0)
		return (NULL);
	words = malloc((count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < count)
	{
		len = get_word_length(str, delim);
		if (is_delim(*str, delim))
			str = get_next_word(str, delim);
		words[i] = malloc((len + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < len)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0';
		str = get_next_word(str, delim);
		i++;
	}
	words[i] = NULL;
	return (words);
}
