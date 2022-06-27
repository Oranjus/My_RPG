/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** collision
*/

#ifndef COLLISION_H_
    #define COLLISION_H_
    #define MAP_W 6144
    #define MAP_H 7680
    #include <SFML/Graphics.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Time.h>
    #include <SFML/Audio.h>
    #include "my_rpg.h"

typedef enum coll_side {
    HAUT,
    BAS,
    GAUCHE,
    DROITE
} coll_side;

typedef enum display_order {
    FRONT,
    BACK
} order;

typedef struct collisions {
    sfIntRect rect;
    sfRectangleShape *display;
    struct collisions *next;
    sfSprite *sprite;
} collision_t;

typedef struct decorations {
    sfSprite **sprite;
    sfIntRect *rect;
} decoration_t;

sfVector2f place_player(sfSprite *player, enum coll_side side, sfVector2f off);
enum coll_side get_direction(double dx, double dy, double width, \
double height);
double get_abs(double nb);
decoration_t *init_deco_list(void);
collision_t *create_collision_list(decoration_t *deco_list);

#endif /* !COLLISION_H_ */
