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
SDL_Texture* hudt = NULL;
SDL_Texture* mn = NULL;
SDL_Texture* fog_t = NULL;
    obj player;
MUS_SYS* mainmusic;
int MAX_ROAD_LEN = 13;
int MAX_ROAD_LINE = NOT_INITIALIZATE;
#define TEXT_SIZE 32

typedef struct {
    char** road;
} roads;

roads m1;
double roady = 0;
int WL = 1;


void GENFULL(roads* m, int ml, int mln)
{


    rep(i, ml)
    {
        int c = 0;
        int d = 6;
       memset((void*)m->road[i], MAX_BUILDERS, mln-2);
        rep(j, mln)
        {
       
          //  puts("gg");
            if (i % 4 == 1) {
                m->road[i][j] = MAX_BUILDERS + 0;
                if (j == mln / 2)
                    m->road[i][j] = MAX_BUILDERS + 1;
            }
            if (j <= (mln * (0.3 + (double)RANDOM(2) / 15))) {
                m->road[i][j] = c + RANDOM(2); 
                c+=(1+RANDOM(3));
               if (c >= 6)
                    c = 0;
            }
            if (j > (mln * (0.66 - (double)RANDOM(2) / 15))) {
                m->road[i][j] = d - RANDOM(2);
                d -= (2);
                if (d <= 1)
                    d = 2;
            }
        }
        // memset(m[i], 46, mln);
    }
   // puts("ggrer");
    return;
}


typedef struct {
  // char t[64];
    SDL_Texture* t;
    char txt[768];
    char isgood[5];
} food;




food obt[32];
int maxobt = 0;
#define maxobt_onscreen 10
obj bonus[maxobt_onscreen];

int curobt_onscreen = 0;
void GENLAST(roads* m, int mln)
{
    WL++;
    int i = 0;
    {
        int c = 0;
        int d = 6;
        memset((void*)m->road[i], MAX_BUILDERS, mln - 2);
        rep(j, mln)
        {

           // puts("gg");
            if (WL % 4 == 1) {
                m->road[i][j] = MAX_BUILDERS + 0;
                if (j == mln / 2)
                    m->road[i][j] = MAX_BUILDERS + 1;
            }
            if (j <= (mln * (0.2 + (double)RANDOM(2) / 15))) {
                m->road[i][j] = c + RANDOM(2);
                c += (1 + RANDOM(3));
                if (c >= 6)
                    c = 0;
            }
            if (j > (mln * (0.7 - (double)RANDOM(2) / 15))) {
                m->road[i][j] = d - RANDOM(2);
                d -= (2);
                if (d <= 1)
                    d = 2;
            }


        
        
        }

                    if (rand() % 10 == 1) {
            if (curobt_onscreen > maxobt_onscreen)
                curobt_onscreen = 0;
            int to = rand() % 2;
            to += 1;
            printf("%d", to);
            bonus[curobt_onscreen].RECT.y = 0;
            bonus[curobt_onscreen].RECT.x = WWSIZE / 3 + (rand() % ((int)(WWSIZE * 0.3)));
            bonus[curobt_onscreen].team = obt[to].isgood[0];
            bonus[curobt_onscreen].visible = 1;
            bonus[curobt_onscreen].state = to;
         //   SDL_DestroyTexture(bonus[curobt_onscreen].TEXTURE);
            bonus[curobt_onscreen].TEXTURE = obt[to].t;
            curobt_onscreen++;
        }
        // memset(m[i], 46, mln);
    }
    return;
}


SDL_Texture** builder;
int gen_roadt()
{
    rep(i, MAX_ROAD_LINE)
    {
        rep(j, MAX_ROAD_LEN)
        {
            view_textureto(builder[m1.road[i][j]], j * MAXH, (i-1) * MAXH + roady, MAXH, MAXH);
            if (roady >= MAXH) {
              
                for (int t = MAX_ROAD_LINE-1; t != 0; t--)
                    rep(l, MAX_ROAD_LEN) m1.road[t][l] = m1.road[t-1][l];
                GENLAST(&m1.road, MAX_ROAD_LEN);
                roady = 0;
            }
        }
        // puts("");
    }
    return 1;
}





