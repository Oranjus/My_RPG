/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** init_char
*/

#include "my.h"
#include "my_rpg.h"

void reset_character(game_t *game)
{
    game->character->state = IDDLE;
    game->stat.health = game->stat.health_max;
    game->stat.stamina = game->stat.stamina_max;
    game->character->rect = (sfIntRect) {72 * 3, 0, 18 * 3, 27 * 3};
    return;
}

void start_clock_char(character_t *character)
{
    character->move = sfClock_create();
    character->clock = sfClock_create();
    character->hit = sfClock_create();
    character->delay = sfClock_create();
    character->stamina = sfClock_create();
    return;
}

character_t *init_character(char *path)
{
    character_t *character = malloc(sizeof(character_t));
    character->rect = (sfIntRect) {72 * 3, 0, 18 * 3, 27 * 3};
    character->pos = (sfVector2f) {5653, 6096};
    character->texture = sfTexture_createFromFile(path, NULL);
    character->sprite = sfSprite_create();
    if (character->texture == NULL || character->sprite == NULL)
        return NULL;
    sfSprite_setTexture(character->sprite, character->texture, sfFalse);
    sfSprite_setTextureRect(character->sprite, character->rect);
    sfSprite_setPosition(character->sprite, character->pos);
    character->state = IDDLE;
    character->direction = UP;
    character->interaction = FREE;
    character->is_hit = 0;
    start_clock_char(character);
    character->foot_particles = create_foot_particle_list(character);
    return character;
}
