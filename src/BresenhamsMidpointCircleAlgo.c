/**
 * Author: Yaseen
 * Date: 17.10.2024
 * Purpose: This program creates a window and uses Bresenham’s Midpoint Circle Algorithm
 *          to draw a circle in the center of the window with a specified radius.
 */

#include <SDL.h>
#include <stdio.h>

/**
 * Draws symmetrical points around the center to form a circle.
 *
 * @param renderer Pointer to SDL_Renderer for drawing.
 * @param x X-coordinate offset from the center.
 * @param y Y-coordinate offset from the center.
 * @param xc X-coordinate of the circle center.
 * @param yc Y-coordinate of the circle center.
 */
void DrawPoint(SDL_Renderer* renderer, int x, int y, int xc, int yc )
{ 
    SDL_RenderDrawPoint(renderer, xc + x, yc - y);
    SDL_RenderDrawPoint(renderer, xc - x, yc - y);
    SDL_RenderDrawPoint(renderer, xc + x, yc + y);
    SDL_RenderDrawPoint(renderer, xc - x, yc + y);
    SDL_RenderDrawPoint(renderer, xc + y, yc + x);
    SDL_RenderDrawPoint(renderer, xc + y, yc - x);
    SDL_RenderDrawPoint(renderer, xc - y, yc + x);
    SDL_RenderDrawPoint(renderer, xc - y, yc - x);
}

int main(int args, char* arcs[])
{
    int running = 1, xc, yc, x, y, r, p;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Initialization failed\n");
        return -1;
    }
    else
    {
        printf("Initialization successful\n");
    }

    SDL_Window* window = SDL_CreateWindow("Main window", 100, 100, 1080, 720, SDL_WINDOW_HIDDEN);
    if (!window)
    {
        printf("Window creation failed\n");
        return -1;
    }
    else
    {
        printf("Window created\n");
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer)
    {
        printf("Renderer creation failed\n");
        SDL_DestroyWindow(window);
        return -1;
    }

    SDL_SetRenderDrawColor(renderer, 255, 10, 0, 255); // Orange background
    SDL_RenderClear(renderer);
    SDL_ShowWindow(window);
    SDL_RenderPresent(renderer);

    // Set circle parameters (center and radius)
    xc = 1080 / 2;
    yc = 720 / 2;
    r = 250;

    // Initial decision parameter
    p = 1 - r;
    x = 0;
    y = r;

    SDL_Event event;
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255); // Cyan color for drawing

    while (x <= y)
    {   
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
        {
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            printf("Program terminated\n");
            SDL_Quit();
            exit(0);
        }

        // Decide the next pixel position
        if (p < 0)
        {
            DrawPoint(renderer, x, y, xc, yc);
            p = p + 2 * x + 1;
        }
        else
        {
            y--;
            DrawPoint(renderer, x, y, xc, yc);
            p = p + 2 * x - 2 * y + 1;
        }

        x++;
        SDL_RenderPresent(renderer);
        SDL_Delay(50);               
    }

    // Allow 4 seconds before automatic close
    int stoppingtime = 4000, timepassed = 0, timerate = 16;
    while (running && timepassed <= stoppingtime)
    {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
        {
            running = 0;
        }
        SDL_Delay(timerate);
        timepassed += timerate;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    printf("Program terminated\n");
    SDL_Quit();

    return 0;
}
