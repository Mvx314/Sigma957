#include "sigma957.h"

// place newly created planet in sorted list
void sort_planets()
{
        int i,j,temp;
        int earliest;
        // sort by planet name
        for (i=0;i<numplanets;i++)
        {
            earliest = i;
            for (j=i;j<numplanets;j++)
            {
                if (strcmp
                   (starnames[stars[planets[planets_by_name[earliest]]
                    .starindex].starnameindex].name,
                    starnames[stars[planets[planets_by_name[j]]
                    .starindex].starnameindex].name) > 0)

                    earliest = j;
            }
            temp = planets_by_name[earliest];
            while (earliest > i)
            {
                  planets_by_name[earliest] = planets_by_name[earliest-1];
                  earliest--;
            }
            planets_by_name[earliest] = temp;
        }

        // sort by planet population
        for (i=0;i<numplanets;i++)
        {
            earliest = i;
            for (j=i;j<numplanets;j++)
            {
                if (planets[planets_by_population[earliest]].pop <
                    planets[planets_by_population[j]].pop)

                    earliest = j;
            }
            temp = planets_by_population[earliest];
            while (earliest > i)
            {
                  planets_by_population[earliest] =
                  planets_by_population[earliest-1];
                  earliest--;
            }
            planets_by_population[earliest] = temp;
        }
        // sort by planet industry
        for (i=0;i<numplanets;i++)
        {
            earliest = i;
            for (j=i;j<numplanets;j++)
            {
                if (planets[planets_by_industry[earliest]].industry <
                    planets[planets_by_industry[j]].industry)

                    earliest = j;
            }
            temp = planets_by_industry[earliest];
            while (earliest > i)
            {
                  planets_by_industry[earliest] =
                  planets_by_industry[earliest-1];
                  earliest--;
            }
            planets_by_industry[earliest] = temp;
        }
}

// show list of planets
void list_planets()
{
        static int sort_by = 0;
        static int top_index = 0;
        clear_screen();
        refresh_planetlist(sort_by,top_index);
        exitplanetlist = FALSE;
        do
        {
                do
                {
                } while (!(mouse_b & 1));

                while (mouse_b & 1)
                {
                };

                switch (mousepos(PLANETLIST,mouse_x,mouse_y))
                {
                case 0: exitplanetlist = TRUE;break;
                case 1: if (sort_by == 0) sort_by = 10;
                        else sort_by = 0;
                        refresh_planetlist(sort_by,top_index);
                        break;
                case 2: if (sort_by == 1) sort_by = 11;
                        else sort_by = 1;
                        refresh_planetlist(sort_by,top_index);
                        break;
                case 3: if (sort_by == 2) sort_by = 12;
                        else sort_by = 2;
                        refresh_planetlist(sort_by,top_index);
                        break;
                case 4: top_index -= 26;
                        if (top_index < 0)
                           top_index = 0;
                        refresh_planetlist(sort_by,top_index);
                        break;
                case 5: top_index -= 1;
                        if (top_index < 0)
                           top_index = 0;
                        refresh_planetlist(sort_by,top_index);
                        break;
                case 6: top_index += 1;
                        if (top_index > numplanets-26)
                           top_index = numplanets-26;
                        refresh_planetlist(sort_by,top_index);
                        break;
                case 7: top_index += 26;
                        if (top_index > numplanets-26)
                           top_index = numplanets-26;
                        refresh_planetlist(sort_by,top_index);
                        break;
                case 8: select_build(0);break;
                default: break;
                }
        } while (exitplanetlist == FALSE);
}

