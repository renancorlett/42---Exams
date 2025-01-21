/*
Assignment name: rostring
Expected files: rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/

#include <unistd.h>
#include <stdlib.h>

int    is_space(char c)
{
    return (c == ' ' || c == '\t');
}

void	print_word(char *str, int start, int end)
{
	int	i = start;

	while (i < end)
	{
		write(1, &str[i], 1);
		i++;
	}
}

void    rostring(char *str)
{
    int    i = 0, 
    int    len = 0, 
    int    first_word_start = -1, 
    int    first_word_end = -1;

    while (str[i] && is_space(str[i]))
        i++;
    first_word_start = i;
    while (str[i] && !is_space(str[i]))
        i++;
    first_word_end = i;
    while (str[i])
    {
        while (str[i] && is_space(str[i]))
            i++;
        if (str[i] && !is_space(str[i]))
        {
            if (len++)
                write(1, " ", 1);
            int start = i;
            while (str[i] && !is_space(str[i]))
                i++;
            print_word(str, start, i);
        }
    }
    if (len)
        write(1, " ", 1);
    print_word(str, first_word_start, first_word_end);
}

int main(int ac, char **av)
{
    if (ac > 1)
        rostring(av[1]);
    write(1, "\n", 1);
    return 0;
}
