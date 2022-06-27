/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** init_fight_system
*/

#include <stdlib.h>
#include "my_rpg.h"

all_fighters_t *init_fighters_list(void)
{
    all_fighters_t *list = malloc(sizeof(all_fighters_t));

    if (list == NULL)
        return NULL;
    list = create_fighters(list);
    if (list == NULL)
        return NULL;
    return list;
}

sfText *init_text(fight_overlay_t *overlay, sfVector2f pos)
{
    sfText *text = sfText_create();
    sfText_setFont(text, overlay->font);
    sfText_setCharacterSize(text, 15);
    sfText_setOutlineThickness(text, 1);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setColor(text, sfWhite);
    sfText_setPosition(text, pos);
    return text;
}

fight_overlay_t *init_fight_overlay(void)
{
    fight_overlay_t *overlay = malloc(sizeof(fight_overlay_t));
    sfTexture *text = init_texture("assets/sprite/fight/bg_health.png");

    if (!overlay || !text)
        return NULL;
    overlay = create_overlay_text(overlay);
    overlay = create_overlay_bars(overlay);
    if (!overlay)
        return NULL;
    overlay->buttons = init_buttons();
    overlay->health_bg = sfSprite_create();
    if (!overlay->health_bg || !overlay->buttons)
        return NULL;
    sfSprite_setTexture(overlay->health_bg, text, sfTrue);
    sfSprite_setPosition(overlay->health_bg, (sfVector2f) {626, 53});
    return overlay;
}

void init_misc_fight(fight_system_t *fight_system)
{
    sfVector2f text_pos = {1537, 962};

    fight_system->waiting = 0;
    fight_system->feed = init_text(fight_system->overlay, text_pos);
    sfText_setString(fight_system->feed, "");
    fight_system->delay = sfClock_create();
    fight_system->start_fight = 0;
    fight_system->win = -1;
    return;
}

fight_system_t *init_fight_system(game_t *game)
{
    fight_system_t *fight_system = malloc(sizeof(fight_system_t));
    sfVector2u size = sfRenderWindow_getSize(game->window);
    char *bg_path = "assets/sprite/fight/bg.png";
    fight_system->fighters_list = init_fighters_list();
    fight_system->fight = malloc(sizeof(fight_t));
    if (!fight_system->fighters_list || !fight_system->fight)
        return NULL;
    fight_system->fight_rect = (sfFloatRect) {0, 0, size.x, size.y};
    fight_system->fight->character = fight_system->fighters_list->character;
    fight_system->fight->opponent = fight_system->fighters_list->wizard;
    fight_system->bg = sfSprite_create();
    fight_system->bg_text = sfTexture_createFromFile(bg_path, NULL);
    if (!fight_system->bg_text || !fight_system->bg)
        return NULL;
    sfSprite_setTexture(fight_system->bg, fight_system->bg_text, sfTrue);
    fight_system->overlay = init_fight_overlay();
    if (!fight_system->overlay)
        return NULL;
    init_misc_fight(fight_system);
    return fight_system;
}
