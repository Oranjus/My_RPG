/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** button
*/

#ifndef BUTTON_H_
    #define BUTTON_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Time.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>
    #define BTN_FILEPATH "assets/menu/button_full.png"
    #define BTN_SCALE 1.4
    #define BTN_W 266
    #define BTN_H 75
    #define BTN_S_W 82
    #define BTN_S_TOP 591
    #define LEFT_S 320
    #define TOP_S 525
    #define WIDTH_S 57
    #define HEIGHT_S 66
    #define LEFT_BAR 0
    #define TOP_BAR 525
    #define WIDTH_BAR 307
    #define HEIGHT_BAR 44

typedef struct game game_t;

typedef struct button {
    sfVector2f position;
    sfIntRect size;
    int (*method_event)(game_t *);
    int (*method_event_reset)(game_t *);
    struct button *next;
    sfSprite *button;
} button_t;

typedef struct slider {
    sfSprite *slider;
    sfSprite *bar;
    int *ptr_value;
    sfVector2f range;
    sfVector2f position;
    int (*func)(sfVector2f, struct slider *);
    struct slider *next;
    bool is_clicked;
} slider_t;

//btn
void add_btn(button_t **head, sfVector2f position,
    sfIntRect size, int (*method_event)(game_t *));
int destroy_btn(button_t *button_list);
void display_btn(sfRenderWindow *window, button_t *button_list);
void change_sprite_btn(sfSprite *sprite, sfVector2f pos, sfIntRect size);
int manage_event_btn(sfEvent event, game_t *game, button_t *root);

// button action
int appear_btn(button_t *button_obj);
int disapear_btn(button_t *button_obj);
int reset_btn(button_t *button_obj);
int foreach_btn(int (*func)(button_t *), button_t *btn);

//sprite
sfSprite *init_sprite(sfVector2f pos, sfIntRect size, char *filepath);
int check_hitbox(sfSprite *sprite, sfVector2f pos_onclick);

//slider
void add_slider(slider_t **head, sfVector2f position, int *value,
sfVector2f range);
int destroy_slider(slider_t *slider_list);
void display_slider(sfRenderWindow *window, slider_t *slider_list);

int unclick_slider(sfVector2f cursor_pos, slider_t *slider);
int appear_slider(sfVector2f vector, slider_t *slider);
int disappear_slider(sfVector2f vector, slider_t *slider);

int move_slider(sfVector2f cursor_pos, slider_t *slider);
int foreach_slider(int (*func)(sfVector2f, slider_t *),
sfVector2f pos_onclick, slider_t *slider);
int manage_event_slider(sfEvent event, game_t *game, slider_t *slider_list);
#endif /* !BUTTON_H_ */
