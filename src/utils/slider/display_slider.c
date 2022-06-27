/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** display_slider
*/

#include "button.h"

void display_slider(sfRenderWindow *window, slider_t *slider_list)
{
    while (slider_list != NULL) {
        sfRenderWindow_drawSprite(window, slider_list->bar, NULL);
        sfRenderWindow_drawSprite(window, slider_list->slider, NULL);
        slider_list = slider_list->next;
    }
}
