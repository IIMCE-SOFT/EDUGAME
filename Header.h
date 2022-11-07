#ifndef GAME_H
#define _CRT_SECURE_NO_WARNINGS
#define GAME_H
#include "math.h"
#include "stdio.h"
#include "string.h"
#include "time.h"

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
/*
#include <C:\Users\Admin\source\repos\ConsoleApplication1\Debug\data\dirent.h>
DIR* curdir;
struct dirent* curdir_ent;
*/

float time_scale_oldpc = 1.0;
#define usleep(a)                               \
    {                                           \
        SDL_Delay((int)((a)*time_scale_oldpc)); \
    }
#define _CUSTOM_FPS_PER_SEC 15
int CUSTOM_FPS_PER_SEC = _CUSTOM_FPS_PER_SEC;
int LAST_CUSTOM_FPS_TIMER = 0;
#define loop while (1)
#define LOOP while (1)

#define SETCUSTOMFPS(a)              \
    {                                \
        CUSTOMFPS = (int)(1000 / a); \
    }
int CUSTOMFPS = (int)(1000 / _CUSTOM_FPS_PER_SEC); // 20 ����� �������� �� ������������ ������� ������
Uint32 _CUSTOMFPS_Timer = 0;
#define GET_CUSTOMFPS_TIMER() _CUSTOMFPS_Timer = SDL_GetTicks()
#define CUSTOMFPS_WAIT_FRAME(a)                                                \
    SETCUSTOMFPS(a);                                                           \
    GET_CUSTOMFPS_TIMER();                                                     \
    if (SDL_GetTicks() - _CUSTOMFPS_Timer < CUSTOMFPS) {                       \
        LAST_CUSTOM_FPS_TIMER = CUSTOMFPS - SDL_GetTicks() + _CUSTOMFPS_Timer; \
        usleep(LAST_CUSTOM_FPS_TIMER);                                         \
    }

#define FPS_WAIT_MOREFRAME(a, b)                                   \
    SETCUSTOMFPS(b);                                               \
    GET_CUSTOMFPS_TIMER();                                         \
    if (SDL_GetTicks() - _CUSTOMFPS_Timer < CUSTOMFPS) {           \
        usleep(a*(CUSTOMFPS - SDL_GetTicks() + _CUSTOMFPS_Timer)); \
    }

#define GET_FPS_NUM(a) ((int)((double)(1.0 / a) * 1000.0))

#define _FPS_PER_SEC 15
int FPS_PER_SEC = _FPS_PER_SEC;
int LAST_FPS_TIMER = 0;
#define SETFPS(a)              \
    {                          \
        FPS = (int)(1000 / a); \
    }
int FPS = (int)(1000 / _FPS_PER_SEC); // 20 ����� �������� �� ������������ ������� ������
Uint32 _FPS_Timer = 0;
#define GET_FPS_TIMER() _FPS_Timer = SDL_GetTicks()
#define FPS_WAIT_FRAME()                                    \
    GET_FPS_TIMER();                                        \
    if (SDL_GetTicks() - _FPS_Timer < FPS) {                \
        LAST_FPS_TIMER = FPS - SDL_GetTicks() + _FPS_Timer; \
        usleep(LAST_FPS_TIMER);                             \
    }

#define FPS_WAIT_MOREFRAME(a)                          \
    GET_FPS_TIMER();                                   \
    if (SDL_GetTicks() - _FPS_Timer < FPS) {           \
        usleep(a*(FPS - SDL_GetTicks() + _FPS_Timer)); \
    }

#define VIEWOBJS_NEW(a, b, c, d, e) VIEWOBJS(a, b, c)
#define iimce_byte signed char
#define iimce_texture SDL_Texture
#define iimce_ttf_font TTF_Font
#define iimce_screen SDL_Window
#define iimce_render SDL_Renderer
#define iimce_int int
#define iimce_double double
#define iimce_mix_music Mix_Music
#define iimce_time unsigned long long

#define iimce_event SDL_Event

#define iimce_thread SDL_Thread

#define byte iimce_byte
#define BYTE iimce_byte
iimce_screen* window = NULL;
iimce_render* render = NULL;

struct iimce_font {
    int FONT_SIZE;
    SDL_Color color;
    iimce_ttf_font* font;
    char* fname[40];
};
#define true 1
#define false 0
iimce_time IIMCE_TIMER_TIME;
iimce_byte IIMCE_TIMER_SIG;
iimce_int TIMER_STEP = 150;
iimce_int CUR_TIME;
iimce_int splash_sizeh;
iimce_int splash_sizew;
iimce_byte view_textureto(iimce_texture* tx, iimce_int x, iimce_int y, iimce_int h, iimce_int w);
iimce_byte view_texture(iimce_texture* tx, iimce_int h, iimce_int w);
iimce_int isFULLSCREEN = false;
Uint32 IIMCE_FULLSCR_FAKEorREAL = SDL_WINDOW_FULLSCREEN;
#define FULLSCRMODSWITCHER                                        \
    if (IIMCE_FULLSCR_FAKEorREAL == SDL_WINDOW_FULLSCREEN)        \
        IIMCE_FULLSCR_FAKEorREAL = SDL_WINDOW_FULLSCREEN_DESKTOP; \
    else                                                          \
        IIMCE_FULLSCR_FAKEorREAL = SDL_WINDOW_FULLSCREEN;

int* cur_level;

#define ABS(x) ((x) >= 0 ? (x) : -(x))

#define swap(T, X, Y) \
    {                 \
        T S = X;      \
        X = Y;        \
        Y = S;        \
    }

#define ifcase(t, com) \
    case t:            \
        com;           \
        break;

#define allcoor_change(n, d, c, d1, c1) \
    {                                   \
        n.x d = c;                      \
        n.y d1 = c1;                    \
    }

#define set(Aa, Bb) \
    Bb;             \
    Aa = Bb

#define WINDOWTI(a, b) \
    WINDOWICON(a);     \
    WINDOWTILE(b);

typedef struct {
    void* any;
} anyobj;

typedef struct {
    anyobj* anys;
} anyobjs;

typedef struct {
    iimce_double x;
    iimce_double y;
} coor;

struct coor4 {
    coor c[4];
};
struct colmap {
    iimce_byte** mp;
};
#define colmap struct colmap
#define coor4 struct coor4

typedef struct {
    iimce_double h;
    iimce_double w;
} size_param;

typedef struct {
    size_param p;
    coor c;
} coor_size_param;

#define method_define(name) void*(name)(struct obj * o, dialog_value d)

typedef struct {
    char* idx;
    iimce_int mx;
} dialog_value;

typedef struct
{
    char str[80];
    char** ans;
    iimce_int* ans_indx;
    iimce_int acount;

} dialog_branch;

typedef struct
{
    iimce_int bcount;
    dialog_branch* b;
    iimce_texture** bg_list;
    iimce_byte mode;
    struct obj* o;
    void (*action)(struct obj* o, dialog_value d);
    struct iimce_font f;
} dialog_three;

struct obj {
    void (*ai)(struct obj* a, coor b);
    SDL_Texture* (*GET_REPRESINTATION)(byte pl_state, SDL_Texture** T);
    byte team;
    byte type;
    iimce_byte visible;
    SDL_Rect RECT;
    iimce_texture* TEXTURE;
    char coll;
    SDL_Rect collr;
    char* name;
    iimce_byte state;
    iimce_byte pstate;
    iimce_int cstate;
    iimce_int cframe;
    iimce_int max_frame;
    iimce_double angle;
    iimce_byte flip;
    iimce_int vec;
    coor c;
    iimce_double stp;
    coor tr;
    iimce_int t;
    iimce_int h;
    char in_inv;
    iimce_int ws, hs;
    iimce_int ps;
    iimce_byte inv[15];
    iimce_int level[2];
    char charvec;
    colmap global_cmp;
    void* cs;
    anyobj acs;
    anyobjs macs;
    coor vecc;
    iimce_int EVERY_SEC;
    iimce_texture** frame;

    dialog_three* dia;
};

typedef struct obj obj;
obj cursor;

#define BMEMSIZE(a) malloc_usable_size(a)
#define BMEMLEN(a) (malloc_usable_size(a) / sizeof(*a))

#define MALLOC_OBJS(NAME, NUMB) \
    NUMB;                       \
    obj* NAME = (obj*)malloc((NUMB) * sizeof(obj));

#define REALLOC_OBJS(NAME, NUMB) \
    NUMB;                        \
    NAME = (obj*)realloc((NAME), (NUMB) * sizeof(obj))

#define RANDOM(mMAX) (rand() % (mMAX))
#define RRANDOM(mMin, mMax) (rand() % (mMax - mMin) + mMin)
#define random(mMAX) (rand() % (mMAX))
#define rrandom(mMin, mMax) (rand() % (mMax - mMin) + mMin)
#define NEWTYPE typedef struct {
#define RANDIMIZE srand(time(0))

#define FUNC
#define PROC extern inline void
#define elif else if
#define forceinline extern inline
#define lev(a, b) ((cur_level[0] == a) && (cur_level[1] == b))
#define curlev() *myworld.wrld[cur_level[0]][cur_level[1]]
#define getlev(a, b) *myworld.wrld[a][b]
#define curbp(a, b) *myworld.wrld[cur_level[0]][cur_level[1]].mp[a][b]
#define RESET_MOUSE SDL_WarpMouseInWindow(window, 0, 0)
#define SETMOUSE(_X, _Y) SDL_WarpMouseInWindow(window, _X, _Y)
#define scMAXH (block_scale_factor * MAXH)
#define scMAXW (block_scale_factor * MAXW)
#define block_scale(a) (block_scale_factor * a)
#define DELAY(a) usleep(a)
#define BLOCK scMAXH, scMAXW

FILE* logfile;
byte IFLOG;

#define LOGON IFLOG = 1
#define LOGOFF IFLOG = 0
#define SLOG(log)            \
    if (IFLOG) {             \
        fputs(log, logfile); \
        fflush(logfile);     \
    }
#define ILOG(log)                    \
    if (IFLOG) {                     \
        fprintf(logfile, "%d", log); \
        fflush(logfile);             \
    }
#define DLOG(log)                    \
    if (IFLOG) {                     \
        fprintf(logfile, "%f", log); \
        fflush(logfile);             \
    }
#define LOGFILE(a) logfile = fopen(a, "w")

#define min(a, b) (((a) < (b)) ? (a) : (b)) // min: Choose smaller of two values.
#define max(a, b) (((a) > (b)) ? (a) : (b)) // max: Choose bigger of two values.
#define abs(a) ((a) < 0 ? -(a) : (a))
#define clamp(a, mi, ma) min(max(a, mi), ma) // clamp: Clamp value into set range.
#define sign(v) (((v) > 0) - ((v) < 0)) // sign: Return the sign of a value (-1, 0 or 1)
#define vxs(x0, y0, x1, y1) ((x0) * (y1) - (x1) * (y0)) // vxs: Vector cross product
// Overlap:  Determine whether the two number ranges overlap.
#define Overlap(a0, a1, b0, b1) (min(a0, a1) <= max(b0, b1) && min(b0, b1) <= max(a0, a1))
// IntersectBox: Determine whether two 2D-boxes intersect.
#define IntersectBox(x0, y0, x1, y1, x2, y2, x3, y3) (Overlap(x0, x1, x2, x3) && Overlap(y0, y1, y2, y3))
// PointSide: Determine which side of a line the point is on. Return value: -1, 0 or 1.
#define PointSide(px, py, x0, y0, x1, y1) sign(vxs((x1) - (x0), (y1) - (y0), (px) - (x0), (py) - (y0)))

#define INITSDL2 SDL_Init(SDL_INIT_EVERYTHING)
#define INITTTF TTF_Init()
#define IIMCE_RENDERER_TYPE SDL_RENDERER_SOFTWARE//SDL_RENDERER_ACCELERATED //SDL_RENDERER_SOFTWARE
#define INITWINDOW                                                                                                            \
    window = SDL_CreateWindow("H", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WWSIZE, WHSIZE, 0 | SDL_WINDOW_RESIZABLE); \
    render = SDL_CreateRenderer(window, -1, IIMCE_RENDERER_TYPE)
#define INITFULLSCREEN                                                                                                                               \
    window = SDL_CreateWindow("H", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WWSIZE, WHSIZE, IIMCE_FULLSCR_FAKEorREAL | SDL_WINDOW_RESIZABLE); \
    render = SDL_CreateRenderer(window, -1, IIMCE_RENDERER_TYPE)

#define FULLSCR                                                    \
    {                                                              \
        SDL_SetWindowFullscreen(window, IIMCE_FULLSCR_FAKEorREAL); \
        SDL_RenderSetLogicalSize(render, WWSIZE, WHSIZE);          \
    }

#define WINDOWER                                          \
    {                                                     \
        SDL_SetWindowFullscreen(window, 0);               \
        SDL_RenderSetLogicalSize(render, WWSIZE, WHSIZE); \
    }

#define WINDOWICON(icon) SDL_SetWindowIcon(window, icon)
#define WINDOWTILE(tile) SDL_SetWindowTitle(window, tile)
#define WINDOWRESIZEBLE SDL_SetWindowResizable(window, SDL_True)
#define WINDOWUNRESIZEBLE SDL_SetWindowResizable(window, SDL_False)
#define GETSCRSIZE SDL_GetCurrentDisplayMode
#define IIMCE_KEYSTATE SDL_GetKeyboardState(NULL)
#define IIMCE_HIDECURSOR SDL_ShowCursor(SDL_DISABLE)

#define REDRAW SDL_RenderPresent(render)
#define REDRAWex(a) SDL_RenderPresent(a)
#define CLS SDL_RenderClear(render)
forceinline iimce_texture** CREATE_TEXTURES(iimce_int max)
{
    return (iimce_texture**)malloc(sizeof(iimce_texture*) * max);
}
forceinline obj* CREATE_OBJS(iimce_int max)
{
    return (obj*)malloc(sizeof(obj) * max);
}
#define CREATS(Type, _Max) (Type*)malloc(sizeof(Type) * _Max)
#define ACREATS(_Point, Type, _Max) (Type*)realloc(_Point, sizeof(Type) * _Max)
#define REPEAT(a, TYPE, VAR) for (TYPE(VAR) = 0; (VAR) != (a); (VAR)++)
#define REPEATex(a, TYPE, VAR, STP) for (TYPE(VAR) = 0; (VAR) != (a); (VAR) += (STP))
#define rep(a, b) for (iimce_int a = 0; a != b; a++)

iimce_int MAXH = 128;
iimce_int MAXW = 128;
iimce_int WWSIZE = 800;
iimce_int WHSIZE = 600;
iimce_double block_scale_factor = 1.0;
iimce_double ui_scale_factor_h = 1.0;
iimce_double ui_scale_factor_w = 1.0;
iimce_int EVERY_SEC;
SDL_DisplayMode MAINDISPLAY;

#define IIMCEMAXCH 4
#define INIT_AUDIO                                                                \
    {                                                                             \
        {                                                                         \
            if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, IIMCEMAXCH, 1024) == -1) \
                Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024);                \
        }                                                                         \
        Mix_AllocateChannels(16);                                                 \
    }

#define IIMCE_LOAD_WAV Mix_LoadWAV
#define IIMCE_SFX Mix_Chunk
#define MAINDISPINIT                                          \
    for (iimce_int i = 0; i < SDL_GetNumVideoDisplays(); ++i) \
        if (!SDL_GetCurrentDisplayMode(i, &MAINDISPLAY))      \
    break
#define RES_TO_WHSIZE       \
    WWSIZE = MAINDISPLAY.w; \
    WHSIZE = MAINDISPLAY.h

