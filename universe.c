#include "sigma957.h"

// construction of the initial state of the universe
void generate_universe()
{
        int i,j,x,y;
        int tooclose,mindist,fails;
	int starnameindex;
        size_of_starnames = 0;
// minimum distance between stars
        mindist = (int)sqrt(universesize*universesize/numstars)-2;
	fails = 0;
// reset universe
        for (x=0;x<universesize;x++)
	    for (y=0;y<universesize;y++)
	        universe[x][y] = -1;
// reset mapgrid
        for (x=0;x<mapsize;x++)
            for (y=0;y<mapsize;y++)
                map[x][y] = -1;
// reset stars
        for (i=0;i<numstars;i++)
            stars[i].planets = 0;
// reset starnames used
        while (starnames[size_of_starnames++].name[0] != 0);
        for (i=0;i<size_of_starnames;i++)
	    starnames[i].used = 0;
        for (i=0;i<MAXPLANETS;i++)
        {
		*planets[i].name = '\0';
                planets_by_name[i] = i;
		planets_by_population[i] = i;
		planets_by_industry[i] = i;
        }
// create stars
        i = 0;
        while (i<numstars)
        {
                stars[i].index = i;
		starnameindex =	random()%size_of_starnames;
		while ((starnames[starnameindex].used != 0) ||
		       (starnames[starnameindex].name[0] == 0))
                      starnameindex = random()%size_of_starnames;
		stars[i].starnameindex = starnameindex;
                starnames[starnameindex].used++;
		for (j=0;j<MAXPLAYERS;j++)
		    stars[i].players_present[j] = 0;
                stars[i].type = (random()%8);
                stars[i].size = ((random()%3)+2);
                stars[i].special = (random()%100);
                for (j=0;j<MAXPLANSTAR;j++)
                    stars[i].planetindex[j] = -1;
                do
                {
                        tooclose = 0;
                        x = (random()%(universesize-6))+3; // avoid edges
                        y = (random()%(universesize-2))+1;
			for (j=0;j<i;j++)
                            if (DIST((stars[j].xpos),x,(stars[j].ypos),y) <
				mindist)
                            {
                               tooclose = TRUE;
			       fails++;
			       textprintf (screen,font,1,1,
					   makecol(128,128,128),"%d ",fails);
                            }
                        if (!(tooclose))
                        {
                           universe[x][y] = stars[i].index;
                           stars[i].xpos = x;
                           stars[i].ypos = y;
                           for (j=0;j<i;j++)
                           {
                               stars[j].distances[i] = (DIST((stars[j].xpos),
                                                       x,(stars[j].ypos),y));
                               stars[i].distances[j] = stars[j].distances[i];
                           }
                        }
                } while (universe[x][y] != stars[i].index);
                i++;
        }
// create planets
        i = 0;
        while (i<numplanets)
        {
                planets[i].index = i;
                planets[i].starindex = (random()%numstars);
		planets[i].owner = -1;
// no two homeworlds in one starsystem
                while ((i<numplayers) &&
                       (stars[planets[i].starindex].planets > 0))
                       planets[i].starindex = (random()%numstars);
                if (i<numplayers)
                {
		   planets[i].owner = i;
		   stars[planets[i].starindex].players_present[i] = 1;
                }
// try not to crowd starsystem (maybe need to repeat more than once)
                if (stars[planets[i].starindex].planets > (MAXPLANSTAR-2))
                   planets[i].starindex = (random()%numstars);
// don't go over maximum per star
                while (stars[planets[i].starindex].planets == MAXPLANSTAR)
                      planets[i].starindex = (random()%numstars);
// add the planet to the selected star, and increment amount
                stars[planets[i].starindex].
                      planetindex[stars[planets[i].starindex].planets] = i;
                stars[planets[i].starindex].planets++;
// name planet after its' star
		strcat(planets[i].name,starnames[stars[planets[i].
		                       starindex].starnameindex].name);
// add an extension to differentiate planets of one star
                switch (stars[planets[i].starindex].planets)
		{
			case 1:	strcat(planets[i].name," I");break;
			case 2:	strcat(planets[i].name," II");break;
			case 3:	strcat(planets[i].name," III");break;
			case 4:	strcat(planets[i].name," IV");break;
			case 5:	strcat(planets[i].name," V");break;
			default: break;
                }
                planets[i].lifetype = (random()%9);
                planets[i].minetype = (random()%6);
                planets[i].size = ((random()%7)-1);
		planets[i].pop = 0;
                planets[i].maxpop = 5000*
		                    (planets[i].lifetype*planets[i].size+2);
                planets[i].industry = 0;
                planets[i].maxindustry = planets[i].minetype*
                                         planets[i].size*
					 planets[i].maxpop/1000;
		if (planets[i].size < 1)  // asteroid (-1) or gas giant (0)
		{
   		        planets[i].lifetype = 0;
			planets[i].minetype = 0;
			planets[i].maxpop = 0;
			planets[i].maxindustry = 0;
                }
                for (j=0;j<MAXBUILDINGS;j++)
                    planets[i].buildings[j] = 0;
                for (j=0;j<ARMYTYPES;j++)
                    planets[i].army[j] = 0;
                i++;
        }
// make homeworlds, add modifications based on race attributes
        i = 0;
        while (i<numplayers)
        {
	        *planets[i].name = '\0';
		strcat(planets[i].name,starnames[stars[planets[i].
		                       starindex].starnameindex].name);
		strcat(planets[i].name," Prime");
                planets[i].lifetype = 6;
                planets[i].minetype = 3;
                planets[i].size = 3;
                planets[i].pop = 80000;
                planets[i].maxpop = 5000*
		                    (planets[i].lifetype*planets[i].size+2);
                planets[i].industry = 240;
                planets[i].maxindustry = planets[i].minetype*
                                         planets[i].size*
					 planets[i].maxpop/1000;
                planets[i].buildings[0] = 1;
                planets[i].army[0] = 1;
                i++;
        }
	currentstar = stars[planets[0].starindex].index;
// testing below
	planets[i].maxpop = 100000;
	planets[i++].pop = 1;
	planets[i].maxpop = 100000;
	planets[i++].pop = 10;
	planets[i].maxpop = 100000;
	planets[i++].pop = 100;
	planets[i].maxpop = 100000;
	planets[i++].pop = 1000;
	planets[i].maxpop = 100000;
	planets[i++].pop = 10000;
}

