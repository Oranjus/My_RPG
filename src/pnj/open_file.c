/*
** EPITECH PROJECT, 2022
** B-PSU-200-BDX-2-1-bstetris-elouan.savy-camaret
** File description:
** open_file
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "my.h"

char **open_file(char *filepath)
{
    FILE *file = NULL;
    struct stat fs;
    char *fcontent = NULL;
    char **result = NULL;

    if (-1 == stat(filepath, &fs))
        return (NULL);
    file = fopen(filepath, "r");
    if (file == NULL)
        return (NULL);
    fcontent = malloc(sizeof(char) * (fs.st_size + 1));
    fread(fcontent, 1, fs.st_size, file);
    fcontent[fs.st_size] = '\0';
    fclose(file);
    result = my_str_to_word_array(fcontent, "\n");
    free(fcontent);
    return (result);
}
