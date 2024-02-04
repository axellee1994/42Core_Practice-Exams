#include <unistd.h>
#include <stdio.h>

unsigned char	swap_bits(unsigned char octet)
{
    octet = (octet >> 4) | (octet << 4);
    return (octet);
}

int main(void)
{
    printf("%d\n", swap_bits(1));
    return (0);
}