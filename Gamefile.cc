#include<iostream>
#include<SDL2/SDL.h>
#define SDL_MAIN_HANDLED
bool running;
SDL_Window* window=NULL;
SDL_Renderer* renderer= NULL;
SDL_Event input;
using namespace std;
int i=0;
int j=0;
int change=0;
void platform()
{int y=430,x=0,w=60,h=10;
    
     
    int i;
    for(i=0;i<35;i++)
    {
    SDL_Rect ground;
    ground.x=x+change;
    ground.y=y;
    ground.w=w;
    ground.h=h;
    SDL_Rect ground2;
    ground2.x=x+20+change;
    ground2.y=y+10;
    ground2.w=w-40;
    ground2.h=h;
    SDL_Rect ground3;
    ground3.x=x+change;
    ground3.y=y+20;
    ground3.w=w-40;
    ground3.h=h;
    SDL_Rect ground4;
    ground4.x=x+40+change;
    ground4.y=y+20;
    ground4.w=w-40;
    ground4.h=h;
    SDL_Rect ground5;
    ground5.x=x+20+change;
    ground5.y=y+30;
    ground5.w=w-40;
    ground5.h=h;
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderFillRect(renderer,&ground);
        SDL_RenderFillRect(renderer,&ground2);
            SDL_RenderFillRect(renderer,&ground3);
                SDL_RenderFillRect(renderer,&ground4);
                    SDL_RenderFillRect(renderer,&ground5);
x=x+60;//to add the ground block every 60 pixels from the previous start point dont forget
    }
}
void userinput(int &x,int &y)
{
    
        SDL_PollEvent(&input);
        switch(input.type)
        {
            case SDL_QUIT:
                running= false;
                break;

            case SDL_KEYUP:
                
                    switch(input.key.keysym.sym)
                    {
                        case SDLK_a:
                        i=0;
                        break;
                        case SDLK_s:
                        i=0;
                        break;
                        case SDLK_d:
                        i=0;
                        break;
                        case SDLK_w:
                        i=0;
                        break;
                        default:
                        break;
                    }
                break;

            case SDL_KEYDOWN:
             i++;
             j++;
             if(j>6)
             {
                j=0;
             }
            if(i>6)
            {
                i=0;
            }
                switch(input.key.keysym.sym)
                {
                    case SDLK_a:
                    x=x;
                    if(j<3)
                        {
                            change=0;
                        }
                     else 
                     {
                        change=-30;
                     }
                        
                    break;
                    case SDLK_s:
                    y=y+20;
                    break;
                    case SDLK_d:
                    x=x;
                      if(j<3)
                        {
                            change=0;
                        }
                  
                        else
                        {
                            change=-30;
                            
                        }
                    break;
                    case SDLK_w:
                    y=y-20;
                    break;
                    default:
                    break;
                }
                break;
                
            default:
                break;
            
            }
        
}

class character
{
    public:
    void render(int x,int y,int w,int h)
    {
        
         SDL_Rect rect;
        rect.x=x;
        rect.y=y;
        rect.w=w;
        rect.h=h;
          SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_RenderFillRect(renderer,&rect);
      
        
      
        }
};


