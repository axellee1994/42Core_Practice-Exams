#include <unistd.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    int i;
    int j;

    i = 0;
    while (s[i])
    {
        j = 0;
        while (reject[j])
        {
            if (s[i] == reject[j])
                return (i);
            j++; 
        }
        i++;
    }
}

int main(void)
{
    const char  t1[] = "Hello Axel";
    const char  t2[] = "BBBBBAddd";
    size_t  result;

    result = ft_strcspn(t1 , t2);
    printf("%zu\n", result);
    return (0);
}