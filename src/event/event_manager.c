/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** event_manager
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_rpg.h"
#include "save.h"

int quit_game(game_t *game)
{
    sfRenderWindow_close(game->window);
    return 0;
}

void update_state(character_t *chr, sfEvent event)
{
    sfKeyCode code = event.key.code;

    if (chr->state == ATTACK || chr->state == DIE)
        return;
    if (code >= 71 && code <= 74) {
        chr->state = IDDLE;
        chr->rect.left = 72 * 3;
    }
    return;
}

void check_move(game_t *game)
{
    character_t *character = game->character;

    if (character->interaction == INTERACT || character->state == DIE)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
        set_direction(game, sfKeyDown);
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
        set_direction(game, sfKeyLeft);
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
        set_direction(game, sfKeyRight);
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
        set_direction(game, sfKeyUp);
        return;
    }
}

void check_all_events(game_t *game)
{
    sfEvent event;
    if (sfRenderWindow_pollEvent(game->window, &event)) {
        event_hud_handler(event, game);
        switch (event.type) {
        case sfEvtClosed:
            sfRenderWindow_close(game->window);
            break;
        case sfEvtMouseButtonReleased:
            break;
        case sfEvtKeyPressed:
            get_input(game, event);
            break;
        case sfEvtKeyReleased:
            update_state(game->character, event);
            break;
        default:
            break;
        }
    }
    return;
}

void event_handler(game_t *game)
{
    check_move(game);
    sfSprite_setPosition(game->character->sprite, game->character->pos);
    move_view(game);
    check_start_fight(game);
    check_all_events(game);
}
