#include<iostream>
#include<SDL2/SDL.h>
#define SDL_MAIN_HANDLED
bool running;
SDL_Window* window=NULL;
SDL_Renderer* renderer= NULL;
SDL_Event input;

void userinput(int &x,int &y)
{
    
        SDL_PollEvent(&input);
        switch(input.type)
        {
            case SDL_QUIT:
                running= false;
                break;
     
            case SDL_KEYDOWN:
                switch(input.key.keysym.sym)
                {
                    case SDLK_a:
                    x=x-1;
                
                    break;
                    case SDLK_s:
                    y=y+1;
                    break;
                    case SDLK_d:
                    x=x+1;
                    break;
                    case SDLK_w:
                    y=y-1;
                    break;
                    default:
                    break;

                }
     
     
     
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
        userinput(x,y);
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
        SDL_RenderPresent(renderer);
        

    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    

    return 0;
}