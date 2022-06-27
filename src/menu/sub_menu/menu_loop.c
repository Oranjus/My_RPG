/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** menu_loop
*/

#include "save.h"
#include "my_rpg.h"

static void display_menu(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_setView(game->window, game->menu->view);
    display_bg(game);
    display_game_object(BACK, game, FRONT);
    sfRenderWindow_setView(game->window, game->menu->static_view);
    sfRenderWindow_drawSprite(game->window, game->menu->bg, NULL);
    display_btn(game->window, game->menu->btn_list);
    sfRenderWindow_display(game->window);
}

static void event_menu_handler(game_t *game)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(game->window, &event)) {
        manage_event_btn(event, game, game->menu->btn_list);
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

void move_view_menu(game_t *game)
{
    if (sfClock_getElapsedTime(game->menu->clock).microseconds < 10000)
        return;
    sfVector2f pos = sfView_getCenter(game->menu->view);
    int state = 0;
    if (game->menu->move_v.x < 0)
        state = -1;
    else
        state = 1;
    if (pos.x <= 2400 || pos.x >= 3750) {
        state *= -1;
    } if (pos.y <= 0)
        state *= -1;
    game->menu->move_v.x = (32 * game->loop_time / 1000000) * state;
    game->menu->move_v.y = (36 * game->loop_time / 1000000) * state;
    sfView_move(game->menu->view, game->menu->move_v);
    sfClock_restart(game->menu->clock);
}

int menu_main_loop(game_t *game)
{
    sfClock_restart(game->character->move);
    if (game->character->state >= DIE) {
        reset_character(game);
        load_from_save(game);
    }
    if (!game->menu)
        return 84;
    event_menu_handler(game);
    move_view_menu(game);
    display_menu(game);
    game->loop_time = (sfClock_restart(game->character->move).microseconds);
    return 0;
}
