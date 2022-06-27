/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** display_sprite
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

void display_pnj(game_t *game)
{
    pnj_t *pnj = game->pnj_list;
    enum save save = game->story->save;

    while (pnj != NULL) {
        if (my_strcmp(pnj->name, "bertrand") == 0 && save < WIZARD_BEATEN) {
            pnj = pnj->next;
            continue;
        }
        sfRenderWindow_drawSprite(game->window, pnj->sprite, NULL);
        pnj = pnj->next;
    }
    return;
}
