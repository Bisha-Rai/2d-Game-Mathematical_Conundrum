#include<iostream>
#include<SDL2/SDL.h>
#define SDL_MAIN_HANDLED
SDL_Window* window=NULL;
SDL_Renderer* renderer=NULL;
bool running=true;
SDL_Event event;
int main(int argc,char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window=SDL_CreateWindow("sample window",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_SHOWN);
    renderer=SDL_CreateRenderer(window,-1,0);
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_Rect rect;
    rect.w=100;
    rect.h=100;
    rect.x=350;
    rect.y=275;
    SDL_RenderFillRect(renderer,&rect);
    SDL_RenderPresent(renderer);
    while(running)
    {
        
        SDL_PollEvent(&event);
        switch(event.type)
        {   
            case SDL_QUIT:
                running=false;
                break;
            default:
            break;
        }
    }

SDL_DestroyWindow(window);
SDL_DestroyRenderer(renderer);
    SDL_Quit();


return 0;
}