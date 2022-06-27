/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** rest
*/

#include "my_rpg.h"

game_t *handle_rest(game_t *game)
{
    fight_t *fight = game->fight_system->fight;
    fight->character->force += fight->character->force_save / 2;
    if (fight->character->force > fight->character->force_save)
        fight->character->force = fight->character->force_save;
    sfSprite_setColor(fight->character->sprite, sfYellow);
    return game;
}
