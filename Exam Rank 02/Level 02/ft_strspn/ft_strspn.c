#include <unistd.h>
#include <stdio.h>

size_t  ft_strspn(const char *s, const char *accept)
{
    int i;
    int j;

    i = 0;
    while (s[i])
    {
        j = 0;
        while (accept [j])
        {
            if (s[i] == accept[j])
                break;
            j++;
        }
        if (accept[i] == '\0')
            break;
        i++;
    }
    return (i);
}

int main(void)
{
    const char  t1[] = "Bello Axel";
    const char  t2[] = "Nooom";
    size_t  result;

    result = ft_strspn(t1, t2);
    printf("%zu\n", result);
    return (0);
}