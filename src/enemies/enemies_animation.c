/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** enemies_animation
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

void anime_enemies_iddle(enemy_t *enemy)
{
    enemy->rect.top = 6;
    if (enemy->rect.left < 249)
        enemy->rect.left = 249;
    enemy->rect.left += 51;
    if (enemy->rect.left > 402)
        enemy->rect.left = 249;
    return;
}

void anime_enemies_right(enemy_t *enemy)
{
    enemy->rect.top = 159;
    enemy->rect.left += 51;
    if (enemy->rect.left > 156)
        enemy->rect.left = 0;
    return;
}

void anime_enemies_left(enemy_t *enemy)
{
    enemy->rect.top = 84;
    enemy->rect.left += 51;
    if (enemy->rect.left > 156)
        enemy->rect.left = 0;
    return;
}

void anime_enemies_top(enemy_t *enemy)
{
    enemy->rect.top = 0;
    enemy->rect.left += 51;
    if (enemy->rect.left > 156)
        enemy->rect.left = 0;
    return;
}

void anime_enemies_bottom(enemy_t *enemy)
{
    enemy->rect.top = 234;
    enemy->rect.left += 51;
    if (enemy->rect.left > 156)
        enemy->rect.left = 0;
    return;
}
