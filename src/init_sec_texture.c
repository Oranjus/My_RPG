/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** init_sec_texture
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_rpg.h"

sec_texture_t *init_sec_texture(game_t *game)
{
    game = game;
    sec_texture_t *text = malloc(sizeof(sec_texture_t));
    text->pnj = sfTexture_createFromFile("assets/sprite/pnj.png", NULL);
    return (text);
}
