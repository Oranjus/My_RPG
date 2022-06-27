/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** move_slider
*/

#include <stdio.h>
#include "button.h"

static float get_pourcentage_bar(sfVector2f next_pos, sfVector2f limit_bar)
{
    return (next_pos.x - limit_bar.x) / (limit_bar.y - limit_bar.x);
}

static int change_value(float prctg_bar, sfVector2f range, int *value)
{
    float range_ = range.y - range.x;
    *value = range_ * prctg_bar;
    return 1;
}

static int can_move(sfVector2f cursor_pos, sfSprite *slider_s, \
sfSprite *bar, slider_t *slider)
{
    sfIntRect rect = sfSprite_getTextureRect(bar);
    sfVector2f limit_size = sfSprite_getPosition(bar);
    limit_size = (sfVector2f){limit_size.x - rect.width / 2,
        limit_size.x + rect.width / 2};

    if (limit_size.x > cursor_pos.x || cursor_pos.x > limit_size.y)
        return 0;

    change_value(get_pourcentage_bar(cursor_pos, limit_size),
    slider->range, slider->ptr_value);

    sfSprite_setPosition(slider_s,
    (sfVector2f){cursor_pos.x, sfSprite_getPosition(slider_s).y});
    return 1;
}

int move_slider(sfVector2f cursor_pos, slider_t *slider)
{
    if (slider->is_clicked == false)
        return 0;
    can_move(cursor_pos, slider->slider, slider->bar, slider);
    return 0;
}
