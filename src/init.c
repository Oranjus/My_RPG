/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** init
*/

#include <stdio.h>
#include "my_rpg.h"
#include "save.h"

int check_ressources(void)
{
    return 0;
}

static stat_t load_stat(void)
{
    stat_t stat;
    stat.health = 50.0;
    stat.health_max = 100.0;
    stat.stamina = 100.0;
    stat.stamina_max = 100.0;
    stat.strenght = 100.0;
    return stat;
}

game_t *check_game(game_t *game)
{
    if (!game->window || !game->state || !game->texture || !game->bg)
        return NULL;
    if (!game->character || !game->view || !game->deco || !game->collisions)
        return NULL;
    if (!game->menu || !game->hud || !game->fight_system || !game->inventory)
        return NULL;
    if (!game->inventory || !game->map_coll || !game->sec_texture)
        return NULL;
    if (!game->pnj_list || !game->inter || !game->enemies || !game->particles)
        return NULL;
    if (!game->story)
        return NULL;
    return game;
}

game_t *init_game_next(game_t *game)
{
    game->pnj_list = init_pnj(game);
    game->loop_time = 16760;
    game->inter = sfClock_create();
    game->enemies = init_all_enemies(game);
    game->particles = create_particle_list();
    game->story = init_story();
    game->stat = load_stat();
    game->musics = init_game_musics();
    game = update_stats(game);
    load_from_save(game);
    save_progression(game);
    return game;
}

game_t *init_game(game_t *game)
{
    sfVideoMode mode = {1920, 1080, 32};
    if (check_ressources() == 84)
        return NULL;
    game->window = create_window(mode, "my_rpg");
    game->state = GS_MENU;
    game->texture = sfTexture_createFromFile("assets/sprite/map.png", NULL);
    game->bg = init_bg(game);
    game->character = init_character("assets/sprite/char/WARRIOR.png");
    game->view = init_view(game);
    game->deco = init_deco_list();
    game->collisions = create_collision_list(game->deco);
    game->menu = init_menu(game);
    game->hud = init_hud(game);
    game->fight_system = init_fight_system(game);
    game->inventory = init_inventory(game);
    game->map_coll = sfImage_createFromFile("assets/sprite/color_map.png");
    game->sec_texture = init_sec_texture(game);
    game = init_game_next(game);
    game = check_game(game);
    return (game);
}
