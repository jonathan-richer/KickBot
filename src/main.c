#include <stdio.h>
#include "GAME_Game.h"

// Déclare le pointeur qui pointe le GAME_Game.
GAME_Game *game = NULL;

int main(void)
{
  // Initialise le jeu.
  GAME_Init(game, GAME_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, false);
  
  while (game->isRunning)
  {
    GAME_HandleEvents(game);
    GAME_Update(game);
    GAME_Render(game);
  }
  
  // Termine le jeu.
  GAME_Quit(game);
  return 0;
}
