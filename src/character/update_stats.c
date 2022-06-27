/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** update_stats
*/

#include "my_rpg.h"

void update_char_stats(game_t *game)
{
    int time = sfClock_getElapsedTime(game->character->stamina).microseconds;

    if (time >= 300000 && game->stat.stamina < game->stat.stamina_max) {
        game->stat.stamina++;
        sfClock_restart(game->character->stamina);
    }
    return;
}
