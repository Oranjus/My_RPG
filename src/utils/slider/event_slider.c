/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** event_slider
*/

#include "my_rpg.h"

int unclick_slider(sfVector2f cursor_pos, slider_t *slider)
{
    cursor_pos = cursor_pos;
    slider->is_clicked = false;
    return 0;
}

static int exec_slider_method(sfVector2f pos_onclick, slider_t *slider)
{
    if (check_hitbox(slider->slider, pos_onclick)) {
        slider->is_clicked = true;
        return 1;
    } else {
        return 0;
    }
}

int foreach_slider(int (*func)(sfVector2f, slider_t *), \
sfVector2f pos_onclick, slider_t *slider)
{
    int exec = 0;

    while (slider != NULL && !exec) {
        exec = func(pos_onclick, slider);
        slider = slider->next;
    }
    return exec;
}

int manage_event_slider(sfEvent event, game_t *game, slider_t *slider_list)
{
    sfVector2i pos_click_tmp = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f pos_click = {pos_click_tmp.x, pos_click_tmp.y};

    switch (event.type) {
        case sfEvtMouseMoved:
            foreach_slider(*move_slider, pos_click, slider_list);
            break;
        case sfEvtMouseButtonPressed:
            foreach_slider(*exec_slider_method, pos_click, slider_list);
            break;
        case sfEvtMouseButtonReleased:
            foreach_slider(*unclick_slider, pos_click, slider_list);
            break;
        default:
            return 1;
        }
    return 0;
}
