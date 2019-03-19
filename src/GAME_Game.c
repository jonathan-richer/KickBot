#include <SDL2/SDL.h>
#include "GAME_Game.h"

GAME_INIT_ReturnCode GAME_Init(GAME_Game *game, GAME_AppSettings &settings)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
  {
    GAME_ERROR = "SDL failed to initialize. SDL Error: " + SDL_GetError();
    return GAME_INIT_SDL_FAILURE;
  }
  
  game->window = SDL_CreateWindow(
                                  settings->TITRE,
                                  settings->POSITIONX,
                                  settings->POSITIONY,
                                  settings->LARGEUR,
                                  settings->HAUTEUR,
                                  (settings->FULLSCREEN == true) ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_BORDERLESS
                                 );
  
  if (game->window == NULL)
  {
    GAME_ERROR = "The window failed to initialize. SDL ERROR: " + SDL_GetError();
    GAME_ERRORFR = "La fenêtre a échoué l'initialisation. SDL ERROR: " + SDL_GetError();
    return GAME_WINDOW_CREATION_FAILURE;
  }
  
  game->renderer = SDL_CreateRenderer(game->window, -1, 0);
  
  if (game->renderer == NULL)
  {
    GAME_ERROR = "The renderer failed to initialize. SDL ERROR: " + SDL_GetError();
    GAME_ERRORFR = "Le renderer a échoué l'initialisation. SDL ERROR: " + SDL_GetError();
    return GAME_RENDERER_CREATION_FAILURE;
  }
  
  game->isRunning = true;
  return GAME_INIT_SUCCESS;
}