iimce_mix_music* IIMCE_LoadMusic(char* path)
{
    iimce_mix_music* music = Mix_LoadMUS(path);
    return music;
}
#define IIMCE_PLAY_MUSIC(a, b) Mix_PlayMusic(a, b)
#define IIMCE_PLAYINGMUS Mix_PlayingMusic
#define CLOSE_AUDIO Mix_CloseAudio()
#define IIMCE_MUSIC iimce_mix_music
#define IIMCE_MusPause Mix_PauseMusic()
#define IIMCE_MusResum Mix_ResumeMusic()

#define IIMCE_PLAY_SFXw(name) while (Mix_PlayChannel(1, name, 0) == -1)
#define IIMCE_PLAY_SFXexw(a, b, c) ((a, b, c) == -1)
#define IIMCE_PLAY_SFX(name) Mix_PlayChannel(-1, name, 0)
#define IIMCE_PLAY_SFXex(a, b, c) Mix_PlayChannel(a, b, c)

iimce_byte TIME_BLOCK = 0;
void IIMCE_TIMER()
{
    while (1) {
        if (IIMCE_TIMER_SIG) {
            TIME_BLOCK = 0;
            usleep(TIMER_STEP * 0.95);
            TIME_BLOCK = 1;
            usleep(1 + TIMER_STEP * 0.05);
            CUR_TIME += 1;
        }
    }
}

iimce_byte _cool_(coor_size_param a, coor_size_param b)
{

    iimce_int ax1, ax2;
    iimce_int ay1, ay2;
    iimce_int bx1, bx2;
    iimce_int by1, by2;
    iimce_int r = 0;
    ax1 = a.c.x;
    ax2 = a.c.x + a.p.w;
    bx1 = b.c.x;
    bx2 = b.c.x + b.p.w;
    ay1 = a.c.y;
    ay2 = a.c.y + a.p.h;
    by1 = b.c.y;
    by2 = b.c.y + b.p.h;
    if ((bx1 >= ax1) && (bx1 <= ax2))
        if ((by1 >= ay1) && (by1 <= ay2))
            return 1;
    if ((bx2 >= ax1) && (bx1 <= ax1))
        if ((by1 >= ay1) && (by1 <= ay2))
            return 1;
    if ((bx1 >= ax1) && (bx1 <= ax2))
        if ((by2 >= ay1) && (by1 <= ay1))
            return 1;
    if ((bx2 >= ax1) && (bx1 <= ax1))
        if ((by2 >= ay1) && (by1 <= ay1))
            return 1;

    return 0;
}

iimce_byte objcollision(obj a, obj b)
{
    coor_size_param aa;
    aa.c.x = a.RECT.x;
    aa.c.y = a.RECT.y;
    aa.p.h = a.RECT.h;
    aa.p.w = a.RECT.w;
    coor_size_param bb;
    bb.c.x = b.RECT.x;
    bb.c.y = b.RECT.y;
    bb.p.h = b.RECT.h;
    bb.p.w = b.RECT.w;
    return _cool_(aa, bb);
}

iimce_byte _bobjscollision(obj* a, iimce_int m, obj b) /*RETURN BOOL*/
{
    iimce_int ax1, ax2;
    iimce_int ay1, ay2;
    iimce_int bx1, bx2;
    iimce_int by1, by2;
    iimce_int r = 0;
    for (iimce_int i = 0; i != m; i++) {
        ax1 = a[i].RECT.x + a[i].collr.x;
        ax2 = a[i].RECT.x + a[i].collr.x + a[i].collr.w;
        bx1 = b.RECT.x + b.collr.x;
        bx2 = b.RECT.x + b.collr.x + b.collr.w;
        ay1 = a[i].RECT.y + a[i].collr.y;
        ay2 = a[i].RECT.y + a[i].collr.y + a[i].collr.h;
        by1 = b.RECT.y + b.collr.y;
        by2 = b.RECT.y + b.collr.y + b.collr.h;
        if ((bx1 >= ax1) && (bx1 <= ax2))
            if ((by1 >= ay1) && (by1 <= ay2))
                return 1;
        if ((bx2 >= ax1) && (bx1 <= ax1))
            if ((by1 >= ay1) && (by1 <= ay2))
                return 1;
        if ((bx1 >= ax1) && (bx1 <= ax2))
            if ((by2 >= ay1) && (by1 <= ay1))
                return 1;
        if ((bx2 >= ax1) && (bx1 <= ax1))
            if ((by2 >= ay1) && (by1 <= ay1))
                return 1;
    }
    return 0;
}

iimce_byte xycollision(iimce_int x, iimce_int y, obj b)
{
    iimce_int ax1, ax2;
    iimce_int ay1, ay2;
    iimce_int bx1, bx2;
    iimce_int by1, by2;
    iimce_int r = 0;
    ax1 = x;
    ax2 = x + 1;
    bx1 = b.RECT.x;
    bx2 = b.RECT.x + b.RECT.w;
    ay1 = y;
    ay2 = y + 1;
    by1 = b.RECT.y;
    by2 = b.RECT.y + b.RECT.h;
    if ((bx1 >= ax1) && (bx1 <= ax2))
        if ((by1 >= ay1) && (by1 <= ay2))
            return 1;
    if ((bx2 >= ax1) && (bx1 <= ax1))
        if ((by1 >= ay1) && (by1 <= ay2))
            return 1;
    if ((bx1 >= ax1) && (bx1 <= ax2))
        if ((by2 >= ay1) && (by1 <= ay1))
            return 1;
    if ((bx2 >= ax1) && (bx1 <= ax1))
        if ((by2 >= ay1) && (by1 <= ay1))
            return 1;

    return 0;
}

iimce_byte game_pause = 0;
iimce_byte mainmusdelay = 0;
iimce_byte mainmusstop = 0;
iimce_byte mus_is_play = 0;
iimce_byte stop_mus_if_end = 0;
void music(char* str)
{
    puts(str);
    IIMCE_MUSIC* mainm;
    mus_is_play = 1;
    mainm = IIMCE_LoadMusic(str);

    IIMCE_PLAY_MUSIC(mainm, -1);
    while (1) {
        printf("%d\n", mus_is_play);
        if (mainmusdelay) {
            IIMCE_MusPause;
            usleep(mainmusdelay);
            IIMCE_MusResum;
            mainmusdelay = 0;
        }
        if (mainmusstop) {
            Mix_FreeMusic(mainm);
            return;
        }
        if (!IIMCE_PLAYINGMUS()) {
            mus_is_play = 0;
            if (!stop_mus_if_end) {
                IIMCE_PLAY_MUSIC(mainm, -1);
                mus_is_play = 1;
            }
        } else
            mus_is_play = 0;
    }
    puts("end");
}

typedef struct {
    IIMCE_MUSIC* m;
    iimce_byte game_pause;
    iimce_byte mainmusdelay;
    iimce_byte mainmusstop;
    iimce_byte mus_is_play;
    iimce_byte stop_mus_if_end;
} MUS_SYS;
MUS_SYS MAIN_FAME_MUSIC;

MUS_SYS* init_music(char* str)
{
    MUS_SYS* MAIN_FAME_MUSIC = malloc(sizeof(MUS_SYS));
    MAIN_FAME_MUSIC->m = IIMCE_LoadMusic(str);
    MAIN_FAME_MUSIC->game_pause = 0;
    MAIN_FAME_MUSIC->mainmusdelay = 0;
    MAIN_FAME_MUSIC->mainmusstop = 0;
    MAIN_FAME_MUSIC->mus_is_play = 0;
    MAIN_FAME_MUSIC->stop_mus_if_end = 0;
    return MAIN_FAME_MUSIC;
}

void new_music(MUS_SYS* MAIN_FAME_MUSIC)
{
    MAIN_FAME_MUSIC->mus_is_play = 1;
    IIMCE_PLAY_MUSIC(MAIN_FAME_MUSIC->m, 1);
    while (1) {
        if (MAIN_FAME_MUSIC->mainmusstop) {
            Mix_PausedMusic();
            Mix_FreeMusic(MAIN_FAME_MUSIC->m);
            MAIN_FAME_MUSIC->mus_is_play = 0;
            break;
        }
        if (MAIN_FAME_MUSIC->mainmusdelay == 1) {
            while (MAIN_FAME_MUSIC->mainmusdelay)
                ;
        }
        if (!IIMCE_PLAYINGMUS()) {
            MAIN_FAME_MUSIC->mus_is_play = 1;
            if (!MAIN_FAME_MUSIC->stop_mus_if_end) {
                IIMCE_PLAY_MUSIC(MAIN_FAME_MUSIC->m, 1);
                MAIN_FAME_MUSIC->mus_is_play = 1;
            } else
                MAIN_FAME_MUSIC->mus_is_play = 0;
        }
    }
    puts("end");
    return;
}

typedef struct {
    colmap cmp;
    iimce_int** mp;
    iimce_int h;
    iimce_int w;
    iimce_int th, tw;
    iimce_int EVERY_SEC;
    iimce_int cf;
    iimce_int mf;
    iimce_int gw[2];
    iimce_int gd[2];
    iimce_int ga[2];
    iimce_int gs[2];
    char* name;
} map;
typedef struct {
    map** wrld;
} world;
world myworld;

#define iimce_randcoor(b, GRLEVW, GRLEVH) \
    {                                     \
        coor t;                           \
        t.x = rand() % GRLEVW;            \
        t.y = rand() % GRLEVH;            \
        b = t;                            \
    }
#define iimce_randcoor4(b, GRLEVW1, GRLEVH1, GRLEVW, GRLEVH) \
    {                                                        \
        coor t;                                              \
        t.x = GRLEVW1 + rand() % (GRLEVW + ABS(GRLEVW1));    \
        t.y = GRLEVH1 + rand() % (GRLEVH + ABS(GRLEVH1));    \
        b = t;                                               \
    }
#define iimce_randlevel(b, GRLEVW, GRLEVH) \
    {                                      \
        coor t;                            \
        t.x = rand() % GRLEVW;             \
        t.y = rand() % GRLEVH;             \
        b.c = t;                           \
        b.level[0] = rand() % 3;           \
        b.level[1] = rand() % 3;           \
    }

#define DEFC 0, 0 /*default coordiante parametr*/
#define OBJT0 0, 1, 0 /*not anim or state object*/

obj init_obj(iimce_int x, iimce_int y, iimce_int h, iimce_int w, iimce_int maxf, iimce_int EVERY_SEC, iimce_int maxs, char* name);
obj init_obj_TEXTTURE(iimce_int x, iimce_int y, iimce_int h, iimce_int w, iimce_int maxf, iimce_int EVERY_SEC, iimce_int maxs, iimce_texture* name);

typedef struct
{
    iimce_byte (*VIEW)(obj* tmp, char per);
    obj (*CREATE)(iimce_int x, iimce_int y, iimce_int h, iimce_int w, iimce_int maxf, iimce_int EVERY_SEC, iimce_int maxs, char* name);
    char* (*GETNAME)(char* name, iimce_int n, char* name2);
    void (*MOVEUP)(obj* tmp, iimce_int offset);
    void (*MOVEDOWN)(obj* tmp, iimce_int offset);
    void (*MOVELEFT)(obj* tmp, iimce_int offset);
    void (*MOVERIGHT)(obj* tmp, iimce_int offset);
    SDL_Event (*CONTROL)(obj* tmp, iimce_byte* stt, iimce_int m, SDL_Event e);
    iimce_texture* (*TXTRLOAD)(SDL_Renderer* ren, const char* name);
} iimce;
iimce II;

map (*init_map)(iimce_int m, iimce_int n, iimce_int H, iimce_int W);
struct iimce_font IIMCE_BASE_FONT;
#define INITIIMCE                                              \
    if (1) {                                                   \
        MAINDISPINIT;                                          \
        II.TXTRLOAD = IMG_LoadTexture;                         \
        IIMCE_BASE_FONT.font = IIMCE_STD_FONT;                 \
        IIMCE_BASE_FONT.color = Red;                           \
        IIMCE_BASE_FONT.FONT_SIZE = 24;                        \
        II.VIEW = view_obj;                                    \
        II.GETNAME = getname;                                  \
        II.CREATE = init_obj;                                  \
        II.MOVEUP = move_up;                                   \
        II.MOVEDOWN = move_down;                               \
        II.MOVELEFT = move_left;                               \
        II.MOVERIGHT = move_right;                             \
        II.CONTROL = control_key8;                             \
        init_map = STD_init_map;                               \
        splash_sizeh = WHSIZE;                                 \
        splash_sizew = WWSIZE;                                 \
        cur_level = (iimce_int*)malloc(sizeof(iimce_int) * 2); \
    } //_key;}

#define START_MAIN  \
    int main()      \
    {               \
        INITSDL2;   \
        INITTTF;    \
        INIT_AUDIO; \
        INITIIMCE;  \
        TIMERINIT;

#define CLOSE_MAIN \
    CLOSEALL;      \
    }

iimce_byte view_obj(obj* tmp, char per)
{
    if (tmp->visible == 0)
        return 0;
    if (tmp != NULL) {
        if (tmp->TEXTURE != NULL) {
            iimce_byte r = SDL_RenderCopy(render, tmp->TEXTURE, NULL, &tmp->RECT);
            if (per)
                SDL_RenderPresent(render);
            return r;
        }
    }
    return 0;
}

iimce_byte view_objex(obj* tmp, iimce_byte per)
{
    if (tmp->visible == 0)
        return 0;
    iimce_byte r = SDL_RenderCopyEx(render, tmp->TEXTURE, NULL, &(tmp->RECT), tmp->angle, NULL, tmp->flip);
    if (per)
        SDL_RenderPresent(render);
    return r;
}

iimce_byte view_anim_obj(obj* tmp, char per)
{
    if (tmp->visible == 0)
        return 0;
    iimce_int ES;
    if (tmp->EVERY_SEC == -1)
        ES = EVERY_SEC;
    else
        ES = tmp->EVERY_SEC;
    iimce_byte r = SDL_RenderCopy(render, tmp->frame[tmp->cframe], NULL, &tmp->RECT); //frame[tmp->cframe], NULL,&tmp->RECT);

    if (per)
        SDL_RenderPresent(render);
    if (TIME_BLOCK)
        if (CUR_TIME % ES == 0)
            tmp->cframe++;
    if (tmp->cframe == tmp->max_frame)
        tmp->cframe = 0;
    return r;
}

iimce_byte VIEWOBJS(obj* o, int per, int max)
{
    REPEAT(max, int, i)
    view_obj(&o[i], per);
}
iimce_byte VIEWOBJSex(obj* o, int per, int max)
{
    REPEAT(max, int, i)
    view_anim_obj(&o[i], per);
}
iimce_byte VIEWOBJSannim(obj* o, int per, int max)
{
    REPEAT(max, int, i)
    view_anim_obj(&o[i], per);
}
iimce_byte VIEWOBJSanimex(obj* o, int per, int max)
{
    REPEAT(max, int, i)
    view_anim_obj(&o[i], per);
}

void HORFLIP(obj* t)
{
    t->flip = SDL_FLIP_HORIZONTAL;
}
void VERFLIP(obj* t)
{
    t->flip = SDL_FLIP_VERTICAL;
}
void NONEFLIP(obj* t)
{
    t->flip = SDL_FLIP_NONE;
}
void VERHORFLIP(obj* t)
{
    t->flip = SDL_FLIP_VERTICAL + SDL_FLIP_HORIZONTAL;
}

#define SLEEP(tm) usleep(tm)

#define MALLOC(type, num, name) type* name = malloc(sizeof(type) * (num))
#define EXIT                         \
    if (1) {                         \
        SDL_DestroyRenderer(render); \
        SDL_DestroyWindow(window);   \
        SDL_Quit();                  \
        exit(0);                     \
    }
