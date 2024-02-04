#include <unistd.h>
#include <stdio.h>

int word_count(char *str)
{
    int word_count;
    int inside_word;
    int i;

    i = 0;
    word_count = 0;
    inside_word = 0;
    while (str[i])
    {
        if (str[i] == 32 || str[i] == 9 || str[i] == 10)
            inside_word = 0;
        else if (!inside_word)
        {
            inside_word = 1;
            word_count++;
        }
        i++;
    }
    return (word_count);
}

char    *make_word(char *start, int len)
{
    int i;
    char    *word;

    i = 0;
    word = (char *)malloc(sizeof(char) * (len + 1));
    while (i < len)
    {
        word[i] = start[i];
        i++;
    }
    word[i] = '\0';
    return (word); 
}

char **ft_split(char *str)
{
    int wc;
    int len;
    int i;
    int j;
    char **words;
    char *start;

    wc = word_count(str);
    len = 0;
    i = 0;
    j = 0;
    words = (char **)malloc(sizeof (char *) * (wc + 1));
    start = str;
    while (i < wc)
    {
        while (str[j] == 32 || str[j] == 9 || str[j] == 10)
            j++;
        start = &str[j];
        while (str[j] && str[j] != 32 && str[j] != 9 && str[j] != 10)
            j++;
        len = &str[j] - start;
        words[i] = make_word(start, len);
        i++;
    }
    words[wc] = NULL;
    return (words);
}

int main(void)
{
    char **words;
    char    str[] = "This is a test string for ft_split";
    int i;

    i = 0;
    words = ft_split(str);
    while (words[i])
    {
        printf("%s\n", words[i]);
        free(words[i]); // free memory immediately after printing
        i++;
    }
    free(words); // free the outer array
    return (0);
}

