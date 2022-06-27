/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** inputs
*/

#include "my_rpg.h"

void get_input(game_t *game, sfEvent event)
{
    sfKeyCode key = event.key.code;
    sfClock *delay = game->character->delay;

    if (key == sfKeyA) {
        if (sfClock_getElapsedTime(delay).microseconds < 1000100)
            return;
        sfClock_restart(game->character->delay);
        game->character->rect.left = 0;
        game->character->state = ATTACK;
    }
    if (key == sfKeyB) {
        game->character->state = DIE;
    }
    return;
}
