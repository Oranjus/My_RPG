/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** save
*/

#ifndef SAVE_H_
    #define SAVE_H_
    #include "my_rpg.h"
int save_progression(game_t *game);
char *nb_to_str(long int nb);
game_t *load_from_save(game_t *game);
int reset_save_progression(void);
#endif /* !SAVE_H_ */
