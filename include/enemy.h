/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** enemy
*/

#ifndef ENEMY_H_
    #define ENEMY_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Time.h>
    #include <SFML/Audio.h>

enum e_status {
    E_IDDLE,
    E_TOP,
    E_BOTTOM,
    E_RIGHT,
    E_LEFT
};

typedef struct enemy {
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    int life;
    int is_hit;
    sfClock *respawn;
    enum e_status status;
    struct enemy *next;
} enemy_t;

typedef struct all_enemies {
    enemy_t *enemy;
    sfClock *clock;
} all_enemies_t;

enemy_t *init_enemies(game_t *game);
void display_enemies(game_t *game);
all_enemies_t *init_all_enemies(game_t *game);
void anime_enemies_iddle(enemy_t *enemy);
void anime_enemies_top(enemy_t *enemy);
void anime_enemies_bottom(enemy_t *enemy);
void anime_enemies_right(enemy_t *enemy);
void anime_enemies_left(enemy_t *enemy);
void move_enemy(enemy_t *enemy, game_t *game);
void check_enemies_respawn(enemy_t *enemy);
game_t *reset_enemies(game_t *game);

#endif /* !ENEMY_H_ */
