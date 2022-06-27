/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** game_loop
*/

#include "my_rpg.h"
#include "my.h"

void display_game_object(order display, game_t *game, order pnj)
{
    collision_t *list = game->collisions;
    if (pnj == FRONT)
        display_pnj(game);
    if (display == BACK)
        sfRenderWindow_drawSprite(game->window, game->character->sprite, NULL);
    while (list != NULL) {
        if (list->sprite != NULL)
            sfRenderWindow_drawSprite(game->window, list->sprite, NULL);
        list = list->next;
    }
    if (display == FRONT)
        sfRenderWindow_drawSprite(game->window, game->character->sprite, NULL);
    if (pnj == BACK)
        display_pnj(game);
    display_enemies(game);
}

order check_pnj_collisions(sfSprite *player, pnj_t *list, game_t *game)
{
    int result = 0;
    while (list != NULL && (result = is_pnj_coll(player, list, game)) == 0) {
        list = list->next;
    }
    if (list != NULL) {
        game->character->pos = check_collision(player, list->rect, game);
        if (result == -1)
            return BACK;
        else
            return FRONT;
    }
    return FRONT;
}

void check_all_collisions(sfSprite *player, game_t *game)
{
    int result = 0;
    collision_t *list = game->collisions;
    order pnj = check_pnj_collisions(player, game->pnj_list, game);
    while (list != NULL && (result = is_collision(player, list, game)) == 0) {
        list = list->next;
    }
    if (list != NULL) {
        game->character->pos = check_collision(player, list->rect, game);
        if (result == -1)
            display_game_object(BACK, game, pnj);
        else
            display_game_object(FRONT, game, pnj);
    } else
        display_game_object(FRONT, game, pnj);
    check_fight_collision(game);
    check_enemies_respawn(game->enemies->enemy);
    return;
}

static int game_loop_turbo(game_t *game)
{
    update_hud(game);
    pnj_interaction(game);
    move_particles(game);
    update_foot_particles(game);
    display_particles(game);
    update_char_stats(game);
    if (game->character->state == DEAD) {
        game->state = GS_MENU;
        reset_enemies(game);
    }
    if (game->stat.health <= 0) {
        game->stat.health = 0;
        game->character->state = DIE;
        game->menu->sc_menu = MENU_SC;
    }
    if (game->story->save == FINISHED)
        game->state = GS_MENU;
    return 0;
}

int game_loop(game_t *game)
{
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    update_story(game);
    check_interaction(game);
    sfClock_restart(game->character->move);
    sfRenderWindow_clear(game->window, sfBlack);
    display_bg(game);
    if (game->story->save >= REPAIRED)
        sfRenderWindow_drawSprite(game->window, game->story->bridge, NULL);
    display_foot_particles(game);
    event_handler(game);
    check_all_collisions(game->character->sprite, game);
    update_character(game);
    display_hud(game);
    sfRenderWindow_setView(game->window, game->view);
    game_loop_turbo(game);
    sfRenderWindow_display(game->window);
    game->loop_time = (sfClock_restart(game->character->move).microseconds);
    return (0);
}
