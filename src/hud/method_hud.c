/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** method_hud
*/

#include "my_rpg.h"

int set_pause(game_t *game)
{
    if (game->state != GS_PAUSE) {
        game->state = GS_PAUSE;
        pause_loop(game);
    } else
        game->state = GS_PLAY;
    return 1;
}

int go_to_menu(game_t *game)
{
    game->state = GS_MENU;
    return 1;
}
