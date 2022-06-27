/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** buttons
*/

#include <stdlib.h>
#include "my_rpg.h"

sfTexture *init_texture(char *path)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    return texture;
}

int check_buttons(buttons_t *button)
{
    if (!button->attack_text || !button->attack_text_h)
        return 84;
    if (!button->rest_text || !button->rest_text_h)
        return 84;
    if (!button->heal_text || !button->heal_text_h)
        return 84;
    button->attack = sfSprite_create();
    button->rest = sfSprite_create();
    button->heal = sfSprite_create();
    return 0;
}

buttons_t *init_buttons(void)
{
    buttons_t *buttons = malloc(sizeof(buttons_t));
    if (!buttons)
        return NULL;
    buttons->attack_text = init_texture("assets/sprite/fight/attack.png");
    buttons->attack_text_h = init_texture("assets/sprite/fight/attack_h.png");
    buttons->rest_text = init_texture("assets/sprite/fight/rest.png");
    buttons->rest_text_h = init_texture("assets/sprite/fight/rest_h.png");
    buttons->heal_text = init_texture("assets/sprite/fight/heal.png");
    buttons->heal_text_h = init_texture("assets/sprite/fight/heal_h.png");
    if (check_buttons(buttons) == 84)
        return NULL;
    sfSprite_setTexture(buttons->attack, buttons->attack_text, sfTrue);
    sfSprite_setTexture(buttons->heal, buttons->heal_text, sfTrue);
    sfSprite_setTexture(buttons->rest, buttons->rest_text, sfTrue);
    sfSprite_setPosition(buttons->attack, (sfVector2f) {428, 928});
    sfSprite_setPosition(buttons->rest, (sfVector2f) {776, 928});
    sfSprite_setPosition(buttons->heal, (sfVector2f) {1139, 928});
    return buttons;
}
