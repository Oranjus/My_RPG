/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** move_particles
*/

#include <stdlib.h>
#include <math.h>
#include "my_rpg.h"

void display_particles(game_t *game)
{
    particles_t *save = game->particles;

    while (save != NULL) {
        sfRenderWindow_drawVertexArray(game->window, save->particles, NULL);
        save = save->next;
    }
    return;
}

int calc_distance(sfVector2f p1, sfVector2f p2)
{
    int dist1 = (p1.x - p2.x) * (p1.x - p2.x);
    int dist2 = (p1.y - p2.y) * (p1.y - p2.y);
    int res = sqrt(dist1 + dist2);
    return res;
}

particles_t *recreate_foot_particle(particles_t *list, game_t *game)
{
    sfColor color = sfColor_fromRGBA(0, 0, 0, 100);
    sfFloatRect rect = sfSprite_getGlobalBounds(game->character->sprite);
    float x = rect.left + 3 + (rand() % 51);
    sfVector2f vect1 = (sfVector2f) {x, rect.top + 60 + (rand() % 18)};

    sfVertexArray_destroy(list->particles);
    list->start_position = vect1;
    list->actual = vect1;
    list->particles = create_particle(vect1, color, 3);
    return list;
}

void update_foot_particles(game_t *game)
{
    particles_t *list = game->character->foot_particles;
    sfFloatRect lim = sfSprite_getGlobalBounds(game->character->sprite);
    sfVector2f middle = {lim.left + 9, lim.top + 3};

    while (list != NULL) {
        if (calc_distance(list->start_position, middle) > 100)
            list = recreate_foot_particle(list, game);
        list = list->next;
    }
    return;
}

void move_particles(game_t *game)
{
    particles_t *list = game->particles;
    particles_t *save = game->particles;
    sfColor color = sfColor_fromRGBA(253, 224, 117, 190);

    while (list != NULL) {
        if (list->actual.x > 0 && list->actual.y < 7679) {
            list = move_particle(list, color);
        } else {
            list = restart_particle(list, color);
        }
        list = list->next;
    }
    game->particles = save;
}
