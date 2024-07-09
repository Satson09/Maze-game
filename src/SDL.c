#include "maze.h"

/* Initialize textures and untextured arrays */
SDL_Texture *textures[TEX_COUNT];
SDL_Texture *untextured[TEX_COUNT];
weapon_t weapon;


/**
 * loadWeapon - loads the weapon texture
 * @file: path to the weapon texture file
 * Return: True on success, False on failure
 */
bool loadWeapon(const char *file)
{
    SDL_Surface *loadedSurface = IMG_Load(file);
    if (!loadedSurface)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", file, IMG_GetError());
        return false;
    }

    weapon.texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);

    if (!weapon.texture)
    {
        printf("Unable to create texture from %s! SDL Error: %s\n", file, SDL_GetError());
        return false;
    }

    // Set weapon position
    weapon.position.x = SCREEN_WIDTH / 2 - 50;
    weapon.position.y = SCREEN_HEIGHT - 150;
    weapon.position.w = 100;
    weapon.position.h = 100;

    return true;
}


/**
 * initSDL - initializes SDL, window, and renderer
 * Return: True on success, False on failure
 */
bool initSDL(void)
{
	bool success = true;

	window = NULL;
	renderer = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}

	window = SDL_CreateWindow("Maze-Game", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (texture == NULL)
	{
		printf("Texture could not be initialized! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	if (!loadWeapon("textures/gun1.png"))
	{
	        success = false;
	}

	return (success);
}

/**
 * updateRenderer - updates renderer with updated buffer / texture
 * @textured: True if user enabled textures, otherwise False
 * Return: void
 */
void updateRenderer(bool textured)
{
	int x, y; /* loop counters */

	/* draw buffer to renderer */
	if (textured)
	{
		SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * 4);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);

		/* clear buffer */
		for (x = 0; x < SCREEN_WIDTH; x++)
			for (y = 0; y < SCREEN_HEIGHT; y++)
			    buffer[y][x] = 0;
	}

	/* update screen */
	SDL_RenderCopy(renderer, weapon.texture, NULL, &weapon.position);
	SDL_RenderPresent(renderer);
}

/**
 * closeSDL - closes texture, renderer, and window
 * Return: void
 */
void closeSDL(void)
{
    // Free textures
    for (int i = 0; i < TEX_COUNT; i++)
    {
        if (textures[i] != NULL)
	{
            SDL_DestroyTexture(textures[i]);
            textures[i] = NULL;
        }

        if (untextured[i] != NULL)
	{
            SDL_DestroyTexture(untextured[i]);
            untextured[i] = NULL;
        }
    }

    // Free weapon texture
    if (weapon.texture != NULL)
    {
        SDL_DestroyTexture(weapon.texture);
        weapon.texture = NULL;
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}
