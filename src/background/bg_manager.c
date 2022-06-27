/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** bg_manager
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_rpg.h"
#include "my.h"

sfSprite *init_bg(game_t *game)
{
    sfSprite *bg = sfSprite_create();

    sfSprite_setTexture(bg, game->texture, sfTrue);
    sfSprite_setPosition(bg, (sfVector2f) {0, 0});
    return (bg);
}

void display_bg(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->bg, NULL);
}