#define NEW(type, num, name) type* name = malloc(sizeof(type) * (num))
#define THREAD SDL_Thread*
#define IF if
#define WHILE while
#define FOR for
#define SWITCH switch
#define CASE case
#define ELSE else
#define ELIF else if
#define BEGIN {
#define END }
#define SWITCHER(a, m) \
    if (a > m)         \
        a = 0;         \
    else               \
        a++;
#define DO do
#define NEWTHR(name, func, tname, arg) iimce_thread* name = SDL_CreateThread(func, tname, arg)
#define THR(name, func, tname, arg) name = SDL_CreateThread(func, tname, arg)

iimce_thread* TIMER;
#define TIMERINIT                                                          \
    if (1) {                                                               \
        TIMER = SDL_CreateThread(IIMCE_TIMER, "IIMCE_TIMER", (void*)NULL); \
    }
#define TIMER_INIT        \
    IIMCE_TIMER_TIME = 0; \
    NEWTHR(timer_thr, timer, "timer_thr", NULL)

#define TIMER_STOP IIMCE_TIMER_SIG = 0
#define TIMER_START IIMCE_TIMER_SIG = 1;

coor Get4nap(obj a, obj b)
{
    coor t = { 0, 0 };
    if (a.RECT.y > b.RECT.y)
        t.y = 8;
    else if (a.RECT.y < b.RECT.y)
        t.y = 2;

    if (a.RECT.x < b.RECT.x)
        t.x = 6;
    else if (a.RECT.x > b.RECT.x)
        t.x = 4;
    return t;
}

coor coorGet4nap(coor a, coor b)
{
    coor t = { 0, 0 };
    if (a.y > b.y)
        t.y = 8;
    else if (a.y < b.y)
        t.y = 2;

    if (a.x < b.x)
        t.x = 6;
    else if (a.x > b.x)
        t.x = 4;
    return t;
}

coor Get8nap(obj a, obj b)
{
    coor t = { 0, 0 };
    if (a.RECT.y > b.RECT.y)
        if (a.RECT.x < b.RECT.x) {
            t.x = 9;
            return t;
        }
    if (a.RECT.y > b.RECT.y)
        if (a.RECT.x > b.RECT.x) {
            t.x = 7;
            return t;
        }
    if (a.RECT.y < b.RECT.y)
        if (a.RECT.x < b.RECT.x) {
            t.x = 3;
            return t;
        }
    if (a.RECT.y < b.RECT.y)
        if (a.RECT.x < b.RECT.x) {
            t.x = 1;
            return t;
        }
    return Get4nap(a, b);
}

coor coorGet8nap(coor a, coor b)
{
    coor t = { 0, 0 };
    if (a.y > b.y)
        if (a.x < b.x) {
            t.x = 9;
            return t;
        }
    if (a.y > b.y)
        if (a.x > b.x) {
            t.x = 7;
            return t;
        }
    if (a.y < b.y)
        if (a.x < b.x) {
            t.x = 3;
            return t;
        }
    if (a.y < b.y)
        if (a.x < b.x) {
            t.x = 1;
            return t;
        }
    return coorGet4nap(a, b);
}

SDL_Event IIMCE_WAIT_EVENT()
{
    SDL_Event KEVENT;
    while (!SDL_WaitEvent(&KEVENT)) {
    };

    if (KEVENT.type == SDL_QUIT)
        exit(0);
    return KEVENT;
}

SDL_Event IIMCE_WAIT_EVENT_old()
{
    SDL_Event e;
    SDL_WaitEvent(&e);
    if (e.type == SDL_QUIT)
        exit(0);
    return e;
}

coor XYTOMAP(iimce_int x, iimce_int y, iimce_int H, iimce_int W)
{
    coor a;
    a.x = x / W;
    a.y = y / H;
    return a;
};
SDL_Color White = { 225, 255, 255, 255 };
SDL_Color Blue = { 0, 0, 255, 255 };
SDL_Color Green = { 0, 255, 0, 255 };
SDL_Color Red = { 225, 0, 0, 255 };
SDL_Color Black = { 0, 0, 0, 0 };
void move_up(obj* tmp, iimce_int offset) { tmp->RECT.y -= offset; }

void move_down(obj* tmp, iimce_int offset) { tmp->RECT.y += offset; }

void move_left(obj* tmp, iimce_int offset) { tmp->RECT.x -= offset; }

void move_right(obj* tmp, iimce_int offset) { tmp->RECT.x += offset; }

SDL_Event control_mouse_click(obj* tmp, iimce_byte* stt, iimce_int m)
{
    SDL_Event e;
    iimce_int xm, ym;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_MOUSEBUTTONUP) {
            if (e.button.button == SDL_BUTTON_LEFT) {
                SDL_GetMouseState(&xm, &ym);
                //
                if (tmp->RECT.x < xm)
                    II.MOVERIGHT(tmp, m);
                else
                    II.MOVELEFT(tmp, m);
                if (tmp->RECT.y > ym)
                    II.MOVEUP(tmp, m);
                else
                    II.MOVEDOWN(tmp, m);
            }
        }
    }
    return e;
}

obj init_obj(iimce_int x, iimce_int y, iimce_int h, iimce_int w, iimce_int maxf, iimce_int EVERY_SEC, iimce_int maxs, char* name)
{
    obj tmp;
    tmp.state = 0;
    tmp.visible = 1;
    tmp.cstate = 0;
    tmp.angle = 0.0;
    tmp.RECT.x = x;
    tmp.EVERY_SEC = EVERY_SEC;
    tmp.RECT.y = y;
    tmp.RECT.h = h;
    tmp.RECT.w = w;
    tmp.cframe = 0;
    tmp.flip = SDL_FLIP_NONE;
    tmp.name = name;
    tmp.coll = 0;
    tmp.collr = tmp.RECT;
    tmp.collr.x = tmp.collr.y = 0;
    puts(name);
    fflush(stdout);
    if (maxf != 0) {
        tmp.max_frame = maxf;
        tmp.frame = CREATS(iimce_texture*, maxf);
    }

  //  tmp.TEXTURE = NULL;
    SDL_DestroyTexture(tmp.TEXTURE);
    tmp.TEXTURE = IMG_LoadTexture(render, name);
    return tmp;
}

obj init_obj_TEXTTURE(iimce_int x, iimce_int y, iimce_int h, iimce_int w, iimce_int maxf, iimce_int EVERY_SEC, iimce_int maxs, iimce_texture* name)
{
    obj tmp;
    tmp.state = 0;
    tmp.visible = 1;
    tmp.cstate = 0;
    tmp.angle = 0.0;
    tmp.RECT.x = x;
    tmp.EVERY_SEC = EVERY_SEC;
    tmp.RECT.y = y;
    tmp.RECT.h = h;
    tmp.RECT.w = w;
    tmp.cframe = 0;
    tmp.flip = SDL_FLIP_NONE;
    tmp.coll = 0;
    tmp.collr = tmp.RECT;
    tmp.collr.x = tmp.collr.y = 0;

    if (maxf != 0) {
        tmp.max_frame = maxf;
        tmp.frame = CREATS(iimce_texture*, maxf);
    }

    tmp.TEXTURE = name;
    return tmp;
}

iimce_int ipow(iimce_int a, iimce_int b)
{
    while (b != 0) {
        a *= a;
        b--;
    }
    return a;
}
SDL_Event control_mouse_likecursor(obj* tmp, iimce_byte* stt, iimce_int m, SDL_Event e)
{

    iimce_int xm, ym;

    SDL_GetMouseState(&xm, &ym);

    tmp->RECT.x = xm;
    tmp->RECT.y = ym;
    return e;
}
SDL_Event control_mouse_tocursor(obj* tmp, iimce_byte* stt, iimce_int m, SDL_Event e)
{

    iimce_int xm, ym;

    SDL_GetMouseState(&xm, &ym);

    if (tmp->RECT.x < xm)
        II.MOVERIGHT(tmp, m);

    else
        II.MOVELEFT(tmp, m);
    if (tmp->RECT.y > ym)
        II.MOVEUP(tmp, m);
    else
        II.MOVEDOWN(tmp, m);
    return e;
}
SDL_Event control_mouse(obj* tmp, iimce_byte* stt, iimce_int m, SDL_Event e)
{

    iimce_int xm, ym;
    // SDL_WaitEvent(&e);

    if (e.type == SDL_MOUSEBUTTONDOWN)
        tmp->state = 1;
    else if (e.type == SDL_MOUSEBUTTONUP)
        tmp->state = 0;
    else if (tmp->state == 1) {
        SDL_GetMouseState(&xm, &ym);
        if (tmp->RECT.x < xm)
            II.MOVERIGHT(tmp, m);
        else
            II.MOVELEFT(tmp, m);
        if (tmp->RECT.y > ym)
            II.MOVEUP(tmp, m);
        else
            II.MOVEDOWN(tmp, m);
    } else if (e.type == SDL_MOUSEBUTTONUP)
        tmp->state = 0;
    return e;
}

void turn_obj(obj* tmp, float angle)
{
    tmp->angle = ((iimce_int)(tmp->angle + angle) % 360);
}

SDL_Event IIMCE_GET_EVENT()
{
    SDL_Event KEVENT;
    SDL_PollEvent(&KEVENT);

    if (KEVENT.type == SDL_QUIT) {
        exit(0);
    }

    return KEVENT;
}

iimce_int res_change(iimce_byte d, iimce_int h, iimce_int w)
{
    iimce_byte res = 0;
    if (d == 1) {
        MAINDISPINIT;

        RES_TO_WHSIZE;
        ui_scale_factor_h = (iimce_double)MAINDISPLAY.h / 720.0;
        ui_scale_factor_w = (iimce_double)MAINDISPLAY.w / 960.0;
        iimce_double block_scale_factor1 = (iimce_double)(WHSIZE / h) / MAXH;
        iimce_double block_scale_factor2 = (iimce_double)(WWSIZE / w) / MAXW;
        if (block_scale_factor2 < block_scale_factor1)
            block_scale_factor1 = block_scale_factor2;

        block_scale_factor = block_scale_factor1;
        printf("%d %d %d %f %f %f\n", WHSIZE, h, MAXH, block_scale_factor, ui_scale_factor_h, ui_scale_factor_w);
        // printf("%d %d %d %f\n", WHSIZE, h, MAXH,block_scale_factor);
        FULLSCR;
        isFULLSCREEN = res = 1;
    }
    if (d == 2) {
        ui_scale_factor_h = ui_scale_factor_w = 1.0;
        block_scale_factor = 1;
        WHSIZE = 720;
        WWSIZE = 960;
        WINDOWER;
        isFULLSCREEN = res = 2;
    }
    return res;
}
iimce_int res_control(Uint8* state, iimce_int h, iimce_int w)
{
    iimce_byte res = 0;
    if (state[SDL_GetScancodeFromKey(SDLK_p)]) {
        MAINDISPINIT;
        RES_TO_WHSIZE;
        ui_scale_factor_h = (iimce_double)MAINDISPLAY.h / 720.0;
        ui_scale_factor_w = (iimce_double)MAINDISPLAY.w / 960.0;
        iimce_double block_scale_factor1 = (iimce_double)(WHSIZE / h) / MAXH;
        iimce_double block_scale_factor2 = (iimce_double)(WWSIZE / w) / MAXW;
        if (block_scale_factor2 < block_scale_factor1)
            block_scale_factor1 = block_scale_factor2;
        block_scale_factor = block_scale_factor1;
        printf("%d %d %d %f %f %f\n", WHSIZE, h, MAXH, block_scale_factor, ui_scale_factor_h, ui_scale_factor_w);
        FULLSCR;
        isFULLSCREEN = res = 1;
    }
    if (state[SDL_GetScancodeFromKey(SDLK_l)]) {
        ui_scale_factor_h = ui_scale_factor_w = 1.0;
        block_scale_factor = 1;
        WHSIZE = 720;
        WWSIZE = 960;
        WINDOWER;
        isFULLSCREEN = res = 2;
    }
    return res;
}

iimce_int inlevh = 12;
iimce_int inlevw = 24;
char splah_scale_type = 1;
#define _splash                                                                                                                                                                                           \
    if (tt != NULL) {                                                                                                                                                                                     \
        CLS;                                                                                                                                                                                              \
        if (splah_scale_type)                                                                                                                                                                             \
            view_textureto(tt, (WWSIZE - splash_sizew * block_scale_factor) / 2, (WHSIZE - splash_sizeh * block_scale_factor) / 2, splash_sizeh * block_scale_factor, splash_sizew * block_scale_factor); \
        else                                                                                                                                                                                              \
            view_textureto(tt, 0, 0, WHSIZE, WWSIZE);                                                                                                                                                     \
    }

forceinline void view_splash(char* n)
{
    CLS;
    game_pause = 1;
    iimce_texture* tt = NULL;
    tt = IMG_LoadTexture(render, n);
    while (tt == NULL)
        tt = IMG_LoadTexture(render, n);
    CLS;
    _splash
        view_obj(&cursor, 0);
    usleep(10);
    REDRAW;
    while (control_mouse_likecursor(&cursor, NULL, 0, IIMCE_WAIT_EVENT()).type != SDL_MOUSEBUTTONUP) {
        res_control(IIMCE_KEYSTATE, inlevh, inlevw);
        ;
        _splash
            view_obj(&cursor, 0);
        usleep(10);
        REDRAW;
    }

    SDL_DestroyTexture(tt);
    game_pause = 0;
}

forceinline void view_splash_texture(iimce_texture* tt)
{
    game_pause = 1;
    CLS;
    _splash
        view_obj(&cursor, 0);
    usleep(10);
    REDRAW;
    while (control_mouse_likecursor(&cursor, NULL, 0, IIMCE_WAIT_EVENT()).type != SDL_MOUSEBUTTONUP) {

        res_control(IIMCE_KEYSTATE, inlevh, inlevw);
        _splash
            view_obj(&cursor, 0);
        usleep(10);
        REDRAW;
    }
    game_pause = 0;
}

forceinline void view_splash_timer(char* n, iimce_int tm)
{
    CLS;
    game_pause = 1;
    iimce_texture* tt = NULL;
    tt = IMG_LoadTexture(render, n);
    while (tt == NULL)
        tt = IMG_LoadTexture(render, n);
    CLS;
    while (IIMCE_GET_EVENT().type != SDL_MOUSEBUTTONUP & tm > 0) {
        control_mouse_likecursor(&cursor, NULL, 0, IIMCE_GET_EVENT());
        res_control(IIMCE_KEYSTATE, inlevh, inlevw);
        _splash
            view_obj(&cursor, 0);
        tm--;
        REDRAW;
        usleep(1);
    }

    SDL_DestroyTexture(tt);
    game_pause = 0;
}

forceinline void view_splash_texture_timer(iimce_texture* tt, iimce_int tm)
{
    game_pause = 1;
    CLS;
    while ((IIMCE_GET_EVENT().type != SDL_MOUSEBUTTONUP) & (tm > 0)) {
        control_mouse_likecursor(&cursor, NULL, 0, IIMCE_GET_EVENT());
        res_control(IIMCE_KEYSTATE, inlevh, inlevw);
        _splash
            view_obj(&cursor, 0);
        tm--;
        REDRAW;
        usleep(1);
    }
    game_pause = 0;
}

SDL_Event control_key(obj* tmp, iimce_byte* stt, iimce_int m, SDL_Event KEVENT)
{
    iimce_byte* state = IIMCE_KEYSTATE;
    if (1) {

        if (state[SDL_GetScancodeFromKey(SDL_KEYDOWN)]) {
            if (KEVENT.key.keysym.sym == SDLK_UP) {
                II.MOVEUP(tmp, m);
            }
            if (state[SDL_GetScancodeFromKey(SDLK_DOWN)]) {
                II.MOVEDOWN(tmp, m);
            }
            if (state[SDL_GetScancodeFromKey(SDLK_RIGHT)]) {
                II.MOVERIGHT(tmp, m);
            }
            if (state[SDL_GetScancodeFromKey(SDLK_LEFT)]) {
                II.MOVELEFT(tmp, m);
            }
        }
    }
    return KEVENT;
}

