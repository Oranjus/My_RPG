/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** init_view
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

sfView *init_view(game_t *game)
{
    sfVector2u size = sfRenderWindow_getSize(game->window);
    sfFloatRect rect = sfSprite_getGlobalBounds(game->character->sprite);
    sfVector2f pos = {2370 + (rect.width / 2), 1220 + (rect.height / 2)};
    sfView *view = sfView_create();
    sfView_setSize(view, (sfVector2f) {size.x, size.y});
    sfView_setCenter(view, pos);
    return (view);
}
