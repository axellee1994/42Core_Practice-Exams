void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0;
	int	temp;

	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i+ 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

int main(void)
{
    int tab[] = {5, 3, 6, 1, 9, 2};
    unsigned int size = sizeof(tab) / sizeof(tab[0]);
    sort_int_tab(tab, size);

    for(unsigned int i = 0; i < size; i++)
    {
        printf("%d ", tab[i]);
    }

    return 0;
}

