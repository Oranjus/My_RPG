/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** opponent
*/

#include <stdlib.h>
#include "my_rpg.h"

game_t *opponent_action(game_t *game)
{
    fight_t *fight = game->fight_system->fight;
    fighter_t *opp = fight->opponent;
    float proba_heal = (1 - ((float) opp->hp / (float) opp->hp_save)) * 60;
    int rand_choice = rand() % 100 + 1;
    sfSprite_setColor(fight->character->sprite, sfWhite);
    sfSprite_setColor(fight->opponent->sprite, sfWhite);
    if (rand_choice < proba_heal) {
        fight->opponent->hp += fight->opponent->hp_save / 3;
        sfSprite_setColor(fight->opponent->sprite, sfGreen);
        sfText_setString(game->fight_system->feed, "The enemy is healing");
    }
    if (rand_choice >= proba_heal) {
        fight->character->hp -= fight->opponent->atk - fight->character->def;
        sfSprite_setColor(fight->character->sprite, sfRed);
        sfText_setString(game->fight_system->feed, "The enemy attacks");
    }
    game->fight_system->waiting = 0;
    sfClock_restart(game->fight_system->delay);
    return game;
}
