/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** action
*/

#ifndef ACTION_H_
    #define ACTION_H_
    #include <stddef.h>
    #include "my_rpg.h"

typedef struct actions {
    game_t *(*action)(game_t *game, pnj_t *pnj);
}   actions_struct_t;

actions_struct_t action_ptr_tab[] = {
    {&start_dialogue},
    {&start_fight_wizard},
    {&start_fight_knight},
    {&start_fight_demon},
    { NULL}
};

#endif /* !ACTION_H_ */
