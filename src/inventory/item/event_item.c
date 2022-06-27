/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** event_item
*/

#include "my_rpg.h"

static int click_item(item_t *item, sfVector2f pos_onclick)
{
    if (check_hitbox(item->item_visual, pos_onclick)) {
        item->click_state = true;
        item->placement_state = false;
        return 1;
    }
    return 0;
}

static int move_item(item_t *item, sfVector2f pos_onclick)
{
    if (item->click_state == true) {
        sfSprite_setPosition(item->item_visual, pos_onclick);
        return 1;
    }
    return 0;
}

static int unclick_item(item_t *item, sfVector2f pos_onclick)
{
    pos_onclick = pos_onclick;
    if (item->click_state == true)
        item->click_state = false;
    return 0;
}

int manage_event_item(sfEvent event, game_t *game)
{
    sfVector2i pos_click_tmp = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f pos_click = {pos_click_tmp.x, pos_click_tmp.y};

    switch (event.type) {
    case sfEvtMouseMoved:
        foreach_item(*move_item, pos_click, game->inventory->item_list);
        break;
    case sfEvtMouseButtonPressed:
        foreach_item(*click_item, pos_click, game->inventory->item_list);
        break;
    case sfEvtMouseButtonReleased:
        manage_slot(game->inventory->item_list, pos_click, game);
        foreach_item(*unclick_item, pos_click, game->inventory->item_list);
        break;
    default:
        return 1;
    }
    return 0;
}

int foreach_item(int (*func)(item_t *item, sfVector2f pos_onclick), \
sfVector2f pos_onclick, item_t *item)
{
    int exec = 0;

    while (item != NULL && !exec) {
        exec = func(item, pos_onclick);
        item = item->next;
    }
    return exec;
}
