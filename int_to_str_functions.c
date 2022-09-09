#include <stdlib.h>

/**
 * _abs - gets the absolute value of an integer
 * @i: integer
 *
 * Return: absolute value
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_numbase_len - gets length of buffer needed for an unsigned int
 * @num: number to get length needed for
 * @base: base of number represntation
 *
 * Return: integer containing length
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbers_buff - fills buffere with correct numbers up to base 36
 * @num: number to convert to string
 * @base: base used in onversion up to base 36
 * @buff: buffer to fill with result of conversion
 * @buff_size: size of buffere in bytes
 *
 * Return: void
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9)
			buff[i] = rem + 87;
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}

/**
 * get_int - returns a pointer to a string representation of @num
 * @num: number to be converted
 *
 * Return: pointer to char
 *         NULL if fails
 */
char *get_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(num);
	length = get_numbase_len(temp, 10);

	if (num < 0 || num_l < 0)
		length++;
	ret = malloc(length + 1);
	if (!ret)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';
	return (ret);
}
