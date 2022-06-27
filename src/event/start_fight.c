/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** start_fight
*/

#include "my_rpg.h"

void check_start_fight(game_t *game)
{
    character_t *character = game->character;

    if (game->fight_system->start_fight == 1 && character->interaction == 3) {
        sfView_reset(game->view, game->fight_system->fight_rect);
        game->state = GS_FIGHT;
        game->fight_system->start_fight = 0;
    }
    return;
}
