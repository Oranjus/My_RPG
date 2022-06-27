/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** slot
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

static sfIntRect *assign_inventory(sfIntRect *rect_list, \
int x_start, int y_start)
{
    int x = 0;
    int y = 0;
    int count = 0;
    for (int i = 0; i < SLOT_NB - 3; x += SLOT_SIZE + SLOT_SPACER,
    count++, i++) {
        if (count >= 4) {
            count = 0;
            x = 0;
            y += SLOT_SIZE + SLOT_SPACER - 8;
        }
        rect_list[i].left += x + x_start;
        rect_list[i].top += y + y_start;
    }
    return rect_list;
}

static sfIntRect *assign_special(sfIntRect *rect_list)
{
    rect_list[SLOT_NB - 3] = (sfIntRect){677, 672, SLOT_SIZE, SLOT_SIZE};
    rect_list[SLOT_NB - 2] = (sfIntRect){752, 672, SLOT_SIZE, SLOT_SIZE};
    rect_list[SLOT_NB - 1] = (sfIntRect){659, 440, 158, 161};
    return rect_list;
}

static sfIntRect *assign_slot(sfIntRect *rect_list)
{
    for (int i = 0; i < SLOT_NB; i++)
        rect_list[i] =
            (sfIntRect){INVENTORY_X, INVENTORY_Y, SLOT_SIZE, SLOT_SIZE};

    return assign_inventory(assign_special(rect_list), 485, 260);
}

sfIntRect *load_slot(void)
{
    sfIntRect *list = malloc(sizeof(sfIntRect) * SLOT_NB);
    list = assign_slot(list);
    return list;
}
