/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** free_game
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_rpg.h"
#include "save.h"
#include "free.h"

void free_sec_texture(game_t *game)
{
    sfTexture_destroy(game->sec_texture->enemy);
    sfTexture_destroy(game->sec_texture->pnj);
    if (game->sec_texture)
        free(game->sec_texture);
}

void free_character(game_t *game)
{
    particles_t *particules = game->character->foot_particles;
    sfTexture_destroy(game->character->texture);
    sfSprite_destroy(game->character->sprite);
    sfClock_destroy(game->character->clock);
    sfClock_destroy(game->character->stamina);
    sfClock_destroy(game->character->move);
    sfClock_destroy(game->character->delay);
    sfClock_destroy(game->character->hit);
    while (particules != NULL) {
        sfVertexArray_destroy(particules->particles);
        particules = particules->next;
    }
    if (game->character->foot_particles)
        free(game->character->foot_particles);
}

void free_remaining_struct(game_t *game)
{
    if (game->character)
        free(game->character);
    if (game->menu)
        free(game->menu);
    if (game->inventory)
        free(game->inventory);
}

void free_story(game_t *game)
{
    sfSprite_destroy(game->story->bridge);
    sfTexture_destroy(game->story->bridge_texture);
    if (game->story)
        free(game->story);
}

void free_game(game_t *game)
{
    sfImage_destroy(game->map_coll);
    sfTexture_destroy(game->texture);
    free_sec_texture(game);
    sfView_destroy(game->view);
    sfSprite_destroy(game->bg);
    sfRenderWindow_destroy(game->window);
    free_character(game);
    free_menu(game);
    free_inventory(game);
    free_pnj(game);
    sfMusic_destroy(game->musics->song_menu);
    free_decoration(game);
    sfClock_destroy(game->inter);
    free_enemies(game);
    free_remaining_struct(game);
    free_fight(game);
    free_particles(game);
    free_story(game);
    if (game)
        free(game);
}
