/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** free_particles
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_rpg.h"
#include "save.h"

void free_particles(game_t *game)
{
    while (game->particles != NULL) {
        sfVertexArray_destroy(game->particles->particles);
        game->particles = game->particles->next;
    }
    if (game->particles)
        free(game->particles);
}
