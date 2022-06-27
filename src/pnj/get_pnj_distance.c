/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** get_distance
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "my_rpg.h"
#include "my.h"
#include "pnj.h"

double get_pnj_distance(sfFloatRect player, sfFloatRect npa)
{
    double x_p = (player.left + (player.width / 2));
    double y_p = (player.top + (player.height / 2));
    double x_n = (npa.left + (npa.width / 2));
    double y_n = (npa.top + (npa.height / 2));
    double f_term = get_abs(x_p - x_n);
    double s_term = get_abs(y_p - y_n);

    f_term *= f_term;
    s_term *= s_term;
    double distance = sqrt(f_term + s_term);
    return (distance);
}

game_t *check_for_interaction(game_t *game, pnj_t *pnj)
{
    if (game->character->interaction == FREE)
        game->character->interaction = TARGET;
    if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue) {
        sfClock_restart(game->inter);
        game = pnj->action(game, pnj);
        return (game);
    }
    return (game);
}

game_t *check_all_interaction(game_t *game, pnj_t *list)
{
    sfFloatRect player = sfSprite_getGlobalBounds(game->character->sprite);
    sfFloatRect pnj = sfSprite_getGlobalBounds(list->sprite);
    enum interaction inter = game->character->interaction;
    int start_inter = inter != INTERACT && inter != INTERACTED;
    double dis = get_pnj_distance(player, pnj);

    if (list->can_interact == 0)
        return (game);
    if ((dis < 120) && start_inter) {
        sfRenderWindow_drawSprite(game->window, list->interact, NULL);
        game = check_for_interaction(game, list);
        return (game);
    } else if (dis < 120 && inter == INTERACT) {
        display_dialogue(list->dialogue[list->index], game);
        game = list->action(game, list);
        return (game);
    }
    return (game);
}

game_t *pnj_interaction(game_t *game)
{
    pnj_t *list = game->pnj_list;
    sfFloatRect player = sfSprite_getGlobalBounds(game->character->sprite);
    sfFloatRect pnj = sfSprite_getGlobalBounds(list->sprite);
    int check = 0;

    while (list != NULL) {
        pnj = sfSprite_getGlobalBounds(list->sprite);
        game = check_all_interaction(game, list);
        if (get_pnj_distance(player, pnj) <= 120)
            check++;
        list = list->next;
    }
    if (check == 0 && game->character->interaction == INTERACTED)
        game->character->interaction = FREE;
    return (game);
}
