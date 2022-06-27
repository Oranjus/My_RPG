/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** fight_collision
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

int is_enemy_hit(sfFloatRect p, sfFloatRect e)
{
    if (((p.left + p.width) >= e.left) && (p.left <= (e.left + e.width))) {
        if (((p.top + p.height) >= e.top) && (p.top <= (e.top + e.height))) {
            return (1);
        }
    }
    return (0);
}

int update_enemy_stats(enemy_t *enemy)
{
    int elapsed = sfClock_getElapsedTime(enemy->respawn).microseconds;
    enemy->is_hit = 1;
    sfSprite_setColor(enemy->sprite, sfColor_fromRGB(190, 110, 106));
    if ((elapsed < 1000000))
        return (1);
    sfClock_restart(enemy->respawn);
    enemy->life -= 1;
    enemy->is_hit = 0;
    return 0;
}

int update_player_stats(character_t *character, game_t *game, enemy_t *enemy)
{
    int elapsed = sfClock_getElapsedTime(character->hit).microseconds;
    character->is_hit = 1;
    sfSprite_setColor(character->sprite, sfColor_fromRGB(190, 110, 106));
    if (elapsed < 1000000)
        return (1);
    sfClock_restart(character->hit);
    game->stat.health -= 2;
    character->is_hit = 0;
    enemy->is_hit = 1;
    return 0;
}

int update_sprites(game_t *game, sfFloatRect p_rect, enemy_t *enemy)
{
    sfFloatRect e_rect = sfSprite_getGlobalBounds(enemy->sprite);
    int is_hit = is_enemy_hit(p_rect, e_rect);
    if (is_hit && game->character->state == ATTACK) {
        update_enemy_stats(enemy);
        return (1);
    } else if (is_hit && !game->character->is_hit) {
        update_player_stats(game->character, game, enemy);
    } else {
        sfSprite_setColor(enemy->sprite, sfWhite);
        sfSprite_setColor(game->character->sprite, sfWhite);
        if (sfClock_getElapsedTime(enemy->respawn).microseconds > 1000000)
            enemy->is_hit = 0;
        if (sfClock_getElapsedTime(game->character->hit).microseconds >
        1000000)
            game->character->is_hit = 0;
    }
    return (0);
}

int check_fight_collision(game_t *game)
{
    sfSprite *player = game->character->sprite;
    enemy_t *enemy = game->enemies->enemy;
    sfFloatRect p_rect = sfSprite_getGlobalBounds(player);

    if (game->character->state == DIE)
        return (0);
    while (enemy != NULL) {
        if (enemy->life <= 0) {
            enemy = enemy->next;
            continue;
        }
        if (update_sprites(game, p_rect, enemy))
            return (1);
        enemy = enemy->next;
    }
    return (0);
}
