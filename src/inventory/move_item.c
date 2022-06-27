/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** move_item
*/

#include "my_rpg.h"

void place_center_slot(sfSprite *spr, sfIntRect rect)
{
    sfVector2f pos =
    {rect.left + rect.width / 2, rect.top + rect.height / 2};
    sfSprite_setPosition(spr, pos);
}

static sfIntRect *check_hitbox_rect(sfIntRect *rect_list, \
sfVector2f pos_onclick)
{
    for (int i = 0; i < SLOT_NB; i++) {
        if (sfIntRect_contains(&rect_list[i], pos_onclick.x, pos_onclick.y)
            == sfTrue) {
            return &rect_list[i];
        }
    }
    return NULL;
}

int slot_taken(item_t *item_list, sfIntRect rect)
{
    sfIntRect rect_curr;
    if (item_list == NULL)
        return 0;
    while (item_list != NULL) {
        if (item_list->location == NULL)
            continue;
        rect_curr = *item_list->location;
        if (rect_curr.top == rect.top
        && rect_curr.left == rect.left
        && rect_curr.width == rect.width
        && rect_curr.height == rect.height)
            return 1;
        item_list = item_list->next;
    }
    return 0;
}

static int process_new_slot(item_t *item, sfVector2f pos_onclick, game_t *game)
{
    item_t *item_list = game->inventory->item_list;
    sfIntRect *rect_list = game->inventory->slot;
    sfIntRect *next_rect = check_hitbox_rect(rect_list, pos_onclick);

    item->placement_state = false;
    if (next_rect == NULL || slot_taken(item_list, *next_rect))
        return 0;
    item->placement_state = true;
    if (check_utility_slot(game, item, *next_rect))
        return 69;
    item->location = next_rect;
    place_center_slot(item->item_visual, *next_rect);
    return 1;
}

int manage_slot(item_t *item, sfVector2f pos_onclick, game_t *game)
{
    sfIntRect rect;

    while (item != NULL) {
        if (item->click_state == true) {
            if (process_new_slot(item, pos_onclick, game) == 69)
                return 2;
        }
        if (item != NULL && item->placement_state == false
        && item->location != NULL) {
            rect = *item->location;
            place_center_slot(item->item_visual, rect);
            item->placement_state = true;
        }
        if (item != NULL)
            item = item->next;
    }
    return 0;
}
