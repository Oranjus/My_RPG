/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** action
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "pnj.h"
#include "my.h"

int dialogue_event(pnj_t *pnj, game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->inter);
    int is_enough_time = time.microseconds >= 300000;
    if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue && is_enough_time) {
        sfClock_restart(game->inter);
        pnj->index++;
        return (1);
    }
    return (0);
}

game_t *start_fight_wizard(game_t *game, pnj_t *pnj)
{
    fight_system_t *system = game->fight_system;

    system->waiting = 0;
    system->fight->opponent = system->fighters_list->wizard;
    if (game->story->save >= WIZARD_BEATEN)
        return game;
    start_dialogue(game, pnj);
    game->fight_system->start_fight = 1;
    return (game);
}

game_t *start_fight_demon(game_t *game, pnj_t *pnj)
{
    fight_system_t *system = game->fight_system;

    system->waiting = 0;
    system->fight->opponent = system->fighters_list->demon;
    if (game->story->save >= FINISHED)
        return game;
    start_dialogue(game, pnj);
    game->fight_system->start_fight = 1;
    return (game);
}

game_t *start_fight_knight(game_t *game, pnj_t *pnj)
{
    fight_system_t *system = game->fight_system;

    system->waiting = 0;
    system->fight->opponent = system->fighters_list->knight;
    if (game->story->save >= REPAIRED)
        return game;
    start_dialogue(game, pnj);
    game->fight_system->start_fight = 1;
    return (game);
}

game_t *start_dialogue(game_t *game, pnj_t *pnj)
{
    item_t *item_list = game->inventory->item_list;
    character_t *character = game->character;

    if (my_strcmp(pnj->name, "bertrand") == 0 && game->story->save < 1)
        return game;
    if (my_strcmp(pnj->name, "bertrand") == 0 && character->interaction != 2) {
        game->stat.health = game->stat.health_max;
        add_item(&item_list, game->inventory->slot, (item_stat_t){33, 0, 20});
    }
    game->character->interaction = INTERACT;
    dialogue_event(pnj, game);
    if (pnj->dialogue[pnj->index] == NULL) {
        pnj->index = 0;
        game->character->interaction = INTERACTED;
    }
    return (game);
}
