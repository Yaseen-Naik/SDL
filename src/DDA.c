/*
  Author: Yaseen
  Date: 17.10.2024
  Purpose: This program initializes SDL to create a window and renderer,
           then draws a line using DDA algorithm with event handling.
 */
 

#include <math.h>
#include <stdio.h>
#include <SDL.h>

int main(int args, char *ar[])
{
    int a = SDL_Init(SDL_INIT_VIDEO); // Initialize SDL for video; returns 0 on success
    if (a != 0)
    {
        printf("failed\n");
        return -1;
    }
    else
    {
        printf("initialization successful\n");
    }

    SDL_Window *Window = SDL_CreateWindow("This is the window name",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, SDL_WINDOW_SHOWN);
    if (!Window)
    {
        printf("Window not created\n");
        return -1;
    }
    else
    {
        printf("Window creation successful\n");
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        printf("Renderer creation failed\n");
        return -1;
    }
    else
    {
        printf("Renderer creation successful\n");
    }

    SDL_SetRenderDrawColor(renderer, 105, 77, 225, 255); // Set background color
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 225, 255); // Set drawing color for the line

    SDL_Event event;
    float x1, y1, x2, y2, steps, dx, dy, running = 0, m;
    x1 = 0;
    y1 = 720;
    x2 = 1080;
    y2 = 0;
    dx = (x2 - x1);
    dy = (y2 - y1);
    m = dy / dx;

    // Determine number of steps based on line slope
    steps = (dy >= dx) ? dy : dx;

    if (m >= 1)
    {
        // Loop to draw line when slope is >= 1
        while (running <= steps)
        {
            SDL_PollEvent(&event);
            if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
            {
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(Window);
                SDL_Quit();
                printf("program terminated successfully\n");
                exit(0);
            }
            SDL_RenderDrawPoint(renderer, x1, y1);
            y1++;
            x1 = round(x1 + 1 / m);
            SDL_RenderPresent(renderer);
            SDL_Delay(16);
            running++;
        }
    }
    else
    {
        // Loop to draw line when slope is < 1
        while (running <= steps)
        {
            SDL_PollEvent(&event);
            if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
            {
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(Window);
                SDL_Quit();
                printf("program terminated successfully\n");
                exit(0);
            }
            SDL_RenderDrawPoint(renderer, round(x1), round(y1));
            x1++;
            y1 = y1 + m;
            SDL_RenderPresent(renderer);
            SDL_Delay(20);
            running++;
        }
    }

    SDL_Delay(2000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
    return 0;
}
