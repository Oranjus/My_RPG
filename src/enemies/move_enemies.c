/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** move_enemies
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

void set_enemy_move(enemy_t *enemy, game_t *game, sfVector2f offset)
{
    sfVector2f pos = sfSprite_getPosition(enemy->sprite);
    collision_t *collision = game->collisions;
    pnj_t *pnj = game->pnj_list;

    pos.x += offset.x * game->loop_time / 1000000;
    pos.y += offset.y * game->loop_time / 1000000;
    while (collision != NULL) {
        if (is_enemy_coll(enemy->sprite, collision, pos))
            return;
        collision = collision->next;
    }
    while (pnj != NULL) {
        if (is_enemy_coll_pnj(enemy->sprite, pnj, pos))
            return;
        pnj = pnj->next;
    }
    if (!check_enemies_color_coll(pos, game, offset, enemy))
        sfSprite_setPosition(enemy->sprite, pos);
}

void move_enemy(enemy_t *enemy, game_t *game)
{
    if (enemy->is_hit)
        return;
    switch (enemy->status) {
        case E_LEFT:
            set_enemy_move(enemy, game, (sfVector2f){-140, 0});
            break;
        case E_RIGHT:
            set_enemy_move(enemy, game, (sfVector2f){140, 0});
            break;
        case E_TOP:
            set_enemy_move(enemy, game, (sfVector2f){0, 140});
            break;
        case E_BOTTOM:
            set_enemy_move(enemy, game, (sfVector2f){0, -140});
            break;
        default:
            break;
    }
}
