/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** read_collisions
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "my_rpg.h"

collision_t *add_sprite_node(collision_t *new_el, char **co_info, \
collision_t *list, decoration_t *deco_list)
{
    int id = my_getnbr(co_info[0]);
    sfVector2f pos = {my_getnbr(co_info[1]), my_getnbr(co_info[2])};
    sfIntRect rect = deco_list->rect[id];
    sfRectangleShape *display = sfRectangleShape_create();
    sfVector2f pos_rect = {0, 0};
    sfVector2f size = {0, 0};

    rect.left += my_getnbr(co_info[1]);
    rect.top += my_getnbr(co_info[2]);
    new_el->rect = rect;
    new_el->sprite = sfSprite_copy(deco_list->sprite[id]);
    sfSprite_setPosition(new_el->sprite, pos);
    pos_rect = (sfVector2f) {rect.left, rect.top};
    size = (sfVector2f) {rect.width, rect.height};
    sfRectangleShape_setSize(display, size);
    sfRectangleShape_setPosition(display, pos_rect);
    new_el->display = display;
    new_el->next = list;
    list = new_el;
    return list;
}

collision_t *add_invisible_node(char **co_info, collision_t *list, \
collision_t *new_el, decoration_t *deco_list)
{
    sfRectangleShape *display = sfRectangleShape_create();
    sfVector2f size = {my_getnbr(co_info[2]), my_getnbr(co_info[3])};
    sfVector2f pos = {my_getnbr(co_info[0]), my_getnbr(co_info[1])};
    sfIntRect rect = {pos.x, pos.y, size.x, size.y};
    sfIntRect rect_text = {0, 0, size.x, size.y};

    sfRectangleShape_setSize(display, size);
    sfRectangleShape_setPosition(display, pos);
    new_el->rect = rect;
    new_el->display = display;
    new_el->next = list;
    new_el->sprite = sfSprite_copy(deco_list->sprite[0]);
    sfSprite_setPosition(new_el->sprite, pos);
    sfSprite_setTextureRect(new_el->sprite, rect_text);
    sfSprite_setColor(new_el->sprite, sfColor_fromRGBA(255, 255, 255, 0));
    list = new_el;
    return list;
}

collision_t *add_colli_node(collision_t *list, char *info, \
decoration_t *deco_list)
{
    collision_t *new_el = malloc(sizeof(collision_t));
    char **co_info = my_str_to_word_array(info, " \n");

    if (!co_info || !co_info[0] || !co_info[1] || !co_info[2])
        return NULL;
    if (co_info[3] == NULL) {
        list = add_sprite_node(new_el, co_info, list, deco_list);
        return list;
    }
    list = add_invisible_node(co_info, list, new_el, deco_list);
    return list;
}

collision_t *create_collision_list(decoration_t *deco_list)
{
    FILE *file = fopen("assets/data/info.txt", "r");
    char *buffer = malloc(sizeof(char) * 100);
    if (file == NULL || buffer == NULL)
        return NULL;
    size_t len = 100;
    collision_t *list = NULL;
    while (getline(&buffer, &len, file) != -1) {
        list = add_colli_node(list, buffer, deco_list);
        if (!list)
            return NULL;
    }
    free(buffer);
    return list;
}
