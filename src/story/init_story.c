/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** init_story
*/

#include <stdlib.h>
#include "my_rpg.h"

story_t *init_story(void)
{
    story_t *story = malloc(sizeof(story_t));
    sfVector2f pos = {2208, 6480};
    char *path = "assets/sprite/bridge.png";

    if (story == NULL)
        return NULL;
    story->save = START;
    story->bridge = sfSprite_create();
    story->bridge_texture = sfTexture_createFromFile(path, NULL);
    if (!story->bridge_texture || !story->bridge)
        return NULL;
    sfSprite_setTexture(story->bridge, story->bridge_texture, sfTrue);
    sfSprite_setPosition(story->bridge, pos);
    return story;
}
