/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** method_btn
*/

#include "my_rpg.h"

int launch_game(game_t *game)
{
    game->state = GS_PLAY;
    if (game->story->save == FINISHED)
        start_new_game(game);
    return 1;
}

int go_to_settings(game_t *game)
{
    game->menu->sc_menu = SETTINGS_SC;
    return 1;
}

int go_to_save(game_t *game)
{
    game->menu->sc_menu = SCORE_SC;
    return 1;
}

int go_back_scene(game_t *game)
{
    game->menu->sc_menu = MENU_SC;
    return 1;
}

int go_to_help(game_t *game)
{
    game->menu->sc_menu = HELP_SC;
    return 1;
}
