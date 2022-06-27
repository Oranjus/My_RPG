/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** dialogue_manager
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
#include "pnj.h"

sfText *create_dialog_text(game_t *game, char *str, sfVector2f pos)
{
    sfFloatRect rect;
    sfColor color = sfColor_fromRGB(230, 230, 230);
    sfText *text = sfText_create();
    sfText_setFont(text, game->fight_system->overlay->font);
    sfText_setCharacterSize(text, 14);
    sfText_setString(text, str);
    sfText_setColor(text, color);
    rect = sfText_getGlobalBounds(text);
    pos.x += 413 - (rect.width / 2);
    pos.y += 27;
    sfText_setPosition(text, pos);
    return (text);
}

void display_dialogue(char *str, game_t *game)
{
    sfSprite *box = sfSprite_create();
    sfVector2f size = sfView_getSize(game->view);
    sfVector2f pos = sfView_getCenter(game->view);
    sfText *text = NULL;
    pos.x = (pos.x - (size.x / 2) + 547);
    pos.y = (pos.y + (size.y / 2)) - 91;
    text = create_dialog_text(game, str, pos);
    sfSprite_setTexture(box, game->sec_texture->pnj, sfTrue);
    sfSprite_setTextureRect(box, (sfIntRect) {0, 432, 826, 75});
    sfSprite_setPosition(box, pos);
    sfRenderWindow_drawSprite(game->window, box, NULL);
    sfRenderWindow_drawText(game->window, text, NULL);
    sfSprite_destroy(box);
    sfText_destroy(text);
}
