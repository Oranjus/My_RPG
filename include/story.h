/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** story
*/

#ifndef STORY_H_
    #define STORY_H_

enum save {
    START,
    WIZARD_BEATEN,
    REPAIRED,
    FINISHED,
};

typedef struct story {
    enum save save;
    sfSprite *bridge;
    sfTexture *bridge_texture;
} story_t;

void update_story(game_t *game);
story_t *init_story(void);

#endif /* !STORY_H_ */
