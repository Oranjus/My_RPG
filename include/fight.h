/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** fight
*/

#ifndef FIGHT_H_
    #define FIGHT_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window/Types.h>

typedef struct fighter {
    sfSprite *sprite;
    sfTexture *texture;
    char *name;
    int atk;
    int def;
    int hp;
    int hp_save;
    int force;
    int force_save;
} fighter_t;

typedef struct all_fighters {
    fighter_t *character;
    fighter_t *wizard;
    fighter_t *knight;
    fighter_t *demon;
} all_fighters_t;

typedef struct fight {
    fighter_t *character;
    fighter_t *opponent;
} fight_t;

typedef struct buttons {
    sfSprite *attack;
    sfTexture *attack_text;
    sfTexture *attack_text_h;
    sfSprite *rest;
    sfTexture *rest_text;
    sfTexture *rest_text_h;
    sfSprite *heal;
    sfTexture *heal_text;
    sfTexture *heal_text_h;
} buttons_t;

typedef struct overlay {
    sfSprite *stats_bar;
    sfSprite *label;
    sfTexture *stats_bar_text;
    sfTexture *power_label_text;
    sfRectangleShape *health_bar;
    sfRectangleShape *power_bar;
    sfSprite *health_bg;
    sfRectangleShape *health_ennemy;
    sfText *health;
    sfText *power;
    sfFont *font;
    buttons_t *buttons;
} fight_overlay_t;

typedef struct fight_system {
    all_fighters_t *fighters_list;
    fight_t *fight;
    sfFloatRect fight_rect;
    sfSprite *bg;
    sfTexture *bg_text;
    sfText *feed;
    fight_overlay_t *overlay;
    sfClock *delay;
    int waiting;
    int win;
    int start_fight;
} fight_system_t;

fight_system_t *init_fight_system(game_t *game);
int fight_loop(game_t *game);
buttons_t *init_buttons(void);
int fight_event_handler(game_t *game);
int handle_attack(game_t *game);
game_t *opponent_action(game_t *game);
game_t *handle_rest(game_t *game);
int handle_heal(game_t *game);
fighter_t *init_opponent_fight(void);
fighter_t *init_character_fight(void);
fight_overlay_t *create_overlay_bars(fight_overlay_t *overlay);
fight_overlay_t *create_overlay_text(fight_overlay_t *overlay);
all_fighters_t *create_fighters(all_fighters_t *list);

#endif /* !FIGHT_H_ */
