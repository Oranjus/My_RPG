/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** listen_event
*/

#include "my_rpg.h"

static int exec_btn_method(sfVector2f pos_onclick, game_t *game_asset,
button_t *button_obj)
{
    if (check_hitbox(button_obj->button, pos_onclick)
    && button_obj->method_event != NULL) {
        button_obj->method_event(game_asset);
        return 1;
    } else {
        return 0;
    }
}

static int foreach_btn_complex(int (*func)(sfVector2f, game_t *, button_t *),
sfVector2f pos_onclick, button_t *btn, game_t *game)
{
    int exec = 0;

    while (btn != NULL && !exec) {
        exec = func(pos_onclick, game, btn);
        btn = btn->next;
    }
    return exec;
}

static int anim_btn_over(sfVector2f pos_onclick, game_t *game,
button_t *button)
{
    game = game;
    sfIntRect rect = sfSprite_getTextureRect(button->button);
    sfVector2f pos = sfSprite_getPosition(button->button);
    int offset_anim = -2;

    int state = check_hitbox(button->button, pos_onclick);

    if ((button->position.y == pos.y) && state) {
        pos.y += offset_anim;
        rect.left = rect.width + 1;
    } else {
        if (!state && pos.y == button->position.y + offset_anim) {
            pos.y -= offset_anim;
            rect.left -= rect.width + 1;
        }
    }
    sfSprite_setPosition(button->button, pos);
    sfSprite_setTextureRect(button->button, rect);
    return 0;
}

static int exec_btn_click(sfVector2f pos_onclick, game_t *game,
button_t *button)
{
    game = game;
    sfIntRect rect = sfSprite_getTextureRect(button->button);
    sfVector2f pos = sfSprite_getPosition(button->button);

    int state = check_hitbox(button->button, pos_onclick);
    if (state == 1 && rect.width == BTN_W)
        rect.left = rect.width * 2;
    sfSprite_setPosition(button->button, pos);
    sfSprite_setTextureRect(button->button, rect);
    return 0;
}

int manage_event_btn(sfEvent event, game_t *game, button_t *root)
{
    sfVector2i pos_click_tmp = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f pos_clic = {pos_click_tmp.x, pos_click_tmp.y};

    switch (event.type) {
        case sfEvtMouseButtonReleased:
            return foreach_btn_complex(*exec_btn_method, pos_clic, root, game);
        case sfEvtMouseButtonPressed:
            return foreach_btn_complex(*exec_btn_click, pos_clic, root, game);
        case sfEvtMouseMoved:
            return foreach_btn_complex(*anim_btn_over, pos_clic, root, game);
        default:
            return 0;
    }
}
