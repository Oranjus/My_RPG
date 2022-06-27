/*
** EPITECH PROJECT, 2021
** my_putnbr
** File description:
** display an int
*/

#include "my.h"

char *int_to_char(int nb)
{
    char *result = malloc(sizeof(char) * 20);
    int i = 0;
    if (nb < 0) {
        result[i] = '-';
        nb = nb * -1;
        i++;
    }
    int deci = 1;
    if (nb == 0)
        result[0] = '0';
    while (deci <= nb)
        deci = deci * 10;
    while (deci / 10 >= 1) {
        deci = deci / 10;
        result[i] = ((nb / deci) + 48);
        nb = nb % deci;
        i++;
    }
    result[i] = '\0';
    return (result);
}
