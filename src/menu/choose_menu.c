/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** set_scene
*/

#include "my_rpg.h"

int menu_loop(game_t *game)
{
    switch (game->menu->sc_menu) {
    case MENU_SC:
        return menu_main_loop(game);
    case SETTINGS_SC:
        return settings_loop(game);
    case SCORE_SC:
        return save_loop(game);
    case HELP_SC:
        return help_loop(game);
    default:
        return 84;
    }
    return 0;
}
