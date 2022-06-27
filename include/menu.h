/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_

typedef enum {
    MENU_SC,
    SETTINGS_SC,
    SAVE_SC,
    HELP_SC,
    SCORE_SC
} menu_state;

typedef struct menu_stat_s {
    int volume;
    int frame_rate;
    int scale;
    int speed_left;
    int speed_right;
} menu_stat_t;

typedef struct settings_menu_s {
    sfSprite *bg;
    button_t *btn_list;
    slider_t *slider_list;
} settings_menu_t;

typedef struct save_menu_s {
    sfSprite *bg;
    button_t *btn_list;
} save_menu_t;

typedef struct help_menu_s {
    sfSprite *bg;
    button_t *btn_list;
} help_menu_t;

typedef struct menu {
    menu_state sc_menu;
    sfClock *clock;
    button_t *btn_list;
    sfView *view;
    sfView *static_view;
    sfSprite *bg;
    sfVector2f move_v;
    settings_menu_t *settings;
    save_menu_t *save;
    help_menu_t *help;
    struct menu_stat_s stat;
} menu_t;

//init_menu
menu_t *init_menu(game_t *game);

//choose menu
int menu_loop(game_t *game);
//pause loop
void pause_loop(game_t *game);

//menu_loop
int menu_main_loop(game_t *game);
void move_view_menu(game_t *game);

//settings loop
int settings_loop(game_t *game);
settings_menu_t *load_settings(sfVector2u W_size, menu_t *menu);

//save_loop
int save_loop(game_t *game);
save_menu_t *load_save_m(sfVector2u W_size, menu_t *menu);

//help_loop
int help_loop(game_t *game);
help_menu_t *load_help_m(sfVector2u W_size, menu_t *menu);

//set_scene
void choose_menu(menu_t *menu);

//method_btn
int launch_game(game_t *game);
int go_to_settings(game_t *game);
int go_to_save(game_t *game);
int go_back_scene(game_t *game);
int go_to_help(game_t *game);

#endif /* !MENU_H_ */
