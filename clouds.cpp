#include<iostream>
#include<SDL2/SDL.h>
#define SDL_MAIN_HANDLED
SDL_Window* window=NULL;
SDL_Renderer* renderer=NULL;
bool running ;
void clouds()
{

}
int main(int argc,char* argv[])
{

    if(SDL_Init(SDL_INIT_EVERYTHING)==0)
    {
        running=true;
        window=SDL_CreateWindow("clouds graphic",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1600,600,SDL_WINDOW_SHOWN);
        renderer=SDL_CreateRenderer(window,-1,0);
    }
    while(running)
    {
        SDL_Event input;
        SDL_PollEvent(&input);
        switch(input.type)
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