SDL_Event control_key8(obj* tmp, iimce_byte* stt, iimce_int m, SDL_Event KEVENT)
{
    iimce_byte* state = IIMCE_KEYSTATE;
    if (1) {

        {
            if (state[SDL_GetScancodeFromKey(SDLK_KP_8)]) {
                II.MOVEUP(tmp, m);
                *stt = 0;
            } else if (state[SDL_GetScancodeFromKey(SDLK_KP_2)]) {
                II.MOVEDOWN(tmp, m);
                *stt = 4;
            } else if (state[SDL_GetScancodeFromKey(SDLK_KP_6)]) {
                II.MOVERIGHT(tmp, m);
                *stt = 2;
            } else if (state[SDL_GetScancodeFromKey(SDLK_KP_4)]) {
                II.MOVELEFT(tmp, m);
                *stt = 2;
            } else if (state[SDL_GetScancodeFromKey(SDLK_KP_7)]) {
                II.MOVEUP(tmp, m);
                II.MOVELEFT(tmp, m);
                *stt = 1;
            } else if (state[SDL_GetScancodeFromKey(SDLK_KP_1)]) {
                II.MOVEDOWN(tmp, m);
                II.MOVELEFT(tmp, m);
                *stt = 3;
            } else if (state[SDL_GetScancodeFromKey(SDLK_KP_9)]) {
                II.MOVERIGHT(tmp, m);
                II.MOVEUP(tmp, m);
                *stt = 1;
            } else if (state[SDL_GetScancodeFromKey(SDLK_KP_3)]) {
                II.MOVERIGHT(tmp, m);
                II.MOVEDOWN(tmp, m);
                *stt = 3;
            }
        }
    }
    return KEVENT;
}

iimce_byte statefromnap(coor a)
{
    if (a.x > 0 && a.y == 0)
        return 2;
    if (a.x < 0 && a.y == 0)
        return 2;
    if (a.x > 0 && a.y > 0)
        return 3;
    if (a.x > 0 && a.y < 0)
        return 1;

    if (a.x < 0 && a.y > 0)
        return 3;
    if (a.x < 0 && a.y < 0)
        return 1;
    if (a.x == 0 && a.y > 0)
        return 4;
    if (a.x == 0 && a.y < 0)
        return 0;
    return 0;
}

map mymap;

iimce_byte TEXT_RENDER_MODE = 1;

coor DISTOBJna(obj a, obj b)
{
    if (a.RECT.x < b.RECT.x)
        a.RECT.x += a.RECT.w;
    else if (a.RECT.x > b.RECT.x)
        b.RECT.x += b.RECT.w;
    if (a.RECT.y < b.RECT.y)
        a.RECT.y += a.RECT.h;
    else if (a.RECT.y > b.RECT.y)
        b.RECT.y += b.RECT.h;
    coor t;
    t.x = (a.RECT.x - b.RECT.x);
    t.y = (a.RECT.y - b.RECT.y);
    return t;
}
coor DISTCOORna(coor a, coor b)
{
    coor t;
    t.x = (a.x - b.x);
    t.y = (a.y - b.y);
    return t;
}

coor DISTOBJ(obj a, obj b)
{
    if (a.RECT.x < b.RECT.x)
        a.RECT.x += a.RECT.w;
    else if (a.RECT.x > b.RECT.x)
        b.RECT.x += b.RECT.w;
    if (a.RECT.y < b.RECT.y)
        a.RECT.y += a.RECT.h;
    else if (a.RECT.y > b.RECT.y)
        b.RECT.y += b.RECT.h;
    coor t;
    t.x = ABS(a.RECT.x - b.RECT.x);
    t.y = ABS(a.RECT.y - b.RECT.y);
    return t;
}
coor DISTCOOR(coor a, coor b)
{
    coor t;
    t.x = ABS(a.x - b.x);
    t.y = ABS(a.y - b.y);
    return t;
}

char IIMCE_TEXT_WRAPPER = 0;
iimce_int TEXT_SCREEN_WIDTH = 0;

iimce_texture* RenderText(char* str, char* fontFile, SDL_Color color, iimce_int fontSize, SDL_Renderer* renderer)
{
    TTF_Font* font = TTF_OpenFont(fontFile, fontSize);
    SDL_Surface* surf;
    if (!IIMCE_TEXT_WRAPPER)
        switch (TEXT_RENDER_MODE) {
        case 1:
            surf = TTF_RenderText_Blended(font, str, color);
            break;
        case 2:
            surf = TTF_RenderUTF8_Blended(font, str, color);
            break;
        case 3:
            surf = TTF_RenderUNICODE_Blended(font, str, color);
            break;
        default:
            surf = TTF_RenderText_Blended(font, str, color);
        }
    else
        switch (TEXT_RENDER_MODE) {
        case 1:
            surf = TTF_RenderText_Blended_Wrapped(font, str, color, TEXT_SCREEN_WIDTH);
            break;
        case 2:
            surf = TTF_RenderUTF8_Blended_Wrapped(font, str, color, TEXT_SCREEN_WIDTH);
            break;
        case 3:
            surf = TTF_RenderUNICODE_Blended_Wrapped(font, str, color, TEXT_SCREEN_WIDTH);
            break;
        default:
            surf = TTF_RenderText_Blended_Wrapped(font, str, color, TEXT_SCREEN_WIDTH);
        }
    iimce_texture* texture = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
    //SDL_DestroyTexture(texture);
    return texture;
}

iimce_texture* RenderTextIFONT(char* str, struct iimce_font fnt, SDL_Renderer* renderer)
{
    TTF_Font* font = fnt.font;
    SDL_Surface* surf;
    if (!IIMCE_TEXT_WRAPPER)
        switch (TEXT_RENDER_MODE) {
        case 1:
            surf = TTF_RenderText_Blended(font, str, fnt.color);
            break;
        case 2:
            surf = TTF_RenderUTF8_Blended(font, str, fnt.color);
            break;
        case 3:
            surf = TTF_RenderUNICODE_Blended(font, str, fnt.color);
            break;
        default:
            surf = TTF_RenderText_Blended(font, str, fnt.color);
        }
    else

        switch (TEXT_RENDER_MODE) {
        case 1:
            surf = TTF_RenderText_Blended_Wrapped(font, str, fnt.color, TEXT_SCREEN_WIDTH);
            break;
        case 2:
            surf = TTF_RenderUTF8_Blended_Wrapped(font, str, fnt.color, TEXT_SCREEN_WIDTH);
            break;
        case 3:
            surf = TTF_RenderUNICODE_Blended_Wrapped(font, str, fnt.color, TEXT_SCREEN_WIDTH);
            break;
        default:
            surf = TTF_RenderText_Blended_Wrapped(font, str, fnt.color, TEXT_SCREEN_WIDTH);
        }

    iimce_texture* texture = SDL_CreateTextureFromSurface(renderer, surf);
    SDL_FreeSurface(surf);
    //SDL_DestroyTexture(texture);
    return texture;
}

void PRINT_TEXTex(iimce_int x, iimce_int y, char* str, char* fontFile,
    SDL_Color color, iimce_int fontSize)
{

    TTF_Font* font = TTF_OpenFont(fontFile, fontSize);
    SDL_Surface* surf;

    if (!IIMCE_TEXT_WRAPPER)
        switch (TEXT_RENDER_MODE) {
        case 1:
            surf = TTF_RenderText_Blended(font, str, color);
            break;
        case 2:
            surf = TTF_RenderUTF8_Blended(font, str, color);
            break;
        case 3:
            surf = TTF_RenderUNICODE_Blended(font, str, color);
            break;
        default:
            surf = TTF_RenderText_Blended(font, str, color);
        }
    else
        switch (TEXT_RENDER_MODE) {
        case 1:
            surf = TTF_RenderText_Blended_Wrapped(font, str, color, TEXT_SCREEN_WIDTH);
            break;
        case 2:
            surf = TTF_RenderUTF8_Blended_Wrapped(font, str, color, TEXT_SCREEN_WIDTH);
            break;
        case 3:
            surf = TTF_RenderUNICODE_Blended_Wrapped(font, str, color, TEXT_SCREEN_WIDTH);
            break;
        default:
            surf = TTF_RenderText_Blended_Wrapped(font, str, color, TEXT_SCREEN_WIDTH);
        }

    iimce_texture* texture = SDL_CreateTextureFromSurface(render, surf);
    iimce_int iW, iH;
    SDL_QueryTexture(texture, NULL, NULL, &iW, &iH);
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.h = iH;
    r.w = iW;
    SDL_RenderCopy(render, texture, NULL, &r);
    SDL_FreeSurface(surf);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
}

TTF_Font* IIMCE_STD_FONT;
#define IIMCEFONT(a, b)                      \
    {                                        \
        TTF_CloseFont(IIMCE_STD_FONT);       \
        IIMCE_STD_FONT = TTF_OpenFont(a, b); \
    }

#define IIMCENEWFONT(name, a, b) \
    TTF_Font* name;              \
    name = TTF_OpenFont(a, b);

#define FONTDECLAR(name) TTF_Font* name;

#define REPLACEFONT(c, a, b) \
    TTF_CloseFont(c);        \
    c = TTF_OpenFont(a, b);

void PRINT_TEXTfont(iimce_int x, iimce_int y, char* str, SDL_Color color, TTF_Font* IIMCE_STD_FONT)
{
    SDL_Surface* surf;
    if (!IIMCE_TEXT_WRAPPER)
        switch (TEXT_RENDER_MODE) {
        case 1:
            surf = TTF_RenderText_Blended(IIMCE_STD_FONT, str, color);
            break;
        case 2:
            surf = TTF_RenderUTF8_Blended(IIMCE_STD_FONT, str, color);
            break;
        case 3:
            surf = TTF_RenderUNICODE_Blended(IIMCE_STD_FONT, str, color);
            break;
        default:
            surf = TTF_RenderText_Blended(IIMCE_STD_FONT, str, color);
        }
    else
        switch (TEXT_RENDER_MODE) {
        case 1:
            surf = TTF_RenderText_Blended_Wrapped(IIMCE_STD_FONT, str, color, TEXT_SCREEN_WIDTH);
            break;
        case 2:
            surf = TTF_RenderUTF8_Blended_Wrapped(IIMCE_STD_FONT, str, color, TEXT_SCREEN_WIDTH);
            break;
        case 3:
            surf = TTF_RenderUNICODE_Blended_Wrapped(IIMCE_STD_FONT, str, color, TEXT_SCREEN_WIDTH);
            break;
        default:
            surf = TTF_RenderText_Blended_Wrapped(IIMCE_STD_FONT, str, color, TEXT_SCREEN_WIDTH);
        }
    iimce_texture* texture = SDL_CreateTextureFromSurface(render, surf);
    iimce_int iW, iH;
    SDL_QueryTexture(texture, NULL, NULL, &iW, &iH);
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.h = iH;
    r.w = iW;
    SDL_RenderCopy(render, texture, NULL, &r);
    SDL_FreeSurface(surf);
    SDL_DestroyTexture(texture);
}

void PRINT_TEXT(iimce_int x, iimce_int y, char* str, SDL_Color color)
{
    SDL_Surface* surf;
    if (!IIMCE_TEXT_WRAPPER)
        switch (TEXT_RENDER_MODE) {
        case 1:
            surf = TTF_RenderText_Blended(IIMCE_STD_FONT, str, color);
            break;
        case 2:
            surf = TTF_RenderUTF8_Blended(IIMCE_STD_FONT, str, color);
            break;
        case 3:
            surf = TTF_RenderUNICODE_Blended(IIMCE_STD_FONT, str, color);
            break;
        default:
            surf = TTF_RenderText_Blended(IIMCE_STD_FONT, str, color);
        }
    else
        switch (TEXT_RENDER_MODE) {
        case 1:
            surf = TTF_RenderText_Blended_Wrapped(IIMCE_STD_FONT, str, color, TEXT_SCREEN_WIDTH);
            break;
        case 2:
            surf = TTF_RenderUTF8_Blended_Wrapped(IIMCE_STD_FONT, str, color, TEXT_SCREEN_WIDTH);
            break;
        case 3:
            surf = TTF_RenderUNICODE_Blended_Wrapped(IIMCE_STD_FONT, str, color, TEXT_SCREEN_WIDTH);
            break;
        default:
            surf = TTF_RenderText_Blended_Wrapped(IIMCE_STD_FONT, str, color, TEXT_SCREEN_WIDTH);
        }
    iimce_texture* texture = SDL_CreateTextureFromSurface(render, surf);
    iimce_int iW, iH;
    SDL_QueryTexture(texture, NULL, NULL, &iW, &iH);
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.h = iH;
    r.w = iW;
    SDL_RenderCopy(render, texture, NULL, &r);
    SDL_FreeSurface(surf);
    SDL_DestroyTexture(texture);
}

void PRINT_TEXT_WF(iimce_int x, iimce_int y, char* str, struct iimce_font IIMCE_STD_FONT)
{
    SDL_Surface* surf;
    if (!IIMCE_TEXT_WRAPPER)
        switch (TEXT_RENDER_MODE) {
        case 1:
            surf = TTF_RenderText_Blended(IIMCE_STD_FONT.font, str, IIMCE_STD_FONT.color);
            break;
        case 2:
            surf = TTF_RenderUTF8_Blended(IIMCE_STD_FONT.font, str, IIMCE_STD_FONT.color);
            break;
        case 3:
            surf = TTF_RenderUNICODE_Blended(IIMCE_STD_FONT.font, str, IIMCE_STD_FONT.color);
            break;
        default:
            surf = TTF_RenderText_Blended(IIMCE_STD_FONT.font, str, IIMCE_STD_FONT.color);
        }
    else
        switch (TEXT_RENDER_MODE) {
        case 1:
            surf = TTF_RenderText_Blended_Wrapped(IIMCE_STD_FONT.font, str, IIMCE_STD_FONT.color, TEXT_SCREEN_WIDTH);
            break;
        case 2:
            surf = TTF_RenderUTF8_Blended_Wrapped(IIMCE_STD_FONT.font, str, IIMCE_STD_FONT.color, TEXT_SCREEN_WIDTH);
            break;
        case 3:
            surf = TTF_RenderUNICODE_Blended_Wrapped(IIMCE_STD_FONT.font, str, IIMCE_STD_FONT.color, TEXT_SCREEN_WIDTH);
            break;
        default:
            surf = TTF_RenderText_Blended_Wrapped(IIMCE_STD_FONT.font, str, IIMCE_STD_FONT.color, TEXT_SCREEN_WIDTH);
        }
    iimce_texture* texture = SDL_CreateTextureFromSurface(render, surf);
    iimce_int iW, iH;
    SDL_QueryTexture(texture, NULL, NULL, &iW, &iH);
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.h = iH;
    r.w = iW;
    SDL_RenderCopy(render, texture, NULL, &r);
    SDL_FreeSurface(surf);
    SDL_DestroyTexture(texture);
}

SDL_Rect get_texture_size(
    iimce_texture* tx)
{
    SDL_Rect r;
    SDL_QueryTexture(tx, NULL, NULL, &r.w, &r.h);
    r.x = 0;
    r.y = 0;
    return r;
}

SDL_Rect get_text_size(char* str, iimce_int x, iimce_int y, TTF_Font* font)
{
    SDL_Rect r;
    r.x = 0;
    r.y = 0;
    TTF_SizeUTF8(font, str, &r.w, &r.h);
    return r;
}

iimce_int getcurw(iimce_int a)
{
    while (a > WWSIZE / 2)
        a /= 1.1;
    return a;
}

