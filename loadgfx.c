#include "sigma957.h"

BITMAP *startscreen;
BITMAP *copyofstartscreen;
BITMAP *selectionmask;

BITMAP *minimap;
BITMAP *mainmap;
BITMAP *starfield;
BITMAP *mainscreen;
BITMAP *infobox;
COLOR_MAP *color_map;
FONT *large_font;
FONT *extra_large_font;

BITMAP *star_bitmap;
BITMAP *star_minimap;

BITMAP *button1;
BITMAP *button1b;
BITMAP *button2;
BITMAP *button2b;
BITMAP *button3;
BITMAP *button3b;
BITMAP *button4;
BITMAP *button4b;
BITMAP *button5;
BITMAP *button5b;
BITMAP *button6;
BITMAP *button6b;
BITMAP *button7;
BITMAP *button7b;
BITMAP *button8;
BITMAP *button8b;
BITMAP *horbeam;
BITMAP *verbeam;
BITMAP *cornbeam;
BITMAP *htbeam;
BITMAP *vtbeam;
BITMAP *verarrow1;
BITMAP *verarrow2;

void load_gfx()
{
        startscreen = load_bitmap ("start.bmp", NULL);
        star_bitmap = load_bitmap ("stars.bmp",NULL);
	star_minimap = create_bitmap (star_bitmap->w/8,star_bitmap->h/8);
	stretch_blit (star_bitmap,star_minimap,
	             0,0,star_bitmap->w,star_bitmap->h,
		     0,0,star_bitmap->w/8,star_bitmap->h/8);
        button1 = load_bitmap ("button1.bmp",NULL);
        button1b = load_bitmap ("button1b.bmp",NULL);
        textout_centre (button1,large_font,"Explosion",47,16,
                       makecol(128,128,255));
        button2 = load_bitmap ("button1.bmp",NULL);
        button2b = load_bitmap ("button1b.bmp",NULL);
        textout_centre (button2,large_font,"***",47,16,
                       makecol(128,128,255));
        button3 = load_bitmap ("button1.bmp",NULL);
        button3b = load_bitmap ("button1b.bmp",NULL);
        textout_centre (button3,large_font,"Planets",47,16,
                       makecol(128,128,255));
        button4 = load_bitmap ("button1.bmp",NULL);
        button4b = load_bitmap ("button1b.bmp",NULL);
        textout_centre (button4,large_font,"***",47,16,
                       makecol(128,128,255));
        button5 = load_bitmap ("button1.bmp",NULL);
        button5b = load_bitmap ("button1b.bmp",NULL);
        textout_centre (button5,large_font,"Homeworld",47,16,
                       makecol(128,128,255));
        button6 = load_bitmap ("button1.bmp",NULL);
        button6b = load_bitmap ("button1b.bmp",NULL);
        textout_centre (button6,large_font,"***",47,16,
                       makecol(128,128,255));
        button7 = load_bitmap ("button1.bmp",NULL);
        button7b = load_bitmap ("button1b.bmp",NULL);
        textout_centre (button7,large_font,"Next turn",47,16,
                       makecol(128,128,255));
        button8 = load_bitmap ("button1.bmp",NULL);
        button8b = load_bitmap ("button1b.bmp",NULL);
        textout_centre (button8,large_font,"Exit game",47,16,
                       makecol(128,128,255));
	horbeam = load_bitmap ("hor-beam.bmp",NULL);
	verbeam = load_bitmap ("ver-beam.bmp",NULL);
	cornbeam = load_bitmap ("cornbeam.bmp",NULL);
	htbeam = load_bitmap ("ht-beam.bmp",NULL);
	vtbeam = load_bitmap ("vt-beam.bmp",NULL);
        verarrow1 = load_bitmap ("verarr1.bmp",NULL);
        verarrow2 = load_bitmap ("verarr2.bmp",NULL);
}

void unload_gfx()
{
        destroy_bitmap (startscreen);
	destroy_bitmap (star_bitmap);
	destroy_bitmap (star_minimap);
	destroy_bitmap (horbeam);
	destroy_bitmap (verbeam);
	destroy_bitmap (cornbeam);
	destroy_bitmap (htbeam);
	destroy_bitmap (vtbeam);
        destroy_bitmap (button1);
        destroy_bitmap (button1b);
        destroy_bitmap (button2);
        destroy_bitmap (button2b);
        destroy_bitmap (button3);
        destroy_bitmap (button3b);
        destroy_bitmap (button4);
        destroy_bitmap (button4b);
        destroy_bitmap (button5);
        destroy_bitmap (button5b);
        destroy_bitmap (button6);
        destroy_bitmap (button6b);
        destroy_bitmap (button7);
        destroy_bitmap (button7b);
        destroy_bitmap (button8);
        destroy_bitmap (button8b);
        destroy_bitmap (verarrow1);
        destroy_bitmap (verarrow2);
}
