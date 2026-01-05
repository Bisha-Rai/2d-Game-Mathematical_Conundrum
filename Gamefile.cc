#include<iostream>
#include<SDL2/SDL.h>
#define SDL_MAIN_HANDLED
bool running;
SDL_Window* window=NULL;
SDL_Renderer* renderer= NULL;

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
    character r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15,r16,r17,r18,r20,r19,r21,r22,r23,r24,r25,r26,r27,r28,r29,r30,r31,r32,r33,r34,r35,r36,r37,r38,r39,r40,r41,r42,r43,r44,r45;
    if(SDL_Init(SDL_INIT_EVERYTHING)==0)
    {
        window=SDL_CreateWindow("Mathematical Conundrum",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1400,800,SDL_WINDOW_SHOWN);
        renderer=SDL_CreateRenderer(window,-1,0);
        running=true;
    }
    else{
        running=false;
    }


    while(running) //currently using for close window later on gameloop.
    {
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        r1.render(500,200,22,10);
        r2.render(522,210,10,10);
        r3.render(532,220,10,10);
        r4.render(532,230,70,10);
        r5.render(592,220,10,10);
        r6.render(602,210,10,10);
        r7.render(612,200,18,10);
        r8.render(630,210,10,60);
        r9.render(640,270,10,40);
        r10.render(630,290,32,10);
        r11.render(630,310,34,10);
        r12.render(616,320,14,10);
        r13.render(630,330,10,10);
        r14.render(640,340,10,40);
        r15.render(630,370,10,10);
        r16.render(620,380,20,10);
        r17.render(610,340,10,80);
        r18.render(580,420,45,10);
        r19.render(580,400,10,20);
        r20.render(540,400,40,10);
        r21.render(540,410,10,20);
        r22.render(510,420,45,10);
        r23.render(510,390,10,30);
        r24.render(490,380,40,10);
        r25.render(460,390,40,10);
        r26.render(440,380,20,10);
        r27.render(430,370,10,10);
        r28.render(420,310,10,60);
        r29.render(430,300,20,10);
        r30.render(450,310,10,50);
        r31.render(490,210,10,80);
        r32.render(468,290,42,10);
        r33.render(470,310,40,10);
        r34.render(490,330,30,10);
        r35.render(480,340,10,10);
        r36.render(470,350,10,20);
        r37.render(480,370,10,10);
        r38.render(515,360,22,10);
        r39.render(530,350,10,30);
        r40.render(602,270,10,30);
        r41.render(542,270,10,30);
        r42.render(572,300,20,10);
        SDL_Event input;
        SDL_PollEvent(&input);
        switch(input.type)
        {
            case SDL_QUIT:
                running= false;
                break;
            default:
                break;
        }
        SDL_RenderPresent(renderer);

    }
    

    return 0;
}