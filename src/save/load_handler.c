/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** load_hanlder
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "save.h"
#include "my.h"

int get_int(FILE *file)
{
    char *buffer = NULL;
    size_t size = 0;
    int read_size = 0;
    int result = 0;

    read_size = getline(&buffer, &size, file);
    if (read_size == -1)
        return (-1);
    buffer[read_size] = '\0';
    result = my_getnbr(buffer);
    if (buffer)
        free(buffer);
    return (result);
}

sfVector2f get_vector(FILE *file)
{
    char *buffer = NULL;
    char **tmp = NULL;
    size_t size = 0;
    int read_size = 0;

    read_size = getline(&buffer, &size, file);
    if (read_size == -1)
        return ((sfVector2f) {-1, -1});
    buffer[read_size] = '\0';
    tmp = my_str_to_word_array(buffer, " ");
    if (buffer)
        free(buffer);
    return ((sfVector2f){my_getnbr(tmp[0]), my_getnbr(tmp[1])});
}

game_t *load_from_save(game_t *game)
{
    FILE *file = NULL;

    if ((file = fopen("assets/save/game.save", "r")) == NULL)
        return (game);
    game->story->save = get_int(file);
    game->stat.health = get_int(file);
    game->stat.stamina = get_int(file);
    game->character->pos = get_vector(file);
    return (game);
}
