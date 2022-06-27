/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** display_item_inventory
*/

#include <stdio.h>
#include "my_rpg.h"

void display_item_inventory(game_t *game, item_t *item_list)
{
    while (item_list != NULL) {
        sfRenderWindow_drawSprite(game->window, item_list->item_visual, NULL);
        item_list = item_list->next;
    }
}
