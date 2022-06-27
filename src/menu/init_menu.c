/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** init_menu
*/

/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** load_btn
*/

#include <stdlib.h>
#include "my_rpg.h"

static button_t *map_btn(menu_t *menu)
{
    menu->btn_list = NULL;
    add_btn(&(menu->btn_list), (sfVector2f){700 + BTN_W / 2, 270 + BTN_H},
        (sfIntRect){0, 0, BTN_W, BTN_H}, *launch_game);
    add_btn(&(menu->btn_list), (sfVector2f){700 + BTN_W / 2, 390 + BTN_H},
        (sfIntRect){0, BTN_H * 3, BTN_W, BTN_H}, *go_to_settings);
    add_btn(&(menu->btn_list), (sfVector2f){700 + BTN_W / 2, 510 + BTN_H},
        (sfIntRect){0, BTN_H * 6, BTN_W, BTN_H}, *start_new_game);
    add_btn(&(menu->btn_list), (sfVector2f){1218 + BTN_W / 2, 640 + BTN_H / 2},
        (sfIntRect){0, BTN_H * 5, BTN_W, BTN_H}, *quit_game);
    return menu->btn_list;
}

static void load_view(game_t *game, menu_t *menu)
{
    menu->view = sfView_create();
    sfVector2u size = sfRenderWindow_getSize(game->window);
    sfView_setSize(menu->view, (sfVector2f){size.x, size.y});
    sfView_zoom(menu->view, 2.5);
    sfView_setCenter(menu->view, (sfVector2f){3000, 4000});

    menu->static_view = sfView_create();
    sfView_setSize(menu->static_view, (sfVector2f){size.x, size.y});
    sfView_setCenter(menu->static_view, (sfVector2f){size.x / 2, size.y / 2});
}

static void load_menu_all(menu_t *menu, sfVector2u W_size)
{
    menu->sc_menu = MENU_SC;
    menu->clock = sfClock_create();
    menu->move_v = (sfVector2f){0.8, 0.9};
    menu->stat = (menu_stat_t){50, 60, 0, 0, 0};
    menu->save = load_save_m(W_size, menu);
    menu->settings = load_settings(W_size, menu);
    menu->help = load_help_m(W_size, menu);
    menu->bg = init_sprite((sfVector2f){0, 0},
        (sfIntRect){-1, -1, -1, -1}, "assets/menu/main_menu.png");
    sfSprite_setScale(menu->bg, (sfVector2f){1.3, 1.3});
    sfSprite_setPosition(menu->bg, (sfVector2f){(W_size.x / 2) -
        ((sfSprite_getTextureRect(menu->bg).width + 137) / 2), 20});
}

menu_t *init_menu(game_t *game)
{
    menu_t *menu = (menu_t *)malloc(sizeof(menu_t));
    sfVector2u W_size = sfRenderWindow_getSize(game->window);
    if (menu == NULL)
        return NULL;
    load_view(game, menu);
    load_menu_all(menu, W_size);
    menu->btn_list = map_btn(menu);
    return menu;
}
