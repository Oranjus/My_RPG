/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** heal
*/

#include "my_rpg.h"

int handle_heal(game_t *game)
{
    int save = 0;
    fight_t *fight = game->fight_system->fight;
    fighter_t *character = fight->character;
    if (character->force < (character->hp_save - character->hp) / 2) {
        character->hp += character->force * 2;
        character->force = 0;
        sfSprite_setColor(character->sprite, sfGreen);
        return 1;
    }
    if (fight->character->force == 0)
        return 0;
    save = character->hp;
    character->hp = character->hp_save;
    character->force -= (character->hp_save - save) / 2;
    sfSprite_setColor(character->sprite, sfGreen);
    return 1;
}
