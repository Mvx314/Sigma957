#include "sigma957.h"
#include <allegttf.h> // all fonts loaded here

void clear_screen()
{
        scare_mouse();
        clear (screen);
        unscare_mouse();
}

int yes_or_no()
{
        BITMAP *background;
        BITMAP *box;
        int truth;
        int bw = 400;
        int bh = 200;
        int bx = 200;
        int by = 200;
        background = create_bitmap (bw,bh);
        box = create_bitmap (bw,bh);
        clear (box);
        scare_mouse();
        blit (mainscreen,background,bx,by,0,0,bw,bh);
        rect (box,0,0,bw-1,bh-1,makecol(255,255,255));
        textout_centre (box,extra_large_font,"Are you sure?",
                       bw/2,25,makecol(255,255,0));
        textout_centre (box,extra_large_font,"YES",
                       bw/3,bh/2,makecol(0,255,0));
        rect (box, bw/3-39,bh/2-2,bw/3+39,bh/2+37,makecol(255,255,255));
        textout_centre (box,extra_large_font,"NO",
                       2*bw/3,bh/2,makecol(255,0,0));
        rect (box, 2*bw/3-39,bh/2-2,2*bw/3+39,bh/2+37,makecol(255,255,255));
        draw_trans_sprite (mainscreen,box,bx,by);
        blit (mainscreen,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        unscare_mouse();
        do
        {
        }
        while  (!(mouse_b & 1));
        while (mouse_b & 1);
        switch (mousepos(YESORNO,mouse_x,mouse_y))
        {
                case 0: truth = FALSE;break;
                case 1: truth = TRUE;break;
                default: truth = FALSE;break;
        };
        scare_mouse();
        blit (background,mainscreen,0,0,bx,by,bw,bh);
        refresh_mainscreen();
        unscare_mouse();
        destroy_bitmap(background);
        destroy_bitmap(box);
        return truth;
}

void load_fonts()
{
	font = load_ttf_font_ex("s957main.ttf",8,8,ALLEGTTF_NOSMOOTH);
	large_font = load_ttf_font_ex("s957main.ttf",12,12,ALLEGTTF_NOSMOOTH);
        extra_large_font = load_ttf_font_ex("s957main.ttf",24,24,
                           ALLEGTTF_NOSMOOTH);
}

void unload_fonts()
{
        destroy_font(font);
        destroy_font(large_font);
        destroy_font(extra_large_font);
}

