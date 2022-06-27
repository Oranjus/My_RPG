/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** settings_loop
*/

#include <stdlib.h>
#include "my_rpg.h"

static void display_menu(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_setView(game->window, game->view);
    display_bg(game);
    display_game_object(BACK, game, FRONT);
    sfRenderWindow_setView(game->window, game->menu->static_view);
    sfRenderWindow_drawSprite(game->window, game->menu->settings->bg, NULL);
    display_btn(game->window, game->menu->settings->btn_list);
    display_slider(game->window, game->menu->settings->slider_list);
    sfRenderWindow_display(game->window);
}

static void event_menu_handler(game_t *game, settings_menu_t *settings)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(game->window, &event)) {
        manage_event_slider(event, game, settings->slider_list);
        manage_event_btn(event, game, settings->btn_list);
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

int settings_loop(game_t *game)
{
    int framerate = 0;

    sfClock_restart(game->character->move);
    if (!game->menu)
        return 84;
    event_menu_handler(game, game->menu->settings);
    move_view_menu(game);
    display_menu(game);
    framerate = game->menu->stat.frame_rate + 30;
    sfRenderWindow_setFramerateLimit(game->window, framerate);
    sfMusic_setVolume(game->musics->song_menu, game->menu->stat.volume);
    game->loop_time = (sfClock_restart(game->character->move).microseconds);
    return 0;
}

settings_menu_t *load_settings(sfVector2u W_size, menu_t *menu)
{
    settings_menu_t *st = malloc(sizeof(settings_menu_t));

    st->slider_list = NULL;
    add_slider(&(st->slider_list), (sfVector2f){W_size.x / 2 + 180, 430},
    &(menu->stat.volume), (sfVector2f){0, 100});
    add_slider(&(st->slider_list), (sfVector2f){W_size.x / 2 + 180, 580},
    &(menu->stat.frame_rate), (sfVector2f){0, 240});
    st->btn_list = NULL;
    add_btn(&(st->btn_list), (sfVector2f){90, 90},
        (sfIntRect){0, BTN_S_TOP, BTN_S_W, BTN_S_W}, *go_back_scene);
    add_btn(&(st->btn_list), (sfVector2f){W_size.x / 2, W_size.y - 300},
        (sfIntRect){0, BTN_H * 4, BTN_W, BTN_H}, *go_to_help);
    st->bg = init_sprite((sfVector2f){460, 176},
        (sfIntRect){-1, -1, -1, -1}, "assets/menu/settings.png");
    return st;
}
