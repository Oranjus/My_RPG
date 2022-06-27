/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** pause
*/

#include "my_rpg.h"

static void display_pause(game_t *game, sfSprite *bg)
{
    sfRenderWindow_clear(game->window, sfBlack);
    display_bg(game);
    display_game_object(BACK, game, FRONT);
    sfRenderWindow_setView(game->window, game->menu->static_view);
    sfRenderWindow_drawSprite(game->window, bg, NULL);
    display_hud(game);
    sfRenderWindow_display(game->window);
}

static int event_menu_handler(game_t *game)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(game->window, &event)) {
        event_hud_handler(event, game);
        switch (event.type) {
        case sfEvtClosed:
            quit_game(game);
            break;
        default:
            return 0;
        }
    }
    return 0;
}

static sfSprite *load_bg(void)
{
    sfSprite *bg = init_sprite((sfVector2f){512, 176},
    (sfIntRect){-1, -1, -1, -1}, "assets/menu/pause.png");
    return bg;
}

void pause_loop(game_t *game)
{
    sfSprite *bg = load_bg();
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    foreach_btn(*disapear_btn, game->hud->btn_list);
    while (game->state == GS_PAUSE && sfRenderWindow_isOpen(game->window)) {
        event_menu_handler(game);
        update_hud(game);
        display_pause(game, bg);
    }
    foreach_btn(*appear_btn, game->hud->btn_list);
    sfSprite_destroy(bg);
}
