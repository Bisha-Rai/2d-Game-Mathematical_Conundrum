#include <iostream>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
bool running = false;

void drawCloud()
{
    // White color ko  cloud banxa
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Cloud made of rectangles
 SDL_Rect r1 = {800, 400, 189, 10};
SDL_Rect r2 = {780, 390, 20, 10};
SDL_Rect r3 = {770, 380, 10, 10};
SDL_Rect r4 = {760, 360, 10, 20};
SDL_Rect r5 = {770, 350, 10, 10};
SDL_Rect r6 = {780, 340, 30, 10};
SDL_Rect r7 = {800, 330, 30, 10};
SDL_Rect r8 = {820, 307, 10, 25};
SDL_Rect r9 = {830, 299, 25, 8};


SDL_Rect r11 = {850, 290, 20, 10};
SDL_Rect r12 = {865, 300, 15, 10};
SDL_Rect r13 = {880, 300, 15, 10};

SDL_Rect r14 = {890, 290, 20, 10};
SDL_Rect r15 = {906, 298, 25, 10};
SDL_Rect r16 = {931, 307, 20, 10};
SDL_Rect r17 = {951, 313, 10, 21};
SDL_Rect r18 = {951, 334, 30, 10};
SDL_Rect r19 = {972, 344, 25, 10};


SDL_Rect r20 = {998, 354, 10, 10};
SDL_Rect r21 = {1008, 364, 10, 20};
SDL_Rect r22 = {998, 383, 10, 10};
SDL_Rect r23 = {990, 393, 10, 10};



    SDL_RenderFillRect(renderer, &r1);
    SDL_RenderFillRect(renderer, &r2);
    SDL_RenderFillRect(renderer, &r3);
    SDL_RenderFillRect(renderer, &r4);
    
    SDL_RenderFillRect(renderer, &r5);
   
    SDL_RenderFillRect(renderer, &r6);
    SDL_RenderFillRect(renderer, &r7);
    SDL_RenderFillRect(renderer, &r8);

     SDL_RenderFillRect(renderer, &r9);
  
   
    
    SDL_RenderFillRect(renderer, &r11);
    SDL_RenderFillRect(renderer, &r12);
    SDL_RenderFillRect(renderer, &r13);
    SDL_RenderFillRect(renderer, &r14);
    SDL_RenderFillRect(renderer, &r15);
    SDL_RenderFillRect(renderer, &r16);

    SDL_RenderFillRect(renderer, &r17);
    SDL_RenderFillRect(renderer, &r18);
    SDL_RenderFillRect(renderer, &r19);

 
    SDL_RenderFillRect(renderer, &r20);
 
    SDL_RenderFillRect(renderer, &r21);
    SDL_RenderFillRect(renderer, &r22); 
    SDL_RenderFillRect(renderer, &r23); 
}

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(
            "Cloud Drawing",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            1600,
            600,
            SDL_WINDOW_SHOWN
        );

        if (window != NULL)
        {
<<<<<<< HEAD
            renderer = SDL_CreateRenderer(window, -1, 0);
            running = true;
=======
            
            case SDL_QUIT:
                running=false;
            break;
            git fg
            clouds();
            case SDL_KEYDOWN:
            
            clouds();break;
            
            default:
            break;
>>>>>>> 0edabf0f4bba0070fe0ff159a7975186b4cca41e
        }
        clouds();
    }

    while (running)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                running = false;
        }

        // Black background
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw cloud
        drawCloud();

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
