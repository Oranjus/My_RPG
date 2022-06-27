/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** init_pnj
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <stddef.h>
#include <sys/types.h>
#include "my_rpg.h"
#include "my.h"
#include "pnj.h"

void free_tab(char **fcontent)
{
    int i = 0;
    while (fcontent[i] != NULL) {
        free(fcontent[i]);
        i++;
    }
    if (fcontent)
        free(fcontent);
}

char *get_path(char *folder, char *filename)
{
    int size = my_strlen(folder) + my_strlen(filename) + 1;
    char *path = malloc(sizeof(char) * size);
    my_strcpy(path, folder);
    my_strcat(path, filename);
    return path;
}

char *get_name(char *str)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != '.') {
        i++;
    }
    str[i] = '\0';
    return (my_strdup(str));
}

pnj_t *init_pnj(game_t *game)
{
    char *filepath = "assets/pnj/";
    DIR *dir = opendir(filepath);
    struct dirent *info = NULL;
    char **fcontent = NULL;
    pnj_t *list = NULL;
    char *path = NULL;
    if (dir == NULL)
        return (NULL);
    while ((info = readdir(dir)) != NULL) {
        if (!check_file_name(info->d_name))
            continue;
        path = get_path(filepath, info->d_name);
        fcontent = open_file(path);
        list = add_to_pnj_list(list, fcontent, game);
        list->name = get_name(info->d_name);
        free(path);
    }
    closedir(dir);
    return list;
}
