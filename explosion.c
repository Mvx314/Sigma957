#include "allegro.h"

#define SIZE 79
#define CENTER ((SIZE/2)+1)
#define RATE 6
#define RESTRATE 15
#define makegrey(A) (makecol((A),(A),(A)))

void explosion(int size,int locx,int locy)
{
        int rate,i,j,c,r,stillgoing,redness,circlecolor;
	int blow[SIZE][SIZE];
	int oldblow[SIZE][SIZE];
	BITMAP *explosion;

	explosion = create_bitmap(SIZE,SIZE);
	for (i=0;i<SIZE;i++)
	    for (j=0;j<SIZE;j++)
	        oldblow[i][j] = blow[i][j] = 0;
        oldblow[CENTER][CENTER] = blow[CENTER][CENTER] = 255;
	redness = 255;
	c = RESTRATE-1;
	r = 2;
	rate = RATE-c/3;
        scare_mouse();
	clear(explosion);
	do
	{
		stillgoing = FALSE;
		circlecolor = 255-4*r;
		if (r < SIZE/2)
		{
		   circlefill (explosion,SIZE/2,SIZE/2,r+1,
		              makegrey(2*circlecolor/3));
		   circlefill (explosion,SIZE/2,SIZE/2,r,
		              makegrey(circlecolor-r));
		   circlefill (explosion,SIZE/2,SIZE/2,r-1,
		              makegrey(circlecolor-r));
		   circlefill (explosion,SIZE/2,SIZE/2,r-2,
		              makegrey(2*circlecolor/3));
		   circlefill (explosion,SIZE/2,SIZE/2,r-3,
		              makegrey((circlecolor-2*r)/2));
		}
                for (i=0;i<SIZE;i++)
	            for (j=0;j<SIZE;j++)
		        oldblow[i][j] = blow[i][j];
	        for (i=1;i<SIZE-1;i++)
	            for (j=1;j<SIZE-1;j++)
		    {
                        if (oldblow[i][j] > 0) stillgoing = TRUE;

		        if ((oldblow[i][j] > 0) && (random()%4 == 1))
			{
				blow[i-1][j-1] = oldblow[i][j]-2*rate;
				blow[i-1][j] = oldblow[i][j]-rate;
				blow[i-1][j+1] = oldblow[i][j]-2*rate;
				blow[i][j-1] = oldblow[i][j]-rate;
				blow[i][j+1] = oldblow[i][j]-rate;
				blow[i+1][j-1] = oldblow[i][j]-2*rate;
				blow[i+1][j] = oldblow[i][j]-rate;
				blow[i+1][j+1] = oldblow[i][j]-2*rate;
                                blow[i][j] = oldblow[i][j]-rate/3;
                        }
                    }
		if (blow[CENTER][CENTER] < 40)
		   redness -= 3*rate;
                if (redness < 0)
		   redness = 0;
                for (i=0;i<SIZE;i++)
	            for (j=0;j<SIZE;j++)
		    {
		        if (blow[i][j] > 127)
		           putpixel (explosion,i,j,
                                    makecol (redness,255-blow[i][j]/16,
                                    2*(blow[i][j])-127));
                        else if (blow[i][j] > 0)
			   putpixel (explosion,i,j,
			            makecol (redness,2*blow[i][j],0));
                        else if (r > SIZE/2)
                           putpixel (explosion,i,j,makegrey(0));
		    }
                blit (explosion,screen,0,0,locx,locy,
		      explosion->w,explosion->h);
                rest(RESTRATE-c);
		c--;
		r+=2;
		rate = RATE-c/3;
		if (c < 1)
		   c = 1;
        }  while (stillgoing);
        unscare_mouse();
	destroy_bitmap(explosion);
}
