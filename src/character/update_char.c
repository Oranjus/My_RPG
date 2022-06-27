/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** update_char
*/

#include "my_rpg.h"

void anim_character_iddle(character_t *character)
{
    if (sfClock_getElapsedTime(character->clock).microseconds < 190000)
        return;
    sfClock_restart(character->clock);
    if (character->rect.left >= (72 + (character->rect.width)) * 3)
        character->rect.left = 72 * 3;
    else
        character->rect.left += character->rect.width;
    return;
}

void anim_character_run(character_t *character)
{
    if (sfClock_getElapsedTime(character->clock).microseconds < 170000)
        return;
    sfClock_restart(character->clock);
    if (character->rect.left >= (character->rect.width) * 3)
        character->rect.left = 0;
    else
        character->rect.left += character->rect.width;
    return;
}

void attack_loop(character_t *character)
{
    if (sfClock_getElapsedTime(character->clock).microseconds < 100000)
        return;
    sfClock_restart(character->clock);
    if (character->rect.left == 0) {
        character->pos.x -= 21;
        character->pos.y -= 29;
    }
    if (character->rect.left > (character->rect.width) * 2) {
        character->state = IDDLE;
        character->rect.left = 0;
        character->rect.width = 18 * 3;
        character->rect.height = 27 * 3;
        sfSprite_setTextureRect(character->sprite, character->rect);
        character->pos.x += 21;
        character->pos.y += 29;
        return;
    } else
        character->rect.left += character->rect.width;
    sfSprite_setTextureRect(character->sprite, character->rect);
}

void anim_character_attack(character_t *character, int dir)
{
    character->rect.width = 96;
    character->rect.height = 138;
    if (dir == DOWN)
        character->rect.top = 780;
    if (dir == UP)
        character->rect.top = 1194;
    if (dir == LEFT)
        character->rect.top = 918;
    if (dir == RIGHT)
        character->rect.top = 1056;
    attack_loop(character);
}

void update_character(game_t *game)
{
    character_t *character = game->character;
    int dir = character->direction;

    if (game->character->state == DIE) {
        death_char(game->character);
        return;
    }
    if (game->character->state == ATTACK) {
        anim_character_attack(game->character, dir);
        return;
    }
    if (game->character->state == IDDLE)
        anim_character_iddle(game->character);
    if (game->character->state == RUN)
        anim_character_run(game->character);
    update_char_dir(game->character);
    sfSprite_setTextureRect(character->sprite, character->rect);
    return;
}
