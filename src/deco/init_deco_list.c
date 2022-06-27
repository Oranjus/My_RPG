/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** inti_deco_list
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my.h"

sfSprite *create_deco(sfIntRect rect, sfTexture *text)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, text, sfFalse);
    sfSprite_setTextureRect(sprite, rect);
    return sprite;
}

decoration_t *create_items(int j, char *buffer, \
decoration_t *deco, sfTexture *text)
{
    int data[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    char **info = my_str_to_word_array(buffer, " ");
    for (int i = 0; i < 8; i++)
        data[i] = my_getnbr(info[i]);
    sfIntRect rect = {data[0], data[1], data[2], data[3]};
    deco->sprite[j] = create_deco(rect, text);
    deco->rect[j] = (sfIntRect) {data[4], data[5], data[6], data[7]};
    for (int i = 0; info[i] != NULL; i++)
        free(info[i]);
    free(info);
    return deco;
}

decoration_t *init_deco_list(void)
{
    decoration_t *deco = malloc(sizeof(decoration_t));
    char *buffer = malloc(sizeof(char) * 100);
    FILE *file = fopen("assets/data/list_items.txt", "r");
    sfTexture *text = sfTexture_createFromFile("assets/sprite/deco.png", NULL);
    size_t len = 1;
    int j = 0;
    if (file == NULL || text == NULL)
        return NULL;
    deco->sprite = malloc(sizeof(sfSprite *) * 30);
    deco->rect = malloc(sizeof(sfIntRect) * 30);
    if (file == NULL)
        return NULL;
    getline(&buffer, &len, file);
    while (getline(&buffer, &len, file) != -1) {
        deco = create_items(j, buffer, deco, text);
        j++;
    }
    return deco;
}
