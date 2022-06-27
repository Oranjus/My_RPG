/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** manage_interaction
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "my.h"
#include "pnj.h"

void change_interact_value(pnj_t *pnj, char *name, int value)
{
    while (my_strcmp(pnj->name, name) && (pnj != NULL)) {
        pnj = pnj->next;
    }
    if (pnj != NULL) {
        pnj->can_interact = value;
    }
}

void interact_start(pnj_t *pnj)
{
    change_interact_value(pnj, "knight", 0);
    change_interact_value(pnj, "bertrand", 0);
    change_interact_value(pnj, "demon", 0);
    change_interact_value(pnj, "wizard", 1);
    change_interact_value(pnj, "adventurer", 1);
}

void interact_wizard(pnj_t *pnj)
{
    change_interact_value(pnj, "knight", 1);
    change_interact_value(pnj, "bertrand", 1);
    change_interact_value(pnj, "wizard", 0);
    change_interact_value(pnj, "adventurer", 1);
    change_interact_value(pnj, "demon", 0);
}

void interact_repared(pnj_t *pnj)
{
    change_interact_value(pnj, "knight", 0);
    change_interact_value(pnj, "demon", 1);
    change_interact_value(pnj, "bertrand", 1);
    change_interact_value(pnj, "wizard", 0);
    change_interact_value(pnj, "adventurer", 1);
}

void check_interaction(game_t *game)
{
    int story = game->story->save;
    pnj_t *pnj = game->pnj_list;

    if (story == START)
        interact_start(pnj);
    if (story == WIZARD_BEATEN)
        interact_wizard(pnj);
    if (story == REPAIRED)
        interact_repared(pnj);
}
