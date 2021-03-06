#include "sigma957.h"

// starnames, planet names are derivatives of the star name
struct starname starnames[] =
{
        {"Sol",0},
        {"Epsilon Eridani",0},
        {"Alpha Centauri",0},
        {"Centauri",0},
        {"Z'ha'dum",0},
        {"Minbar",0},
        {"Hoth",0},
        {"Epsilon Three",0},
        {"Tau Ceti",0},
        {"Orion",0},
        {"Sigma Draconis",0},
        {"Tatooine",0},
        {"Gorash",0},
        {"Dorian",0},
        {"Cluster",0},
        {"Tremaine",0},
        {"Ithaca",0},
        {"Ixcatlha",0},
        {"Vega",0},
        {"Antares",0},
        {"Betelgeuze",0},
        {"Kernighan",0},
        {"Ritchie",0},
        {"Allegro",0},
        {"Coriana",0},
        {"Narn",0},
        {"Mesondo",0},
        {"Bosonia",0},
        {"Leptonus",0},
        {"Origination",0},
        {"Dunham",0},
        {"Shock",0},
        {"Asimov",0},
        {"Clarke",0},
        {"Dunwich",0},
        {"R'lyeh",0},
        {"Mercator",0},
        {"Ishamael",0},
        {"Shay'tan",0},
        {"Baalzamon",0},
        {"Gaugamela",0},
        {"Issus",0},
        {"Prokhorovka",0},
        {"Misizhava",0},
        {"Antiokia",0},
        {"De Sienda",0},
        {"Sierra Madre",0},
        {"Ardennes",0},
        {"Ian Chronos",0},
        {"Nova Sol",0},
        {"Mikado",0},
        {"Romulus",0},
        {"Remus",0},
        {"Stygia",0},
        {"Cimmeria",0},
        {"Horvath",0},
        {"Dragons Hoard",0},
        {"Paleozoica",0},
        {"Mesozoica",0},
        {"Eucariotis",0},
        {"Shadizar",0},
        {"Shandalar",0},
        {"Ebeneezer",0},
        {"Scrooge",0},
        {"Eschaton",0},
        {"Xanadu",0},
        {"Sociedad",0},
        {"Pikachu",0},
        {"Nuu-Nuu",0},
        {"NeverNever",0},
        {"Quadratico",0},
        {"Linwindos",0},
        {"Oratorium",0},
        {"Bibliotic",0},
        {"Mulderia",0},
        {"Scullia",0},
        {"Unnamed",0},
        {"Barnard",0},
        {"Wolf 359",0},
        {"Lalande",0},
        {"Sirius",0},
        {"Luyten",0},
        {"Ross",0},
        {"Cygni",0},
        {"Procyon",0},
        {"Epsilon Indi",0},
        {"Kruger",0},
        {"Kapteyn",0},
        {"von Maanen",0},
        {"Canopus",0},
        {"Arcturus",0},
        {"Capella",0},
        {"Rigel",0},
        {"Achenar",0},
        {"Altair",0},
        {"Aldebaran",0},
        {"Spica",0},
        {"Castor",0},
        {"Pollux",0},
        {"Fomalhaut",0},
        {"Deneb",0},
        {"Regulus",0},
        {"Adhara",0},
        {"Shaula",0},
        {"Belltrix",0},
        {"El Nath",0},
        {"Alnilam",0},
        {"Al Nair",0},
};

int size_of_starnames;// = (sizeof starnames / sizeof (struct starname));

// racenames and -attributes
struct race races[] =
{
	{ 0,"Hewman",  0x00000080,0x00000000},
	{ 1,"Klinghan",0x00001800,0x00000000},
	{ 2,"Romiulan",0x00000000,0x00000000},
	{ 3,"Voorlon", 0x00000000,0x00000000},
	{ 4,"Zhadow",  0x00000000,0x00000000},
	{ 5,"Psicore", 0x00000000,0x00000000},
	{ 6,"Centura", 0x00000000,0x00000000},
	{ 7,"Minibar", 0x00000000,0x00000000},
	{ 8,"Kalckon", 0x00000000,0x00000000},
	{ 9,"Bjorn",   0x00000000,0x00000000},
	{10,"Killrat", 0x00000000,0x00000000},
	{11,"Melkone", 0x00000000,0x00000000},
	{12,"Darling", 0x00000000,0x00000000},
	{13,"Pullroth",0x00000000,0x00000000},
	{14,"Alakari", 0x00000000,0x00000000},
	{15,"Disaign", 0x00000000,0x00000000},
};

// raceattributenames
struct attributes attributes[] =
{
// attributes1
        { 0x00000001,"Population growth -50%",-5},
	{ 0x00000002,"Population growth +50%",5},
	{ 0x00000004,"Population growth +100%",10},
	{ 0x00000008,"Industry -50%",-5},
	{ 0x00000010,"Industry +50%",5},
	{ 0x00000020,"Industry +100%",10},
	{ 0x00000040,"Science -50%",-5},
	{ 0x00000080,"Science +50%",5},
	{ 0x00000100,"Science +100%",10},
	{ 0x00000200,"Ship attack -50%",-5},
	{ 0x00000400,"Ship attack +50%",5},
	{ 0x00000800,"Ship attack +100%",10},
	{ 0x00001000,"Ship defence -50%",-5},
	{ 0x00002000,"Ship defence +50%",5},
	{ 0x00004000,"Ship defence +100%",10},
	{ 0x00008000,"Ground combat -50%",-5},
	{ 0x00010000,"Ground combat +50%",5},
	{ 0x00020000,"Ground combat +100%",10},
	{ 0x00040000,"Espionage -50%",-5},
	{ 0x00080000,"Espionage +50%",5},
	{ 0x00100000,"Espionage +100%",10},
	{ 0x00200000,"Money -50%",-5},
	{ 0x00400000,"Money +50%",5},
	{ 0x00800000,"Money +100%",10},
	{ 0x01000000,"Medieval",-5},            // government
	{ 0x02000000,"Dictatorship",0},
	{ 0x04000000,"Republic",5},
	{ 0x08000000,"Hivemind",10},
	{ 0x10000000,"Warrior",5},		// racial mind
	{ 0x20000000,"Pacifist",-5},
	{ 0x40000000,"Intellectual",5},
	{ 0x80000000,"Mindless",-5},
// attributes2
	{ 0x00000001,"",},
	{ 0x00000002,"",},
	{ 0x00000004,"",},
	{ 0x00000008,"",},
	{ 0x00000010,"",},
	{ 0x00000020,"",},
	{ 0x00000040,"",},
	{ 0x00000080,"",},
	{ 0x00000100,"",},
	{ 0x00000200,"",},
	{ 0x00000400,"",},
	{ 0x00000800,"",},
	{ 0x00001000,"",},
	{ 0x00002000,"",},
	{ 0x00004000,"",},
	{ 0x00008000,"",},
	{ 0x00010000,"",},
	{ 0x00020000,"",},
	{ 0x00040000,"",},
	{ 0x00080000,"",},
	{ 0x00100000,"",},
	{ 0x00200000,"",},
	{ 0x00400000,"",},
	{ 0x00800000,"",},
	{ 0x01000000,"",},
	{ 0x02000000,"",},
	{ 0x04000000,"",},
	{ 0x08000000,"",},
	{ 0x10000000,"",},
	{ 0x20000000,"",},
	{ 0x40000000,"",},
	{ 0x80000000,"",},
};

