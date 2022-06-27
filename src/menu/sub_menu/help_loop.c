/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** help_loop
*/

#include <stdlib.h>
#include "my_rpg.h"

static void display_menu(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_setView(game->window, game->menu->view);
    display_bg(game);
    sfRenderWindow_setView(game->window, game->menu->static_view);
    sfRenderWindow_drawSprite(game->window, game->menu->help->bg, NULL);
    display_btn(game->window, game->menu->help->btn_list);
    sfRenderWindow_display(game->window);
}

static void event_menu_handler(game_t *game, help_menu_t *help)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(game->window, &event)) {
        manage_event_btn(event, game, help->btn_list);
        switch (event.type) {
        case sfEvtClosed:
            quit_game(game);
            break;
        case sfEvtKeyPressed:
            if (event.key.code == sfKeyEscape)
                quit_game(game);
            break;
        default:
            return;
        }
    }
}

int help_loop(game_t *game)
{
    sfClock_restart(game->character->move);
    if (!game->menu)
        return 84;
    event_menu_handler(game, game->menu->help);
    move_view_menu(game);
    display_menu(game);
    game->loop_time = (sfClock_restart(game->character->move).microseconds);
    return 0;
}

help_menu_t *load_help_m(sfVector2u W_size, menu_t *menu)
{
    help_menu_t *st = malloc(sizeof(help_menu_t));

    W_size = W_size;
    menu = menu;
    st->btn_list = NULL;
    add_btn(&(st->btn_list), (sfVector2f){90, 90},
        (sfIntRect){0, BTN_S_TOP, BTN_S_W, BTN_S_W}, *go_to_settings);
    st->bg = init_sprite((sfVector2f){460, 176},
        (sfIntRect){-1, -1, -1, -1}, "assets/menu/how_to_play.png");
    return st;
}
