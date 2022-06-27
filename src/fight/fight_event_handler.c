/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-elouan.savy-camaret
** File description:
** fight_event_handler
*/

#include "my_rpg.h"

int handle_click(game_t *game, sfEvent event)
{
    buttons_t *buttons = game->fight_system->overlay->buttons;
    sfVector2f pos = {event.mouseButton.x, event.mouseButton.y};
    sfClock_restart(game->fight_system->delay);
    if (game->fight_system->waiting == 1)
        return 0;
    if (check_hitbox(buttons->attack, pos) == 1) {
        return handle_attack(game);
    }
    if (check_hitbox(buttons->rest, pos) == 1) {
        game = handle_rest(game);
        return 1;
    }
    if (check_hitbox(buttons->heal, pos) == 1) {
        return handle_heal(game);
    }
    return 0;
}

int check_hover(game_t *game)
{
    sfVector2i tmp = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f pos = {tmp.x, tmp.y};
    buttons_t *buttons = game->fight_system->overlay->buttons;

    sfSprite_setTexture(buttons->attack, buttons->attack_text, sfTrue);
    sfSprite_setTexture(buttons->rest, buttons->rest_text, sfTrue);
    sfSprite_setTexture(buttons->heal, buttons->heal_text, sfTrue);
    if (check_hitbox(buttons->attack, pos) == 1) {
        sfSprite_setTexture(buttons->attack, buttons->attack_text_h, sfTrue);
    }
    if (check_hitbox(buttons->rest, pos) == 1) {
        sfSprite_setTexture(buttons->rest, buttons->rest_text_h, sfTrue);
    }
    if (check_hitbox(buttons->heal, pos) == 1) {
        sfSprite_setTexture(buttons->heal, buttons->heal_text_h, sfTrue);
    }
    return 0;
}

int fight_event_handler(game_t *game)
{
    sfEvent event;
    fight_t *fight = game->fight_system->fight;

    check_hover(game);
    sfSprite_setColor(fight->character->sprite, sfWhite);
    sfSprite_setColor(fight->opponent->sprite, sfWhite);
    int return_value = 0;
    if (sfRenderWindow_pollEvent(game->window, &event)) {
        switch (event.type) {
        case sfEvtClosed:
            quit_game(game);
            break;
        case sfEvtMouseButtonPressed:
            return_value = handle_click(game, event);
            break;
        default:
            break;
        }
    }
    return return_value;
}
