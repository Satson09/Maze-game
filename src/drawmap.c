#include "maze.h"

bool minimapEnabled = true;

/**
 * drawMinimap - Draws the minimap on the window
 * @maze: 2D array defining the maze map
 * Return: void
 */
void renderMinimap(int *maze) {
    int mapScale = 10; // Scale factor for the minimap
    int playerSize = 5; // Size of the player marker

    // Draw the maze
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            SDL_Rect rect = {x * mapScale, y * mapScale, mapScale, mapScale};
            if (maze[y * MAP_WIDTH + x] > 0) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White for walls
            } else {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black for empty space
            }
            SDL_RenderFillRect(renderer, &rect);
        }
    }

    // Draw the player
    SDL_Rect playerRect = {(int)(pos.x * mapScale) - playerSize / 2, (int)(pos.y * mapScale) - playerSize / 2, playerSize, playerSize};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green for the player
    SDL_RenderFillRect(renderer, &playerRect);

    // Draw the player's line of sight
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red for the line of sight
    SDL_RenderDrawLine(renderer, (int)(pos.x * mapScale), (int)(pos.y * mapScale),
                       (int)((pos.x + dir.x * 5) * mapScale), (int)((pos.y + dir.y * 5) * mapScale));
}