// creating a small map showing whole universe, with zoom square
void create_minimap()
{
        int x,y;
	minimap = create_bitmap (MINIMAPSIZE,MINIMAPSIZE);
	clear (minimap);
        vline (minimap,
              (centerx-mapsize/2)*MINIMAPSIZE/universesize,
              (centery-mapsize/2)*MINIMAPSIZE/universesize,
	      (centery+mapsize/2)*MINIMAPSIZE/universesize-1,
	      makecol(99,99,0));
        vline (minimap,
              (centerx+mapsize/2)*MINIMAPSIZE/universesize-1,
              (centery-mapsize/2)*MINIMAPSIZE/universesize,
	      (centery+mapsize/2)*MINIMAPSIZE/universesize-1,
	      makecol(99,99,0));
        hline (minimap,
              (centerx-mapsize/2)*MINIMAPSIZE/universesize,
              (centery-mapsize/2)*MINIMAPSIZE/universesize,
	      (centerx+mapsize/2)*MINIMAPSIZE/universesize-1,
	      makecol(99,99,0));
        hline (minimap,
              (centerx-mapsize/2)*MINIMAPSIZE/universesize,
              (centery+mapsize/2)*MINIMAPSIZE/universesize-1,
	      (centerx+mapsize/2)*MINIMAPSIZE/universesize-1,
	      makecol(99,99,0));
        for (x=0;x<universesize;x++)
        {
    	   for (y=0;y<universesize;y++)
            {
                if (universe[x][y] > -1)
                {
                        masked_blit (star_minimap,minimap,
                        (stars[universe[x][y]].type%4)*TILESIZE/8,
                        (stars[universe[x][y]].type/4)*TILESIZE/8,
                        x*MINIMAPSIZE/universesize,
			y*MINIMAPSIZE/universesize,
			TILESIZE/8,TILESIZE/8);
                }
            }
	}
}