// redraw the mainscreen when necessary
void refresh_planetlist(int sort_by,int top_index)
{
        BITMAP *planetlistscreen;
	int i = top_index;
        int line = 0;
        const int lines = 26;
        planetlistscreen = create_bitmap (SCREEN_W,SCREEN_H);
        clear_to_color (planetlistscreen,makecol(32,32,32));
        scare_mouse();
        text_mode (makecol(0,0,96));
        textprintf (planetlistscreen,large_font,14,13,
                   makecol(200,200,200),"PLANET");
        textprintf (planetlistscreen,large_font,200,13,
                   makecol(200,200,200),"POPULATION");
        textprintf (planetlistscreen,large_font,325,13,
                   makecol(200,200,200),"Growth");
        textprintf (planetlistscreen,large_font,400,13,
                   makecol(200,200,200),"INDUSTRY");
        textprintf (planetlistscreen,large_font,776,13,
                   makecol(255,0,0),"X");
        while (i-top_index < lines)
        {
        switch (sort_by)
        {
                case 0: textprintf (planetlistscreen,large_font,
                        14,45+21*(line%lines),makecol(200,200,200),"%s",
                        planets[planets_by_name[i]].name);
                        textprintf (planetlistscreen,large_font,
                        200,45+21*(line%lines),makecol(200,200,200),"%8d",
                        planets[planets_by_name[i]].pop);
                        textprintf (planetlistscreen,large_font,
                        325,45+21*(line%lines),makecol(200,200,200),"%+6d",
                        planets[planets_by_name[i]].popchange);
                        textprintf (planetlistscreen,large_font,
                        400,45+21*(line%lines),makecol(200,200,200),"%5d",
                        planets[planets_by_name[i]].industry);break;
                case 1: textprintf (planetlistscreen,large_font,
                        14,45+21*(line%lines),makecol(200,200,200),"%s",
                        planets[planets_by_population[i]].name);
                        textprintf (planetlistscreen,large_font,
                        200,45+21*(line%lines),makecol(200,200,200),"%8d",
                        planets[planets_by_population[i]].pop);
                        textprintf (planetlistscreen,large_font,
                        325,45+21*(line%lines),makecol(200,200,200),"%+6d",
                        planets[planets_by_population[i]].popchange);
                        textprintf (planetlistscreen,large_font,
                        400,45+21*(line%lines),makecol(200,200,200),"%5d",
                        planets[planets_by_population[i]].industry);break;
                case 2: textprintf (planetlistscreen,large_font,
                        14,45+21*(line%lines),makecol(200,200,200),"%s",
                        planets[planets_by_industry[i]].name);
                        textprintf (planetlistscreen,large_font,
                        200,45+21*(line%lines),makecol(200,200,200),"%8d",
                        planets[planets_by_industry[i]].pop);
                        textprintf (planetlistscreen,large_font,
                        325,45+21*(line%lines),makecol(200,200,200),"%+6d",
                        planets[planets_by_industry[i]].popchange);
                        textprintf (planetlistscreen,large_font,
                        400,45+21*(line%lines),makecol(200,200,200),"%5d",
                        planets[planets_by_industry[i]].industry);break;
                case 10: textprintf (planetlistscreen,large_font,
                        14,45+21*(line%lines),makecol(200,200,200),"%s",
                        planets[planets_by_name[numplanets-i-1]].name);
                        textprintf (planetlistscreen,large_font,
                        200,45+21*(line%lines),makecol(200,200,200),"%8d",
                        planets[planets_by_name[numplanets-i-1]].pop);
                        textprintf (planetlistscreen,large_font,
                        325,45+21*(line%lines),makecol(200,200,200),"%+6d",
                        planets[planets_by_name[i]].popchange);
                        textprintf (planetlistscreen,large_font,
                        400,45+21*(line%lines),makecol(200,200,200),"%5d",
                        planets[planets_by_name[numplanets-i-1]].industry);
                        break;
                case 11: textprintf (planetlistscreen,large_font,
                        14,45+21*(line%lines),makecol(200,200,200),"%s",
                        planets[planets_by_population[numplanets-i-1]].name);
                        textprintf (planetlistscreen,large_font,
                        200,45+21*(line%lines),makecol(200,200,200),"%8d",
                        planets[planets_by_population[numplanets-i-1]].pop);
                        textprintf (planetlistscreen,large_font,
                        325,45+21*(line%lines),makecol(200,200,200),"%+6d",
                        planets[planets_by_population[i]].popchange);
                        textprintf (planetlistscreen,large_font,
                        400,45+21*(line%lines),makecol(200,200,200),"%5d",
                        planets[planets_by_population[numplanets-i-1]].
                        industry);break;
                case 12: textprintf (planetlistscreen,large_font,
                        14,45+21*(line%lines),makecol(200,200,200),"%s",
                        planets[planets_by_industry[numplanets-i-1]].name);
                        textprintf (planetlistscreen,large_font,
                        200,45+21*(line%lines),makecol(200,200,200),"%8d",
                        planets[planets_by_industry[numplanets-i-1]].pop);
                        textprintf (planetlistscreen,large_font,
                        325,45+21*(line%lines),makecol(200,200,200),"%+6d",
                        planets[planets_by_industry[i]].popchange);
                        textprintf (planetlistscreen,large_font,
                        400,45+21*(line%lines),makecol(200,200,200),"%5d",
                        planets[planets_by_industry[numplanets-i-1]].
                        industry);break;
                default: break;
        };
        i++;
        line = i-top_index;
        }
	blit (horbeam,planetlistscreen,0,0,  0,  0,horbeam->w,horbeam->h);
	blit (horbeam,planetlistscreen,0,0,200,  0,horbeam->w,horbeam->h);
	blit (horbeam,planetlistscreen,0,0,400,  0,horbeam->w,horbeam->h);
	blit (horbeam,planetlistscreen,0,0,600,  0,horbeam->w,horbeam->h);
	blit (horbeam,planetlistscreen,0,0,  0, 32,horbeam->w,horbeam->h);
	blit (horbeam,planetlistscreen,0,0,200, 32,horbeam->w,horbeam->h);
	blit (horbeam,planetlistscreen,0,0,400, 32,horbeam->w,horbeam->h);
	blit (horbeam,planetlistscreen,0,0,600, 32,horbeam->w,horbeam->h);
	blit (horbeam,planetlistscreen,0,0,  0,588,horbeam->w,horbeam->h);
	blit (horbeam,planetlistscreen,0,0,200,588,horbeam->w,horbeam->h);
	blit (horbeam,planetlistscreen,0,0,400,588,horbeam->w,horbeam->h);
	blit (horbeam,planetlistscreen,0,0,600,588,horbeam->w,horbeam->h);
	blit (verbeam,planetlistscreen,0,0,  0,  0,verbeam->w,verbeam->h);
	blit (verbeam,planetlistscreen,0,0,  0,200,verbeam->w,verbeam->h);
	blit (verbeam,planetlistscreen,0,0,  0,400,verbeam->w,verbeam->h);
	blit (verbeam,planetlistscreen,0,0,788,  0,verbeam->w,verbeam->h);
	blit (verbeam,planetlistscreen,0,0,788,200,verbeam->w,verbeam->h);
	blit (verbeam,planetlistscreen,0,0,788,400,verbeam->w,verbeam->h);
	draw_sprite (planetlistscreen,cornbeam,0,0);
	draw_sprite_v_flip (planetlistscreen,cornbeam,0,588);
	draw_sprite_h_flip (planetlistscreen,cornbeam,788,0);
	draw_sprite_vh_flip (planetlistscreen,cornbeam,788,588);
	draw_sprite (planetlistscreen,vtbeam,0,32);
	draw_sprite_h_flip (planetlistscreen,vtbeam,788,32);
        draw_sprite (planetlistscreen,verarrow1,776,460);
        draw_sprite (planetlistscreen,verarrow2,776,524);
        draw_sprite_v_flip (planetlistscreen,verarrow1,776,140);
        draw_sprite_v_flip (planetlistscreen,verarrow2,776,44);
        blit (planetlistscreen,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        unscare_mouse();
        text_mode (0);
        destroy_bitmap (planetlistscreen);
}

// list and select from available races
int list_races()
{
        int i;
        int selected = 0;
        BITMAP *racelistscreen;
        racelistscreen = create_bitmap (SCREEN_W,SCREEN_H);
        clear_to_color (racelistscreen,makecol(32,32,32));
        scare_mouse();
        text_mode (makecol(0,96,96));
        textprintf (racelistscreen,large_font,14,13,
                   makecol(200,200,200),"AVAILABLE RACES");

        for (i=0;i<MAXRACES;i++)
        {
                textprintf (racelistscreen,large_font,
                           14,45+21*i,makecol(200,200,200),"%s",
                           races[i].name);
                textprintf (racelistscreen,large_font,
                           200,45+21*i,makecol(200,200,200),"%8d",
                           races[i].attributes1);
        }
	blit (horbeam,racelistscreen,0,0,  0,  0,horbeam->w,horbeam->h);
	blit (horbeam,racelistscreen,0,0,200,  0,horbeam->w,horbeam->h);
	blit (horbeam,racelistscreen,0,0,400,  0,horbeam->w,horbeam->h);
	blit (horbeam,racelistscreen,0,0,600,  0,horbeam->w,horbeam->h);
	blit (horbeam,racelistscreen,0,0,  0, 32,horbeam->w,horbeam->h);
	blit (horbeam,racelistscreen,0,0,200, 32,horbeam->w,horbeam->h);
	blit (horbeam,racelistscreen,0,0,400, 32,horbeam->w,horbeam->h);
	blit (horbeam,racelistscreen,0,0,600, 32,horbeam->w,horbeam->h);
	blit (horbeam,racelistscreen,0,0,  0,588,horbeam->w,horbeam->h);
	blit (horbeam,racelistscreen,0,0,200,588,horbeam->w,horbeam->h);
	blit (horbeam,racelistscreen,0,0,400,588,horbeam->w,horbeam->h);
	blit (horbeam,racelistscreen,0,0,600,588,horbeam->w,horbeam->h);
	blit (verbeam,racelistscreen,0,0,  0,  0,verbeam->w,verbeam->h);
	blit (verbeam,racelistscreen,0,0,  0,200,verbeam->w,verbeam->h);
	blit (verbeam,racelistscreen,0,0,  0,400,verbeam->w,verbeam->h);
	blit (verbeam,racelistscreen,0,0,788,  0,verbeam->w,verbeam->h);
	blit (verbeam,racelistscreen,0,0,788,200,verbeam->w,verbeam->h);
	blit (verbeam,racelistscreen,0,0,788,400,verbeam->w,verbeam->h);
	draw_sprite (racelistscreen,cornbeam,0,0);
	draw_sprite_v_flip (racelistscreen,cornbeam,0,588);
	draw_sprite_h_flip (racelistscreen,cornbeam,788,0);
	draw_sprite_vh_flip (racelistscreen,cornbeam,788,588);
	draw_sprite (racelistscreen,vtbeam,0,32);
	draw_sprite_h_flip (racelistscreen,vtbeam,788,32);
        draw_sprite (racelistscreen,verarrow1,776,460);
        draw_sprite (racelistscreen,verarrow2,776,524);
        draw_sprite_v_flip (racelistscreen,verarrow1,776,140);
        draw_sprite_v_flip (racelistscreen,verarrow2,776,44);
        blit (racelistscreen,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        unscare_mouse();
        do
        {
                do
                {
                } while (!(mouse_b & 1));

                while (mouse_b & 1)
                {
                };
                selected = mousepos(LISTRACES,mouse_x,mouse_y);
        } while (0);
        text_mode (0);
        destroy_bitmap (racelistscreen);
        return selected;
}