SDL_Rect print_center(char* str, iimce_int y, SDL_Color color, TTF_Font* font)
{
    SDL_Rect rect = get_text_size(str, WWSIZE / 2 - 0 / 2, 0, font);
    iimce_int x = WWSIZE / 2 - getcurw(rect.w / 2);
    SDL_Surface* surf;
    surf = TTF_RenderUTF8_Blended_Wrapped(font, str, color, TEXT_SCREEN_WIDTH);
    iimce_texture* texture = SDL_CreateTextureFromSurface(render, surf);
    SDL_Rect r = get_texture_size(texture);
    r.y = y;
    r.x = x;
    SDL_RenderCopy(render, texture, NULL, &r);
    SDL_FreeSurface(surf);
    SDL_DestroyTexture(texture);
    return r;
}

forceinline void view_text_messenger(char* n, char* bg)
{
    game_pause = 1;
    iimce_texture* tt = IMG_LoadTexture(render, bg);
    iimce_texture* ttx = RenderTextIFONT(n, IIMCE_BASE_FONT, render);
    iimce_int h, w;
    SDL_QueryTexture(ttx, NULL, NULL, &w, &h);
    CLS;
    while (control_mouse_likecursor(&cursor, NULL, 0, IIMCE_WAIT_EVENT()).type != SDL_MOUSEBUTTONUP) {
        res_control(IIMCE_KEYSTATE, inlevh, inlevw);
        ;
        _splash
            view_textureto(ttx, 25, 25, h, w);
        view_obj(&cursor, 0);
        CUSTOMFPS_WAIT_FRAME(45);
        REDRAW;
    }
    SDL_DestroyTexture(ttx);
    SDL_DestroyTexture(tt);
    game_pause = 0;
}
forceinline void view_text_messenger_texture(char* n, iimce_texture* tt)
{
    game_pause = 1;
    iimce_texture* ttx = RenderTextIFONT(n, IIMCE_BASE_FONT, render);
    iimce_int h, w;
    SDL_QueryTexture(ttx, NULL, NULL, &w, &h);
    CLS;
    while (control_mouse_likecursor(&cursor, NULL, 0, IIMCE_WAIT_EVENT()).type != SDL_MOUSEBUTTONUP) {
        res_control(IIMCE_KEYSTATE, inlevh, inlevw);
        ;
        _splash
            view_textureto(ttx, 25, 25, h, w);
        view_obj(&cursor, 0);
        CUSTOMFPS_WAIT_FRAME(45);
        REDRAW;
    }
    SDL_DestroyTexture(ttx);
    game_pause = 0;
}

forceinline void view_text_messenger_timer(char* n, char* bg, iimce_int tm)
{
    game_pause = 1;
    iimce_texture* tt = IMG_LoadTexture(render, bg);
    iimce_texture* ttx = RenderTextIFONT(n, IIMCE_BASE_FONT, render);
    iimce_int h, w;
    SDL_QueryTexture(ttx, NULL, NULL, &w, &h);
    CLS;
    while (control_mouse_likecursor(&cursor, NULL, 0, IIMCE_GET_EVENT()).type != SDL_MOUSEBUTTONUP & tm != 0) {
        res_control(IIMCE_KEYSTATE, inlevh, inlevw);
        _splash
            view_textureto(ttx, 25, 25, h, w);
        view_obj(&cursor, 0);
        CUSTOMFPS_WAIT_FRAME(45);
        tm--;
        REDRAW;
    }
    SDL_DestroyTexture(ttx);
    SDL_DestroyTexture(tt);
    game_pause = 0;
}
forceinline void view_text_messenger_texture_timer(char* n, iimce_texture* tt, iimce_int tm)
{
    game_pause = 1;
    iimce_texture* ttx = RenderTextIFONT(n, IIMCE_BASE_FONT, render);
    iimce_int h, w;
    SDL_QueryTexture(ttx, NULL, NULL, &w, &h);
    CLS;
    while (control_mouse_likecursor(&cursor, NULL, 0, IIMCE_GET_EVENT()).type != SDL_MOUSEBUTTONUP & tm != 0) {
        res_control(IIMCE_KEYSTATE, inlevh, inlevw);
        ;
        _splash
            view_textureto(ttx, 25, 25, h, w);
        view_obj(&cursor, 0);
        tm--;
        CUSTOMFPS_WAIT_FRAME(45);
        REDRAW;
    }
    SDL_DestroyTexture(ttx);
    game_pause = 0;
}

char RectRav(SDL_Rect a, SDL_Rect b)
{
    if (a.h == b.h)
        if (a.w == a.w)
            if (a.x == b.x)
                if (a.y == a.y)
                    return 1;
    return 0;
}

map STD_init_map(iimce_int m, iimce_int n, iimce_int H, iimce_int W)
{
    map tmp;
    tmp.th = scMAXH;
    tmp.tw = scMAXW;
    tmp.h = m;
    tmp.w = n;
    m++;
    n++;
    tmp.cmp.mp = (iimce_byte**)malloc(m * sizeof(iimce_byte*));
    tmp.mp = (iimce_int**)malloc(m * sizeof(iimce_int*));
    REPEAT(m, iimce_byte, i)
    {
        tmp.cmp.mp[i] = (iimce_byte*)malloc(n * sizeof(iimce_byte));
        tmp.mp[i] = (iimce_int*)malloc(n * sizeof(iimce_int));
    }
    REPEAT(m, iimce_int, mm)
    REPEAT(n, iimce_int, nn)
    {
        tmp.mp[mm][nn] = 0;
        if (mm == nn)
            tmp.mp[mm][nn] = 1;
        if (RANDOM(5) == 2)
            tmp.mp[mm][nn] = 1;
    }

    tmp.cf = 0;
    return tmp;
}

char getcnn(FILE* f)
{
    char t = getc(f);
    if ((t < 32) | (t > 126))
        return getcnn(f);
    return t;
}

void load(iimce_int* cmp, iimce_int len, map* t, iimce_int m, iimce_int n, char* name)
{
    FILE* f;
    f = fopen(name, "r");
    *t = init_map(m, n, 0, 0);
    for (iimce_int i = 0; i != m; i++) {
        for (iimce_int i1 = 0; i1 != n; i1++) {
            t->mp[i][i1] = getcnn(f);
            t->cmp.mp[i][i1] = -1;
            rep(c, len)
            {
                if (t->mp[i][i1] == cmp[c])
                    t->cmp.mp[i][i1] = 0;
            }
        }
    }
    fclose(f);
}

iimce_byte sizeof_num(iimce_int x)
{
    long p = 10;
    for (iimce_int i = 1; i < 10; i++) {
        if (x < p)
            return i;
        p = 10 * p;
    }
    return 19;
}

char* getname(char* name, iimce_int n, char* name2)
{
    char* name3;
    iimce_int sz = sizeof(char) * (strlen(name) + strlen(name2) + sizeof_num(n) + 1);
    name3 = (char*)malloc(sz);
    memset(name3, 0, sz);
    name3[0] = '\0';
    sprintf(name3, "%s%d%s", name, n, name2);
    return name3;
}

iimce_byte view_texture(iimce_texture* tx, iimce_int h, iimce_int w)
{
    SDL_Rect t;
    t.x = 0;
    t.y = 0;
    t.h = h;
    t.w = w;
    return SDL_RenderCopy(render, tx, NULL, &t);
}

iimce_byte view_textureto(iimce_texture* tx, iimce_int x, iimce_int y, iimce_int h, iimce_int w)
{
    if (tx != NULL) {
        SDL_Rect t;
        t.x = x;
        t.y = y;
        t.h = h;
        t.w = w;
        return SDL_RenderCopy(render, tx, NULL, &t);
    }
    return NULL;
}

iimce_byte view_textureEx(iimce_texture* tx, iimce_int h, iimce_int w, iimce_double angle, iimce_byte flip)
{
    SDL_Rect t;
    t.x = 0;
    t.y = 0;
    t.h = h;
    t.w = w;
    return SDL_RenderCopyEx(render, tx, NULL, &t, angle, NULL, flip);
}

iimce_byte view_texturetoEx(iimce_texture* tx, iimce_int x, iimce_int y, iimce_int h, iimce_int w, iimce_double angle, iimce_byte flip)
{
    SDL_Rect t;
    t.x = x;
    t.y = y;
    t.h = h;
    t.w = w;
    return SDL_RenderCopyEx(render, tx, NULL, &t, angle, NULL, flip);
}
#define LOADSURFACE(a) SDL_LoadBMP(a)

iimce_texture** LOADTEXTURES(iimce_int max, char* s1, char* s2, iimce_int offs)
{
    iimce_texture** t = (iimce_texture**)malloc(sizeof(iimce_texture*) * max);
    for (iimce_int i = 0; i != max; i++) {
        t[i] = IMG_LoadTexture(render, getname(s1, i + offs, s2));
        //printf("%s\n", getname(s1, i + offs, s2));
    }
    return t;
}
SDL_Surface** LOADSURFACES(iimce_int max, char* s1, char* s2, iimce_int offs)
{
    SDL_Surface** t = (SDL_Surface**)malloc(sizeof(SDL_Surface*) * max);
    for (iimce_int i = 0; i != max; i++) {
        t[i] = LOADSURFACE(getname(s1, i + offs, s2));
    }
    return t;
}

#define IIMCE_LOADTEXTURE(a, b) IMG_LoadTexture(a, b)

coor GETOBJ_XY(obj a)
{
    coor b;
    b.x = a.RECT.x;
    b.y = a.RECT.y;
    return b;
}
coor GETRECT_XY(SDL_Rect a)
{
    coor b;
    b.x = a.x;
    b.y = a.y;
    return b;
}

#define MOVEINPROGRES 0
#define MOVEFINIS 1
iimce_byte OBJSM_MOVE(obj* a, coor b, iimce_byte d)
{
    iimce_byte t = 0;
    iimce_int x = (a->RECT.x - b.x);
    iimce_int y = (a->RECT.y - b.y);
    if ((ABS(x) / d > 0) || (ABS(y) / d > 0))
        BEGIN

    if (x != 0) {
        a->RECT.x -= x / d;

        t++;
    }
    if (y != 0) {
        a->RECT.y -= y / d;
        t++;
    }

    if (t)
        return MOVEINPROGRES;
    END else
    {
        a->RECT.x = b.x;
        a->RECT.y = b.y;
    }

    return MOVEFINIS;
}
iimce_byte COORSM_MOVE(coor* a, coor b, iimce_byte d)
{
    iimce_byte t = 0;
    iimce_int x = (a->x - b.x);
    iimce_int y = (a->y - b.y);
    if ((ABS(x) / d > 0) || (ABS(y) / d > 0))
        BEGIN

    if (x != 0) {
        a->x -= x / d;

        t++;
    }
    if (y != 0) {
        a->y -= y / d;
        t++;
    }

    if (t)
        return MOVEINPROGRES;
    END else
    {
        a->x = b.x;
        a->y = b.y;
    }

    return MOVEFINIS;
}
iimce_byte OBJSM_MOVE_fix(obj* a, coor b, iimce_byte d)
{
    iimce_byte t = 0;
    iimce_int x = (a->RECT.x - b.x);
    iimce_int y = (a->RECT.y - b.y);
    if (1)

        BEGIN

    if (x < 0) {
        a->RECT.x += d;
        t++;
    }
    if (x > 0) {
        a->RECT.x -= d;
        t++;
    }
    if (y < 0) {
        a->RECT.y += d;
        t++;
    }
    if (y > 0) {
        a->RECT.y -= d;
        t++;
    }

    if (t)
        return MOVEINPROGRES;
    END else
    {
        a->RECT.x = b.x;
        a->RECT.y = b.y;
    }

    return MOVEFINIS;
}
iimce_byte COORSM_MOVE_fix(coor* a, coor b, iimce_byte d)
{
    iimce_byte t = 0;
    iimce_int x = (a->x - b.x);
    iimce_int y = (a->y - b.y);
    if (1)

        BEGIN

    if (x < 0) {
        a->x += d;
        t++;
    }
    if (x > 0) {
        a->x -= d;

        t++;
    }
    if (y < 0) {
        a->y += d;
        t++;
    }
    if (y > 0) {
        a->y -= d;
        t++;
    }

    if (t)
        return MOVEINPROGRES;
    END else
    {
        a->x = b.x;
        a->y = b.y;
    }

    return MOVEFINIS;
}

char coor_move(coor* a, coor b, iimce_double off)
{
    if ((a->x != b.x) & (a->y != b.y))
        off /= 2.0;

    if (rand() % 2 == 0) {
        if (ABS(a->x - b.x) > off)
            if (a->x != b.x) {
                if (a->x < b.x) {
                    a->x += off;
                    return 'd';
                } else if (a->x > b.x)
                    a->x -= off;
                return 'a';
            }
        if (ABS(a->y - b.y) > off)
            if (a->y != b.y) {
                if (a->y < b.y) {
                    a->y += off;
                    return 's';
                } else if (a->y > b.y)
                    a->y -= off;
                return 'w';
            }
    } else {
        if (ABS(a->y - b.y) > off)
            if (a->y != b.y) {
                if (a->y < b.y) {
                    a->y += off;
                    return 's';
                } else if (a->y > b.y)
                    a->y -= off;
                return 'w';
            }
        if (ABS(a->x - b.x) > off)
            if (a->x != b.x) {
                if (a->x < b.x) {
                    a->x += off;
                    return 'd';
                } else if (a->x > b.x)
                    a->x -= off;
                return 'a';
            }
    }
    return 'g';
}

char coor_move_alt(coor* a, coor b, iimce_double off)
{
    if ((a->x != b.x) & (a->y != b.y))
        off /= 2.0;
    if (rand() % 2 == 0) {

        if (a->x != b.x) {
            if (a->x < b.x) {
                a->x += off;
                return 'd';
            } else if (a->x > b.x)
                a->x -= off;
            return 'a';
        }
        if (a->y != b.y) {
            if (a->y < b.y) {
                a->y += off;
                return 's';
            } else if (a->y > b.y)
                a->y -= off;
            return 'w';
        }
    } else {
        if (a->y != b.y) {
            if (a->y < b.y) {
                a->y += off;
                return 's';
            } else if (a->y > b.y)
                a->y -= off;
            return 'w';
        }
        if (a->x != b.x) {
            if (a->x < b.x) {
                a->x += off;
                return 'd';
            } else if (a->x > b.x)
                a->x -= off;
            return 'a';
        }
    }
    return 'g';
}
/*SDL_Surface* CreateSurfaceFromTexture(iimce_texture* texture,iimce_int x,iimce_int y)
	{
		// Get raw texture data
		std::vector<unsigned char> dataVec = texture_GetData();

		// Create SDL surface
		// TODO Investigate relevance of last four arguments
		SDL_Surface* tempSurface = SDL_CreateRGBSurfaceFrom(
			dataVec.data(),
			textureSize.x,
			textureSize.y,
			32,
			textureSize.x * 4,
			0x000000ff,
			0x0000ff00,
			0x00ff0000,
			0xff000000
			);

		std::cout << "1 " << tempSurface << std::endl;

		// Return
		return tempSurface;
	}
*/

void TextureToFile(const char* file_name, SDL_Renderer* renderer, iimce_texture* texture)
{
    iimce_texture* target = SDL_GetRenderTarget(renderer);
    SDL_SetRenderTarget(renderer, texture);
    iimce_int width, height;
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    SDL_Surface* surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    SDL_RenderReadPixels(renderer, NULL, surface->format->format, surface->pixels, surface->pitch);
    SDL_SaveBMP(surface, file_name);
    SDL_FreeSurface(surface);
    SDL_SetRenderTarget(renderer, target);
    return;
}

