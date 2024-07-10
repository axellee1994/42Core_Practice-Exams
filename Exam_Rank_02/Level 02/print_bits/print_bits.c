#include <unistd.h>
#include <stdio.h>

void	print_bits(unsigned char octet)
{
    int i;

    i = 128;
    while (i > 0)
    {
        if ((octet & i) != 0)
            write(1, "1", 1);
        else
            write(1, "0", 1);
        i /= 2;
    }
}

int main(void)
{
    print_bits(2);
    return (0);
}