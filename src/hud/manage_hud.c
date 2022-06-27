/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** manage_hud
*/

#include "my_rpg.h"

static void make_bar(sfSprite *bar, float health, float max_health, \
int with_bar)
{
    float offset = (health / max_health) * with_bar;
    if (health > max_health || health < 0)
        offset = with_bar;
    sfIntRect rect = sfSprite_getTextureRect(bar);
    rect.width = offset;
    sfSprite_setTextureRect(bar, rect);
}

static int manage_health_hud(game_t *game)
{
    float health_curr = game->stat.health;
    float health_max = game->stat.health_max;
    float stamina_curr = game->stat.stamina;
    float stamina_max = game->stat.stamina_max;
    make_bar(game->hud->bar_health, health_curr, health_max, 425);
    make_bar(game->hud->bar_energy, stamina_curr, stamina_max, 389);
    return 1;
}

static int manage_bar_inventory(sfSprite *bar, int nb_item)
{
    sfIntRect rect = sfSprite_getTextureRect(bar);
    rect.height = nb_item * 10;
    if (nb_item > SLOT_NB)
        return 0;
    sfSprite_setTextureRect(bar, rect);
    return 1;
}

int update_hud(game_t *game)
{
    manage_health_hud(game);
    manage_bar_inventory(game->hud->bar_inventory, 7);
    if (game->hud->cool_down_pop >= 0
    && sfClock_getElapsedTime(game->menu->clock).microseconds > 2000) {
        game->hud->cool_down_pop -= 1;
    }
    return 1;
}
