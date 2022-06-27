/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** save_utils
*/

#include <stdlib.h>
#include "my.h"

long int check_nb_size(long int nb)
{
    long int counter = 1;
    long int i = 10;

    while (i <= nb) {
        counter += 1;
        i *= 10;
    }
    return (counter);
}

char *nb_to_str(long int nb)
{
    int size = check_nb_size(nb);
    char *str = malloc(sizeof(char) * (size + 1));
    long int divisor = my_compute_power_rec(10, size) / 10;
    int i = 0;

    if (size == 1) {
        i += 2;
        str[0] = (nb / divisor) + 48;
    }
    while (i < size) {
        str[i] = (nb / divisor) + 48;
        nb %= divisor;
        divisor /= 10;
        i += 1;
    }
    str[size] = '\0';
    return (str);
}
