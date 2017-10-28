#include "sigma957.h"

// drawing titlescreen(s)
void display_title()
{
        BITMAP *titlescreen;
	BITMAP *pentagon;
        char *text;
	fixed apu;
	int growing;
	char version[22],datetime[35];
	V3D _v[] = {{100<<16, 25<<16,0,0,0,makecol(255,255,255)},
                    {187<<16, 87<<16,0,0,0,makecol(0,255,0)},
                    {154<<16,190<<16,0,0,0,makecol(0,0,255)},
                    { 46<<16,190<<16,0,0,0,makecol(255,0,0)},
                    { 13<<16, 87<<16,0,0,0,makecol(255,255,0)}};
        V3D *vertex[] =	{&_v[0],&_v[1],&_v[2],&_v[3],&_v[4]};
	pentagon = create_bitmap(200,200);
	clear (pentagon);
        scare_mouse();
        text = "";
//	version = "Version: xxx.xxx.xxx";
	sprintf (version,"Version: %d.%d.%d",
                 VERSION_MAJOR,VERSION_MINOR,VERSION_PATCH);
//	datetime = "Compiled: Mmm.dd.yyyy hh:mm:ss   ";
	sprintf(datetime,"Compiled: %s %s",__DATE__,__TIME__);
        check_cpu();
        titlescreen = load_bitmap("title.bmp", NULL);
	textout (screen,font,version,10,(SCREEN_H-20),makecol(128,0,128));
	textout (screen,font,datetime,10,(SCREEN_H-10),makecol(128,0,128));
        textout (screen,font,allegro_id,0,0,makecol(128,128,0));
        switch (os_type)
        {
        case OSTYPE_WIN95 : text = "Windows 95";break;
        case OSTYPE_WIN98 : text = "Windows 98";break;
        default: text = "Unsupported OS";
        }
        textout (screen,font,text,0,10,makecol(128,128,0));
        textout (screen,font,cpu_vendor,0,20,makecol(128,128,0));
        switch (cpu_family)
        {
        case 3 : text = "386";break;
        case 4 : text = "486";break;
        case 5 : text = "Pentium";break;
        case 6 : text = "PPro";break;
        default: text = "Unknown CPU family";break;
        }
        textout (screen,font,text,0,30,makecol(128,128,0));
        textprintf (screen,font,0,40,makecol(128,128,0),
                   "CPU subtype %d",cpu_model);
        if (cpu_fpu == TRUE) text = "FPU detected";
           else text = "No FPU detected";
        textout (screen,font,text,0,50,makecol(128,128,0));
	textprintf (screen,font,0,60,makecol(128,128,0),"Mouse buttons: %d",
		   num_mouse_buttons);
        blit (titlescreen,screen,0,0,(SCREEN_W-titlescreen->w)/2,
                                    (SCREEN_H-titlescreen->h)/2,
                                     titlescreen->w,titlescreen->h);
        destroy_bitmap (titlescreen);
        while (!(mouse_b & 1))
	{
	        polygon3d (pentagon,POLYTYPE_GCOL,NULL,5,vertex);
		apu = vertex[4]->c;
	        vertex[4]->c = vertex[3]->c;
	        vertex[3]->c = vertex[2]->c;
	        vertex[2]->c = vertex[1]->c;
	        vertex[1]->c = vertex[0]->c;
	        vertex[0]->c = apu;
		apu = vertex[0]->y;
		if (apu == itofix(25)) growing = TRUE;
		if (apu == itofix(15)) growing = FALSE;
		vertex[0]->y = growing ? vertex[0]->y - itofix(1) :
			       vertex[0]->y + itofix(1);
		vertex[1]->x = growing ? vertex[1]->x + itofix(1) :
			       vertex[1]->x - itofix(1);
		vertex[2]->y = growing ? vertex[2]->y + itofix(1) :
			       vertex[2]->y - itofix(1);
		vertex[2]->x = growing ? vertex[2]->x + itofix(1) :
			       vertex[2]->x - itofix(1);
		vertex[3]->y = growing ? vertex[3]->y + itofix(1) :
			       vertex[3]->y - itofix(1);
		vertex[3]->x = growing ? vertex[3]->x - itofix(1) :
			       vertex[3]->x + itofix(1);
		vertex[4]->x = growing ? vertex[4]->x - itofix(1) :
			       vertex[4]->x + itofix(1);
		blit (pentagon,screen,0,0,300,0,200,200);
		clear (pentagon);
		rest(100);
	}
        while (mouse_b & 1);
        unscare_mouse();
	destroy_bitmap(pentagon);
}
