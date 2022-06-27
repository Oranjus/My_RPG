/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** update_story
*/

#include "save.h"
#include "my_rpg.h"
#include "my.h"

void update_story(game_t *game)
{
    fight_t *fight = game->fight_system->fight;
    int check_merchant = my_strcmp(fight->opponent->name, "wizard");
    int check_bridge = my_strcmp(fight->opponent->name, "knight");
    int check_demon = my_strcmp(fight->opponent->name, "demon");
    if (game->fight_system->win == 1 && check_bridge == 0) {
        game->story->save = REPAIRED;
        game->fight_system->win = -1;
        save_progression(game);
    }
    if (game->fight_system->win == 1 && check_merchant == 0) {
        game->story->save = WIZARD_BEATEN;
        game->fight_system->win = -1;
        save_progression(game);
    }
    if (game->fight_system->win == 1 && check_demon == 0) {
        game->story->save = FINISHED;
        game->fight_system->win = -1;
        save_progression(game);
    }
    return;
}
