/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_
    #define INVENTORY_X 468
    #define INVENTORY_Y 164
    #define ITEM_PATH "assets/sprite/items.png"
    #define ITEM_WIDTH 32
    #define ITEM_HEIGHT 32
    #define INV_SPACER 85
    #define SLOT_NB 15
    #define SLOT_SIZE 44
    #define SLOT_SPACER 62

typedef enum type {
    SWORD,
    AXE,
    STICK,
} item_list;

typedef struct item_stat_s {
    item_list id;
    int health;
    int strenght;
} item_stat_t;

typedef struct item_s {
    sfSprite *item_visual;
    sfText *item_text;
    item_stat_t stat;
    bool click_state;
    bool placement_state;
    sfIntRect *location;
    struct item_s *next;
} item_t;

typedef struct inventory_s {
    sfSprite *bg;
    sfSprite *character;
    item_t *item_list;
    sfIntRect *slot;
    sfText *stats_text;
} inventory_t;

//init inventory
inventory_t *init_inventory(game_t *game);

//loop
int inventory_loop(game_t *game);
int open_inventory(game_t *game);

//slot
sfIntRect *load_slot(void);

//item
void display_item_inventory(game_t *game, item_t *item_list);
int destroy_item(item_t *item_list);
void add_item(item_t **head, sfIntRect *slot_list, item_stat_t stat);
int foreach_item(int (*func)(item_t *item, sfVector2f pos_onclick),
sfVector2f pos_onclick, item_t *item);

//move item
void place_center_slot(sfSprite *spr, sfIntRect rect);
int manage_event_item(sfEvent event, game_t *game);
int slot_taken(item_t *item_list, sfIntRect rect);
int manage_slot(item_t *item, sfVector2f pos_onclick, game_t *game);
int place_item_slot(item_t *item, sfIntRect rect);

//action item
int check_utility_slot(game_t *game, item_t *item, sfIntRect next_rect);
int check_equiped_slot(game_t *game, inventory_t *inventory);

#endif /* !INVENTORY_H_ */
