/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** check_collision
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

double get_abs(double nb)
{
    if (nb < 0)
        return (-1 * nb);
    return (nb);
}

enum coll_side get_direction(double dx, double dy, double width, double height)
{
    double offset_w = get_abs(width) - get_abs(dx);
    double offset_h = get_abs(height) - get_abs(dy);
    if (offset_h < offset_w) {
        if (dy < 0)
            return (HAUT);
        else
            return (BAS);
    } else {
        if (dx < 0)
            return (GAUCHE);
        else
            return (DROITE);
    }
}

sfVector2f place_player(sfSprite *player, enum coll_side side, sfVector2f off)
{
    sfVector2f pos = sfSprite_getPosition(player);
    switch (side) {
    case HAUT:
        pos.y += off.y;
        break;
    case BAS:
        pos.y -= off.y;
        break;
    case GAUCHE:
        pos.x += off.x;
        break;
    default:
        pos.x -= off.x;
        break;
    }
    return (pos);
}

sfVector2f get_offset(sfFloatRect p_b, sfIntRect o_b)
{
    sfVector2f pos;
    if (p_b.left < o_b.left)
        pos.x = (p_b.left + p_b.width) - o_b.left;
    else
        pos.x = (o_b.left + o_b.width) - p_b.left;
    if (p_b.top < o_b.top)
        pos.y = (p_b.top + p_b.height) - o_b.top;
    else
        pos.y = (o_b.top + o_b.height) - p_b.top;
    return pos;
}

sfVector2f check_collision(sfSprite *player, sfIntRect o_b, game_t *game)
{
    sfFloatRect p_b = sfSprite_getGlobalBounds(player);
    sfVector2f pos = {p_b.left, p_b.top};

    if (o_b.top == 6588 && o_b.left == 2205 && game->story->save >= REPAIRED)
        return pos;
    p_b.top += (p_b.height / 4) * 3;
    p_b.height -= (p_b.height / 4) * 3;
    double dx = (o_b.left + (o_b.width / 2)) - (p_b.left + (p_b.width / 2));
    double dy = (o_b.top + (o_b.height / 2)) - (p_b.top + (p_b.height / 2));
    double width = (p_b.width + o_b.width) / 2;
    double height = (p_b.height + o_b.height) / 2;
    enum coll_side direction;

    if (get_abs(dx) <= width && get_abs(dy) <= height) {
        direction = get_direction(dx, dy, width, height);
        pos = place_player(player, direction, get_offset(p_b, o_b));
        return (pos);
    }
    return (pos);
}
