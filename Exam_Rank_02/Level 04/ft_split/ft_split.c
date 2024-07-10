#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str)
{
	int	i;
	int	j;
	int	k;
	char	**array;

	i = 0;
	j = 0;
	array = malloc(sizeof(*array) * 100);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i])
	{
		if (str[i] != 32 && str[i] != 9)
		{
			k = 0;
			array[j] = malloc(sizeof(char) * 100);
			while (str[i] && (str[i] != 32 && str[i] != 9))
			{
				array[j][k] = str[i];
				k++;
				i++;
			}
			array[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	array[j] = NULL;
	return (array);
}

int	main(void)
{
	char	**words;
	char	str[] = "This is a test string for ft_split";
	int	i;

	i = 0;
	words = ft_split(str);
	while (words[i])
	{
		printf("%s\n", words[i]);
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}
