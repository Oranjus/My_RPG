/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** free
*/

#ifndef FREE_H_
    #define FREE_H_
    #include "my_rpg.h"

void free_menu(game_t *game);
void free_game(game_t *game);
void free_btn_list(button_t *btn);
void free_hud(game_t *game);
void free_inventory(game_t *game);
void free_pnj(game_t *game);
void free_collision(game_t *game);
void free_decoration(game_t *game);
void free_enemies(game_t *game);
void free_fight(game_t *game);
void free_particles(game_t *game);

#endif /* !FREE_H_ */
