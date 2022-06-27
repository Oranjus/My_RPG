/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** fight_loop
*/

#include "my_rpg.h"
#include "my.h"

int get_time(sfClock *clock)
{
    return sfClock_getElapsedTime(clock).microseconds / 1000000;
}

game_t *update_bar_size(game_t *game)
{
    fighter_t *character = game->fight_system->fight->character;
    fighter_t *ennemy = game->fight_system->fight->opponent;
    sfRectangleShape *health = game->fight_system->overlay->health_bar;
    sfRectangleShape *power = game->fight_system->overlay->power_bar;
    sfRectangleShape *health_en = game->fight_system->overlay->health_ennemy;
    int offset = 350 - (character->hp * 350 / character->hp_save);

    sfRectangleShape_setSize(health, (sfVector2f) {40, offset});
    offset = 350 - (character->force * 350 / character->force_save);
    sfRectangleShape_setSize(power, (sfVector2f) {40, offset});
    offset = ennemy->hp * 664 / ennemy->hp_save;
    sfRectangleShape_setSize(health_en, (sfVector2f) {offset, 16});
    return game;
}

void draw_all(game_t *game, sfRenderWindow *win)
{
    fight_t *fight = game->fight_system->fight;
    fight_overlay_t *overlay = game->fight_system->overlay;
    buttons_t *buttons = overlay->buttons;
    sfRenderWindow_drawSprite(win, game->fight_system->bg, NULL);
    sfRenderWindow_drawSprite(win, fight->character->sprite, NULL);
    sfRenderWindow_drawSprite(win, fight->opponent->sprite, NULL);
    sfRenderWindow_drawSprite(win, overlay->stats_bar, NULL);
    sfRenderWindow_drawText(win, overlay->health, NULL);
    sfRenderWindow_drawText(win, overlay->power, NULL);
    sfRenderWindow_drawRectangleShape(win, overlay->health_bar, NULL);
    sfRenderWindow_drawRectangleShape(win, overlay->power_bar, NULL);
    sfRenderWindow_drawSprite(win, overlay->label, NULL);
    sfRenderWindow_drawSprite(win, buttons->attack, NULL);
    sfRenderWindow_drawSprite(win, buttons->rest, NULL);
    sfRenderWindow_drawSprite(win, buttons->heal, NULL);
    sfRenderWindow_drawSprite(win, overlay->health_bg, NULL);
    sfRenderWindow_drawRectangleShape(win, overlay->health_ennemy, NULL);
    sfRenderWindow_drawText(win, game->fight_system->feed, NULL);
    sfRenderWindow_display(win);
}

int fight_actions(game_t *game)
{
    fight_system_t *fight_sys = game->fight_system;
    fight_t *fight = game->fight_system->fight;

    if (fight_sys->waiting == 1 && get_time(fight_sys->delay) > 1)
        game = opponent_action(game);
    if (fight->character->hp <= 0) {
        game->fight_system->win = 0;
        fight->opponent->hp = fight->opponent->hp_save;
        game->state = GS_PLAY;
    }
    if (fight->opponent->hp > fight->opponent->hp_save)
        fight->opponent->hp = fight->opponent->hp_save;
    if (get_time(fight_sys->delay) > 1 && fight_event_handler(game) == 1)
        fight_sys->waiting = 1;
    if (fight->opponent->hp <= 0) {
        game->fight_system->win = 1;
        game->state = GS_PLAY;
    }
    return 0;
}

int fight_loop(game_t *game)
{
    fight_t *fight = game->fight_system->fight;
    fight_overlay_t *overlay = game->fight_system->overlay;

    reload_stats(game);
    fight_actions(game);
    game = update_bar_size(game);
    sfText_setString(overlay->health, int_to_char(fight->character->hp));
    sfText_setString(overlay->power, int_to_char(fight->character->force));
    sfRenderWindow_clear(game->window, sfBlack);
    if (my_strlen(int_to_char(fight->character->hp)) == 3)
        sfText_setPosition(overlay->health, (sfVector2f) {0, 1005});
    else
        sfText_setPosition(overlay->health, (sfVector2f) {10, 1005});
    if (my_strlen(int_to_char(fight->character->force)) == 3)
        sfText_setPosition(overlay->power, (sfVector2f) {48, 1005});
    else
        sfText_setPosition(overlay->power, (sfVector2f) {58, 1005});
    draw_all(game, game->window);
    game = update_stats(game);
    return 0;
}
