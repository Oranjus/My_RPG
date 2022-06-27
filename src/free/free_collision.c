/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** free_collision
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_rpg.h"
#include "save.h"
#include "free.h"

void free_decoration(game_t *game)
{
    int i = 0;

    while (i < 14) {
        sfSprite_destroy(game->deco->sprite[i]);
        i++;
    }
    if (game->deco->sprite)
        free(game->deco->sprite);
}

void free_collision(game_t *game)
{
    while (game->collisions != NULL) {
        sfRectangleShape_destroy(game->collisions->display);
        sfSprite_destroy(game->collisions->sprite);
        game->collisions = game->collisions->next;
    }
    if (game->collisions)
        free(game->collisions);
}
