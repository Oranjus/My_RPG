/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** hud
*/

#ifndef HUD_H_
    #define HUD_H_

typedef struct hud {
    button_t *btn_list;
    sfSprite *head;
    sfSprite *bar_health;
    sfSprite *bar_energy;
    sfSprite *container_bar;
    sfSprite *bar_inventory;
    sfText *pop_msg;
    int cool_down_pop;
} hud_t;

//init
hud_t *init_hud(game_t *game);

//hud
void display_hud(game_t *game);
void pop_up_text(char *message, int time, game_t *game);

//manage hud
int update_hud(game_t *game);

//event
int event_hud_handler(sfEvent event, game_t *game);

//method
int set_pause(game_t *game);
int go_to_menu(game_t *game);

#endif /* !HUD_H_ */
