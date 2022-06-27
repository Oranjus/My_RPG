/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** overlay
*/

#include "my_rpg.h"

fight_overlay_t *init_rects(fight_overlay_t *overlay)
{
    sfRectangleShape *health_bar = sfRectangleShape_create();
    sfRectangleShape *power_bar = sfRectangleShape_create();
    sfRectangleShape *health_ennemy = sfRectangleShape_create();

    if (!health_bar || !power_bar || !health_ennemy)
        return NULL;
    sfRectangleShape_setPosition(health_bar, (sfVector2f) {5, 651});
    sfRectangleShape_setPosition(power_bar, (sfVector2f) {51, 651});
    sfRectangleShape_setPosition(health_ennemy, (sfVector2f) {629, 56});
    sfRectangleShape_setFillColor(health_bar, sfWhite);
    sfRectangleShape_setFillColor(power_bar, sfWhite);
    sfRectangleShape_setFillColor(health_ennemy, sfColor_fromRGB(181, 14, 14));
    sfRectangleShape_setSize(health_bar, (sfVector2f) {40, 0});
    sfRectangleShape_setSize(power_bar, (sfVector2f) {40, 0});
    sfRectangleShape_setSize(health_ennemy, (sfVector2f) {16, 100});
    overlay->health_bar = health_bar;
    overlay->power_bar = power_bar;
    overlay->health_ennemy = health_ennemy;
    return overlay;
}

fight_overlay_t *create_overlay_text(fight_overlay_t *overlay)
{
    overlay->font = sfFont_createFromFile("assets/fonts/PressStart2P.ttf");
    if (!overlay->font)
        return NULL;
    overlay->health = init_text(overlay, (sfVector2f) {0, 1005});
    overlay->power = init_text(overlay, (sfVector2f) {48, 1005});
    if (!overlay->power || !overlay->health)
        return NULL;
    return overlay;
}

fight_overlay_t *create_overlay_bars(fight_overlay_t *overlay)
{
    overlay->stats_bar = sfSprite_create();
    overlay->stats_bar_text = init_texture("assets/sprite/fight/bar_bg.png");
    if (!overlay->stats_bar_text || !overlay->stats_bar)
        return NULL;
    sfSprite_setTexture(overlay->stats_bar, overlay->stats_bar_text, sfTrue);
    sfSprite_setPosition(overlay->stats_bar, (sfVector2f) {0, 646});
    overlay = init_rects(overlay);
    if (!overlay)
        return NULL;
    overlay->label = sfSprite_create();
    overlay->power_label_text = init_texture("assets/sprite/fight/LABEL.png");
    if (!overlay->label || !overlay->power_label_text)
        return NULL;
    sfSprite_setTexture(overlay->label, overlay->power_label_text, sfTrue);
    sfSprite_setPosition(overlay->label, (sfVector2f) {12, 843});
    return overlay;
}
