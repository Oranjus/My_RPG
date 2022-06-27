/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** init_enemies
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

enemy_t *add_to_enemy_list(int x, int y, enemy_t *list, sfTexture *texture)
{
    enemy_t *element = malloc(sizeof(enemy_t));
    element->pos = (sfVector2f) {x, y};
    element->sprite = sfSprite_create();
    element->rect = (sfIntRect) {249, 6, 48, 75};
    element->status = E_IDDLE;
    element->life = 2;
    element->is_hit = 0;
    element->respawn = sfClock_create();
    sfSprite_setPosition(element->sprite, element->pos);
    sfSprite_setTexture(element->sprite, texture, sfTrue);
    sfSprite_setTextureRect(element->sprite, element->rect);
    element->next = list;
    return (element);
}

enemy_t *init_enemies(game_t *game)
{
    char **fcontent = open_file("assets/enemy/enemies.conf");
    sfTexture *txt = sfTexture_createFromFile("assets/sprite/enemy.png", NULL);
    enemy_t *list = NULL;
    char **buffer = NULL;
    int x = 0;
    int y = 0;
    int i = 0;

    game->sec_texture->enemy = txt;
    while (fcontent[i] != NULL) {
        buffer = my_str_to_word_array(fcontent[i], " \n");
        x = my_getnbr(buffer[0]);
        y = my_getnbr(buffer[1]);
        list = add_to_enemy_list(x, y, list, txt);
        free_tab(buffer);
        i++;
    }
    return (list);
}

all_enemies_t *init_all_enemies(game_t *game)
{
    all_enemies_t *all_enemies = malloc(sizeof(all_enemies_t));
    all_enemies->enemy = init_enemies(game);
    all_enemies->clock = sfClock_create();
    return (all_enemies);
}
