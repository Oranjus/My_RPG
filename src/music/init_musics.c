/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** init_musics
*/

#include "my_rpg.h"
#include "my.h"

musics_t *init_game_musics(void)
{
    musics_t *musics = malloc(sizeof(musics_t));
    char *path = "assets/musics/game_music.ogg";
    sfMusic *sound_menu = sfMusic_createFromFile(path);

    musics->song_menu = sound_menu;
    sfMusic_setLoop(musics->song_menu, sfTrue);
    sfMusic_setVolume(musics->song_menu, 50);
    return musics;
}
