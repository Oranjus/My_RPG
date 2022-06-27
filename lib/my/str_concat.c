/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-elouan.savy-camaret
** File description:
** str_concat
*/

#include "my.h"

char *str_concat(char const *src1, char const *src2, char separator)
{
    int len_1 = my_strlen(src1);
    int len_2 = my_strlen(src2);
    char *result = malloc(sizeof(char) * (len_1 + len_2 + 2));
    int i = 0;

    if (src1 == NULL || src2 == NULL)
        return (NULL);
    my_strcpy(result, src1);
    result[len_1] = separator;
    while (src2[i] != '\0') {
        result[len_1 + 1 + i] = src2[i];
        i += 1;
    }
    result[len_1 + 1 + i] = '\0';
    return (result);
}
