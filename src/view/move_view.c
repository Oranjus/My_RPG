/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** move_view
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_rpg.h"
#include "collision.h"
#include "my.h"

int check_view_limit(sfVector2f pos, sfVector2f size, game_t *game)
{
    int result = 0;
    if (pos.x - (size.x / 2) < 0) {
        pos.x = size.x / 2;
        result = 1;
    } else if (pos.x + (size.x / 2) > MAP_W) {
        pos.x = MAP_W - (size.x / 2);
        result = 1;
    }
    if (pos.y - (size.y / 2) < 0) {
        pos.y = size.y / 2;
        result = 1;
    } else if (pos.y + (size.y / 2) > MAP_H) {
        pos.y = MAP_H - (size.y / 2);
        result = 1;
    }
    sfView_setCenter(game->view, pos);
    return (result);
}

game_t *move_view(game_t *game)
{
    sfVector2f pos = sfView_getCenter(game->view);
    sfVector2f size = sfView_getSize(game->view);
    sfFloatRect bd = sfSprite_getGlobalBounds(game->character->sprite);
    float y = bd.top + (bd.height / 2);
    float x = bd.left + (bd.width / 2);

    if (check_view_limit((sfVector2f) {x, y}, size, game))
        return (game);
    pos.x = x;
    pos.y = y;
    sfView_setCenter(game->view, pos);
    return (game);
}