iimce_texture* RenderToTexture(SDL_Renderer* renderer)
{
    if (renderer == NULL)
        return NULL;
    iimce_texture* texture = NULL;
    iimce_texture* target = SDL_GetRenderTarget(renderer);
    SDL_SetRenderTarget(renderer, texture);
    //if (texture == NULL)
    //return NULL;
    SDL_Surface* surface = SDL_CreateRGBSurface(0, WWSIZE, WHSIZE, 32, 0, 0, 0, 0);
    SDL_RenderReadPixels(renderer, NULL, surface->format->format, surface->pixels, surface->pitch);
    iimce_texture* texture1 = SDL_CreateTextureFromSurface(render, surface);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    SDL_SetRenderTarget(renderer, target);
    return texture1;
}
iimce_texture* RenderToTextureEx(SDL_Renderer* renderer, iimce_int WHSIZE, iimce_int WWSIZE)
{
    if (renderer == NULL)
        return NULL;
    iimce_texture* texture = NULL;
    iimce_texture* target = SDL_GetRenderTarget(renderer);
    SDL_SetRenderTarget(renderer, texture);
    //if (texture == NULL)
    //return NULL;
    SDL_Surface* surface = SDL_CreateRGBSurface(0, WWSIZE, WHSIZE, 32, 0, 0, 0, 0);
    SDL_RenderReadPixels(renderer, NULL, surface->format->format, surface->pixels, surface->pitch);
    iimce_texture* texture1 = SDL_CreateTextureFromSurface(render, surface);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    SDL_SetRenderTarget(renderer, target);
    return texture1;
}
SDL_Surface* TextureToSurface(const char* file_name, SDL_Renderer* renderer, iimce_texture* texture)
{
    iimce_texture* target = SDL_GetRenderTarget(renderer);
    SDL_SetRenderTarget(renderer, texture);
    iimce_int width, height;
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    SDL_Surface* surface = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
    SDL_RenderReadPixels(renderer, NULL, surface->format->format, surface->pixels, surface->pitch);
    SDL_SetRenderTarget(renderer, target);
    return surface;
}

void SurfaceToFile(const char* file_name, SDL_Surface* surface)
{

    SDL_SaveBMP(surface, file_name);
    return;
}

unsigned long long itime;
void timer()
{
    while (1) {
        switch (IIMCE_TIMER_SIG) {
        case 0:
            continue;
            break;
        case -1:
            return;
            break;
        }
        usleep(TIMER_STEP);
        IIMCE_TIMER_TIME++;
    }
}

iimce_time gettime() { return IIMCE_TIMER_TIME; }

iimce_byte DESTROY(obj** objs, iimce_int n, iimce_int* m)
{
    if (*m <= 2)
        return 0;
    for (iimce_int i = 1; i < *m - 1; i++) {
        if (i >= n)
            (*objs)[i] = (*objs)[i + 1];
    }
    //if(realloc((*objs),sizeof(obj)*(*m-1))!=NULL)*
    *m -= 1;
    return 1;
}

iimce_byte DESTROY_WR(obj** objs, iimce_int n, iimce_int* m)
{
    if (*m <= 2)
        return 0;
    for (iimce_int i = 1; i < *m - 1; i++) {
        if (i >= n)
            (*objs)[i] = (*objs)[i + 1];
    }
    REALLOC_OBJS((*objs), (*m));
    *m -= 1;
    return 1;
}

iimce_byte STDmpcol(map m, iimce_int x, iimce_int y, iimce_byte mode)
{
    iimce_int tw, th;
    if (mode) {
        tw = m.tw;
        th = m.th;
    } else
        tw = th = 1;
    if (x >= 0)
        if (x < m.w * tw)
            if (y >= 0)
                if (y < m.h * th) {
                    return m.cmp.mp[x / tw][y / th];
                }
    return 1;
}

iimce_byte OBJMAPCOL(map m, obj t)
{
    return 0;
    iimce_int x = t.RECT.x, y = t.RECT.y;
    iimce_int tw, th;
    tw = m.tw;
    th = m.th;

    if (x >= 0)
        if (x < m.w * tw)
            if (y >= 0)
                if (y < m.h * th) {
                    obj tm;

                    tm.RECT.x = ((x / tw)) * tw;
                    tm.RECT.y = ((y / th)) * th;
                    tm.RECT.h = m.th;
                    tm.RECT.w = m.tw;
                    if (tm.RECT.x >= 0)
                        if (tm.RECT.x < m.w * tw)
                            if (tm.RECT.y >= 0)
                                if (tm.RECT.y < m.h * th)
                                    return 1;

                    if (m.cmp.mp[tm.RECT.x][tm.RECT.y])
                        return objcollision(t, tm);
                    else
                        return 0;
                }
    return 1;
}

#define MINDIST 1
#define MAXDIST 2
#define AVGDIST 3
#define DISTOFPOINT(x1, y1, x2, y2) sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
struct GET_DIST_STRCT {
    iimce_int ds;
    iimce_int index;
};
typedef struct GET_DIST_STRCT GET_DIST_STRCT;

typedef struct
{
    iimce_byte c;
    iimce_int index;
} OBJCOOLSTRUCT;

OBJCOOLSTRUCT objscollision(obj* a, iimce_int m, obj b)
{
    OBJCOOLSTRUCT t;
    iimce_int ax1, ax2;
    iimce_int ay1, ay2;
    iimce_int bx1, bx2;
    iimce_int by1, by2;
    iimce_int r = 0;
    t.c = 1;
    for (iimce_int i = 0; i != m; i++) {
        t.index = i;
        ax1 = a[i].RECT.x + a[i].collr.x;
        ax2 = a[i].RECT.x + a[i].collr.x + a[i].collr.w;
        bx1 = b.RECT.x + b.collr.x;
        bx2 = b.RECT.x + b.collr.x + b.collr.w;
        ay1 = a[i].RECT.y + a[i].collr.y;
        ay2 = a[i].RECT.y + a[i].collr.y + a[i].collr.h;
        by1 = b.RECT.y + b.collr.y;
        by2 = b.RECT.y + b.collr.y + b.collr.h;
        if ((bx1 >= ax1) && (bx1 <= ax2))
            if ((by1 >= ay1) && (by1 <= ay2))
                return t;
        if ((bx2 >= ax1) && (bx1 <= ax1))
            if ((by1 >= ay1) && (by1 <= ay2))
                return t;
        if ((bx1 >= ax1) && (bx1 <= ax2))
            if ((by2 >= ay1) && (by1 <= ay1))
                return t;
        if ((bx2 >= ax1) && (bx1 <= ax1))
            if ((by2 >= ay1) && (by1 <= ay1))
                return t;
    }
    t.c = 0;
    t.index = -1;
    return t;
}

GET_DIST_STRCT GET_DIST(iimce_byte mode, obj* t, obj tr, iimce_int tmax)
{

    GET_DIST_STRCT* ds = (GET_DIST_STRCT*)malloc(sizeof(GET_DIST_STRCT) * tmax);
    for (iimce_int i = 0; i != tmax; i++) {
        ds[i].ds = (iimce_int)DISTOFPOINT(t[i].RECT.x, t[i].RECT.y, tr.RECT.x, tr.RECT.y);
        ds[i].index = i;
    }
    if (tmax == 0)
        return ds[0];
    for (iimce_int i = 0; i != tmax; i++) {
        iimce_int j = 0;

        for (j; j < tmax - 1 - i; j++) {

            if (ds[j].ds > ds[j + 1].ds) {
                swap(GET_DIST_STRCT, ds[j], ds[j + 1]);
            }
        }
    }
    if (mode == 1)
        return ds[0];
    if (mode == 2)
        return ds[tmax - 1];
    if (mode == 3) {
        GET_DIST_STRCT tmp;
        tmp.ds = 0;
        for (iimce_int i = 0; i != tmax; i++) {
            tmp.ds += ds[i].ds;
        }
        tmp.ds /= tmax;
        tmp.index = tmax / 2;
        return tmp;
    }
}

iimce_byte OBJSM_MOVEr(obj* a, coor b, iimce_int d, map m, iimce_byte (*mapcol)(map m, obj t))
{
    iimce_byte t = 0;
    iimce_int x = (a->RECT.x - b.x);
    iimce_int y = (a->RECT.y - b.y);
    if ((ABS(x) / d > 0) || (ABS(y) / d > 0))
        BEGIN

    if (x != 0) {
        if (!mapcol(m, *a))
            a->RECT.x -= x / d;

        t++;
        if (RANDOM(8) == 1)
            return MOVEINPROGRES;
    }
    if (y != 0) {
        if (!mapcol(m, *a))
            a->RECT.y -= y / d;
        t++;
        if (RANDOM(8) == 1)
            return MOVEINPROGRES;
    }

    if (t)
        return MOVEINPROGRES;
    END else
    {
        a->RECT.x = b.x;
        a->RECT.y = b.y;
    }

    return MOVEFINIS;
}

iimce_byte OBJSM_MOVErOBJCOL(obj* a, obj* s, iimce_int mx, coor b, iimce_int d, iimce_byte (*objcol)(obj* m, iimce_int mx, obj t))
{
    iimce_byte t = 0;
    iimce_int x = (a->RECT.x - b.x);
    iimce_int y = (a->RECT.y - b.y);
    if ((ABS(x) / d > 0) || (ABS(y) / d > 0))
        BEGIN

    if (x != 0) {
        if (!objcol(s, mx, *a))
            a->RECT.x -= x / d;

        t++;
        if (RANDOM(2) == 1)
            return MOVEINPROGRES;
    }
    if (y != 0) {
        if (!objcol(s, mx, *a))
            a->RECT.y -= y / d;
        t++;
        if (RANDOM(2) == 1)
            return MOVEINPROGRES;
    }

    if (t)
        return MOVEINPROGRES;
    END else
    {
        a->RECT.x = b.x;
        a->RECT.y = b.y;
    }

    return MOVEFINIS;
}

#define IIMCE_PAUSE(_a)           \
    {                             \
        iimce_time a = CUR_TIME;  \
        while (a + _a > CUR_TIME) \
            ;                     \
    }

void MAPUPD(map* tmp, iimce_int m, iimce_int n, iimce_int H, iimce_int W)
{

    REPEAT(m, iimce_int, mm)
    REPEAT(n, iimce_int, nn)
    {
        tmp->mp[mm][nn] = 0;
        tmp->cmp.mp[mm][nn] = 0;

        if (tmp->mp[mm][nn] > 0)
            tmp->cmp.mp[mm][nn] = 1;
    }
    tmp->h = m;
    tmp->w = n;
    tmp->cf = 0;
    tmp->EVERY_SEC = 20;
}

#define USE_RENDERBG 12
//legacy dialog system
struct dialog {
    iimce_int count_answer;
    char* string;
    char** answer;
    iimce_int use_custom_font;
    iimce_texture* bg;
    struct iimce_font f;
};

struct dialogs {
    struct dialog* dlog;
    iimce_int mx;
    iimce_int cur;
    iimce_int curans;
    char mode;
};

struct dialogs init_dialogs(iimce_int c, iimce_int m)
{
    struct dialogs t;
    t.dlog = (struct dialog*)malloc(c * sizeof(struct dialog));
    t.mx = c;
    t.cur = 0;
    t.mode = m;
    return t;
}

struct dialog init_dialog(iimce_int c, iimce_texture* bg1)
{
    struct dialog t;
    t.answer = (char**)malloc(c * sizeof(char*));
    t.string = (char*)malloc(384);
    t.bg = bg1;
    rep(i, c) t.answer[i] = (char*)malloc(384);
    t.count_answer = c;
    return t;
}

forceinline iimce_int dialog_window(struct dialog d, iimce_texture* bg, iimce_byte bgmode)
{
    game_pause = 1;

    obj stro;

    iimce_int HS, WS;
    iimce_texture* background = d.bg;
    if (bgmode == USE_RENDERBG)
        background = bg;
    iimce_texture* strn = RenderTextIFONT(d.string, d.f, render);
    if (strn == 0)
        while (1)
            puts("dfgdfg");
    SDL_QueryTexture(strn, NULL, NULL, &WS, &HS);
    stro = init_obj_TEXTTURE(20, (HS), HS, WS, 0, 0, 0, strn);
    iimce_texture** answer_t = (iimce_texture**)malloc(sizeof(iimce_texture*) * d.count_answer);
    obj* answer = (obj*)malloc(sizeof(obj) * d.count_answer);
    rep(i, d.count_answer)
    {
        iimce_int H;
        iimce_int W;
        answer_t[i] = RenderTextIFONT(d.answer[i], d.f, render);
        SDL_QueryTexture(answer_t[i], NULL, NULL, &W, &H);
        answer[i] = init_obj_TEXTTURE(20, 120 + HS + i * (H + 4), H, W, 0, 0, 0, answer_t[i]);
    }

    iimce_int indx = -1;
    while (indx == -1) {
        usleep(10);
        view_texture(background, WHSIZE, WWSIZE);
        VIEWOBJS_NEW(answer, 0, d.count_answer, 0, NULL);
        view_obj(&cursor, 0);
        view_obj(&stro, 0);
        REDRAW;

        // CLS;

        if (control_mouse_likecursor(&cursor, NULL, 0, IIMCE_WAIT_EVENT()).type == SDL_MOUSEBUTTONUP) {
            indx = objscollision(answer, d.count_answer, cursor).index;
            if (indx == -1)
                indx = (objcollision(cursor, stro)) - 2;
        }
    }
    game_pause = 0;
    usleep(100);
    rep(i, d.count_answer) SDL_DestroyTexture(answer_t[i]);
    free(answer_t);
    free(answer);
    return indx + 1;
}

forceinline iimce_int dialogs_window(struct dialogs* d, iimce_byte bgmode)
{
    iimce_texture* background = NULL;
    if (bgmode == USE_RENDERBG)
        background = RenderToTexture(render);

    iimce_int ans = -1;
    if (d->mx > 1)
        for (d->cur; d->cur != d->mx; d->cur++) {

            ans = dialog_window(d->dlog[d->cur], background, bgmode);
        }
    else
        ans = dialog_window(d->dlog[0], background, bgmode);

    if (bgmode == USE_RENDERBG)
        SDL_DestroyTexture(background);
    if (ans != -1) {

        d->curans = ans;
        return ans;
    }

    if (d->mode == 1)
        d->cur = d->mx - 1;
    else if (d->mode == 2) {
        d->cur = 0;
    } else if (d->mode == 3)
        return d->curans;

    return ans;
}

//never dialog system

#define DIALOG_END 6666

void SET_STRING(char** s, char* str)
{
    *s = NULL;
    *s = CREATS(char, strlen(str) + 4);
    sprintf(*s, str);
    return;
}

dialog_three init_dthree(iimce_int n, iimce_int mode)
{
    dialog_three t;
    t.mode = mode;
    t.b = CREATS(dialog_branch, n);
    t.bg_list = CREATS(iimce_texture*, n);
    t.bcount = n;
    t.f.font = IIMCE_STD_FONT;
    t.f.color = Red;
    t.f.FONT_SIZE = 24;
    t.action = NULL;
    return t;
}
dialog_branch init_branch(iimce_int n, char* str)
{
    dialog_branch t;
    t.acount = n;
    t.ans = CREATS(char*, n);
    t.ans_indx = CREATS(iimce_int, n);
    sprintf(t.str, str);
    return t;
}

