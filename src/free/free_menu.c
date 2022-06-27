/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** free_menu
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_rpg.h"
#include "save.h"

void free_btn_list(button_t *btn)
{
    while (btn != NULL) {
        sfSprite_destroy(btn->button);
        btn = btn->next;
    }
}

void free_slider_list(slider_t *slider)
{
    while (slider != NULL) {
        sfSprite_destroy(slider->slider);
        sfSprite_destroy(slider->bar);
        slider = slider->next;
    }
}

void free_struct(game_t *game)
{
    if (game->menu->settings->slider_list)
        free(game->menu->settings->slider_list);
    if (game->menu->settings)
        free(game->menu->settings);
    if (game->menu->save)
        free(game->menu->save);
    if (game->menu->help)
        free(game->menu->help);
}

void free_menu(game_t *game)
{
    sfClock_destroy(game->menu->clock);
    free_btn_list(game->menu->btn_list);
    if (game->menu->btn_list)
        free(game->menu->btn_list);
    sfView_destroy(game->menu->view);
    sfView_destroy(game->menu->static_view);
    sfSprite_destroy(game->menu->bg);
    sfSprite_destroy(game->menu->settings->bg);
    sfSprite_destroy(game->menu->help->bg);
    free_btn_list(game->menu->settings->btn_list);
    free_btn_list(game->menu->save->btn_list);
    free_btn_list(game->menu->help->btn_list);
    free_slider_list(game->menu->settings->slider_list);
    free_struct(game);
}
