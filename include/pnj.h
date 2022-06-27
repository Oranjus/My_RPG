/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** pnj
*/

#ifndef PNJ_H_
    #define PNJ_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Time.h>
    #include <SFML/Audio.h>

typedef struct pnj {
    sfVector2f pos;
    char **dialogue;
    sfSprite *sprite;
    sfIntRect rect;
    char *name;
    sfSprite *interact;
    int index;
    int can_interact;
    game_t *(*action) (game_t *game, struct pnj *pnj);
    struct pnj *next;
} pnj_t;

int get_tab_size(char **fcontent);
pnj_t *init_pnj(game_t *game);
int check_file_name(char *name);
char **open_file(char *filepath);
void free_tab(char **fcontent);
void display_pnj(game_t *game);
void display_dialogue(char *str, game_t *game);
void change_interact_value(pnj_t *pnj, char *name, int value);
void check_interaction(game_t *game);

#endif /* !PNJ_H_ */
