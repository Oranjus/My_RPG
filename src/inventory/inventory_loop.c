/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** inventory_loop
*/

#include "my_rpg.h"
#include "my.h"

static void update_stats_text(game_t *game)
{
    char str[200] = "ATK = ";
    my_strcat(str, int_to_char(game->stat.atk));
    my_strcat(str, "   DEF = ");
    my_strcat(str, int_to_char(game->stat.strenght));
    sfText_setString(game->inventory->stats_text, str);
    return;
}

static int display_inventory(game_t *game, inventory_t *inventory)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_setView(game->window, game->view);
    display_bg(game);
    display_game_object(BACK, game, FRONT);
    sfRenderWindow_setView(game->window, game->menu->static_view);
    sfRenderWindow_drawSprite(game->window, inventory->bg, NULL);
    sfRenderWindow_drawSprite(game->window, inventory->character, NULL);
    update_stats_text(game);
    sfRenderWindow_drawText(game->window, inventory->stats_text, NULL);
    display_item_inventory(game, game->inventory->item_list);
    display_hud(game);
    sfRenderWindow_display(game->window);
    return 0;
}

static int event_handler_inv(game_t *game)
{
    sfEvent event;

    if (sfRenderWindow_pollEvent(game->window, &event)) {
        event_hud_handler(event, game);
        manage_event_item(event, game);
        switch (event.type) {
        case sfEvtKeyPressed:
            if (event.key.code == sfKeyEscape)
                game->state = GS_PLAY;
            break;
        case sfEvtClosed:
            quit_game(game);
            break;
        default:
            return 0;
        }
    }
    return 1;
}

int inventory_loop(game_t *game)
{
    event_handler_inv(game);
    update_hud(game);
    check_equiped_slot(game, game->inventory);
    display_inventory(game, game->inventory);
    return 0;
}

int open_inventory(game_t *game)
{
    if (game->state != GS_INVENTORY)
        game->state = GS_INVENTORY;
    else
        game->state = GS_PLAY;
    return 1;
}
