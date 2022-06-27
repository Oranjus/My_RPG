/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** free_enemies
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

void free_enemies(game_t *game)
{
    sfClock_destroy(game->enemies->clock);

    while (game->enemies->enemy != NULL) {
        sfSprite_destroy(game->enemies->enemy->sprite);
        sfClock_destroy(game->enemies->enemy->respawn);
        game->enemies->enemy = game->enemies->enemy->next;
    }
    if (game->enemies->enemy)
        free(game->enemies->enemy);
    if (game->enemies)
        free(game->enemies);
}
