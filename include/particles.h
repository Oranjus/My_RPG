/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** particles
*/

#ifndef PARTICLES_H_
    #define PARTICLES_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window/Types.h>

typedef struct particle {
    sfVertexArray *particles;
    sfVector2f start_position;
    sfVector2f actual;
    struct particle *next;
    int size;
} particles_t;

particles_t *move_particle(particles_t *node, sfColor color);
particles_t *create_particle_list(void);
particles_t *restart_particle(particles_t *node, sfColor color);
sfVertexArray *create_particle(sfVector2f p1, sfColor color, int size);

#endif /* !PARTICLES_H_ */
