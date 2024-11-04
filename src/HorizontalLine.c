/**
 * Author: Yaseen
 * Date: 15.10.24
 * Purpose: This program creates an SDL window and draws a horizontal line using individual points.
 */

#include <stdio.h>
#include <SDL.h>

int main(int argc, char* arr[])
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("\nInitialization Failed");
        return -1;
    }
    else
    {
        printf("\nInitialization Successful");
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("MyWindow", 100, 100, 1080, 720, SDL_WINDOW_SHOWN);
    if (!window)
    {
        printf("\nWindow Not Created");
        return -1;
    }
    else
    {
        printf("\nWindow Created Successfully");
    }

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer)
    {
        printf("\nRenderer Not Created");
        return -1;
    }

    // Set background color and clear the renderer
    SDL_SetRenderDrawColor(renderer, 20, 30, 40, 100);
    SDL_RenderClear(renderer);

    // Set draw color for the line
    SDL_SetRenderDrawColor(renderer, 50, 50, 255, 255);

    // Draw a horizontal line by drawing points
    for (int i = 40; i <= 1040; i++)
    {
        int j = 360; // Y-coordinate for the horizontal line
        SDL_RenderDrawPoint(renderer, i, j);
        SDL_Delay(4); // Delay to control drawing speed
        SDL_RenderPresent(renderer); // Present the rendered point
    }

    // Cleanup and exit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
