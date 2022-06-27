/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** init_inventory
*/

#include <stdlib.h>
#include "my_rpg.h"

static sfSprite *load_bg(sfVector2u W_size)
{
    sfSprite *bg = init_sprite((sfVector2f){W_size.x / 2, W_size.y / 2},
    (sfIntRect){-1, -1, -1, -1}, "assets/menu/inventory.png");
    sfSprite_setOrigin(bg, (sfVector2f)
    {(sfSprite_getTextureRect(bg).width) / 2,
    (sfSprite_getTextureRect(bg).height) / 2});
    return bg;
}

static item_t *load_item(sfIntRect *slot_list)
{
    item_t *item_list = NULL;
    add_item(&item_list, slot_list, (item_stat_t){197, 50, 0});
    add_item(&item_list, slot_list, (item_stat_t){196, 50, 0});
    add_item(&item_list, slot_list, (item_stat_t){195, 50, 0});
    add_item(&item_list, slot_list, (item_stat_t){201, 50, 0});
    add_item(&item_list, slot_list, (item_stat_t){196, 50, 0});
    return item_list;
}

static sfSprite *load_char(void)
{
    sfSprite *character = init_sprite((sfVector2f){740, 510},
    (sfIntRect) {72 * 3 + 1, 0, 18 * 3, 27 * 3},
    "assets/sprite/char/WARRIOR.png");
    sfSprite_setScale(character, (sfVector2f){1.5, 1.5});
    return character;
}

inventory_t *init_inventory(game_t *game)
{
    inventory_t *inventory = malloc(sizeof(inventory_t) * 1);
    sfVector2u W_size = sfRenderWindow_getSize(game->window);
    inventory->bg = load_bg(W_size);
    inventory->character = load_char();
    inventory->slot = load_slot();
    inventory->item_list = load_item(inventory->slot);
    inventory->stats_text = sfText_create();
    sfText_setString(inventory->stats_text, "TEST");
    sfText_setCharacterSize(inventory->stats_text, 22);
    sfText_setFont(inventory->stats_text, game->fight_system->overlay->font);
    sfText_setPosition(inventory->stats_text, (sfVector2f) {869, 695});
    return inventory;
}
