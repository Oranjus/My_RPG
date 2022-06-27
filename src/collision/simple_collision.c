/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** simple_collision
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

int check_position(sfFloatRect player, sfIntRect coll, game_t *game)
{
    float offset = 250 * game->loop_time / 1000000;
    if ((player.top + player.height) > (coll.top + offset))
        return (1);
    return (-1);
}

int is_enemy_coll_pnj(sfSprite *enemy, pnj_t *collision, sfVector2f pos)
{
    if (collision->sprite == NULL)
        return (0);
    sfFloatRect p = sfSprite_getGlobalBounds(enemy);
    sfFloatRect o = sfSprite_getGlobalBounds(collision->sprite);
    p.left = pos.x;
    p.top = pos.y;
    p.top += (p.height / 4) * 3;
    p.height -= (p.height / 4) * 3;
    if (((p.left + p.width) >= o.left) && (p.left <= (o.left + o.width))) {
        if (((p.top + p.height) >= o.top) && (p.top <= (o.top + o.height))) {
            return (1);
        }
    }
    return (0);
}

int is_enemy_coll(sfSprite *enemy, collision_t *collision, sfVector2f pos)
{
    if (collision->sprite == NULL)
        return (0);
    sfFloatRect p = sfSprite_getGlobalBounds(enemy);
    sfFloatRect o = sfSprite_getGlobalBounds(collision->sprite);
    p.left = pos.x;
    p.top = pos.y;
    p.top += (p.height / 4) * 3;
    p.height -= (p.height / 4) * 3;
    if (((p.left + p.width) >= o.left) && (p.left <= (o.left + o.width))) {
        if (((p.top + p.height) >= o.top) && (p.top <= (o.top + o.height))) {
            return (1);
        }
    }
    return (0);
}

int is_pnj_coll(sfSprite *player, pnj_t *collision, game_t *game)
{
    if (collision->sprite == NULL)
        return (0);
    sfFloatRect p = sfSprite_getGlobalBounds(player);
    sfFloatRect o = sfSprite_getGlobalBounds(collision->sprite);

    if (my_strcmp(collision->name, "bertrand") == 0 && game->story->save < 1)
        return (0);
    p.top += (p.height / 4) * 3;
    p.height -= (p.height / 4) * 3;
    if (((p.left + p.width) >= o.left) && (p.left <= (o.left + o.width))) {
        if (((p.top + p.height) >= o.top) && (p.top <= (o.top + o.height))) {
            return (check_position(p, collision->rect, game));
        }
    }
    return (0);
}

int is_collision(sfSprite *player, collision_t *collision, game_t *game)
{
    if (collision->sprite == NULL)
        return (0);
    sfFloatRect p = sfSprite_getGlobalBounds(player);
    sfFloatRect o = sfSprite_getGlobalBounds(collision->sprite);
    p.top += (p.height / 4) * 3;
    p.height -= (p.height / 4) * 3;
    if (((p.left + p.width) >= o.left) && (p.left <= (o.left + o.width))) {
        if (((p.top + p.height) >= o.top) && (p.top <= (o.top + o.height))) {
            return (check_position(p, collision->rect, game));
        }
    }
    return (0);
}
