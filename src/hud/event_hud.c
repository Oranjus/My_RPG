/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** event_hud
*/

#include "my_rpg.h"

int event_hud_handler(sfEvent event, game_t *game)
{
    manage_event_btn(event, game, game->hud->btn_list);
    switch (event.type) {
    case sfEvtKeyPressed:
        if (event.key.code == sfKeyI || event.key.code == sfKeyTab)
            return open_inventory(game);
        if (event.key.code == sfKeyEscape && game->state != GS_INVENTORY)
            return set_pause(game);
        break;
    default:
        return 84;
    }
    return 0;
}
