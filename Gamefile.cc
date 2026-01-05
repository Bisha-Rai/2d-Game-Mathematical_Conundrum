#include<iostream>
#include<SDL2/SDL.h>
#define SDL_MAIN_HANDLED
bool running;
SDL_Window* window=NULL;
SDL_Renderer* renderer= NULL;
int main(int argc,char* argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING)==0)
    {
        window=SDL_CreateWindow("Mathematical Conundrum",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1400,800,SDL_WINDOW_SHOWN);
        renderer=SDL_CreateRenderer(window,-1,0);
        running=true;
    }
    else{
        running=false;
    }

    while(running)
    {
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

    }
    

    return 0;
}