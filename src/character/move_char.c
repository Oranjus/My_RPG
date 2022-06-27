/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** move_char
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_rpg.h"

void update_char_dir(character_t *character)
{
    int dir = character->direction;

    if (character->state == ATTACK || character->state == DIE)
        return;
    if (dir == DOWN)
        character->rect.top = 0;
    if (dir == UP)
        character->rect.top = 171;
    if (dir == LEFT)
        character->rect.top = 87;
    if (dir == RIGHT)
        character->rect.top = 258;
}

void set_char_pos(game_t *game, enum direction dir, sfVector2f offset)
{
    game->character->direction = dir;
    game->character->pos.y += (offset.y * game->loop_time / 1000000);
    game->character->pos.x += (offset.x * game->loop_time / 1000000);
    check_color_collision(game->character->pos, game, offset);
}

void switch_direction(game_t *game, sfKeyCode key)
{
    switch (key) {
        case sfKeyDown:
            set_char_pos(game, DOWN, (sfVector2f) {0, 240});
            break;
        case sfKeyUp:
            set_char_pos(game, UP, (sfVector2f) {0, -240});
            break;
        case sfKeyLeft:
            set_char_pos(game, LEFT, (sfVector2f) {-240, 0});
            break;
        case sfKeyRight:
            set_char_pos(game, RIGHT, (sfVector2f) {240, 0});
            break;
        case sfKeyEscape :
            quit_game(game);
        default:
            break;
    }
}

void set_direction(game_t *game, sfKeyCode key)
{
    if (game->character->state == ATTACK || game->character->state == DIE)
        return;
    game->character->state = RUN;
    switch_direction(game, key);
    return;
}
