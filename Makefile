##
## EPITECH PROJECT, 2021
## B-MUL-100-BDX-1-1-myhunter-elouan.savy-camaret
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/init.c	\
		src/texture_handler.c \
		src/window/window_handler.c \
		src/game/game_loop.c \
		src/event/event_manager.c \
		src/event/start_fight.c \
		src/event/inputs.c \
		src/display_usage.c \
		src/music/init_musics.c \
		src/character/init_char.c \
		src/character/update_stats.c \
		src/character/update_char.c \
		src/character/move_char.c \
		src/character/death_char.c \
		src/background/bg_manager.c \
		src/view/init_view.c \
		src/view/move_view.c \
		src/collision/read_collisions.c \
		src/collision/check_collision.c \
		src/collision/check_color_collision.c \
		src/collision/simple_collision.c	\
		src/collision/fight_collision.c \
		src/deco/init_deco_list.c \
		src/menu/init_menu.c		\
		src/menu/method_btn.c		\
		src/menu/choose_menu.c		\
		src/menu/sub_menu/menu_loop.c		\
		src/menu/sub_menu/pause.c			\
		src/menu/sub_menu/settings_loop.c	\
		src/menu/sub_menu/save_loop.c		\
		src/menu/sub_menu/help_loop.c		\
		src/utils/button/display_btn.c		\
		src/utils/button/init_buton.c		\
		src/utils/button/event_btn.c		\
		src/utils/button/manage_btn.c		\
		src/utils/sprite/load_sprite.c		\
		src/utils/slider/init_slider.c		\
		src/utils/slider/event_slider.c		\
		src/utils/slider/display_slider.c	\
		src/utils/slider/move_slider.c		\
		src/hud/hud.c			\
		src/hud/init_hud.c		\
		src/hud/event_hud.c		\
		src/hud/method_hud.c	\
		src/hud/manage_hud.c	\
		src/fight/init_fight_system.c	\
		src/fight/fight_loop.c	\
		src/fight/int_to_char.c	\
		src/fight/buttons.c	\
		src/fight/fight_event_handler.c	\
		src/fight/attack.c	\
		src/fight/rest.c	\
		src/fight/heal.c	\
		src/fight/opponent.c	\
		src/fight/overlay.c	\
		src/fight/create_fighters.c	\
		src/fight/update_stats.c	\
		src/pnj/check_file.c	\
		src/pnj/init_pnj.c	\
		src/pnj/pnj_list_manager.c	\
		src/pnj/utils.c	\
		src/pnj/open_file.c	\
		src/pnj/display_sprite.c	\
		src/pnj/get_pnj_distance.c	\
		src/pnj/dialogue_manager.c	\
		src/pnj/action.c	\
		src/pnj/manage_interaction.c	\
		src/init_sec_texture.c	\
		src/enemies/init_enemies.c	\
		src/enemies/display_enemies.c	\
		src/enemies/enemies_animation.c	\
		src/enemies/move_enemies.c	\
		src/enemies/check_enemies_respawn.c	\
		src/enemies/reset_enemies.c	\
		src/particles/create_particle.c	\
		src/particles/move_particles.c	\
		src/particles/create_foot_particles.c	\
		src/inventory/inventory_loop.c	\
		src/inventory/init_inventory.c	\
		src/inventory/item/init_item.c	\
		src/inventory/item/display_item_inventory.c	\
		src/inventory/item/event_item.c	\
		src/inventory/move_item.c	\
		src/inventory/slot.c	\
		src/inventory/action_item.c	\
		src/story/init_story.c	\
		src/story/update_story.c	\
		src/check_files.c	\
		src/save/save_handler.c	\
		src/save/load_handler.c	\
		src/save/save_utils.c	\
		src/free/free_collision.c	\
		src/free/free_enemies.c	\
		src/free/free_fight.c	\
		src/free/free_game.c	\
		src/free/free_hud.c	\
		src/free/free_inventory.c	\
		src/free/free_menu.c	\
		src/free/free_particles.c	\
		src/free/free_pnj.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra

NAME	=	my_rpg

CPPFLAGS	=	-I./include

LIB     =       -L./lib/ -lmy

LIBMYPATH =	./lib/libmy.a

all:	$(NAME)

$(NAME):	$(LIBMYPATH) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CPPFLAGS) $(LIB) -lcsfml-graphics -lcsfml-audio \
	-lcsfml-window -lcsfml-system -lsfml-graphics -lsfml-audio -lsfml-window \
	-lsfml-system -lm

clean:
	rm -f $(OBJ);
	rm -f *~;
	rm -f *.gc*
	rm -f vgcore*

fclean : clean
	make fclean -C lib/my
	rm -f $(NAME)
	rm -f unit_tests

re: fclean all

debug: fclean
	make -C lib/my
	gcc -o $(NAME) $(SRC) $(CPPFLAGS) $(LIB) $(CFLAGS) -lcsfml-graphics \
	-lcsfml-system -lcsfml-window -lcsfml-audio -lm -ggdb3

tests_run:
	gcc -o unit_tests $(TEST) $(CPPFLAGS) -Llib/ -lmy -lcriterion --coverage
	./unit_tests

$(LIBMYPATH):
	make -C ./lib/my
