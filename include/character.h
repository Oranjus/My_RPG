/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** character
*/

#ifndef CHARACTER_H_
    #define CHARACTER_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Time.h>
    #include <SFML/Audio.h>
    #include "particles.h"

enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

enum state {
    IDDLE,
    RUN,
    DIE,
    DEAD,
    ATTACK
};

enum interaction {
    FREE,
    TARGET,
    INTERACT,
    INTERACTED
};

typedef struct character {
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *clock;
    sfClock *stamina;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *move;
    sfClock *delay;
    int is_hit;
    sfClock *hit;
    enum direction direction;
    enum state state;
    enum interaction interaction;
    particles_t *foot_particles;
} character_t;

character_t *init_character(char *path);
void update_char_dir(character_t *character);
void death_char(character_t *character);

#endif /* !CHARACTER_H_ */