// drawing the map
void create_mainmap()
{
        int x,y,sx,sy;
        mainmap = create_bitmap (mapsize*TILESIZE,mapsize*TILESIZE);
	clear (mainmap);
// background scenery, only created once per game
	if (newgame)
        {
           starfield = create_bitmap (2*mainmap->w,2*mainmap->h);
	   clear (starfield);
	   newgame = FALSE;
           for (x=0;x<1000;x++)
	   {
               int color;
	       color = 60+random()%192;
	       sx = (1+random()%(starfield->w-2));
	       sy = (1+random()%(starfield->h-2));
	       switch (random()%20)
	       {
		  case 0:
                  case 1: circle (starfield,sx,sy,1,
                                 makecol(color/2,color/2,color/2));
			  putpixel (starfield,sx,sy,
                                   makecol(color,color,color));break;
		  case 2:
                  case 3: putpixel (starfield,sx+1,sy,
                                    makecol(color,color,color));
			  putpixel (starfield,sx+1,sy+1,
                                    makecol(color,color,color));
			  putpixel (starfield,sx,sy+1,
                                    makecol(color,color,color));
                          putpixel (starfield,sx,sy,
                                   makecol(color,color,color));break;
                  case 4: putpixel (starfield,sx,sy,
                                   makecol(color,color,color/3));break;
		  case 5:  if (random()%8 == 1)
                           {
                           circlefill (starfield,sx,sy,2,
                                      makecol(color,color,color));
                           circle (starfield,sx,sy,2,
                                  makecol(color/2,color/2,color/2));
                           putpixel (starfield,sx+2,sy-1,makecol(0,0,0));
                           putpixel (starfield,sx+1,sy-2,makecol(0,0,0));
                           putpixel (starfield,sx+2,sy+1,makecol(0,0,0));
                           putpixel (starfield,sx+1,sy+2,makecol(0,0,0));
                           putpixel (starfield,sx-2,sy-1,makecol(0,0,0));
                           putpixel (starfield,sx-1,sy-2,makecol(0,0,0));
                           putpixel (starfield,sx-2,sy+1,makecol(0,0,0));
                           putpixel (starfield,sx-1,sy+2,makecol(0,0,0));
                           };break;
                  default: putpixel (starfield,sx,sy,
                                    makecol(color,color,color));break;
               }
           }
        }
        blit (starfield,mainmap,
             (centerx-mapsize/2)*(int)(starfield->w/
	      (2.0*(universesize-mapsize))),
             (centery-mapsize/2)*(int)(starfield->h/
	      (2.0*(universesize-mapsize))),
	      0,0,mainmap->w,mainmap->h);
// actual map, generated whenever map is recentered
        for (x=centerx-mapsize/2;x<centerx+mapsize/2;x++)
        {
    	   for (y=centery-mapsize/2;y<centery+mapsize/2;y++)
            {
                if (universe[x][y] > -1)
                {
                        masked_blit (star_bitmap,mainmap,
                        (stars[universe[x][y]].type%4)*TILESIZE,
                        (stars[universe[x][y]].type/4)*TILESIZE,
                        (x+mapsize/2-centerx)*TILESIZE,
			(y+mapsize/2-centery)*TILESIZE,
			TILESIZE,TILESIZE);

			textprintf_centre (mainmap,font,
                        (x+mapsize/2-centerx)*TILESIZE+TILESIZE/2,
			(y+mapsize/2-centery)*TILESIZE+TILESIZE,
			makecol(200*stars[universe[x][y]].players_present[0]
				,96,96),"%s",
			starnames[stars[universe[x][y]].starnameindex].name);
                }
            }
	}
        if (centerx == mapsize/2)
	   vline (mainmap,0,0,(mainmap->h-1),makecol(199,199,0));
        if (centerx == universesize-mapsize/2)
           vline (mainmap,(mainmap->w-1),0,(mainmap->h-1),makecol(199,199,0));
        if (centery == mapsize/2)
           hline (mainmap,0,0,(mainmap->w-1),makecol(199,199,0));
        if (centery == universesize-mapsize/2)
           hline (mainmap,0,(mainmap->h-1),(mainmap->w-1),makecol(199,199,0));
}

int get_star_index()
{
        int xpos,ypos;
        xpos = (int)((mouse_x-12)/TILESIZE);
        ypos = (int)((mouse_y-12)/TILESIZE);
	xpos = xpos-mapsize/2+centerx;
	ypos = ypos-mapsize/2+centery;
	if (universe[xpos][ypos] != -1)
	   currentstar = stars[universe[xpos][ypos]].index;
	if (universe[xpos][ypos] != -1)
	   return stars[universe[xpos][ypos]].index;
	else
           return -1;
}

// display detailed info on selected planet
void show_planet_info(int index)
{
        exitplanetlist = FALSE; // change if return to map selected
}

