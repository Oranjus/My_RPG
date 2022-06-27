/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** free_fight
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_rpg.h"
#include "save.h"
#include "free.h"

void free_fighter(fighter_t *fighter)
{
    if (fighter->sprite)
        sfSprite_destroy(fighter->sprite);
}

void free_all_fighter(all_fighters_t *all_fighter)
{
    free_fighter(all_fighter->character);
    free_fighter(all_fighter->demon);
    free_fighter(all_fighter->knight);
    free_fighter(all_fighter->wizard);
    if (all_fighter)
        free(all_fighter);
}

void free_buttons(buttons_t *buttons)
{
    sfSprite_destroy(buttons->attack);
    sfSprite_destroy(buttons->rest);
    sfSprite_destroy(buttons->heal);
    sfTexture_destroy(buttons->attack_text);
    sfTexture_destroy(buttons->attack_text_h);
    sfTexture_destroy(buttons->rest_text);
    sfTexture_destroy(buttons->rest_text_h);
    sfTexture_destroy(buttons->heal_text);
    sfTexture_destroy(buttons->heal_text_h);
    if (buttons)
        free(buttons);
}

void free_overlay(fight_overlay_t *fight_overlay)
{
    sfSprite_destroy(fight_overlay->stats_bar);
    sfSprite_destroy(fight_overlay->label);
    sfSprite_destroy(fight_overlay->health_bg);
    sfTexture_destroy(fight_overlay->stats_bar_text);
    sfTexture_destroy(fight_overlay->power_label_text);
    sfText_destroy(fight_overlay->health);
    sfText_destroy(fight_overlay->power);
    sfFont_destroy(fight_overlay->font);
    sfRectangleShape_destroy(fight_overlay->health_bar);
    sfRectangleShape_destroy(fight_overlay->power_bar);
    sfRectangleShape_destroy(fight_overlay->health_ennemy);
    free_buttons(fight_overlay->buttons);
    if (fight_overlay)
        free(fight_overlay);
}

void free_fight(game_t *game)
{
    sfSprite_destroy(game->fight_system->bg);
    sfTexture_destroy(game->fight_system->bg_text);
    sfText_destroy(game->fight_system->feed);
    sfClock_destroy(game->fight_system->delay);
    free_all_fighter(game->fight_system->fighters_list);
    if (game->fight_system->fight)
        free(game->fight_system->fight);
    free_overlay(game->fight_system->overlay);
    if (game->fight_system)
        free(game->fight_system);
}
