/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** reset_enemies
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

game_t *reset_enemies(game_t *game)
{
    enemy_t *enemy = game->enemies->enemy;

    while (enemy != NULL) {
        enemy->life = 2;
        enemy->is_hit = 0;
        sfSprite_setPosition(enemy->sprite, enemy->pos);
        enemy = enemy->next;
    }
    return (game);
}
