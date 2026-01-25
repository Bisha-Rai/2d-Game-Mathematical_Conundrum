#include<iostream>
using namespace std;
#include<SDL2/SDL.h>
int isRunning;
int j=0;
int change=0;

SDL_Window*window=NULL;
    SDL_Renderer*renderer=NULL;
void platform()
{int y=200,x=0,w=60,h=10;
     
    int i;
    for(i=0;i<15;i++)
    {
    SDL_Rect ground;
    ground.x=x;+change;
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
x=x+60;
    }
}
int main(int argc,char* argv[])
{   int c,i;
    cout<<"enter 1 for rectangle 2 for line"<<endl;
    cin>>c;

    
    if(SDL_Init(SDL_INIT_EVERYTHING)==0)
    {
        window=SDL_CreateWindow("SDL test window",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,300,SDL_WINDOW_SHOWN);
        renderer=SDL_CreateRenderer(window,-1,0);
        isRunning=1;
    }
    else{
        isRunning=0;
    }
    while(isRunning)
    {
        Uint32 start=SDL_GetTicks();
       
            SDL_Event event;
            SDL_PollEvent(&event);
            switch(event.type)
            {
                case SDL_QUIT:
                    isRunning=0;
                    break;
                case SDL_KEYDOWN:
                 j++;
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_a:
                        if(j%2==0)
                        {
                            change=0;
                        }
                        else
                        {
                            change=-30;
                        }
                        case SDLK_d:
                         if(j%2==0)
                        {
                            change=-30;
                        }
                        else
                        {
                            change=0;
                        }
                        default:
                        break;
                    }
                    default:
                    break;
                
        }
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        if(c==1)
        {
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_Rect rect;
        rect.x=100;
        rect.y=100;
        rect.w=50;
        rect.h=25;

        SDL_RenderFillRect(renderer,&rect);
        }
        else
        {
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        for(i=200;i<400;i++)
            {

                SDL_RenderDrawPoint(renderer,i,i);
            }
        }
        platform();
        SDL_RenderPresent(renderer);
        int end=SDL_GetTicks()-start;
        if(end<16)
        {
        SDL_Delay(16-end);
    }
}

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}
