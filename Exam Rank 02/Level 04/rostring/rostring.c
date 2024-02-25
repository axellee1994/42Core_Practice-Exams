#include <unistd.h>
#include <stdio.h>

void	rostring(char *str)
{
	int	i;
	int	word_start;
	int	word_end;

	i = 0;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	word_start = i;
	while (str[i] && (str[i] != 32 && str[i] != 9))
		i++;
	word_end = i;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while(str[i])
	{
		while (str[i] && (str[i] != 32 && str[i] != 9))
		{
			write(1, &str[i], 1);
			i++;
		}
		while (str[i] && (str[i] == 32 || str[i] == 9))
			i++;
		if (str[i - 1] != '\0')
			write(1, " ", 1);
	}
	while (word_start < word_end)
	{
		write(1, &str[word_start], 1);
		word_start++;
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
		rostring(argv[1]);
		write(1, "\n", 1);
		return (0);
	}
}
