/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** utils
*/

#include <stddef.h>

int get_tab_size(char **fcontent)
{
    int count = 0;

    while (fcontent[count] != NULL) {
        count++;
    }
    return (count);
}
