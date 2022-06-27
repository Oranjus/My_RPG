/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** menu save_loop
*/

#include <stdlib.h>
#include "my_rpg.h"

static void display_menu(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_setView(game->window, game->menu->view);
    display_bg(game);
    display_btn(game->window, game->menu->save->btn_list);
    sfRenderWindow_display(game->window);
}

static void event_menu_handler(game_t *game, save_menu_t *save)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(game->window, &event)) {
        manage_event_btn(event, game, save->btn_list);
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

int save_loop(game_t *game)
{
    sfClock_restart(game->character->move);
    if (!game->menu)
        return 84;
    event_menu_handler(game, game->menu->save);
    move_view_menu(game);
    display_menu(game);
    game->loop_time = (sfClock_restart(game->character->move).microseconds);
    return 0;
}

save_menu_t *load_save_m(sfVector2u W_size, menu_t *menu)
{
    save_menu_t *st = malloc(sizeof(save_menu_t));

    W_size = W_size;
    menu = menu;
    st->btn_list = NULL;
    add_btn(&(st->btn_list), (sfVector2f){90, 90},
        (sfIntRect){0, BTN_S_TOP, BTN_S_W, BTN_S_W}, *go_back_scene);
    return st;
}
