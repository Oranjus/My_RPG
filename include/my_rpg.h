/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** my_world
*/

#ifndef MY_RPG_H_
    #define MY_RPG_H_
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Text.h>
    #include <SFML/Graphics/Text.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Time.h>
    #include <SFML/Audio.h>
    #include "character.h"
    #include "particles.h"
    #include "collision.h"
    #include "button.h"
    #include "fight.h"
    #include "menu.h"
    #include "hud.h"
    #include "pnj.h"
    #include "enemy.h"
    #include "story.h"
    #include "inventory.h"
    #define SEED 8156089
    #define HASH 107278

enum gamestate {
    GS_PLAY,
    GS_MENU,
    GS_FIGHT,
    GS_PAUSE,
    GS_LOAD,
    GS_INVENTORY
};

typedef struct musics {
    sfMusic *song_menu;
} musics_t;

typedef struct secondary_texture {
    sfTexture *pnj;
    sfTexture *enemy;
} sec_texture_t;

typedef struct stat_s {
    float health;
    float health_max;
    float stamina;
    float stamina_max;
    float strenght;
    float atk;
    float atk_max;
} stat_t;

typedef struct game {
    enum gamestate state;
    sfImage *map_coll;
    sfTexture *texture;
    sec_texture_t *sec_texture;
    sfView *view;
    sfSprite *bg;
    sfRenderWindow *window;
    musics_t *musics;
    character_t *character;
    menu_t *menu;
    hud_t *hud;
    inventory_t *inventory;
    pnj_t *pnj_list;
    sfSprite *frame;
    collision_t *collisions;
    decoration_t *deco;
    sfClock *inter;
    all_enemies_t *enemies;
    fight_system_t *fight_system;
    float loop_time;
    particles_t *particles;
    story_t *story;
    stat_t stat;
} game_t;

//init
game_t *init_game(game_t *game);
sfSprite *init_bg(game_t *game);

sfRenderWindow *create_window(sfVideoMode md, char *name);
void window_icon(game_t *game);
void draw_2d_map(game_t *game);
musics_t *init_game_musics(void);
void get_input(game_t *game, sfEvent event);

void event_handler(game_t *game);
int game_loop(game_t *game);

int quit_game(game_t *game);

int display_usage(void);

void update_character(game_t *game);

void display_bg(game_t *game);

sfView *init_view(game_t *game);
game_t *move_view(game_t *game);

sfVector2f check_collision(sfSprite *player, sfIntRect o_b, game_t *game);
int check_color_collision(sfVector2f pos, game_t *game, sfVector2f offset);
int check_enemies_color_coll(sfVector2f pos, game_t *game, sfVector2f offset,
enemy_t *enemy);
void set_char_pos(game_t *game, enum direction dir, sfVector2f offset);

void set_direction(game_t *game, sfKeyCode key);

char *int_to_char(int nb);

pnj_t *add_to_pnj_list(pnj_t *list, char **fcontent, game_t *game);
int is_pnj_coll(sfSprite *player, pnj_t *collision, game_t *game);
double get_pnj_distance(sfFloatRect player, sfFloatRect npa);
game_t *pnj_interaction(game_t *game);
int is_collision(sfSprite *player, collision_t *collision, game_t *game);
int check_fight_collision(game_t *game);
game_t *start_dialogue(game_t *game, pnj_t *pnj);
int is_enemy_coll(sfSprite *enemy, collision_t *collision, sfVector2f pos);
int is_enemy_coll_pnj(sfSprite *enemy, pnj_t *collision, sfVector2f pos);
game_t *start_fight_wizard(game_t *game, pnj_t *pnj);
game_t *start_fight_knight(game_t *game, pnj_t *pnj);
game_t *start_fight_demon(game_t *game, pnj_t *pnj);
void check_start_fight(game_t *game);

sec_texture_t *init_sec_texture(game_t *game);
sfTexture *init_texture(char *path);

sfText *init_text(fight_overlay_t *overlay, sfVector2f pos);

void move_particles(game_t *game);
void display_foot_particles(game_t *game);
void update_foot_particles(game_t *game);
particles_t *create_foot_particle_list(character_t *character);
void update_foot_particles(game_t *game);
int check_files(void);

void display_particles(game_t *game);
void display_game_object(order display, game_t *game, order pnj);

game_t *update_stats(game_t *game);
void reload_stats(game_t *game);
void update_char_stats(game_t *game);

void reset_character(game_t *game);
int start_new_game(game_t *game);

#endif /* !MY_RPG_H_ */
