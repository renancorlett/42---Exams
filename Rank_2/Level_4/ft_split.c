/*Assignment name: ft_split
Expected files: ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);*/

#include <stdlib.h>
#include <stdio.h>

void	ft_strncpy(char *dest, char *src, int n)
{
	int	i = 0;

	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	**ft_split(char *str)
{
	int	i = 0;
	int	j = 0;
	int	k = 0;
	int	len = 0;
	char	**out;

	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			len++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	out = (char **)malloc((len + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		if (i > j)
		{
			out[k] = (char *)malloc((i - j) * sizeof(char) + 1));
			if (!out[k])
			{
				while (k > 0)
					free(out[--k]);
				free(out);
				return (NULL);
			}
			ft_strncpy(out[k++], &str[j], i - j);
		}
	}
	out[k] = NULL;
	return (out);
}

/*int	main(void)
{
	char	**words;
	char	str[] = "   Olá   mundo!  Bem-vindo ao   ft_split.  ";
	int		i;

	words = ft_split(str);
	if (!words)
	{
		printf("Erro: Falha ao dividir a string.\n");
		return (1);
	}
	printf("Palavras encontradas:\n");
	for (i = 0; words[i]; i++)
	{
		printf("Palavra %d: '%s'\n", i + 1, words[i]);
		free(words[i]);
	}
	free(words);

	return (0);
}*/
