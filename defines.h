#define VERSION_MAJOR 0	   // 0 until this is "ready"
#define VERSION_MINOR 0	   // 0 until you can actually _do_ something
#define VERSION_PATCH 8	   // incremented when I feel like it

#define UNIVERSEMAX 64	   // maxsize of the universe
#define MINIMAPSIZE 188    // small fullmap in pixels
#define MAPSIZE 18         // 588/TILESIZE, size of visible grid
#define TILESIZE 32        // graphic tilesize
#define MAXSTARS 72        // maximum number of stars
#define MAXSTARNAMES (MAXSTARS*3) // max number of names for stars
#define MAXPLANETS (MAXSTARS*3)   // maximum number of planets
#define MAXPLANSTAR 5      // maximum number of planets/star
#define MAXPLAYERS 8       // maximum number of players in one game
#define MAXRACES 16        // number of different races
#define MAXATTRIBUTES 64   // number of different racial attributes

#define MAXSHIPCLASSES 60  // different shipclasses/player
#define MAXWEAPONS 6       // weaponslots/shipclass
#define MAXAUXSYSTEMS 8    // auxiliary systems/shipclass
#define MAXSHIPS (MAXPLAYERS*250) // maximum number of ships in the universe
#define MAXFLEETS MAXSHIPS // each ship can be a fleet of its own
#define MAXLEADERS 80      // maximum number of leaders
#define LEADERBONUSES 12   // leaderbonuses affecting fleet/system
#define MAXABILITIES 6     // different abilities/leader
#define MAXTECHS 255       // max number of technologies
#define MAXFIELDS 8        // divided into fields of research

#define MAXBUILDINGS 24    // number of different buildings
#define ARMYTYPES 4        // different types of planetary combat units

// macros
#define DIST(X1,X2,Y1,Y2) (int)(sqrt((pow((X1)-(X2),2))+(pow((Y1)-(Y2),2))))

// screennames
#define SELECTSCREEN 0     // first screen where to select something
#define GAMESCREEN 1	   // main game screen, with map and buttons
#define GAMEOPTIONS 2	   // screen with general system options, if any
#define	LISTRACES 3        // raceselectionscreen
#define PLANETLIST 4	   // list showing information on planets
#define YESORNO 5	   // query box with yes or no answer

// tech classes
#define TECH_WEAPON      1
#define TECH_ARMOR       2
#define TECH_SHIELD      4
#define TECH_SYSTEM      8
#define TECH_COMPUTER   16
#define TECH_BUILDING   32
#define TECH_PLANET     64
#define TECH_PERSONAL  128
#define TECH_STELLAR   256
#define TECH_GALACTIC  512
#define TECH_FUTURE   1024

