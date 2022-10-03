#include "Header.h"
#include "stdio.h"
#include "stdlib.h"

#define NOT_INITIALIZATE -1

//timer
int gl_time = 0;
int MAXH, MAXW, WHSIZE, WWSIZE;
#define MAX_BUILDERS 6
#define MAX_ROADT 2

SDL_Texture* road_tmpt = NULL;
SDL_Texture** builder;

#define MAX_ROAD_LEN 13
int MAX_ROAD_LINE = NOT_INITIALIZATE;
#define TEXT_SIZE 16

typedef struct {
    int** road;
} roads;

roads m1;

void GENFULL(roads* m, int ml, int mln)
{
   

    int c = 0;
    rep(i, ml)
    {
        rep(j, mln)
        {
            puts("gg");
            if (i % 4 == 1) {
                m->road[i][j] = MAX_BUILDERS + 1;
                if (j == 1 + mln / 2)
                    m->road[i][j] = MAX_BUILDERS + 2;
            }
            if (j < (mln * 0.35)) {
                m->road[i][j] = c + random(2);
                c++;
                if (c >= 5)
                    c = 0;
            }
            c = 4;
            if (j >= (mln * 0.7)) {
                m->road[i][j] = c - random(2);
                c--;
                if (c <= 1)
                    c = 5;
            }
           
        }
       // memset(m[i], 46, mln);
    }
    puts("ggrer");
    return;
}

int gen_roadt(){
	int MAXH=MAXW/4;
	 rep(i, MAX_ROAD_LEN)
        {
            rep(j, MAX_ROAD_LINE)
            {
               view_textureto(builder[m1.road[i][j]],j*MAXH,i*MAXH,MAXH,MAXH);
            }
           // puts("");
        } 
	return 1;
}




void GENLAST()
{
}


int main(int argc, char* argv[])
{
    MAINDISPINIT;
    RES_TO_WHSIZE;

    INITTTF;
    INIT_AUDIO;
    IIMCEFONT("s.ttf", TEXT_SIZE);
    INITIIMCE;
    TEXT_SCREEN_WIDTH = WWSIZE;
    IIMCE_TEXT_WRAPPER = 1;
    CUR_TIME = 1;
  



    WWSIZE = 800;
    WHSIZE = 600;
    MAXH = WHSIZE / MAX_ROAD_LEN;
    MAXW = MAXH;
	  INITWINDOW;
	  	builder = LOADTEXTURES(8,"",".png",0);
    MAX_ROAD_LINE = WHSIZE / MAXH + 1;
    //init road road
    m1.road = (int**)malloc(sizeof(int*) * (MAX_ROAD_LINE));
    rep(i, (MAX_ROAD_LINE))
    {
        m1.road[i] = (int*)malloc(sizeof(int) * (MAX_ROAD_LEN));
        memset(m1.road[i], (int)0, MAX_ROAD_LINE * sizeof(int));
    };

   GENFULL(&m1.road, MAX_ROAD_LINE, MAX_ROAD_LEN);
    while (1)
    {
        IIMCE_GET_EVENT();
       // exit(0);
        rep(i, MAX_ROAD_LEN)
        {
            rep(j, MAX_ROAD_LINE)
            {
                printf("%d", m1.road[i][j]);
            }
            puts("");
        }
		if(gen_roadt())
		 REDRAW;
        fflush(stdout);
    }
   
}
