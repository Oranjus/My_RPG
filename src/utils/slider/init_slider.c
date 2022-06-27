/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** init_slider
*/

#include <stdlib.h>
#include "button.h"

static slider_t *init_slider(sfVector2f position, int *ptr, sfVector2f range)
{
    slider_t *out_slider = malloc(sizeof(slider_t));
    sfVector2f scale = {BTN_SCALE, BTN_SCALE};
    sfIntRect size_slider = {LEFT_S, TOP_S, WIDTH_S, HEIGHT_S};
    sfIntRect size_bar = {LEFT_BAR, TOP_BAR, WIDTH_BAR, HEIGHT_BAR};
    out_slider->position = position;
    out_slider->range = range;
    out_slider->ptr_value = ptr;
    out_slider->slider = init_sprite(out_slider->position, size_slider,
        BTN_FILEPATH);
    out_slider->bar = init_sprite(out_slider->position, size_bar,
        BTN_FILEPATH);
    sfSprite_setScale(out_slider->slider, scale);
    sfSprite_setScale(out_slider->bar, scale);
    out_slider->func = NULL;
    out_slider->is_clicked = false;
    return out_slider;
}

void add_slider(slider_t **head, sfVector2f position, int *value,
sfVector2f range)
{
    slider_t *new_node = init_slider(position, value, range);
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    slider_t *curr = *head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new_node;
}

int disappear_slider(sfVector2f vector, slider_t *slider)
{
    vector = sfSprite_getPosition(slider->slider);
    vector.x -= 1000;
    sfSprite_setPosition(slider->slider, vector);
    vector = sfSprite_getPosition(slider->bar);
    vector.x -= 1000;
    sfSprite_setPosition(slider->bar, vector);
    return 0;
}

int appear_slider(sfVector2f vector, slider_t *slider)
{
    vector = sfSprite_getPosition(slider->slider);
    vector.x += 1000;
    sfSprite_setPosition(slider->slider, vector);
    vector = sfSprite_getPosition(slider->bar);
    vector.x += 1000;
    sfSprite_setPosition(slider->bar, vector);
    return 0;
}

int destroy_slider(slider_t *slider_list)
{
    slider_t *tmp;

    while (slider_list != NULL) {
        tmp = slider_list->next;
        sfSprite_destroy(slider_list->slider);
        sfSprite_destroy(slider_list->bar);
        free(slider_list);
        slider_list = tmp;
    }
    if (slider_list == NULL)
        return 0;
    else
        return 84;
}
