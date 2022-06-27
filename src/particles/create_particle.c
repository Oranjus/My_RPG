/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** create_particle
*/

#include <stdlib.h>
#include "my_rpg.h"

sfVertexArray *create_particle(sfVector2f p1, sfColor color, int size)
{
    sfVector2f p2 = {p1.x, p1.y + size};
    sfVector2f p3 = {p1.x + size, p1.y + size};
    sfVector2f p4 = {p1.x + size, p1.y};
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = p1, .color = color};
    sfVertex vertex2 = {.position = p2, .color = color};
    sfVertex vertex3 = {.position = p3, .color = color};
    sfVertex vertex4 = {.position = p4, .color = color};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    return (vertex_array);
}

particles_t *restart_particle(particles_t *node, sfColor color)
{
    sfVector2f vect1 = {rand() % 5225, 5189 + (rand() % 1700)};

    node->actual = vect1;
    sfVertexArray_destroy(node->particles);
    node->particles = create_particle(vect1, color, node->size);
    return node;
}

particles_t *move_particle(particles_t *node, sfColor color)
{
    int choice = rand() % 3;
    sfVector2f vect1 = {0, 0};

    if (choice == 0)
        vect1 = (sfVector2f) {node->actual.x - 1, node->actual.y + 1};
    else if (choice == 1)
        vect1 = (sfVector2f) {node->actual.x, node->actual.y + 1};
    else
        vect1 = (sfVector2f) {node->actual.x - 1, node->actual.y};

    node->actual = vect1;
    sfVertexArray_destroy(node->particles);
    node->particles = create_particle(vect1, color, node->size);
    return node;
}

particles_t *add_particle_node(particles_t *list, sfColor color)
{
    particles_t *new_node = malloc(sizeof(particles_t));
    sfVector2f vect1 = (sfVector2f) {rand() % 5225, 5189 + (rand() % 1700)};

    new_node->start_position = vect1;
    new_node->actual = vect1;
    new_node->size = 4 + rand() % 3;
    new_node->particles = create_particle(vect1, color, new_node->size);
    new_node->next = list;
    return new_node;
}

particles_t *create_particle_list(void)
{
    particles_t *list = NULL;
    sfColor color = sfColor_fromRGBA(253, 224, 117, 120);

    srand(SEED);
    for (int i = 0; i < 1000; i++) {
        list = add_particle_node(list, color);
    }
    return list;
}
