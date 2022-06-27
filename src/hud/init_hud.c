/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** init_hud
*/

#include <stdlib.h>
#include "my_rpg.h"

static button_t *map_btn(hud_t *hud, sfVector2u W_size)
{
    hud->btn_list = NULL;
    add_btn(&(hud->btn_list), (sfVector2f){90, 90},
        (sfIntRect){325, BTN_S_TOP, BTN_S_W, BTN_S_W}, *set_pause);
    add_btn(&(hud->btn_list), (sfVector2f){W_size.x - 100, W_size.y - 90},
        (sfIntRect){0, 673, 89, 103}, *open_inventory);
    add_btn(&(hud->btn_list), (sfVector2f){827 + BTN_W / 2, 355 + BTN_H / 2},
        (sfIntRect){0, BTN_H * 2, BTN_W, BTN_H}, *set_pause);
    add_btn(&(hud->btn_list), (sfVector2f){827 + BTN_W / 2, 455 + BTN_H / 2},
        (sfIntRect){0, BTN_H * 1, BTN_W, BTN_H}, *go_to_menu);
    add_btn(&(hud->btn_list), (sfVector2f){827 + BTN_W / 2, 555 + BTN_H / 2},
        (sfIntRect){0, BTN_H * 5, BTN_W, BTN_H}, *quit_game);
    return hud->btn_list;
}

static sfText *load_pop_msg(void)
{
    sfText *text = sfText_create();
    sfText_setCharacterSize(text, 40);
    sfText_setFont(text,
    sfFont_createFromFile("assets/fonts/PressStart2P.ttf"));
    sfText_setColor(text, sfColor_fromRGB(248, 238, 222));
    sfText_setOutlineThickness(text, 4);
    return text;
}

void load_asset_hud(hud_t *hud, sfVector2u W_size)
{
    float scale = 0.75;
    hud->head = init_sprite((sfVector2f){W_size.x - 90, 70},
        (sfIntRect){474, 117, 167, 149}, "assets/menu/hud.png");
    hud->bar_health = init_sprite((sfVector2f){W_size.x - 360, 75},
        (sfIntRect){35, 236, 425, 44}, "assets/menu/hud.png");
    hud->bar_energy = init_sprite((sfVector2f){W_size.x - 345, 114},
        (sfIntRect){71, 297, 389, 15}, "assets/menu/hud.png");
    hud->container_bar = init_sprite((sfVector2f){W_size.x - 360, 90},
        (sfIntRect){22, 117, 453, 108}, "assets/menu/hud.png");
    hud->bar_inventory = init_sprite((sfVector2f){W_size.x - 20, 920},
        (sfIntRect){0, 116, 21, 159}, "assets/menu/hud.png");
    sfSprite_setScale(hud->head, (sfVector2f){scale, scale});
    sfSprite_setScale(hud->bar_health, (sfVector2f){-scale, scale});
    sfSprite_setScale(hud->bar_energy, (sfVector2f){-scale, scale});
    sfSprite_setScale(hud->bar_inventory, (sfVector2f){scale, scale});
    sfSprite_setScale(hud->container_bar, (sfVector2f){scale, scale});
}

hud_t *init_hud(game_t *game)
{
    sfVector2u W_size = sfRenderWindow_getSize(game->window);
    hud_t *hud = malloc(sizeof(hud_t) * 1);

    hud->btn_list = map_btn(hud, W_size);
    hud->pop_msg = load_pop_msg();
    hud->cool_down_pop = 0;
    load_asset_hud(hud, W_size);
    foreach_btn(*appear_btn, hud->btn_list->next->next);
    return hud;
}
