#include <SDL2/SDL.h>

/**
 * L'implémentation de vrai/faux pour le programme.
 */
typedef enum {
  false = 0,
  true  = 1
} GAME_Bool;

/**
 * La structure qui contient les données nnécessaires au jeu.
 */
typedef struct
{
  // La position de la fenêtre est non définie.
  const unsigned int POSITIONX = SDL_WINDOWPOS_UNDEFINED;
  const unsigned int POSITIONY = SDL_WINDOWPOS_UNDEFINED;
  
  // La hauteur et la largeur de la fenêtre.
  const unsigned int LARGEUR   = 940;
  const unsigned int HAUTEUR   = 720;
  
  // Le titre de la fenêtre.
  const char *TITRE            = "Kick The Bot - par Yannick Desrosiers et Jonathan Richer dit Laflèche";
  
  // Les variables pour la fenêtre.
  SDL_Window   *window         = NULL;
  SDL_Renderer *renderer       = NULL;
  GAME_Bool     isRunning      = false;
} GAME_Game;
