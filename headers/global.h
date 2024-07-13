#ifndef GLOBAL_H
#define GLOBAL_H


/* texture for muzzle flash */
SDL_Texture *muzzleFlashTexture;

/* flag to indicate muzzle flash visibility */
bool muzzleFlashActive;

/* end time for muzzle flash duration */
Uint32 muzzleFlashEndTime;

/* texture for muzzle flash */
extern SDL_Texture *muzzleFlashTexture;

/* flag to indicate muzzle flash visibility */
extern bool muzzleFlashActive;

/* end time for muzzle flash duration */
extern Uint32 muzzleFlashEndTime;


/* render window */
extern SDL_Window *window;

/* window renderer */
extern SDL_Renderer *renderer;

/* texture */
extern SDL_Texture *texture;

/* buffer for textures */
extern uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

/* array of textures */
extern uint32_t tiles[TEX_COUNT][TEX_HEIGHT][TEX_WIDTH];

extern bool minimapEnabled;

/* X and Y start position */
extern point_t pos;

/* initial direction vector */
extern point_t dir;

/* camera plane */
extern point_t plane;

/* time of current frame */
extern double time;

/*weapon textture */
extern weapon_t weapon;

#endif /* GLOBAL_H */
