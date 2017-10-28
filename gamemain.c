#include "sigma957.h"

// THE MAIN GAME LOOP
void game_main()
{
        int x;
        do
        {
                for (x=1;x<numplayers;x++) // human is player 0
                    computer_orders(x);
                player_orders();
                if (endgame == FALSE)
                {
                        building();
                        growth();
                        movement();
                        combat();
		        turncounter++;
                }
        } while (endgame == FALSE);
        destroy_bitmap(starfield);
}

// computer player orders
void computer_orders(int playernumber)
{
}

// redraw the mainscreen when necessary
void refresh_mainscreen()
{
	blit (mainmap,mainscreen,0,0, 12, 12,mainmap->w,mainmap->h);
	blit (minimap,mainscreen,0,0,600, 12,minimap->w,minimap->h);
	blit (infobox,mainscreen,0,0,600,212,infobox->w,infobox->h);
        blit (button1,mainscreen,0,0,600,400,button1->w,button1->h);
        blit (button2,mainscreen,0,0,694,400,button2->w,button2->h);
        blit (button3,mainscreen,0,0,600,447,button3->w,button3->h);
        blit (button4,mainscreen,0,0,694,447,button4->w,button4->h);
        blit (button5,mainscreen,0,0,600,494,button5->w,button5->h);
        blit (button6,mainscreen,0,0,694,494,button6->w,button6->h);
        blit (button7,mainscreen,0,0,600,541,button7->w,button7->h);
        blit (button8,mainscreen,0,0,694,541,button8->w,button8->h);
	blit (horbeam,mainscreen,0,0,  0,  0,horbeam->w,horbeam->h);
	blit (horbeam,mainscreen,0,0,200,  0,horbeam->w,horbeam->h);
	blit (horbeam,mainscreen,0,0,400,  0,horbeam->w,horbeam->h);
	blit (horbeam,mainscreen,0,0,600,  0,horbeam->w,horbeam->h);
	blit (horbeam,mainscreen,0,0,600,200,horbeam->w,horbeam->h);
	blit (horbeam,mainscreen,0,0,600,388,horbeam->w,horbeam->h);
	blit (horbeam,mainscreen,0,0,  0,588,horbeam->w,horbeam->h);
	blit (horbeam,mainscreen,0,0,200,588,horbeam->w,horbeam->h);
	blit (horbeam,mainscreen,0,0,400,588,horbeam->w,horbeam->h);
	blit (horbeam,mainscreen,0,0,600,588,horbeam->w,horbeam->h);
	blit (verbeam,mainscreen,0,0,  0,  0,verbeam->w,verbeam->h);
	blit (verbeam,mainscreen,0,0,  0,200,verbeam->w,verbeam->h);
	blit (verbeam,mainscreen,0,0,  0,400,verbeam->w,verbeam->h);
	blit (verbeam,mainscreen,0,0,588,  0,verbeam->w,verbeam->h);
	blit (verbeam,mainscreen,0,0,588,200,verbeam->w,verbeam->h);
	blit (verbeam,mainscreen,0,0,588,400,verbeam->w,verbeam->h);
	blit (verbeam,mainscreen,0,0,788,  0,verbeam->w,verbeam->h);
	blit (verbeam,mainscreen,0,0,788,200,verbeam->w,verbeam->h);
	blit (verbeam,mainscreen,0,0,788,400,verbeam->w,verbeam->h);
	draw_sprite (mainscreen,cornbeam,0,0);
	draw_sprite_v_flip (mainscreen,cornbeam,0,588);
	draw_sprite_h_flip (mainscreen,cornbeam,788,0);
	draw_sprite_vh_flip (mainscreen,cornbeam,788,588);
	draw_sprite (mainscreen,htbeam,588,0);
	draw_sprite_v_flip (mainscreen,htbeam,588,588);
	draw_sprite (mainscreen,vtbeam,588,200);
	draw_sprite (mainscreen,vtbeam,588,388);
	draw_sprite_h_flip (mainscreen,vtbeam,788,200);
	draw_sprite_h_flip (mainscreen,vtbeam,788,388);
        text_mode (makecol(61,61,61));
	textprintf (mainscreen,font,256,1,makecol(255,128,0),
	           "YEAR: %4.1f",3500+(float)turncounter/10);
        text_mode (0);
        scare_mouse();
        blit (mainscreen,screen,0,0,0,0,mainscreen->w,mainscreen->h);
        unscare_mouse();
}