int main(int argc, char* argv[])
{
  //  MAINDISPINIT;
 //   RES_TO_WHSIZE;
  int stt;
  double life = 15;
  int px = WWSIZE / 2 - MAXH / 2;
    INITTTF;
    INIT_AUDIO;
    IIMCEFONT("s.ttf", TEXT_SIZE);
    INITIIMCE;
    splash_sizeh = WHSIZE;
    splash_sizew = WWSIZE;
    TEXT_SCREEN_WIDTH = WWSIZE;
    IIMCE_TEXT_WRAPPER = 1;
    CUR_TIME = 1;
    srand(time(0));
    WWSIZE = 480;
    WHSIZE = 720;

    MAXH = WWSIZE / MAX_ROAD_LEN;
    MAXW = MAXH;
    INITWINDOW;
    IIMCE_HIDECURSOR;
    builder = LOADTEXTURES(8, "", ".png", 0);
    hudt = II.TXTRLOAD(render, "hud.png");
    fog_t = II.TXTRLOAD(render, "fog.png");
    mn = II.TXTRLOAD(render, "mn.png");
    obj but[3];
    obj cursor = init_obj(0, WHSIZE * 0.9, WHSIZE * 0.1, WWSIZE, 0, 0, 0, "");
    but[0] = init_obj(0, WHSIZE * 0.9, WHSIZE / 16, WWSIZE, 0, 0, 0, "");
    but[1] = init_obj(0, WHSIZE * 0.9, WHSIZE / 16, WWSIZE, 0, 0, 0, "");
    but[2] = init_obj(0, WHSIZE * 0.9, WHSIZE / 16, WWSIZE, 0, 0, 0, "");
    but[1].RECT.y = WHSIZE * 0.35;
    but[1].RECT.h = WHSIZE * 0.1;
    but[0].RECT.y = WHSIZE*0.2;
    but[0].RECT.h = WHSIZE * 0.1;
    but[2].RECT.y *= 0.98;
    but[2].RECT.h *= 1.5;
    rep(i, 10) {
        bonus[i] = init_obj(WWSIZE / 3 + (rand() % ((int)(WWSIZE * 0.3))), 0, MAXH, MAXW, 0, 0, 0, "");

    }

    int game_mod = 0;
    LOOP
    {
        view_texture(mn, WHSIZE, WWSIZE);
        if (control_mouse_likecursor(&cursor, &stt, 1, IIMCE_GET_EVENT()).type == SDL_MOUSEBUTTONUP) { 
        game_mod = objscollision(but, 3, cursor).index;
            if (game_mod >= 0) {
            break;
        }
    }
        REDRAW;
    }
    rep(i,7) {
        IIMCE_GET_EVENT();
        view_texture(builder[i], WHSIZE, WWSIZE);
        REDRAW;
    }

    //IIMCE_PLAY_MUSIC(mainmusic->m, 1);




    {
        int p = 2;
        int c = 0;
        char buff[64];
        char buff1[64];
        char buff2[64];


        memset(buff, 0, 64);
        memset(buff1, 0, 64);
        memset(buff2, 0, 64);

        int i = 1;
        FILE* tmp;
        if ((tmp = fopen("food.data", "r")) == NULL)
            return;
        if (fopen == NULL)
            return;
     //   system("dir");
        while (fgets(buff, 256, tmp) != NULL) {
            trim_weol(buff);
            sprintf(buff1, "foods\\%s.txt", buff);
            sprintf(buff2, "foods\\%s.png", buff);

            puts(buff1);
            puts(buff2);


            fflush(stdout);
            puts("--------------------");
            if(1){
              //  memset(obt[i].t, 0, 64);
                FILE* txt = fopen(buff1, "r");
           
                  fgets(obt[i].isgood, 10, txt);
                int j = 0;
                char ch = ' ';
                while (ch != EOF) {
                    ch = fgetc(txt);
                    if (c != EOF)
                        obt[i].txt[j] = ch;
                    j++;
                }
                obt[i].t = IMG_LoadTexture(render, buff2);
                fclose(txt);
            }

            i++;
        }
        fclose(tmp);
        maxobt = i;
    }
    puts("--------------------");
    for (int i = 0; i != maxobt; i++) {
        puts(obt[i].isgood);
        puts("--------------------");
        puts(obt[i].txt);
    }



    mainmusic = init_music("tst.wav");
    mainmusic->stop_mus_if_end = 0;
    mainmusic->mainmusstop = 1;
    NEWTHR(musth1, new_music, "mus", mainmusic);

    MAX_ROAD_LINE = WHSIZE / MAXH + 1;
    MAX_ROAD_LEN = WWSIZE / MAXH;

    //init road road
    m1.road = (char**)malloc(sizeof(char*) * (MAX_ROAD_LINE+1));
    rep(i, (MAX_ROAD_LINE + 1))
    {
        m1.road[i] = (char*)malloc(sizeof(char) * (MAX_ROAD_LEN));
    };
    player = init_obj(WWSIZE / 2 - MAXH / 2, MAXH * (MAX_ROAD_LINE - 2), MAXH, MAXH, 0, 0, 0, "boy.png");
    GENFULL(&m1.road, MAX_ROAD_LINE, MAX_ROAD_LEN);
    coor t;
    t.x = (WWSIZE / 2 - MAXW / 2) / 1;
    t.y = WHSIZE;
    unsigned long count = 0;
    int tik = 0;
    double speeds[10] = { 0.5, 1, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5 };
    double speed = 0.0;


    while (life>0) {




        tik++;
        if (tik == 512) {
            count++;
            tik = 0;
        }
        if (count < 3)
            speed = speeds[count];
        else
            speed = speeds[3];
     //   speed = 0.25;
        roady += speed;
        rep(i, maxobt_onscreen) bonus[i].RECT.y += speed;

        if (gen_roadt()) {

          if (roady < MAXH / 2) 
                if (m1.road[MAX_ROAD_LINE - 1][(player.RECT.x +player.RECT.w / 2) / MAXH] < 6) {
                    OBJSM_MOVE_fix(&player, t, 4);
                    life-=0.01;
                }
           if (roady >= MAXH / 2) 
              if (m1.road[MAX_ROAD_LINE - 2][(player.RECT.x + player.RECT.w / 2) / MAXH] < 6) {
                  OBJSM_MOVE_fix(&player, t, 4);
                  life -= 0.01;
              }

//movement segment
           iimce_event e = IIMCE_GET_EVENT();
           control_mouse_tocursor(&player, &stt, 1, e);
           control_mouse_tocursor(&player, &stt, 1, e);

          player.RECT.y = MAXH * (MAX_ROAD_LINE-2);
          obj tmp = player;
          tmp.RECT.x -= player.RECT.w/2;


          int plcool = -1;
          plcool = objscollision(bonus, curobt_onscreen, tmp).index;
          if (plcool > 0)
              if (bonus[plcool].visible == 1) {
                  bonus[plcool].visible = 0;
                  if (bonus[plcool].team == 'y')
                      life++;
                  else {

                      life--;
                      view_text_messenger_texture(obt[bonus[plcool].state].txt, RenderToTexture(render));
                  }
              }




          view_obj(&tmp, 0);
          view_textureto(hudt, 0, 0, WHSIZE * 0.15, WWSIZE * 0.41);
          for (int i = 0; i != 2; i++) {
          //    puts(obt[1+i].t);

          }
          VIEWOBJS(bonus, 0, maxobt_onscreen);
          if (game_mod == 1)
              view_textureto(fog_t, player.RECT.x - WHSIZE * 1.33, player.RECT.y - WHSIZE * 1.33, WHSIZE * 2.66, WHSIZE * 2.66);
            PRINT_TEXT(1, 30, getname("your life = ", (int)life, ""), Red);
            REDRAW;
        }
    }


}
