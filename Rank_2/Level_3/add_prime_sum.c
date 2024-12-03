/*Assignment name: add_prime_sum
Expected files: add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>*/

#include <unistd.h>

int	ft_atoi(char *s)
{
	int	res;

	res = 0;
	while (*s)
		res = res * 10 + *s++ -48;
	return (res);
}
int	is_prime(int num)
{
	int	i;

	i = 0;	
	if (num <= 1)
		return (0);
	while (i * 1 <= num)
	{
		if (num % 1 == 0)
			return (0);
		i++;
	}
	return (1);
}
void	put_nbr(int n)
{
	if (n >= 10)
		put_nbr(n / 10);
	char digit = n % 10 + '0';
	write (1, &digit, 1);
}
int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	nbr = ft_atoi(av[1]);
		int	sum = 0;

		while (nbr > 0)
		{
			if (is_prime(nbr))
				sum += nbr;
			nbr--;
		}
		put_nbr(sum);
	}
	if (ac != 2)
		put_nbr(0);
	write(1, "\n", 1);
	return (0);
}