// human player orders
void player_orders()
{
        int endturn;
        endgame = FALSE;
        endturn = FALSE;
        infobox = create_bitmap(188,176);
        clear(infobox);
        mainscreen = create_bitmap(SCREEN_W,SCREEN_H);
        clear(mainscreen);
	center_map(0,0,2);
        show_star_info(currentstar);
        sort_planets();
        refresh_mainscreen();
        do
        {
            do
            {
            } while ((!(mouse_b & 1)) && (!(mouse_b & 2)));
	    if (mouse_b & 1)
            {
                while (mouse_b & 1);
                switch (mousepos(GAMESCREEN,mouse_x,mouse_y))
                {
                case -1: break;
                case 0:	destroy_bitmap(minimap);
                        destroy_bitmap(mainmap);
		        show_star_info(get_star_index());
		        center_map(mouse_x,mouse_y,-1);break;
		case 1:	destroy_bitmap(minimap);
                        destroy_bitmap(mainmap);
		        center_map(mouse_x,mouse_y,1);break;
                case 2: break;
                case 3: explosion(1,12,12);break;
                case 4: list_planets();refresh_mainscreen();break;
                case 5: center_map(0,0,0);
                        show_star_info(currentstar = planets[0].starindex);
                        break;
                case 6: endturn = TRUE;break;
                case 7: break;
                case 8: break;
                case 9: break;
                case 10: endgame = yes_or_no();break;
                default: break;
                }
            }
            else if (mouse_b & 2)
            {
	        while (mouse_b & 2);
		switch (mousepos(GAMESCREEN,mouse_x,mouse_y))
                {
                case 0:	destroy_bitmap(minimap);
                        destroy_bitmap(mainmap);
                        center_map(mouse_x,mouse_y,-1);
                        /*show_distance();*/break;
                default: ;break;
                }
            };
        } while ((endgame == FALSE) && (endturn == FALSE));
        destroy_bitmap(mainscreen);
        destroy_bitmap(infobox);
	destroy_bitmap(minimap);
        destroy_bitmap(mainmap);
}

// select what a planet builds
void select_build(int index)
{
        exitplanetlist = FALSE; // change as necessary
}

/*void show_distance()
{
	int index,x1,x2,y1,y2,ok,ocentx,ocenty;
	ok = FALSE;
	index = get_star_index();
	if (index != -1)
	{
	x1 = (mapsize/2)*32+16;
	y1 = (mapsize/2)*32+16;
	ok = TRUE;
	}
	while (!(mouse_b & 2));
	x2 = mouse_x-12;
	y2 = mouse_y-12;
	ok = TRUE;
	if (ok)
	   line (mainmap,x1,y1,x2,y2,makecol(255,0,0));
        textprintf (infobox,font,1,10,makecol(255,0,0),
                   "Distance: %d",(map[xpos][ypos] > -1) ?
                   stars[].distances[map[xpos][ypos]] :
                   (DIST(xpos,lastx,ypos,lasty)));
        scare_mouse();
        blit (mainmap,screen,0,0,12,12,mainmap->w,mainmap->h);
	unscare_mouse();
}*/


