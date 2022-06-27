/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** init_item
*/

#include <stdlib.h>
#include "my_rpg.h"

static sfIntRect get_sprite_by_id(int id)
{
    sfIntRect final = {0, 0, ITEM_WIDTH, ITEM_HEIGHT};
    int offest = ITEM_WIDTH;

    for (int count = 0; count < id; count++) {
        if (final.left >= 512) {
            final.left = 0;
            final.top += offest;
        }
        final.left += offest;
    }
    return final;
}

static sfIntRect *get_free_slot(sfIntRect *slot_list, item_t *item_list)
{
    for (int i = 0; i < SLOT_NB - 3; i++) {
        if (slot_taken(item_list, slot_list[i]) == 0)
            return &slot_list[i];
    }
    return NULL;
}

static item_t *init_item(item_stat_t stat, sfIntRect *slot_list,
item_t *item_list)
{
    item_t *item = malloc(sizeof(item_t));

    item->item_visual = init_sprite((sfVector2f){0, 0},
    get_sprite_by_id(stat.id), ITEM_PATH);
    item->stat = stat;
    item->click_state = false;
    item->location = get_free_slot(slot_list, item_list);
    if (item->location == NULL) {
        free(item);
        return NULL;
    }
    place_center_slot(item->item_visual, *item->location);
    item->placement_state = true;
    return item;
}

void add_item(item_t **head, sfIntRect *slot_list, item_stat_t stat)
{
    item_t *new_node = init_item(stat, slot_list, *head);
    if (!new_node || !slot_list)
        return;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    item_t *curr = *head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new_node;
}

int destroy_item(item_t *item_list)
{
    item_t *tmp;

    while (item_list != NULL) {
        tmp = item_list->next;
        sfSprite_destroy(item_list->item_visual);
        sfText_destroy(item_list->item_text);
        free(item_list);
        item_list = tmp;
    }
    if (item_list == NULL)
        return 0;
    else
        return 84;
}
