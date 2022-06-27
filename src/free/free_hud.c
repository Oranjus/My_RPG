/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** free_hud
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

void free_hud(game_t *game)
{
    sfSprite_destroy(game->hud->head);
    sfSprite_destroy(game->hud->bar_energy);
    sfSprite_destroy(game->hud->bar_health);
    sfSprite_destroy(game->hud->bar_inventory);
    sfSprite_destroy(game->hud->container_bar);
    sfText_destroy(game->hud->pop_msg);
    free_btn_list(game->hud->btn_list);
    if (game->hud->btn_list)
        free(game->hud->btn_list);
    if (game->hud)
        free(game->hud);
}
