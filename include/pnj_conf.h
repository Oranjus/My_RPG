/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** pnj_conf
*/

#ifndef PNJ_CONF_H_
    #define PNJ_CONF_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Time.h>
    #include <SFML/Audio.h>

typedef struct pnj_conf {
    sfIntRect rect;
    int offset;
} pnj_conf_t;

pnj_conf_t pnj_conf[] = {
    {(sfIntRect) {0, 0, 144, 168}, 110},
    {(sfIntRect) {144, 0, 144, 168}, 110},
    {(sfIntRect) {288, 0, 144, 168}, 110},
    {(sfIntRect) {432, 0, 144, 168}, 110},
    {(sfIntRect) {0, 192, 144, 168}, 110},
    {(sfIntRect) {144, 192, 144, 168}, 110},
    {(sfIntRect) {288, 192, 144, 168}, 110},
    {(sfIntRect) {432, 192, 144, 168}, 110},
    {(sfIntRect) {576, 0, 60, 87}, 69}, //wizard
    {(sfIntRect) {636, 0, 48, 78}, 66}, //knight
    {(sfIntRect) {684, 0, 48, 87}, 66}, //archer
    {(sfIntRect) {732, 0, 51, 81}, 66}, //demon
};

#endif /* !PNJ_CONF_H_ */
