/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** hud
*/

#include "my_rpg.h"

void display_hud(game_t *game)
{
    sfRenderWindow_setView(game->window, game->menu->static_view);
    sfRenderWindow_drawSprite(game->window, game->hud->head, NULL);
    sfRenderWindow_drawSprite(game->window, game->hud->bar_health, NULL);
    sfRenderWindow_drawSprite(game->window, game->hud->bar_energy, NULL);
    sfRenderWindow_drawSprite(game->window, game->hud->container_bar, NULL);
    sfRenderWindow_drawSprite(game->window, game->hud->bar_inventory, NULL);
    display_btn(game->window, game->hud->btn_list);
    if (game->hud->cool_down_pop > 0)
        sfRenderWindow_drawText(game->window, game->hud->pop_msg, NULL);
    sfRenderWindow_setView(game->window, game->view);
}

void pop_up_text(char *message, int time, game_t *game)
{
    sfVector2f center = {910, 540};

    sfText_setString(game->hud->pop_msg, message);
    sfFloatRect rect = sfText_getLocalBounds(game->hud->pop_msg);
    center.x -= rect.width / 2;
    center.y -= rect.height / 2;
    sfText_setPosition(game->hud->pop_msg, center);
    game->hud->cool_down_pop = time;
}
