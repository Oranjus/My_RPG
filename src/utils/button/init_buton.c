/*
** EPITECH PROJECT, 2022
** dev_menu
** File description:
** init_buton
*/

#include <stdlib.h>
#include "button.h"

static button_t *init_button(sfVector2f position,
sfIntRect size, int (*method_event)(game_t *))
{
    button_t *out_btn = malloc(sizeof(button_t));
    sfVector2f scale = {BTN_SCALE, BTN_SCALE};

    out_btn->position = position;
    out_btn->size = size;
    out_btn->method_event = method_event;
    out_btn->method_event_reset = method_event;
    out_btn->button = init_sprite(out_btn->position, out_btn->size,
        BTN_FILEPATH);
    sfSprite_setScale(out_btn->button, scale);
    return out_btn;
}

void add_btn(button_t **head, sfVector2f position,
sfIntRect size, int (*method_event)(game_t *))
{
    button_t *new_node = init_button(position, size, method_event);
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    button_t *curr = *head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new_node;
}

int destroy_btn(button_t *button_list)
{
    button_t *tmp;

    while (button_list != NULL) {
        tmp = button_list;
        sfSprite_destroy(button_list->button);
        free(button_list);
        button_list = tmp->next;
    }
    if (button_list == NULL)
        return 0;
    else
        return 84;
}
