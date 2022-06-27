/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** load_sprite
*/

#include "my_rpg.h"

sfSprite *init_sprite(sfVector2f pos, sfIntRect size, char *filepath)
{
    sfSprite *sprite = sfSprite_create();

    if (size.width != 0)
        sfSprite_setOrigin(sprite,
        (sfVector2f){size.width / 2, size.height / 2});
    sfSprite_setTexture(sprite,
    sfTexture_createFromFile(filepath, NULL), sfTrue);
    if (size.left != -1)
        sfSprite_setTextureRect(sprite, size);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}

int check_hitbox(sfSprite *sprite, sfVector2f pos_onclick)
{
    sfFloatRect hitbox = sfSprite_getGlobalBounds(sprite);

    if ((pos_onclick.x > hitbox.left) &&
    (pos_onclick.x < (hitbox.left + hitbox.width))) {
        if ((pos_onclick.y > hitbox.top) &&
        (pos_onclick.y < (hitbox.top + hitbox.height))) {
            return 1;
        }
    }
    return 0;
}
