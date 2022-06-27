/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** display_enemies
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "enemy.h"
#include "my.h"

void enemies_animation_handler(enemy_t *enemy)
{
    switch (enemy->status) {
        case E_IDDLE:
            anime_enemies_iddle(enemy);
            break;
        case E_LEFT:
            anime_enemies_left(enemy);
            break;
        case E_RIGHT:
            anime_enemies_right(enemy);
            break;
        case E_TOP:
            anime_enemies_top(enemy);
            break;
        case E_BOTTOM:
            anime_enemies_bottom(enemy);
            break;
        default:
            break;
    }
}

enum e_status get_enemy_dir(enemy_t *enemy, sfFloatRect player)
{
    sfFloatRect e_rect = sfSprite_getGlobalBounds(enemy->sprite);
    double dis = get_pnj_distance(player, e_rect);
    double dx = 0;
    double dy = 0;

    if (dis > 350)
        return (E_IDDLE);
    dx = player.left - e_rect.left;
    dy = player.top - e_rect.top;
    if (get_abs(dx) > get_abs(dy)) {
        if (dx > 0)
            return (E_RIGHT);
        else
            return (E_LEFT);
    } else {
        if (dy > 0)
            return (E_TOP);
        else
            return (E_BOTTOM);
    }
}

void display_enemies(game_t *game)
{
    enemy_t *list = game->enemies->enemy;
    sfClock *clock = game->enemies->clock;
    sfFloatRect player = sfSprite_getGlobalBounds(game->character->sprite);
    while (list != NULL) {
        if (list->life <= 0) {
            list = list->next;
            continue;
        }
        list->status = get_enemy_dir(list, player);
        move_enemy(list, game);
        sfRenderWindow_drawSprite(game->window, list->sprite, NULL);
        if (sfClock_getElapsedTime(clock).microseconds > 220000) {
            enemies_animation_handler(list);
            sfSprite_setTextureRect(list->sprite, list->rect);
        }
        list = list->next;
    }
    if (sfClock_getElapsedTime(clock).microseconds > 220000)
        sfClock_restart(clock);
    return;
}
