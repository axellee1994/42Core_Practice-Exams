#include <unistd.h>
#include <stdio.h>

char    *ft_strpbrk(const char *s1, const char *s2)
{
    int i;
    int j;

    i = 0;
    while (s1[i])
    {
        j = 0;
        while (s2[j])
        {
            if (s1[i] == s2[j])
                return ((char *)&s1[i]);
            j++;
        }
        i++;
    }
}

int main(void)
{
    const char  t1[] = "Example String";
    const char  t2[] = "Str";
    printf("%s\n", ft_strpbrk(t1,t2));
    return (0);
}