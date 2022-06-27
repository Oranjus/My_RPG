/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** check_enemies_respawn
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

void check_enemies_respawn(enemy_t *enemy)
{
    int elapsed = 0;

    while (enemy != NULL) {
        elapsed = sfClock_getElapsedTime(enemy->respawn).microseconds;
        if (enemy->life == 0) {
            sfSprite_setPosition(enemy->sprite, enemy->pos);
            enemy->life = -1;
            sfClock_restart(enemy->respawn);
        }
        if (enemy->life == -1 && elapsed > 1200000000) {
            enemy->life = 2;
        }
        enemy = enemy->next;
    }
}
