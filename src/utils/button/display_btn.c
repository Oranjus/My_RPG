/*
** EPITECH PROJECT, 2022
** dev_menu
** File description:
** display_btn
*/

#include "button.h"

void display_btn(sfRenderWindow *window, button_t *button_list)
{
    while (button_list != NULL) {
        sfRenderWindow_drawSprite(window, button_list->button, NULL);
        button_list = button_list->next;
    }
}
