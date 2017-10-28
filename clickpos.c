#include "sigma957.h"

// mouseclick positioning, defines locations of graphical elements
int mousepos(int whichscreen,int mousex,int mousey)
{
        typedef struct clickpos	clickpos;

	struct clickpos
        {
                int x1;
                int y1;
                int x2;
                int y2;
        };

        int i;

        clickpos selectscreen[] = {
                                  { 230,220,570,275 },
                                  { 230,275,570,330 },
                                  { 230,330,570,385 },
                                  { 230,385,570,440 },
                                  };
        clickpos gamescreen[] = {
                                {  12, 12,588,588 }, // mainmap
			        { 600, 12,788,200 }, // minimap
				{ 600,212,788,388 }, // infobox
                                { 600,400,694,447 }, // first column
                                { 600,447,694,494 },
                                { 600,494,694,541 },
                                { 600,541,694,588 },
                                { 694,400,788,447 }, // second column
                                { 694,447,788,494 },
                                { 694,494,788,541 },
                                { 694,541,788,588 },
                                };
        clickpos gameoptionscreen[] = {
	                              { 12,12,100,32 },    // proceed
				      { 100,100,200,125 }, // numplayers
				      { 100,130,200,155	}, // race
                                      };
	clickpos racelistscreen[] = {
	                            { 12,44,200,64 }, // first race
	                            };
        clickpos planetlistscreen[] =	{
	                                { 776, 12,788, 32 }, // exit
	                                {  12, 12,200, 32 }, // namesort
					{ 200, 12,325, 32 }, // popsort
					{ 400, 12,500, 32 }, // indsort
					{ 776, 44,788,108 }, // pageup
					{ 776,140,788,172 }, // lineup
					{ 776,460,788,492 }, // linedown
					{ 776,524,788,588 }, // pagedown
				        };
        clickpos yesornoscreen[] = {
	                           { 295,299,373,338 },
                                   };
        switch (whichscreen)
        {
        case SELECTSCREEN: {
                           for (i=0;i<4;i++)
                           {
                               if ((selectscreen[i].x1 < mousex) &&
                                   (selectscreen[i].x2 > mousex) &&
                                   (selectscreen[i].y1 < mousey) &&
                                   (selectscreen[i].y2 > mousey))
                                   {return i;break;}
                           }
                           {return -1;break;}
                           }
        case GAMESCREEN: {
	                 for (i=0;i<11;i++)
			 {
                             if ((gamescreen[i].x1 < mousex) &&
                                 (gamescreen[i].x2 > mousex) &&
                                 (gamescreen[i].y1 < mousey) &&
                                 (gamescreen[i].y2 > mousey))
                                 {return i;break;}
                         }
                         {return -1;break;}
                         }
        case GAMEOPTIONS: {
                          for (i=0;i<3;i++)
			  {
                              if ((gameoptionscreen[i].x1 < mousex) &&
                                  (gameoptionscreen[i].x2 > mousex) &&
                                  (gameoptionscreen[i].y1 < mousey) &&
                                  (gameoptionscreen[i].y2 > mousey))
	                          {return i;break;}
                          }
                          {return -1;break;}
                          }
        case LISTRACES: { // undone
	                return (mousey%16);break;
			}
        case PLANETLIST: {
                         for (i=0;i<8;i++)
                         {
                             if ((planetlistscreen[i].x1 < mousex) &&
                                 (planetlistscreen[i].x2 > mousex) &&
                                 (planetlistscreen[i].y1 < mousey) &&
                                 (planetlistscreen[i].y2 > mousey))
                                 {return i;break;}
			 }
                         {return -1;break;}
                         }
        case YESORNO: {
	              if ((yesornoscreen[0].x1 < mousex) &&
                          (yesornoscreen[0].x2 > mousex) &&
                          (yesornoscreen[0].y1 < mousey) &&
                          (yesornoscreen[0].y2 > mousey))
                          {return 1;break;}
                      else {return 0;break;}
		      }
        default: return -1;
        }
        return -1;	 // not needed, but, just in case...
}
