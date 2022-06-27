/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** update_stats
*/

#include "my_rpg.h"

game_t *update_stats(game_t *game)
{
    game->stat.health = game->fight_system->fight->character->hp;
    game->stat.health_max = game->fight_system->fight->character->hp_save;
    game->stat.stamina = game->fight_system->fight->character->force;
    game->stat.stamina_max = game->fight_system->fight->character->force_save;
    game->stat.strenght = game->fight_system->fight->character->def;
    game->stat.atk = game->fight_system->fight->character->atk;
    game->stat.atk_max = game->fight_system->fight->character->atk;
    return game;
}

void reload_stats(game_t *game)
{
    game->fight_system->fight->character->hp = game->stat.health;
    game->fight_system->fight->character->hp_save = game->stat.health_max;
    game->fight_system->fight->character->force = game->stat.stamina;
    game->fight_system->fight->character->force_save = game->stat.stamina_max;
    game->fight_system->fight->character->def = game->stat.strenght;
    game->fight_system->fight->character->atk = game->stat.atk;
    return;
}
