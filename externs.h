// function prototypes

// clickpos.c
extern int mousepos(int,int,int);

// gamemain.c
extern void game_main();
extern void computer_orders(int);
extern void player_orders();
extern void select_build();
extern void refresh_mainscreen();
//extern void show_distance()
//extern void old_player_orders();

// universe.c
extern void generate_universe();
extern void create_minimap();
extern void create_mainmap();
extern int get_star_index();
extern void show_planet_info(int);
extern void show_star_info(int);
extern void center_map(int,int,int);
extern void building();
extern void growth();
extern void movement();
extern void combat();

// listscreen.c
extern void refresh_planetlist(int,int);
extern void sort_planets();
extern void list_planets();
extern int list_races();

// title.c
extern void display_title();

// select.c
extern void selection_screen();
extern void select_game_options();
extern void refresh_gameoptionscreen();

// explosion.c
extern void explosion(int,int,int);

// utility.c
extern void clear_screen();
extern int yes_or_no();
extern void load_fonts();
extern void unload_fonts();

// loadgfx.c
extern void load_gfx();
extern void unload_gfx();