/*void old_player_orders()
{
        BITMAP *selectionmask;
        BITMAP *deselectmask;
        BITMAP *infobox;
        BITMAP *copyofmainmap;
        int xpos,oldxpos,ypos,oldypos;
        int lastx,lasty,distshow;
        int endturn;
        int i;
        distshow = FALSE;
        endgame = FALSE;
        endturn = FALSE;
        copyofmainmap = create_bitmap(mainmap->w,mainmap->h);
        blit(mainmap,copyofmainmap,0,0,0,0,mainmap->w,mainmap->h);
        infobox = create_bitmap(200,400);
        clear(infobox);
        selectionmask = create_bitmap(32,32);
        deselectmask = create_bitmap(32,32);
        clear_to_color(selectionmask,makecol(200,200,200));
        blit (mainmap,deselectmask,0,0,0,0,32,32);
        oldxpos = 0;
        oldypos = 0;
        lastx = -1;
        lasty = -1;
        do
        {
            do
            {
              do
              {
                xpos = ((mouse_x >= 12) && (mouse_x <= 588)) ?
                       (int)((mouse_x-12)/32) : -1;
                ypos = ((mouse_y >= 12) && (mouse_y <= 588)) ?
                       (int)((mouse_y-12)/32) : -1;
                if (((oldxpos != xpos) || (oldypos != ypos)) &&
                   (xpos != -1) && (ypos != -1))
                {
                        textprintf (infobox,font,1,1,makecol(128,255,128),
                                   "t:%d x:%d y:%d p:%d",
                                   map[xpos][ypos] == -1 ? -1 :
                                   stars[map[xpos][ypos]].type,
                                   xpos,ypos,map[xpos][ypos] == -1 ? 0 :
                                   stars[map[xpos][ypos]].planets);
                        for (i=0;i<stars[map[xpos][ypos]].planets;i++)
                            textprintf (infobox,font,1,(i+1)*10,
                                       makecol(99,99,199),"index:%d pop:%d",
                                       planets[stars[map[xpos][ypos]].
                                       planetindex[i]].index,
                                       planets[stars[map[xpos][ypos]].
                                       planetindex[i]].pop);

                        blit (deselectmask,mainmap,0,0,oldxpos*32,
                              oldypos*32,32,32);
                        blit (mainmap,deselectmask,xpos*32,ypos*32,0,0,32,32);
                        draw_trans_sprite (mainmap,selectionmask,xpos*32,
                                           ypos*32);
                        if (distshow)
                        {
                           line (mainmap,16+lastx*32,16+lasty*32,
                                 16+xpos*32,16+ypos*32,
                                 makecol(255,0,0));
                           textprintf (infobox,font,1,10,makecol(255,0,0),
                                      "Distance: %d",(map[xpos][ypos] > -1) ?
                                      stars[map[lastx][lasty]].
                                      distances[map[xpos][ypos]] :
                                      (DIST(xpos,lastx,ypos,lasty)));
                        }
                        scare_mouse();
                        blit (mainmap,screen,0,0,12,12,
                              mainmap->w,mainmap->h);
                        blit (infobox,screen,0,0,600,12,
                              infobox->w,infobox->h);
                        unscare_mouse();
                        blit (copyofmainmap,mainmap,0,0,0,0,mainmap->w,
                              mainmap->h);
                        clear(infobox);
                } else
                if ((oldxpos != xpos) || (oldypos != ypos))
                {
                        textprintf (infobox,font,1,1,makecol(128,255,128),
                                   "Outside map");
                        blit (deselectmask,mainmap,0,0,oldxpos*32,
                              oldypos*32,32,32);
                        scare_mouse();
                        blit (mainmap,screen,0,0,12,12,
                              mainmap->w,mainmap->h);
                        blit (infobox,screen,0,0,600,12,
                              infobox->w,infobox->h);
                        unscare_mouse();
                        clear(infobox);
                }
                oldxpos = xpos;
                oldypos = ypos;
              } while ((!(mouse_b & 1)) && (!(mouse_b & 2)));

              if (mouse_b & 2)
              {
                  while (mouse_b & 2);
                  if (distshow == TRUE)
                  {
                      distshow = FALSE;
                      lastx = -1;
                      lasty = -1;
                  } else
                  if ((xpos != -1) && (ypos != -1) && (map[xpos][ypos] > -1))
                  {
                        distshow = TRUE;
                        lastx = xpos;
                        lasty = ypos;
                  }
              }
            } while (!(mouse_b & 1));
            while (mouse_b & 1);
            if (mousepos(GAMESCREEN,mouse_x,mouse_y) == 1)
                endturn = TRUE;
            else
                endgame = TRUE;
        } while ((endgame == FALSE) && (endturn == FALSE));
        scare_mouse();
        destroy_bitmap(selectionmask);
        destroy_bitmap(deselectmask);
        destroy_bitmap(copyofmainmap);
        destroy_bitmap(infobox);
        clear_keybuf();
        unscare_mouse();
}*/

