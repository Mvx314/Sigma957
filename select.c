#include "sigma957.h"

// number of players, mapsize etc.
void select_game_options()
{
// make selectable someday...
        mapsize = MAPSIZE;
        numstars = MAXSTARS;
        numplanets = MAXPLANETS;
	numplayers = MAXPLAYERS;
	universesize = UNIVERSEMAX;
// draw numbers...
	refresh_gameoptionscreen();
        do
        {
	        do
                {
                } while (!(mouse_b & 1));
                while (mouse_b & 1);
                switch (mousepos(GAMEOPTIONS,mouse_x,mouse_y))
                {
		case 1: numplayers++;
                        if (numplayers > MAXPLAYERS)
                           numplayers = 2;
                        refresh_gameoptionscreen();
                        break;
                case 2: players[0].race = list_races();
			refresh_gameoptionscreen();
                        break;
		default: break;
                }
        } while	(mousepos(GAMEOPTIONS,mouse_x,mouse_y) != 0);
}

// redraw
void refresh_gameoptionscreen()
{
        clear_screen();
        scare_mouse();
	textprintf (screen,large_font,12,12,makecol(100,200,100),
                   "Proceed");
        textprintf (screen,large_font,100,100,makecol(200,200,200),
                   "Number of players: %d ",numplayers);
        textprintf (screen,large_font,100,130,makecol(200,200,200),
	           "Current race: %s ",races[players[0].race].name);
        unscare_mouse();
}

// drawing selectionscreen and making selections
void selection_screen()
{
        int skip,position,oldposition;
        int startgame;
        startgame = FALSE;
        clear_screen();
        copyofstartscreen = create_bitmap(startscreen->w,startscreen->h);
        blit (startscreen,copyofstartscreen,0,0,0,0,
              startscreen->w,startscreen->h);
        selectionmask = create_bitmap(400,55);
        clear_to_color(selectionmask,makecol(200,200,200));
        position = -1;
        position_mouse (10+(SCREEN_W-startscreen->w)/2,220+10);
        unscare_mouse();
        do
        {
            do
            {
                oldposition = position;
                position = mousepos(SELECTSCREEN,mouse_x,mouse_y);
                if (position == -1) skip = 1;
                   else skip = 0;

                if ((skip == 0) && (oldposition != position))
                {
                        draw_trans_sprite(startscreen,selectionmask,
                                          0,position*55);
                        scare_mouse();
                        blit (startscreen,screen,0,0,
                              (SCREEN_W-startscreen->w)/2,220,
                              startscreen->w,startscreen->h);
                        unscare_mouse();
                        blit (copyofstartscreen,startscreen,0,0,0,0,
                              startscreen->w,startscreen->h);
                }
		rest(10);
            } while (!(mouse_b & 1));
            scare_mouse();
            switch (mousepos(SELECTSCREEN,mouse_x,mouse_y))
            {
                case 0: clear_screen();textprintf(screen,font,100,100,
                        makecol(200,200,200),"No, I haven't written it yet.");
                        skip = 0;break;
                case 1: clear_screen();startgame = TRUE;newgame = TRUE;
		        turncounter = 1;
		        skip = 1;break;
                case 2: clear_screen();textprintf(screen,font,100,100,
                        makecol(200,200,200),"If I ever make any");
                        skip = 0;break;
                case 3: clear_screen();startgame = TRUE;exitgame = TRUE;
                        skip = 1;break;
                default: skip = 1;break;
            };
            unscare_mouse();
            while (mouse_b & 1);
            if (skip == 0)
            {
                while (!(mouse_b & 1));
                while (mouse_b & 1);
                position = -1;
                position_mouse (10+(SCREEN_W-startscreen->w)/2,220+10);
                clear_screen();
            };
        } while (startgame == FALSE);
        while (mouse_b & 1);
        blit (copyofstartscreen,startscreen,0,0,0,0,
              copyofstartscreen->w,copyofstartscreen->h);
        destroy_bitmap(copyofstartscreen);
        destroy_bitmap(selectionmask);
}

