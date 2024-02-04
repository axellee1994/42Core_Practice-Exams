#include <unistd.h>
#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
    octet = (octet & 0xF0) >> 4 | (octet & 0x0F) << 4;
    octet = (octet & 0xCC) >> 2 | (octet & 0x33) << 2;
    octet = (octet & 0xAA) >> 1 | (octet & 0x55) << 1;
    return (octet);
}

int main(void)
{
    printf("%d\n", reverse_bits(38));
    return (0);
}

/* Return is 100 when printed out */