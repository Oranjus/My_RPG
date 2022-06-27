/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** action_item
*/

#include <stdlib.h>
#include "my_rpg.h"

static int free_node(item_t *node)
{
    sfSprite_destroy(node->item_visual);
    free(node);
    return 1;
}

static int remove_node_item(item_t **item, item_t *node)
{
    if (item == NULL || node == NULL || *item == NULL)
        return 84;
    item_t *current = *item;
    item_t *prev = *item;

    if (*item == node) {
        *item = node->next;
        return free_node(node);
    }
    while (current->next != NULL && current != node) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    return free_node(node);
}

static int apply_item(item_t *node, game_t *game)
{
    if (game->stat.health >= game->stat.health_max) {
        pop_up_text("health already max", 30, game);
        return 0;
    }
    if (game->stat.health + node->stat.health < game->stat.health_max) {
        game->stat.health += node->stat.health;
        pop_up_text("+ hp", 30, game);
    } else {
        game->stat.health = game->stat.health_max;
        pop_up_text("Hp Full", 30, game);
    }
    return 1;
}

int check_utility_slot(game_t *game, item_t *item, sfIntRect next_rect)
{
    if (next_rect.width != game->inventory->slot[SLOT_NB - 1].width)
        return 0;
    if (apply_item(item, game)) {
        remove_node_item(&game->inventory->item_list, item);
        return 1;
    } else {
        item->placement_state = false;
        place_center_slot(item->item_visual, *item->location);
        return 1;
    }
}

int check_equiped_slot(game_t *game, inventory_t *inventory)
{
    sfIntRect slot_1 = inventory->slot[SLOT_NB - 2];
    item_t *item = inventory->item_list;
    float add_atk = 0;

    for (;item != NULL; item = item->next) {
        if (slot_1.top != item->location->top) {
            continue;
        }
        add_atk += item->stat.strenght;
    }
    if (game->stat.atk + add_atk > game->stat.atk_max + add_atk)
        game->stat.atk -= add_atk;
    game->stat.atk = game->stat.atk_max + add_atk;
    return 1;
}
