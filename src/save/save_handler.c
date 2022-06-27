/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** save_handler
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "save.h"
#include "my.h"
#include "save_coord.h"

int start_new_game(game_t *game)
{
    fighter_t *wizard = game->fight_system->fighters_list->wizard;
    fighter_t *knight = game->fight_system->fighters_list->knight;
    fighter_t *demon = game->fight_system->fighters_list->demon;

    reset_save_progression();
    load_from_save(game);
    game->state = GS_PLAY;
    game->story->save = START;
    wizard->hp = wizard->hp_save;
    knight->hp = knight->hp_save;
    demon->hp = demon->hp_save;
    return 0;
}

int save_int(FILE *file, int value)
{
    char *buffer = nb_to_str(value);
    int size = my_strlen(buffer);

    fwrite(buffer, 1, size, file);
    fwrite("\n", 1, 1, file);
    if (buffer)
        free(buffer);
    return (0);
}

int save_vector(FILE *file, sfVector2f vector)
{
    char *f_value = nb_to_str(vector.x);
    int f_size = my_strlen(f_value);
    char *s_value = nb_to_str(vector.y);
    int s_size = my_strlen(s_value);

    fwrite(f_value, 1, f_size, file);
    fwrite(" ", 1, 1, file);
    fwrite(s_value, 1, s_size, file);
    fwrite("\n", 1, 1, file);
    if (f_value)
        free(f_value);
    if (s_value)
        free(s_value);
    return (0);
}

int save_progression(game_t *game)
{
    FILE *file = NULL;
    int progress = game->story->save;
    int life = game->stat.health;
    int stamina = game->stat.stamina;
    sfVector2f pos = coord[game->story->save].pos;
    if ((file = fopen("assets/save/game.save", "w")) == NULL)
        return (-1);
    save_int(file, progress);
    save_int(file, life);
    save_int(file, stamina);
    save_vector(file, pos);
    fclose(file);
    return (0);
}

int reset_save_progression(void)
{
    FILE *file = NULL;
    int progress = 0;
    int life = 100;
    int stamina = 150;
    sfVector2f pos = (sfVector2f) {5653, 6096};
    if ((file = fopen("assets/save/game.save", "w")) == NULL)
        return (-1);
    save_int(file, progress);
    save_int(file, life);
    save_int(file, stamina);
    save_vector(file, pos);
    fclose(file);
    return (0);
}
