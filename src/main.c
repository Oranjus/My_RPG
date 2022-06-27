/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#include "my_rpg.h"
#include "my.h"
#include "free.h"

void check_gs(game_t *game)
{
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    switch (game->state) {
    case GS_MENU:
        menu_loop(game);
        break;
    case GS_PLAY:
        game_loop(game);
        break;
    case GS_FIGHT:
        fight_loop(game);
        break;
    case GS_INVENTORY:
        inventory_loop(game);
        break;
    case GS_LOAD:
    default:
        break;
    }
}

int check_display(char **env)
{
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], "DISPLAY", 7) == 0)
            return 0;
    }
    return 84;
}

int main(int argc, char **argv, char **env)
{
    game_t *game = malloc(sizeof(game_t));

    if (!env[0] || check_display(env) == 84)
        return (84);
    if (argc > 1 && !my_strcmp(argv[1], "-h")) {
        display_usage();
        return (0);
    }
    if (check_files() == 84)
        return (84);
    game = init_game(game);
    if (game == NULL)
        return (84);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    window_icon(game);
    sfMusic_play(game->musics->song_menu);
    while (sfRenderWindow_isOpen(game->window))
        check_gs(game);
    free_game(game);
    return (0);
}
