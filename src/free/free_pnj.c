/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** free_pnj
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

void free_pnj(game_t *game)
{
    while (game->pnj_list != NULL) {
        free_tab(game->pnj_list->dialogue);
        sfSprite_destroy(game->pnj_list->sprite);
        if (game->pnj_list->name)
            free(game->pnj_list->name);
        sfSprite_destroy(game->pnj_list->interact);
        game->pnj_list = game->pnj_list->next;
    }
    if (game->pnj_list)
        free(game->pnj_list);
}
