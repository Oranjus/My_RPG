/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** check_files
*/

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_rpg.h"
#include "my.h"

int check_hash(char *buf)
{
    int hash = 0;
    for (int i = 0; buf[i] != '\0'; i++)
        hash += buf[i];
    return hash;

}

int check_file_list(char **path, char *buffer)
{
    int fd = 0;

    for (int i = 0; path[i] != NULL; i++) {
        fd = open(path[i], O_RDONLY);
        if (fd == -1) {
            free(buffer);
            return 84;
        }
        close(fd);
        free(path[i]);
    }
    free(buffer);
    free(path);
    return 0;
}

int check_files(void)
{
    FILE *file = fopen("assets/list.txt", "r");
    char *buffer = malloc(sizeof(char) * 10000);
    char **path = NULL;

    if (file == NULL)
        return 84;
    size_t len = fread(buffer, 1, 10000, file);
    buffer[len] = '\0';
    if (check_hash(buffer) != HASH)
        return 84;
    path = my_str_to_word_array(buffer, "\n");
    return check_file_list(path, buffer);
}
