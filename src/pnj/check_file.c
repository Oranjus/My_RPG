/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** check_file
*/

#include "my.h"

int check_file_name(char *name)
{
    char buffer[] = ".pnj";
    int size = my_strlen(name);

    for (int i = 0; i < 4; i++) {
        if (name[size - i - 1] != buffer[3 - i])
            return (0);
    }
    return (1);
}
