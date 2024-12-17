/*Assignment name: ft_atoi_base
Expected files: ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);*/

#include <stdlib.h>

int	is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}
int	is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}
int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
int	is_space(char c)
{
	return (c >= ' ' && (c >= '\t' && c <= '\r'));
}
int	ft_atoi_base(const char *str, int str_base)
{
	int	i = 0;
	int	result = 0;
	int	sign = 1;

	if (str_base < 2 || str_base > 16)
		return (0);
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		result *= str_base;
		if (is_digit(str[i]))
			result += str[i] - '0';
		else if (is_upper(str[i]))
			result += str[i] - 'A' + 10;
		else if (is_lower(str[i]))
			result += str[i] - 'a' + 10;
		else
			break;
		i++;
	}
	return (result * sign);
}
