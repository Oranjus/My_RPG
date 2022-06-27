/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** pnj_list_manager
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "pnj.h"
#include "pnj_conf.h"
#include "action.h"
#include "my.h"

sfIntRect get_rect(sfIntRect rect, int index, sfVector2f pos)
{
    sfIntRect new_rect;
    new_rect.left = pos.x;
    new_rect.top = pos.y;
    new_rect.width = rect.width;
    new_rect.height = rect.height;
    new_rect.top += pnj_conf[index].offset;
    new_rect.height -= pnj_conf[index].offset;
    return (new_rect);
}

sfVector2f get_pos(char *line)
{
    char **fcontent = my_str_to_word_array(line, " ,");
    sfVector2f pos = {my_getnbr(fcontent[0]), my_getnbr(fcontent[1])};
    free_tab(fcontent);
    return (pos);
}

sfSprite *get_pnj_sprite(int index, sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, pnj_conf[index].rect);
    return (sprite);
}

char **get_dialogue(char **fcontent)
{
    int size = get_tab_size(fcontent) - 4;
    char **dialogues = malloc(sizeof(char *) * size);
    int i = 0;

    while (i < size - 1) {
        dialogues[i] = my_strdup(fcontent[i + 5]);
        i++;
    }
    dialogues[size - 1] = NULL;
    return (dialogues);
}

pnj_t *add_to_pnj_list(pnj_t *list, char **fcontent, game_t *game)
{
    pnj_t *el = malloc(sizeof(pnj_t));
    sfVector2f pos;
    int index = my_getnbr(fcontent[1]);
    el->pos = get_pos(fcontent[0]);
    el->sprite = get_pnj_sprite(index, game->sec_texture->pnj);
    sfSprite_setPosition(el->sprite, el->pos);
    el->dialogue = get_dialogue(fcontent);
    el->action = action_ptr_tab[my_getnbr(fcontent[2])].action;
    el->next = list;
    el->rect = get_rect(pnj_conf[index].rect, index, el->pos);
    el->interact = sfSprite_create();
    sfSprite_setTexture(el->interact, game->sec_texture->pnj, sfTrue);
    sfSprite_setTextureRect(el->interact, (sfIntRect) {0, 366, 84, 57});
    pos.x = el->pos.x + my_getnbr(fcontent[3]);
    pos.y = el->pos.y + my_getnbr(fcontent[4]);
    el->index = 0;
    sfSprite_setPosition(el->interact, pos);
    return (el);
}