dialog_value view_dthree(dialog_three t)
{
    game_pause = 1;
    dialog_value t1;
    t1.idx = CREATS(char, t.bcount);
    iimce_int i = 0;
    iimce_int i1 = 0;
    iimce_int next_ans = 0;
    while (next_ans != DIALOG_END) {
        if (i == DIALOG_END) {
            t1.mx = i1;
            game_pause = 0;
            if (t.action != NULL)
                t.action(t.o, t1);

            return t1;
        }
        next_ans = i;
        iimce_int ans_count = t.b[i].acount;
        obj stro;
        iimce_texture* strn = RenderTextIFONT(t.b[i].str, t.f, render);
        iimce_int sh, sw;
        SDL_QueryTexture(strn, NULL, NULL, &sw, &sh);
        stro = init_obj_TEXTTURE(20, (sh), sh, sw, 0, 0, 0, strn);

        iimce_texture** ans_t = CREATS(iimce_texture*, t.b[i].acount);
        rep(j, t.b[i].acount) ans_t[j] = RenderTextIFONT(t.b[i].ans[j], t.f, render);
        obj* ans_o = CREATS(obj, t.b[i].acount);
        rep(j, ans_count)
        {
            iimce_int th, tw;
            SDL_QueryTexture(ans_t[j], NULL, NULL, &tw, &th);
            ans_o[j] = init_obj_TEXTTURE(20, 120 + 60 + j * (th + 4), th, tw, 0, 0, 0, ans_t[j]);
        }
        while (1) {

            if (t.mode == 0)
                view_textureto(t.bg_list[0], 0, 0, 720 * ui_scale_factor_h, 960 * ui_scale_factor_w);
            if (t.mode != 0)
                view_textureto(t.bg_list[i], 0, 0, 720 * ui_scale_factor_h, 960 * ui_scale_factor_w);
            // view_obj(&stro, 0);
            view_obj(&stro, 0);

            VIEWOBJS_NEW(ans_o, 0, ans_count, 0, NULL);
            // stro;
            view_obj(&cursor, 1);
            iimce_int idx = -1;
            if (control_mouse_likecursor(&cursor, NULL, 0, IIMCE_WAIT_EVENT()).type == SDL_MOUSEBUTTONUP)
                idx = objscollision(ans_o, ans_count, cursor).index;
            if (idx != -1) {
                i = t.b[i].ans_indx[idx];
                t1.idx[i1] = idx;
                break;
            }
            usleep(7);
        }
        i1++;
    }
}

iimce_int MAX_STP = 300;

iimce_double get_nx(iimce_double a, iimce_double m)
{
    a++;
    if (a > m)
        a = m;
    return a;
}
iimce_double get_px(iimce_double a, iimce_double m)
{
    a--;
    if (a < m)
        a = m;
    return a;
}

iimce_double coor_rast_block(coor a, coor b)
{
    a.x *= scMAXW;
    a.y *= scMAXH;
    b.x *= scMAXW;
    b.y *= scMAXH;
    iimce_double x = a.x - b.x;
    iimce_double y = a.y - b.y;
    return (sqrt(x * x + y * y)) / ((scMAXW + scMAXH) / 2);
}

iimce_double coor_rast(coor a, coor b)
{
    a.x *= scMAXW;
    a.y *= scMAXH;
    b.x *= scMAXW;
    b.y *= scMAXH;
    iimce_double x = a.x - b.x;
    iimce_double y = a.y - b.y;
    return (sqrt(x * x + y * y));
}
coor4 coor4set(coor a)
{
    coor4 c;
    rep(i, 4) c.c[i] = a;
    return c;
}
coor4 get4coor(coor b, iimce_int xmx, iimce_int xmn, iimce_int ymx, iimce_int ymn, coor a)
{
    coor4 c;
    c.c[0].x = get_nx(b.x, xmx);
    c.c[1].x = get_px(b.x, xmn);
    c.c[0].y = b.y;
    c.c[1].y = b.y;

    c.c[2].x = b.x;
    c.c[3].x = b.x;
    c.c[2].y = get_nx(b.y, ymx);
    c.c[3].y = get_px(b.y, ymn);

    iimce_int rs[4];
    rep(i, 4) rs[i] = coor_rast(c.c[i], a);
    iimce_int min = rs[0];
    rep(i, 4) if (min > rs[i]) min = rs[i];
    rep(i, 4) if (min == rs[i])
    {
        min = i;
        break;
    }
    iimce_int max = rs[0];
    rep(i, 4) if (max < rs[i]) max = rs[i];
    rep(i, 4) if (max == rs[i])
    {
        max = i;
        break;
    }
    swap(coor, c.c[min], c.c[0]);
    return c;
}

void GEN_PATH(iimce_int stp, coor a, coor b, colmap* global_cmp, iimce_int xmx, iimce_int xmn, iimce_int ymx, iimce_int ymn)
{
#define GEN_PATH_code                                                                          \
    coor4 tmp = get4coor(a, xmx, xmn, ymx, ymn, b);                                            \
    stp++;                                                                                     \
    if (stp == MAX_STP)                                                                        \
        return;                                                                                \
    rep(i, 4)                                                                                  \
    {                                                                                          \
        if (global_cmp->mp[(iimce_int)tmp.c[i].y][(iimce_int)tmp.c[i].x] == 0) {               \
            global_cmp->mp[(iimce_int)tmp.c[i].y][(iimce_int)tmp.c[i].x] = (signed char)(stp); \
            if (tmp.c[i].x == b.x && tmp.c[i].y == b.y)                                        \
                return;                                                                        \
            GEN_PATH(stp, tmp.c[i], b, global_cmp, xmx, xmn, ymx, ymn);                        \
        }                                                                                      \
    }                                                                                          \
    return;
    GEN_PATH_code;
}

int _getcurcoor(int x, int mn, int mx)
{
    if (x < mn)
        x = mn + 1;
    else if (x > mx)
        x = mx - 1;
    return x;
}

void simpleGEN_PATH(iimce_int stp, coor a, coor b, colmap* global_cmp, iimce_int xmx, iimce_int xmn, iimce_int ymx, iimce_int ymn)
{
    coor4 tmp = get4coor(a, xmx, xmn, ymx, ymn, b);
    stp++;
    if (stp == MAX_STP)
        return;
    int r = stp;
    int x = (int)a.x;
    int y = (int)a.y;
    global_cmp->mp[y][x] = 1;
    for (int i = _getcurcoor(y - r, 0, inlevh); i != _getcurcoor(y + r, 0, inlevh); i++) {
        if (global_cmp->mp[i][x - r] == 0)
            global_cmp->mp[i][x - r] = r + 1;
        if (global_cmp->mp[i][x + r] == 0)
            global_cmp->mp[i][x + r] = r + 1;
        if ((x - r) == b.x && i == b.y)
            return;
        if ((x + r) == b.x && i == b.y)
            return;
    }
    for (int j = _getcurcoor(x - r, 0, inlevw); j != _getcurcoor(x + r + 1, 0, inlevw); j++) {
        if (global_cmp->mp[y - r][j] == 0)
            global_cmp->mp[y - r][j] = r + 1;
        if (global_cmp->mp[y + r][j] == 0)
            global_cmp->mp[y + r][j] = r + 1;
        if ((y - r) == b.y && j == b.x)
            return;
        if ((y + r) == b.y && j == b.x)
            return;
    }
    puts("123123123123123123123");
    simpleGEN_PATH(stp, a, b, global_cmp, xmx, xmn, ymx, ymn);
    return;
}

coor simpleGET_PATH(iimce_double* cstp, map* cmp, colmap* global_cmp, coor* pr, coor* a, coor b, iimce_double stp_size)
{
    if (a->x == b.x)
        if (a->y == b.y)
            return b;
    coor p = *a;
    if ((pr->x != b.x) || (pr->y != b.y)) {
        rep(i, cmp->h)
            rep(j, cmp->w)
        {
            global_cmp->mp[i][j] = cmp->cmp.mp[i][j];
        }
        global_cmp->mp[(iimce_int)p.y][(iimce_int)p.x] = -2;
        iimce_int stp = 0;
        *cstp = 1;
        simpleGEN_PATH(stp, p, b, global_cmp, cmp->w - 1, 0, cmp->h - 1, 0);
    }
    *pr = b;
    if (global_cmp == NULL || global_cmp->mp == NULL) {
        return b;
    }
    iimce_double f = global_cmp->mp[(iimce_int)b.y][(iimce_int)b.x];
    if (f <= 0) {
        return b;
    }
    iimce_int mm = 0;
    if (f == (iimce_int)(*cstp)) {
        return b;
    }
    while (f != (iimce_int)(*cstp)) {
        puts("ERRRORRORORO");
        mm++;
        if (mm == 250)
            break;
        coor4 tmp = get4coor(b, cmp->w - 1, 0, cmp->h - 1, 0, b);
        rep(i, 4)
        {
            if ((global_cmp->mp[(iimce_int)tmp.c[i].y][(iimce_int)tmp.c[i].x]) == f - 1) {
                b = tmp.c[i];

                break;
            }
        }
        f -= 1;
    }
    *cstp += stp_size;
    return b;
}

void GEN_PATH_CMS(iimce_int stp, coor a, coor b, colmap* global_cmp, iimce_int xmx, iimce_int xmn, iimce_int ymx, iimce_int ymn, iimce_int MAX_STP)
{
    coor4 tmp = get4coor(a, xmx, xmn, ymx, ymn, b);
    stp++;
    if (stp == MAX_STP)
        return;
    rep(i, 4)
    {
        if (global_cmp->mp[(iimce_int)tmp.c[i].y][(iimce_int)tmp.c[i].x] == 0) {
            global_cmp->mp[(iimce_int)tmp.c[i].y][(iimce_int)tmp.c[i].x] = (signed char)(stp);
            if (tmp.c[i].x == b.x && tmp.c[i].y == b.y)
                return;
            GEN_PATH(stp, tmp.c[i], b, global_cmp, xmx, xmn, ymx, ymn);
        }
    }

    return;
}
coor GET_PATH(iimce_double* cstp, map* cmp, colmap* global_cmp, coor* pr, coor* a, coor b, iimce_double stp_size)
{
    if (a->x == b.x)
        if (a->y == b.y)
            return b;
    coor p = *a;
    if ((pr->x != b.x) || (pr->y != b.y)) {
        rep(i, cmp->h)
            rep(j, cmp->w)
        {
            global_cmp->mp[i][j] = cmp->cmp.mp[i][j];
        }
        global_cmp->mp[(iimce_int)p.y][(iimce_int)p.x] = -2;
        iimce_int stp = 0;
        *cstp = 1;
        GEN_PATH(stp, p, b, global_cmp, cmp->w - 1, 0, cmp->h - 1, 0);
    }
    *pr = b;
    if (global_cmp == NULL || global_cmp->mp == NULL) {
        return b;
    }
    iimce_double f = global_cmp->mp[(iimce_int)b.y][(iimce_int)b.x];
    if (f <= 0) {
        return b;
    }
    iimce_int mm = 0;
    if (f == (iimce_int)(*cstp)) {
        return b;
    }
    while (f != (iimce_int)(*cstp)) {
        mm++;
        if (mm == 250)
            break;
        coor4 tmp = get4coor(b, cmp->w - 1, 0, cmp->h - 1, 0, b);
        rep(i, 4)
        {
            if ((global_cmp->mp[(iimce_int)tmp.c[i].y][(iimce_int)tmp.c[i].x]) == f - 1) {
                b = tmp.c[i];

                break;
            }
        }
        f -= 1;
    }
    *cstp += stp_size;
    return b;
}

coor GET_PATH_CMS(iimce_double* cstp, map* cmp, colmap* global_cmp, coor* pr, coor* a, coor b, iimce_double stp_size, iimce_int MAX_STP)
{
    if (a->x == b.x)
        if (a->y == b.y)
            return b;
    coor p = *a;
    if ((pr->x != b.x) || (pr->y != b.y)) {
        rep(i, cmp->h)
            rep(j, cmp->w)
        {
            global_cmp->mp[i][j] = cmp->cmp.mp[i][j];
        }
        global_cmp->mp[(iimce_int)p.y][(iimce_int)p.x] = -2;
        iimce_int stp = 0;
        *cstp = 1;
        GEN_PATH(stp, p, b, global_cmp, cmp->w - 1, 0, cmp->h - 1, 0);
    }
    *pr = b;
    if (global_cmp == NULL || global_cmp->mp == NULL) {
        return b;
    }
    iimce_double f = global_cmp->mp[(iimce_int)b.y][(iimce_int)b.x];
    if (f <= 0) {
        return b;
    }
    iimce_int mm = 0;
    if (f == (iimce_int)(*cstp)) {
        return b;
    }
    while (f != (iimce_int)(*cstp)) {
        mm++;
        if (mm == 250)
            break;
        coor4 tmp = get4coor(b, cmp->w - 1, 0, cmp->h - 1, 0, b);
        rep(i, 4)
        {
            if ((global_cmp->mp[(iimce_int)tmp.c[i].y][(iimce_int)tmp.c[i].x]) == f - 1) {
                b = tmp.c[i];

                break;
            }
        }
        f -= 1;
    }
    *cstp += stp_size;
    return b;
}

void to_next(iimce_int* a, iimce_int* b)
{
    for (iimce_int i = 0; i != 2; i++) {
        a[i] = b[i];
    }
}

byte player_check_grr(coor* o, iimce_int xmx, iimce_int xmn, iimce_int ymx, iimce_int ymn)
{
    byte t = 0;
    if (o->y > ymx) {
        to_next(cur_level, &curlev().gs);
        o->y = ymn;
        t++;
    }
    if (o->y < ymn) {
        to_next(cur_level, &curlev().gw);
        o->y = ymx;
        t++;
    }
    if (o->x > xmx) {
        to_next(cur_level, &curlev().gd);
        o->x = xmn;
        t++;
    }
    if (o->x < xmn) {
        to_next(cur_level, &curlev().ga);
        o->x = xmx;
        t++;
    }
    return t;
}

byte iimce_check_gr(coor* o, iimce_int* level, iimce_int xmx, iimce_int xmn, iimce_int ymx, iimce_int ymn)
{
    byte t = 0;
    {
        if (o->y > ymx) {
            to_next(level, &getlev(level[0], level[1]).gs);
            o->y = ymn;
            t++;
        }
        if (o->y < ymn) {
            to_next(level, &getlev(level[0], level[1]).gw);
            o->y = ymx;
            t++;
        }
        if (o->x > xmx) {
            to_next(level, &getlev(level[0], level[1]).gd);
            o->x = xmn;
            t++;
        }
        if (o->x < xmn) {
            to_next(level, &getlev(level[0], level[1]).ga);
            o->x = xmx;
            t++;
        }
    }
    return t;
}

