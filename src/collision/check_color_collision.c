/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** check_color_collision
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>

#include "my_rpg.h"

int check_color_line(game_t *game, int height, sfFloatRect rect)
{
    sfColor color;
    for (int j = rect.left; j < (rect.left + rect.width); j++) {
        color = sfImage_getPixel(game->map_coll, j, height);
        if (color.r == 0 && color.g == 0 && color.b == 0)
            return (1);
    }
    return (0);
}

int check_map_limit(sfFloatRect rect, game_t *game, sfVector2f offset)
{
    int result = 0;
    offset.x = offset.x * game->loop_time / 1000000;
    offset.y = offset.y * game->loop_time / 1000000;
    if ((rect.left + offset.x < 0) ||
    (rect.left + rect.width + offset.x > MAP_W)) {
        game->character->pos.x -= offset.x;
        result = 1;
    }
    if ((rect.top + offset.y < 0) ||
    (rect.top + rect.height + offset.y > MAP_H)) {
        game->character->pos.y -= offset.y;
        result = 1;
    }
    return (result);
}

int check_color_collision(sfVector2f pos, game_t *game, sfVector2f offset)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(game->character->sprite);

    if (check_map_limit(rect, game, offset))
        return (1);
    rect.top = pos.y;
    rect.left = pos.x;
    rect.top += (rect.height / 4) * 3;
    rect.height -= (rect.height / 4) * 3;
    for (int i = rect.top; i < (rect.top + rect.height); i++) {
        if (check_color_line(game, i, rect)) {
            game->character->pos.y -= offset.y * game->loop_time / 1000000;
            game->character->pos.x -= offset.x * game->loop_time / 1000000;
            return (1);
        }
    }
    return (0);
}

int check_enemies_color_coll(sfVector2f pos, game_t *game, sfVector2f offset,
enemy_t *enemy)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(enemy->sprite);

    if (check_map_limit(rect, game, offset))
        return (1);
    rect.top = pos.y;
    rect.left = pos.x;
    rect.top += (rect.height / 4) * 3;
    rect.height -= (rect.height / 4) * 3;
    for (int i = rect.top; i < (rect.top + rect.height); i++) {
        if (check_color_line(game, i, rect)) {
            pos.y -= offset.y * game->loop_time / 1000000;
            pos.x -= offset.x * game->loop_time / 1000000;
            sfSprite_setPosition(enemy->sprite, pos);
            return (1);
        }
    }
    return (0);
}
