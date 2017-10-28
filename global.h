// table of all races
struct race
{
        int index;
        char *name;
        int attributes1;
	int attributes2;
};
extern struct race races[MAXRACES];

// definitions of racial attributes
struct attributes
{
        int index;
	char *name;
	int cost;
};
extern struct attributes attributes[MAXATTRIBUTES];

// table of races in game
struct player
{
        int index;
        int race;
        char *nameofleader;
	int money;
        int strategy;                  // builder,warrior etc.
        int aggressivity;              // pacifist,maniac etc.
        int starinfo[MAXSTARS];        // what is known about stars
        int planetinfo[MAXPLANETS];    // what is known about planets
        int status[MAXPLAYERS];        // diplomatic status
	int feelings[MAXPLAYERS];      // tendency of diplomacy
        int honesty;                   // likely to keep or break deals
        int willpower;                 // easily persuaded?
};
extern struct player players[MAXPLAYERS];

// table of star(system)s
struct star
{
        int index;
	int players_present[MAXPLAYERS]; // players who have planets here
	int starnameindex;
	int type;
        int size;
        int planets;
        int planetindex[MAXPLANSTAR];
        int special;
        int xpos;
        int ypos;
        int distances[MAXSTARS];
};
extern struct star stars[MAXSTARS];

// table of planets
struct planet
{
        char name[30];
        int index;
        int starindex;
	int owner;
        int lifetype;
        int minetype;
        int size;
        int pop;
        int maxpop;
	int popchange;
        int industry;
        int maxindustry;
        int buildings[MAXBUILDINGS];	// what buildings have been built
	int production;                 // amount spent towards next building
        int army[ARMYTYPES];
};
extern struct planet planets[MAXPLANETS];
extern int planets_by_name[MAXPLANETS];
extern int planets_by_population[MAXPLANETS];
extern int planets_by_industry[MAXPLANETS];

// table of shipclasses
struct shipclass
{
        int index;
        int pictureindex;
	int race;               // creator race
        int hullsize;
        int engine;
        int speed;
	int armor;
	int structure;
        int shield;
	int shield_regen;
        int weapons[MAXWEAPONS];
        int auxsystems[MAXAUXSYSTEMS];
};
extern struct shipclass shipclasses[MAXSHIPCLASSES*MAXPLAYERS];

// table of ships
struct ship
{
        int index;
        int shipclass;
	int built;
	int builder;
	int controller;
        int damage_armor;
	int damage_structure;
	int shield_status;
        int experience;
	int morale;
        int leader;
        int fleetindex;
};
extern struct ship ships[MAXSHIPS];

// table of fleets
struct fleet
{
        int index;
        int sourcex;
        int sourcey;
        int destx;
        int desty;
        int speed;
        int totalshipmass;
        int totalships;
        int ships[MAXSHIPS/MAXPLAYERS];
        int leaderbonuses[LEADERBONUSES];
};
extern struct fleet fleets[MAXFLEETS];

// table of leaders
struct leader
{
        int index;
        char *name;
        int experience;
        int affiliation;
        int abilities[MAXABILITIES];
        int location[MAXFLEETS+MAXSTARS];
};
extern struct leader leaders[MAXLEADERS];

struct tech
{
        int index;
	char *name;
	int cost;		// minimum cost to research
	int classification;     // weapon,armor,shield,drive,colony,empire
	int requires1;          // what techs you need to research this,
	int requires2;          // sort of a tech tree,
	int requires3;		// 0 means no needs
	int type1;		// effect when used, weapons, armor etc.
	int type2;		// more effects when used
};
extern struct tech techs[MAXTECHS];

// whole universe
extern int universe[UNIVERSEMAX][UNIVERSEMAX];

// mapgrid on screen
extern int map[MAPSIZE][MAPSIZE];

// starnames
struct starname
{
        char name[30];
	int used;
};
extern struct starname starnames[MAXSTARNAMES];
extern int size_of_starnames;

// global auxiliary variables
extern int universesize,mapsize,numstars,numplanets,numplayers;
extern int centerx,centery;       // coordinates of mapview center
extern int currentstar;           // star that was last clicked
extern int exitgame,endgame,newgame;
extern int exitplanetlist;
extern int num_mouse_buttons;
extern int turncounter;
extern int money[MAXRACES];
extern int research[MAXRACES][];

