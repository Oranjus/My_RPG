/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** death_char
*/

#include "my_rpg.h"

void death_char(character_t *character)
{
    int time = sfClock_getElapsedTime(character->clock).microseconds;

    if (character->rect.top != 225 * 3) {
        character->rect.top = 225 * 3;
        character->rect.left = 0;
        character->rect.width = 36 * 3;
        character->rect.height = 35 * 3;
        sfClock_restart(character->clock);
        sfSprite_setTextureRect(character->sprite, character->rect);
        return;
    }
    if (character->rect.left == 360 * 3)
        character->state = DEAD;
    if (time > 300000 && character->rect.left != 360 * 3) {
        character->rect.left += 36 * 3;
        sfClock_restart(character->clock);
        sfSprite_setTextureRect(character->sprite, character->rect);
    }
    return;
}
