/**
 * Author: Yaseen
 * Date: 07.10.2024
 * Purpose: This program creates an SDL window and allows the user to draw points at mouse click locations.
 *          The program exits when the Escape key is pressed or the window is closed.
 */

#include <stdio.h>
#include <SDL.h>

int main(int arcs, char *args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Initialization failed");
        return -1;
    }
    else
    {
        printf("Initialization successful");
    }

    SDL_Window *Window = SDL_CreateWindow("Main Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, SDL_WINDOW_SHOWN);
    if (!Window)
    {
        printf("Window creation failed");
        return -1;
    }
    else
    {
        printf("Window created successfully");
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer)
    {
        printf("Renderer creation failed");
        return -1;
    }
    else
    {
        printf("Renderer created successfully");
    }

    // Set background color and clear renderer
    SDL_SetRenderDrawColor(renderer, 20, 198, 199, 255);
    SDL_RenderClear(renderer);
    
    // Set draw color to black for points
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);

    int running = 1;
    SDL_Event event;

    // Event loop to handle mouse clicks and exit conditions
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int x = event.button.x;
                int y = event.button.y;
                SDL_RenderDrawPoint(renderer, x, y); // Draws a point at the mouse click location
                SDL_RenderPresent(renderer);
                SDL_Delay(10); // Delay to control drawing speed
            }
            if (event.key.keysym.sym == SDLK_ESCAPE || event.type == SDL_QUIT)
            {
                running = 0; // Exits the program on Escape key or window close
                return 0;
            }
        }
    }

    SDL_Delay(4000); // Delay before closing window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
}
