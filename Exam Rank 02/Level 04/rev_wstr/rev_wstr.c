#include <unistd.h>
#include <stdio.h>

void	rev_wstr(char *str)
{
	int	i;
	int	word_start;
	int	word_end;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i >= 0)
	{
		while (str[i] && (str[i] == 32 || str[i] == 9))
			i--;
		word_end = i;
		while (str[i] && (str[i] != 32 && str[i] != 9))
			i--;
		word_start = i + 1;
		while (word_start <= word_end)
		{
			write(1, &str[word_start], 1);
			word_start++;
		}
		if (i > 0)
			write(1, " ", 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		rev_wstr(argv[1]);
		write(1, "\n", 1);
		return (0);
	}
}