// display info on selected star
void show_star_info(int index)
{
        int xpos,ypos;
        int i;
        xpos = (int)((mouse_x-12)/TILESIZE);
        ypos = (int)((mouse_y-12)/TILESIZE);
	xpos = xpos-mapsize/2+centerx;
	ypos = ypos-mapsize/2+centery;
	clear(infobox);
	textprintf (infobox,font,1,100,makecol(128,255,128),
                   "%d names available",size_of_starnames);
	if (index != -1)
        {
		textprintf (infobox,large_font,1,0,makecol(255,64,64),
                           "%s",starnames[stars[index].starnameindex].name);
	        textprintf (infobox,font,1,18,makecol(128,255,128),
                           "(%d,%d) Type:%d  Planets:%d",
			   stars[index].xpos,
			   stars[index].ypos,
			   stars[index].type,
                           stars[index].planets);
                for (i=0;i<stars[index].planets;i++)
                    textprintf (infobox,font,1,30+(i*12),
                               makecol(99,99,199),"Index:%d Population:%3.3f",
                               planets[stars[index].planetindex[i]].index,
                               planets[stars[index].
			       planetindex[i]].pop/1000.0);
        }
        else
        {
                textprintf (infobox,font,1,1,makecol(128,255,128),
                           "(%d,%d)",xpos,ypos);
        }
        scare_mouse();
        blit (infobox,screen,0,0,600,212,infobox->w,infobox->h);
        unscare_mouse();
}

// centers map when clicked
void center_map(int x,int y,int special)
{
        int xpos,ypos;
	switch (special)
        {
	        case -1: // mainmap centering
                       {
                        xpos = (int)((x-12)/TILESIZE);
                        ypos = (int)((y-12)/TILESIZE);
	                xpos = xpos-mapsize/2+centerx;
	                ypos = ypos-mapsize/2+centery;
                       };break;
                case 0:	// human player homeworld
                       {
		        xpos = stars[planets[0].starindex].xpos;
                        ypos = stars[planets[0].starindex].ypos;
                       };break;
                case 1:	// minimap centering
		       {
		        xpos = (int)((x-600)/
		               ((float)MINIMAPSIZE/(float)universesize));
			ypos = (int)((y- 12)/
			       ((float)MINIMAPSIZE/(float)universesize));
                       };break;
                case 2: // center on currentstar
		       {
			xpos = stars[currentstar].xpos;
                        ypos = stars[currentstar].ypos;
                       };break;
                default:
		       {
			xpos = 0;
			ypos = 0;
                       };break;
        }
        centerx = xpos;
        centery = ypos;
        if (centerx < mapsize/2)
           centerx = mapsize/2;
        if (centerx > universesize-mapsize/2)
           centerx = universesize-mapsize/2;
        if (centery < mapsize/2)
           centery = mapsize/2;
        if (centery > universesize-mapsize/2)
           centery = universesize-mapsize/2;
	create_minimap();  // these both must be destroyed before
        create_mainmap();  // calling this function
        scare_mouse();
	blit (minimap,screen,0,0,600,12,minimap->w,minimap->h);
        blit (mainmap,screen,0,0,12,12,mainmap->w,mainmap->h);
        unscare_mouse();
}


// building
void building()
{
        int i;
        for (i=0;i<numplanets;i++)
            ;
}

// population growth
void growth()
{
        int i,growth,oldpop;
	float growthfactor;
        for (i=0;i<numplanets;i++)
        {
// add building and race modifiers,starvation effects etc. etc.
                growthfactor = (100.0*
                               (float)(planets[i].maxpop-planets[i].pop))/
                               (float)(planets[i].maxpop+1);
                ((growthfactor > 50) ?
                 (growth = (int) (planets[i].pop*((97.0+random()%7+
                                 (random()%10)/10.0)/100.0)*
                                 (6.0-sqrt((growthfactor-50.0)/2.0)))/100.0) :
                 (growth = (int) (planets[i].pop*((97.0+random()%7+
                                 (random()%10)/10.0)/100.0)*
		                 (5.2-sqrt((50.0-growthfactor)/2.0)))/100.0));
		oldpop = planets[i].pop;
                if (planets[i].pop > 0)
                   planets[i].pop += growth;
                if (planets[i].pop >= planets[i].maxpop)
                   planets[i].pop = planets[i].maxpop;
                planets[i].popchange = planets[i].pop - oldpop;
        }
}

// move ships
void movement()
{
}

// combat
void combat()
{
}





