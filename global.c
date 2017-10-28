#include "sigma957.h"

// table of all races
struct race races[MAXRACES];

// table of races in game
struct player players[MAXPLAYERS];

// table of star(system)s
struct star stars[MAXSTARS];

// table of planets
struct planet planets[MAXPLANETS];
int planets_by_name[MAXPLANETS];
int planets_by_population[MAXPLANETS];
int planets_by_industry[MAXPLANETS];

// table of shipclasses
struct shipclass shipclasses[MAXSHIPCLASSES*MAXPLAYERS];

// table of ships
struct ship ships[MAXSHIPS];

// table of fleets
struct fleet fleets[MAXFLEETS];

// table of leaders
struct leader leaders[MAXLEADERS];

// table of techs
struct tech techs[MAXTECHS];

// universe
int universe[UNIVERSEMAX][UNIVERSEMAX];

// mapgrid
int map[MAPSIZE][MAPSIZE];

// global auxiliary variables
int universesize,mapsize,numstars,numplanets,numplayers;
int centerx,centery; // currently center of map
int currentstar;     // last star clicked
int exitgame,endgame,newgame;
int exitplanetlist;
int num_mouse_buttons;
int turncounter;
int money[MAXRACES];
int research[MAXRACES][MAXFIELDS];


