/*
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n);
*/

int	is_power_of_2(unsigned int n)
{
	return (n && !(n & (n - 1)));
}
/*int	is_power_of_2(unsigned int n)
{
	unsigned int i;

	i = 2;
	if (n == 1)
		return (1);
	while (i <= n)
	{
		if (i == n)
			return (1);
		i *= 2;
	}
	return (0);
}*/
