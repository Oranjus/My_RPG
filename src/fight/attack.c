/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** attack
*/

#include "my_rpg.h"

int handle_attack(game_t *game)
{
    fight_t *fight = game->fight_system->fight;

    if (fight->character->force >= (fight->character->atk / 2)) {
        fight->character->force -= (fight->character->atk / 2);
        fight->opponent->hp -= (fight->character->atk - fight->character->def);
        sfSprite_setColor(fight->character->sprite, sfWhite);
        sfSprite_setColor(fight->opponent->sprite, sfRed);
        return 1;
    }
    return 0;
}
