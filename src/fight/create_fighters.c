/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** create_fighters
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_rpg.h"
#include "my.h"

int *get_int_array(char **info, int len)
{
    int *result = malloc(sizeof(int) * len);

    for (int i = 0; i < len; i++) {
        result[i] = my_getnbr(info[i]);
        free(info[i]);
    }
    free(info);
    return result;
}

fighter_t *create_fighter(const char *buf, sfTexture *text, \
char *name, sfVector2f pos)
{
    fighter_t *fighter = malloc(sizeof(fighter_t));
    int *info = get_int_array(my_str_to_word_array(buf, " "), 8);
    if (!fighter || !info)
        return NULL;
    sfIntRect rect = {info[4], info[5], info[6], info[7]};
    fighter->sprite = sfSprite_create();
    fighter->texture = text;
    if (!fighter->texture || !fighter->sprite)
        return NULL;
    sfSprite_setTexture(fighter->sprite, fighter->texture, sfTrue);
    sfSprite_setTextureRect(fighter->sprite, rect);
    fighter->name = name;
    fighter->atk = info[0];
    fighter->def = info[1];
    fighter->hp = info[2];
    fighter->hp_save = info[2];
    fighter->force = info[3];
    fighter->force_save = info[3];
    sfSprite_setPosition(fighter->sprite, pos);
    return fighter;
}

void start_fighters(all_fighters_t *list, FILE *fp, char *buffer, \
sfTexture *char_text)
{
    sfVector2f pos_char = {500, 449};
    sfVector2f pos_op = {1420, 449};
    size_t len = 0;

    len = getline(&buffer, &len, fp);
    len = getline(&buffer, &len, fp);
    list->character = create_fighter(buffer, char_text, "character", pos_char);
    len = getline(&buffer, &len, fp);
    list->knight = create_fighter(buffer, char_text, "knight", pos_op);
    len = getline(&buffer, &len, fp);
    list->wizard = create_fighter(buffer, char_text, "wizard", pos_op);
    len = getline(&buffer, &len, fp);
    list->demon = create_fighter(buffer, char_text, "demon", pos_op);
}

all_fighters_t *create_fighters(all_fighters_t *list)
{
    char *path = "assets/sprite/fight/fighters.png";
    sfTexture *char_text = sfTexture_createFromFile(path, sfFalse);
    char *buffer = malloc(sizeof(char) * 100);
    FILE *fp = fopen("assets/data/fighters.txt", "r");

    if (fp == NULL || buffer == NULL)
        return NULL;
    start_fighters(list, fp, buffer, char_text);
    if (!list->character || !list->knight || !list->wizard || !list->demon)
        return NULL;
    return list;
}
