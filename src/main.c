#include <stdio.h>
#include <SDL.h>
int main(int args ,char* ar[])
{
    int a= SDL_Init(SDL_INIT_VIDEO); // if a == 0 means true else flase
    if(a!=0){
        printf("failed");
        return -1;
    }
    else{
        printf("intiallization successful");
    }
    SDL_Window* Window=SDL_CreateWindow("This is the window name",
    SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1080,720,SDL_WINDOW_SHOWN);
    if(!Window)
    {
        printf("Window not created\n");
        return -1;
    }
    else
        printf("Window creation successfully");
        
        SDL_Renderer* renderer=SDL_CreateRenderer(Window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer==NULL){
        printf("rendered failed");
        return -1;
    }        
    else
    {
        printf("sucessful");
    }
    SDL_SetRenderDrawColor(renderer,105,77,225,255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(2000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
}