int main(int argc,char* argv[])
{
    int x=0,y=0,w=0,h=0;
    character r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15,r16,r17,r18,r20,r19,r21,r22,r23,r24,r25,r26,r27,r28,r29,r30,r31,r32,r33,r34,r35,r36,r37,r38,r39,r40,r41,r42,r43,r44,r45,r46,r47,r48,r49,r50,r51,r52,r53,r54,r55,r56,r57,r58,r59,r60,r61,r62,r63,r64;
    if(SDL_Init(SDL_INIT_EVERYTHING)==0)
    {
        window=SDL_CreateWindow("Mathematical Conundrum",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1500,700,SDL_WINDOW_SHOWN);
        renderer=SDL_CreateRenderer(window,-1,0);
        running=true;
    }
    else{
        running=false;
    }
    SDL_Rect rect2;
    rect2.x=-100;
    rect2.y=430;
    rect2.w=2000;
    rect2.h=10;


    while(running) 
    {
        Uint32 framestart=SDL_GetTicks();
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        userinput(x,y);
       
        if(i<=3)
        {
        r1.render(x+500,y+200,22,10);
        r2.render(x+522,y+210,10,10);
        r3.render(x+532,y+220,10,10);
        r4.render(x+532,y+230,70,10);
        r5.render(x+592,y+220,10,10);
        r6.render(x+602,y+210,10,10);
        r7.render(x+612,y+200,18,10);
        r8.render(x+630,y+210,10,60);
        r9.render(x+640,y+270,10,40);
        r10.render(x+630,y+290,32,10);
        r11.render(x+630,y+310,34,10);
        r12.render(x+616,y+320,14,10);
        r13.render(x+630,y+330,10,10);
        r14.render(x+640,y+340,10,40);
        r15.render(x+630,y+370,10,10);
        r16.render(x+620,y+380,20,10);
        r17.render(x+610,y+340,10,80);
        r18.render(x+580,y+420,45,10);
        r19.render(x+580,y+400,10,20);
        r20.render(x+540,y+400,40,10);
        r21.render(x+540,y+410,10,20);
        r22.render(x+510,y+420,45,10);
        r23.render(x+510,y+390,10,30);
        r24.render(x+490,y+380,40,10);
        r25.render(x+460,y+390,40,10);
        r26.render(x+440,y+380,20,10);
        r27.render(x+430,y+370,10,10);
        r28.render(x+420,y+310,10,60);
        r29.render(x+430,y+300,20,10);
        r30.render(x+450,y+310,10,50);
        r31.render(x+490,y+210,10,80);
        r32.render(x+468,y+290,42,10);
        r33.render(x+470,y+310,40,10);
        r34.render(x+490,y+330,30,10);
        r35.render(x+480,y+340,10,10);
        r36.render(x+470,y+350,10,20);
        r37.render(x+480,y+370,10,10);
        r38.render(x+515,y+360,22,10);
        r39.render(x+530,y+350,10,30);
        r40.render(x+602,y+270,10,30);
        r41.render(x+542,y+270,10,30);
        r42.render(x+572,y+300,20,10);
        }
        if(i>3&&i<=6)
        {
            r1.render(x+520,y+420,30,10);
            r2.render(510+x,y+390,10,30);
            r3.render(x+550,y+390,10,25);
            r4.render(x+520,y+380,15,10);
            r5.render(x+550,y+390,10,25);
            r6.render(x+560,y+380,50,10);
            r7.render(x+610,y+390,10,10);
            r8.render(x+620,y+400,25,10);
            r9.render(x+645,y+390,10,10);
            r10.render(x+655,y+360,10,30);
            r11.render(x+647,y+360,8,10);
            r12.render(x+635,y+295,10,70);
            r13.render(x+623,y+365,12,10);
            r14.render(x+645,y+328,10,7);
            r15.render(x+647,y+325,30,8);
            r16.render(x+663,y+328,25,7);
            r17.render(x+688,y+293,10,32);
            r18.render(x+658,y+293,30,10);
            r19.render(x+597,y+286,50,10);
            r20.render(x+647,y+277,27,8);
            r21.render(x+648,y+275,20,10);
            r22.render(x+674,y+267,10,10);
            r23.render(x+684,y+257,10,10);
            r24.render(x+694,y+247,30,10);
            r25.render(x+694,y+229,30,8);
            r26.render(x+704,y+209,10,20);
            r27.render(x+694,y+129,10,80);
            r28.render(x+678,y+119,16,10);
            r29.render(x+668,y+129,10,10);
            r30.render(x+658,y+139,10,10);
            r31.render(x+578,y+149,80,10);
            r32.render(x+568,y+139,10,10);
            r33.render(x+558,y+129,10,10);
            r34.render(x+533,y+119,25,10);
            r35.render(x+523,y+129,10,110);
            r36.render(x+510,y+216,40,10);
            r37.render(x+533,y+239,10,30);
            r38.render(x+523,y+246,30,10);
            r39.render(x+543,y+269,10,10);
            r40.render(x+553,y+279,10,10);
            r41.render(x+543,y+295,20,10);
            r42.render(x+523,y+305,20,10);
            r43.render(x+513,y+315,10,25);
            r44.render(x+520,y+340,30,10);
            r45.render(x+550,y+325,10,40);
            r46.render(x+560,y+325,20,10);
            r47.render(x+500,y+365,60,10);
            r48.render(x+492,y+355,8,10);
            r49.render(x+480,y+345,10,10);
            r50.render(x+472,y+335,8,10);
            r51.render(x+460,y+275,9,60);
            r52.render(x+470,y+264,15,11);
            r53.render(x+487,y+275,9,60);
            r54.render(x+497,y+335,12,10);
            r55.render(x+665,y+205,10,30);
            r56.render(x+593,y+205,12,30);
            r57.render(x+623,y+240,20,12);
        }
        platform();
           SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_RenderFillRect(renderer,&rect2);
        SDL_RenderPresent(renderer);    
         
        Uint32 frameduration=SDL_GetTicks()-framestart;
        if(frameduration<32)
        {
            SDL_Delay(32-frameduration);
        }
      
    }
     
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    

    return 0;
}
