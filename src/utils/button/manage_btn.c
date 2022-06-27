/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-lucas.brahimi
** File description:
** manage_btn
*/

#include "button.h"

void change_sprite_btn(sfSprite *sprite, sfVector2f pos, sfIntRect size)
{
    sfSprite_setTextureRect(sprite, size);
    sfSprite_setPosition(sprite, pos);
}

int reset_btn(button_t *button_obj)
{
    sfSprite_setPosition(button_obj->button, button_obj->position);
    sfSprite_setTextureRect(button_obj->button, button_obj->size);
    button_obj->method_event = button_obj->method_event_reset;
    return 0;
}

int appear_btn(button_t *button_obj)
{
    sfVector2f pos = sfSprite_getPosition(button_obj->button);
    sfSprite_setPosition(button_obj->button,
    (sfVector2f){pos.x + 4000, pos.y});
    return 0;
}

int disapear_btn(button_t *button_obj)
{
    sfVector2f pos = sfSprite_getPosition(button_obj->button);
    sfSprite_setPosition(button_obj->button,
    (sfVector2f){pos.x - 4000, pos.y});
    return 0;
}

int foreach_btn(int (*func)(button_t *), button_t *btn)
{
    int exec = 0;

    while (btn != NULL && !exec) {
        exec = func(btn);
        btn = btn->next;
    }
    return exec;
}
