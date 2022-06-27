/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** save_coord
*/

#ifndef SAVE_COORD_H_
    #define SAVE_COORD_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Time.h>
    #include "my_rpg.h"

typedef struct spawn_coord {
    enum save save;
    sfVector2f pos;
} spawn_t;

const spawn_t coord[] = {
    {START, (sfVector2f) {5653, 6096}},
    {WIZARD_BEATEN, (sfVector2f) {4982, 1237}},
    {REPAIRED, (sfVector2f) {1067, 2241}},
    {FINISHED, (sfVector2f) {1172, 6760}}
};
#endif /* !SAVE_COORD_H_ */
