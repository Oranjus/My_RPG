/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** create_foot_particles
*/

#include <math.h>
#include <stdlib.h>
#include "my_rpg.h"

void display_foot_particles(game_t *game)
{
    particles_t *list = game->character->foot_particles;

    if (game->character->direction == DOWN || game->character->state == IDDLE)
        return;
    while (list != NULL) {
        sfRenderWindow_drawVertexArray(game->window, list->particles, NULL);
        list = list->next;
    }
    return;
}

particles_t *add_foot_particle_node(particles_t *list, sfColor color, \
character_t *character)
{
    particles_t *new_node = malloc(sizeof(particles_t));
    sfFloatRect rect = sfSprite_getGlobalBounds(character->sprite);
    float x = rect.left + 3 + (rand() % 51);
    sfVector2f vect1 = (sfVector2f) {x, rect.top + 60 + (rand() % 18)};

    new_node->start_position = vect1;
    new_node->actual = vect1;
    new_node->particles = create_particle(vect1, color, 3);
    new_node->next = list;
    return new_node;
}

particles_t *create_foot_particle_list(character_t *character)
{
    particles_t *list = NULL;
    sfColor color = sfColor_fromRGBA(0, 0, 0, 100);

    srand(SEED);
    for (int i = 0; i < 4; i++) {
        list = add_foot_particle_node(list, color, character);
    }
    return list;
}