void baseAI(world* myworld, void* monster, anyobj* targetslist, iimce_int max, iimce_byte need_path, iimce_byte randtarcoor, iimce_double stp_size, iimce_byte (*checkcmp)(void* any, world* myworld), iimce_double rast, void (*custom_action)(void* any, void* any1), iimce_int speed)
{
    if (targetslist == NULL) {
        need_path = 0;
        randtarcoor = 1;
    }
    if (RANDOM(100) < (100 - speed))
        return;
    obj* a = (obj*)monster;
    obj** targets = (obj**)malloc(sizeof(obj*) * max);
    rep(i, max) targets[i] = (((obj*)(targetslist[i].any)));

    iimce_int need_rand = 1;
    obj* b = (obj*)malloc(sizeof(obj) * 1);
    b->in_inv = 1;
    coor rndcr = { 0, 0 };
    for (iimce_int i = 0; i != max; i++) {
        if ((targets[i] != NULL) & ((a->level[0] == targets[i]->level[0]) & (a->level[1] == targets[i]->level[1]) & targets[i]->in_inv == 0)) {
            b = targets[i];
            rndcr = b->c;
            need_rand = 0;
            break;
        }
    }

    if ((b->in_inv == 1)) {
        need_path = 0;
        randtarcoor = 1;
    }
    if ((need_rand) | (randtarcoor)) {
        iimce_randcoor4(rndcr, -200, -200, myworld->wrld[cur_level[0]][cur_level[1]].w + 300, myworld->wrld[cur_level[0]][cur_level[1]].h + 300);
    } else if (need_rand == 0) {
        for (iimce_int i = 0; i != max; i++)
            if ((a->level[0] == targets[i]->level[0]) && (a->level[1] == targets[i]->level[1]))
                if ((coor_rast(a->c, targets[i]->c) < coor_rast(b->c, targets[i]->c)) & targets[i]->in_inv == 0) {
                    b = targets[i];
                    rndcr = b->c;
                }

        if (need_path)
            if ((coor_rast(a->c, b->c) > rast))
                rndcr = GET_PATH(&a->stp, &myworld->wrld[cur_level[0]][cur_level[1]], &a->global_cmp, &a->tr, &a->c, b->c, stp_size);
    }
    coor old = a->c;
    char tmp = coor_move(&a->c, rndcr, stp_size);
    if (tmp == 'd')
        a->charvec = tmp;
    if ((a->charvec == 'd') && (tmp != 'g') && (tmp != 'w') && (tmp != 's'))
        a->charvec = tmp;
    iimce_check_gr(&a->c, a->level, myworld->wrld[cur_level[0]][cur_level[1]].w - 1, 0, myworld->wrld[cur_level[0]][cur_level[1]].h - 1, 0);
    if (!checkcmp((void*)a, myworld)) {
        a->c = old;
        if (!need_path) {
            if (a->charvec == 'a' || a->charvec == 'b')
                rndcr.y += rand() % (10) - 5;
            else
                rndcr.x += rand() % (10) - 5;
            // a->charvec = coor_move(&a->c, rndcr, stp_size);
            if (!checkcmp((void*)a, myworld))
                a->c = old;
            char tmp = coor_move(&a->c, rndcr, stp_size);
            ;
            if (tmp == 'd')
                a->charvec = tmp;
            if ((a->charvec == 'd') && (tmp != 'g') && (tmp != 'w') && (tmp != 's'))
                a->charvec = tmp;
        }
    }
    if (b->in_inv != 1)
        custom_action((void*)a, (void*)(b));
    return;
}

void simplebaseAI(world* myworld, void* monster, anyobj* targetslist, iimce_int max, iimce_byte need_path, iimce_byte randtarcoor, iimce_double stp_size, iimce_byte (*checkcmp)(void* any, world* myworld), iimce_double rast, void (*custom_action)(void* any, void* any1), iimce_int speed)
{
    if (targetslist == NULL) {
        need_path = 0;
        randtarcoor = 1;
    }
    if (RANDOM(100) < (100 - speed))
        return;
    obj* a = (obj*)monster;
    obj** targets = (obj**)malloc(sizeof(obj*) * max);
    rep(i, max) targets[i] = (((obj*)(targetslist[i].any)));

    iimce_int need_rand = 1;
    obj* b = (obj*)malloc(sizeof(obj) * 1);
    b->in_inv = 1;
    coor rndcr = { 0, 0 };
    for (iimce_int i = 0; i != max; i++) {
        if ((targets[i] != NULL) & ((a->level[0] == targets[i]->level[0]) & (a->level[1] == targets[i]->level[1]) & targets[i]->in_inv == 0)) {
            b = targets[i];
            rndcr = b->c;
            need_rand = 0;
            break;
        }
    }

    if ((b->in_inv == 1)) {
        need_path = 0;
        randtarcoor = 1;
    }
    if ((need_rand) | (randtarcoor)) {
        iimce_randcoor4(rndcr, -200, -200, myworld->wrld[cur_level[0]][cur_level[1]].w + 300, myworld->wrld[cur_level[0]][cur_level[1]].h + 300);
    } else if (need_rand == 0) {
        for (iimce_int i = 0; i != max; i++)
            if ((a->level[0] == targets[i]->level[0]) && (a->level[1] == targets[i]->level[1]))
                if ((coor_rast(a->c, targets[i]->c) < coor_rast(b->c, targets[i]->c)) & targets[i]->in_inv == 0) {
                    b = targets[i];
                    rndcr = b->c;
                }

        if (need_path)
            if ((coor_rast(a->c, b->c) > rast))
                rndcr = simpleGET_PATH(&a->stp, &myworld->wrld[cur_level[0]][cur_level[1]], &a->global_cmp, &a->tr, &a->c, b->c, stp_size);
    }

    coor old = a->c;
    a->charvec = coor_move(&a->c, rndcr, stp_size);
    iimce_check_gr(&a->c, a->level, myworld->wrld[cur_level[0]][cur_level[1]].w - 1, 0, myworld->wrld[cur_level[0]][cur_level[1]].h - 1, 0);
    if (!checkcmp((void*)a, myworld)) {
        a->c = old;
        if (!need_path) {
            if (a->charvec == 'a' || a->charvec == 'b')
                rndcr.y += rand() % (10) - 5;
            else
                rndcr.x += rand() % (10) - 5;
            a->charvec = coor_move(&a->c, rndcr, stp_size);
            if (!checkcmp((void*)a, myworld))
                a->c = old;
        }
    }
    if (b->in_inv != 1)
        custom_action((void*)a, (void*)(b));
    return;
}

struct iimce_window {
    iimce_int x;
    iimce_int y;
    obj* b;
    iimce_int bcount;
    char title[80];
    iimce_texture* tt;
    iimce_texture* bg;
    iimce_texture* cont;
};

iimce_int view_window(struct iimce_window* wn)
{
    struct iimce_font IIMCE_BASE_FONT;
    IIMCE_BASE_FONT.font = IIMCE_STD_FONT;
    IIMCE_BASE_FONT.color = Red;
    IIMCE_BASE_FONT.FONT_SIZE = 10;
    iimce_int b = 0;
    game_pause = 1;
    iimce_texture* ttl = RenderTextIFONT(wn->title, IIMCE_BASE_FONT, render);
    iimce_int tw, th;
    SDL_QueryTexture(ttl, NULL, NULL, &tw, &th);
    iimce_int w = 84 + tw / 2;
    iimce_int h = 54 + th;
    rep(i, wn->bcount) w += wn->b[i].RECT.w;
    h += wn->b[0].RECT.h;
    obj ttile_o = init_obj_TEXTTURE(wn->x * ui_scale_factor_w, wn->y * ui_scale_factor_h, 40 * ui_scale_factor_h, w * ui_scale_factor_w, 0, 0, 0, wn->tt);

    rep(i, wn->bcount) wn->b[i].RECT.w = (w) / (wn->bcount + 1);
    rep(i, (wn->bcount)) wn->b[i].RECT.x = (25) * ui_scale_factor_w + ttile_o.RECT.x + (10 * ui_scale_factor_w + (w) / (wn->bcount + 1) * i) * ui_scale_factor_w;
    rep(i, (wn->bcount)) wn->b[i].RECT.y = (100) * ui_scale_factor_h + ttile_o.RECT.y;
    rep(i, wn->bcount) wn->b[i].RECT.h = (wn->b[i].RECT.w * 0.60);
    w = 84 + tw / 2;
    h = 54 + th;

    rep(i, wn->bcount) w += wn->b[i].RECT.w;
    h += wn->b[0].RECT.h;
    rep(i, (wn->bcount)) wn->b[i].RECT.x = (25) * ui_scale_factor_w + ttile_o.RECT.x + (10 * ui_scale_factor_w + (w) / (wn->bcount + 1) * i) * ui_scale_factor_w;
    rep(i, (wn->bcount)) wn->b[i].RECT.y = (100) * ui_scale_factor_h + ttile_o.RECT.y;
    while (1) {
        view_texture(wn->bg, WHSIZE, WWSIZE);
        view_textureto(wn->cont, ttile_o.RECT.x, ttile_o.RECT.y + 40 * ui_scale_factor_h, h * ui_scale_factor_h, ttile_o.RECT.w);
        view_obj(&ttile_o, 0);
        view_textureto(ttl, ttile_o.RECT.x + 2, ttile_o.RECT.y + 1, th * ui_scale_factor_h, tw * ui_scale_factor_w);
        rep(i, wn->bcount) view_obj(&wn->b[i], 0);
        //VIEWOBJS_NEW(wn->b, 0, wn->bcount, 0, NULL);
        view_obj(&cursor, 1);

        SDL_Event ev = control_mouse_likecursor(&cursor, NULL, 0, IIMCE_WAIT_EVENT());
        if (b) {
            control_mouse_likecursor(&ttile_o, NULL, 0, ev);
            wn->x = ttile_o.RECT.x;
            wn->y = ttile_o.RECT.y;
            rep(i, (wn->bcount)) wn->b[i].RECT.x = (25) * ui_scale_factor_w + ttile_o.RECT.x + (10 * ui_scale_factor_w + (w) / (wn->bcount + 1) * i) * ui_scale_factor_w;
            rep(i, (wn->bcount)) wn->b[i].RECT.y = (100) * ui_scale_factor_h + ttile_o.RECT.y;
        }
        if (ev.type == SDL_MOUSEBUTTONDOWN) {
            if (objcollision(ttile_o, cursor)) {
                b = 1;
            }
            iimce_int idx = objscollision(wn->b, wn->bcount, cursor).index;
            if (idx != -1) {
                game_pause = 0;
                return idx;
            }
        } else if (ev.type == SDL_MOUSEBUTTONUP)
            b = 0;
        usleep(10);
    }
}

#define setting_file_name "setting.txt"
#define setting_data_lenght 1024
#define setting_str_lenght 32
#define max_setting_name 128

int setting_pos = 0;
char setting_data[setting_data_lenght];
#define clear_setting_pos() \
    {                       \
        setting_pos = 0;    \
    }

void load_setting_data()
{

    memset(setting_data, 0, setting_data_lenght);
    int c = 0;
    int i = 0;
    FILE* tmp;
    if ((tmp = fopen(setting_file_name, "r")) == NULL)
        return;
    if (fopen == NULL)
        return;

    while (c != EOF) {
        c = fgetc(tmp);
        if (c != EOF)
            setting_data[i] = c;
        i++;
    }
    fclose(tmp);
    clear_setting_pos();
    return;
}

int cmpMem(const char* block1, const char* block2, int size)
{

    for (int i = 0; i < size; ++i) {
        if (block1[i] != block2[i]) {
            return 0;
        }
    }
    return 1;
}

int strpos(int bpos, const char* str, const char* sub)
{

    int res = -1;
    int lenSub = strlen(sub);
    int lenStr = strlen(str);
    for (int i = bpos; i <= lenStr - lenSub; ++i) {
        if (cmpMem(sub, str + i, lenSub)) {
            res = i;
            break;
        }
    }
    return res;
}

byte setting_file_is_create = 0;

char* get_setting_wpos(char* set)
{

    char setstr[(setting_str_lenght + 1)];
    memset(setstr, 0, setting_str_lenght + 1);
    int setlen = strlen(set);
    int oldpos = setting_pos;
    int pos = strpos(oldpos, setting_data, set);

    if (pos == -1)
        return "error";
    pos += setlen + 1;
    int nlpos = pos + setting_str_lenght - 1;
    int i = 0;
    while (pos != nlpos) {
        setstr[i] = setting_data[pos];
        pos++;
        i++;
    }
    char* buf = (char*)malloc(setting_str_lenght + 2);
    sprintf(buf, "%s", setstr);
    setting_pos = pos;
    return buf;
}

char* get_setting(char* set)
{

    char setstr[(setting_str_lenght + 1)];
    memset(setstr, 0, setting_str_lenght + 1);
    int setlen = strlen(set);
    int oldpos = 0;
    int pos = strpos(oldpos, setting_data, set);
    if (pos == -1) {
        char* buf = (char*)malloc(setting_str_lenght + 2);
        buf[0] = '\0';
        sprintf(buf, "error");
        return buf;
    }

    pos += setlen + 1;
    int nlpos = pos + setting_str_lenght - 1;
    int i = 0;
    while (pos != nlpos) {
        setstr[i] = setting_data[pos];
        //printf("%c %c %d %d %s",setting_data[pos],setstr[i],pos,i,set);
        pos++;
        i++;

        //puts("");
    }
    char* buf = (char*)malloc(setting_str_lenght + 2);
    buf[0] = '\0';

    sprintf(buf, "%s", setstr);
    //puts(buf);puts(setstr);
    //printf("%d",&buf);
    return buf;
}

char* format(char* str, int n)
{
    int m = strlen(str);
    // printf("%d",m);
    for (int i = m; i < n - 1; i++)
        str[i] = ' ';
    str[n - 1] = 0;
    return str;
}

void add_setting_str_to_file(char* key, char* str)
{

    char* buff = (char*)malloc(max_setting_name + setting_str_lenght);
    sprintf(buff, "%s %s\n", key, format(str, setting_str_lenght));
    FILE* f = fopen(setting_file_name, "a");
    fprintf(f, "%s", buff);
    fclose(f);
    free(buff);
}

void interactice_isas_comandline()
{

    puts("\n___WELLCOME TO ISASS - IIMCE Save Setting System");
    char cmd[256];
    char* cmdstr;
    printf("isass_user@ ");
    fgets(cmd, 256, stdin);
    while (strpos(0, cmd, "exit") == -1) {
        if (strpos(0, cmd, "add") != -1) {
            puts("write key");
            memset(cmd, 0, 256);
            fgets(cmd, 256, stdin);
            char buf1[max_setting_name - setting_str_lenght];
            sprintf(buf1, "%s", cmd);
            buf1[strlen(buf1) - 1] = 0;
            puts("write option");
            memset(cmd, 0, 256);
            fgets(cmd, 256, stdin);
            char buf2[setting_str_lenght];
            sprintf(buf2, "%s", cmd);
            buf2[strlen(buf2)] = 0;
            add_setting_str_to_file(buf1, buf2);

        } else if (strpos(0, cmd, "write") != -1) {
            puts("write key");
            memset(cmd, 0, 256);
            fgets(cmd, 256, stdin);
            char buf1[max_setting_name - setting_str_lenght];
            sprintf(buf1, "%s", cmd);
            buf1[strlen(buf1) - 1] = 0;
            printf("%s", get_setting(buf1));
        } else if (strpos(0, cmd, "reload") != -1)
            load_setting_data();
        else {
            puts("error");
        }
        memset(cmd, 0, 256);
        fgets(cmd, 256, stdin);
    }
}
void trim(char* s)
{
    // удаляем пробелы и табы с начала строки:
    int i = 0, j;
    while ((s[i] == ' ') || (s[i] == '\t')) {
        i++;
    }
    if (i > 0) {
        for (j = 0; j < strlen(s); j++) {
            s[j] = s[j + i];
        }
        s[j] = '\0';
    }

    // удаляем пробелы и табы с конца строки:
    i = strlen(s) - 1;
    while ((s[i] == ' ') || (s[i] == '\t')) {
        i--;
    }
    if (i < (strlen(s) - 1)) {
        s[i + 1] = '\0';
    }
}


void trim_weol(char* s)
{
    // удаляем пробелы и табы с начала строки:
    int i = 0, j;
    while ((s[i] == ' ') || (s[i] == '\t') || (s[i] == '\0') || (s[i] == '\n')) {
        i++;
    }
    if (i > 0) {
        for (j = 0; j < strlen(s); j++) {
            s[j] = s[j + i];
        }
        s[j] = '\0';
    }

    // удаляем пробелы и табы с конца строки:
    i = strlen(s) - 1;
    while ((s[i] == ' ') || (s[i] == '\t') || (s[i] == '\0') || (s[i] == '\n')) {
        i--;
    }
    if (i < (strlen(s) - 1)) {
        s[i + 1] = '\0';
    }
}


#define casedo(a, b) \
    case a:          \
        b;           \
        break;

#define create_setting_file()              \
    {                                      \
        FILE* f;                           \
        f = fopen(setting_file_name, "w"); \
    }

#endif

#pragma once
