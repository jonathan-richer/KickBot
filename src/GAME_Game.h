#include <SDL2/SDL.h>

/**
 ****************************************************
 * L'implémentation de vrai/faux pour le programme. *
 ****************************************************
 * Program's implementation of boolean.             *
 ****************************************************
 */

typedef enum {
  false = 0,
  true  = 1
} GAME_Bool;



/**
 *********************************************
 * Les séquences possibles de l'application. *
 *********************************************
 * The application's possible stages.        *
 *********************************************
 */
enum GAME_Stage {
  MENU     = 0,
  IN_GAME  = 1
};



/**
 *****************************************************************************************
 * Les valeurs possibles que GAME_Init peut retourner                                    *
 * avec les codes d'erreur:                                                              *
 *     SUCESS                     : Tout va bien, tout est initialisé.                   *
 *     SDL_INIT_FAILURE           : SDL a eu un problème lors de SDL_Init.               *
 *     WINDOW_CREATION_FAILURE    : La fenêtre n'a pas pu être initialisée.              *
 *     RENDERER_CREATION_FAILURE  : Le renderer n'a pas pu être initialisé.              *
 *****************************************************************************************
 * The possible values that GAME_Init can return                                         *
 * with the error codes associated with it:                                              *
 *     SUCESS                     : Everything is right, everything is initialized.      *
 *     SDL_INIT_FAILURE           : SDL had a problem to initialize at SDL_Init.         *
 *     WINDOW_CREATION_FAILURE    : The window had an error during the initialization.   *
 *     RENDERER_CREATION_FAILURE  : The renderer had an error during the initialization. *
 *****************************************************************************************
 */

typedef enum {
  SUCCESS                    =  0,
  SDL_INIT_FAILURE           = -1,
  WINDOW_CREATION_FAILURE    = -2,
  RENDERER_CREATION_FAILURE  = -3
} GAME_INIT_ReturnCode;



/**
 *******************************************************
 * La structure qui contient les variables nécessaires *
 * à l'application.                                    *
 *******************************************************
 * The data structure that contains the application's  *
 * needed variables.                                   *
 *******************************************************
 */

typedef struct
{
  /**
   ********************************
   * La fenêtre de l'application. *
   ********************************
   * The application's window.    *
   ********************************
   */
  SDL_Window        *window     = NULL;

  /**
   **********************************************************
   * La structure qui contient le contenu de la fenêtre.    *
   **********************************************************
   * The data structure that contains the window's content. *
   **********************************************************
   */
  SDL_Renderer      *renderer   = NULL;

  /**
   ************************************************************
   * La variable qui définit si l'application <<run>>.        *
   ************************************************************
   * The variable that defines if the application is running. *
   ************************************************************
   */
  GAME_Bool          isRunning  = false;

  /**
   **********************************************
   * La séquence qui est actuellement en action *
   **********************************************
   * The stage that's currently running         *
   **********************************************
   */
  GAME_Stage         stage      = MENU;

} GAME_Game;



/**
 ****************************************************************
 * La structure qui définit les constantes de l'application.    *
 ****************************************************************
 * The data structure that defines the application's constants. *
 ****************************************************************
 */

struct GAME_AppSettings
{
  /**
   ***************************************************
   * Le x et le y de la fenêtre relativement au coin *
   * en-haut à gauche de l'écran. (non-définit)      *
   ***************************************************
   * The window's x and y coordinates relatively to  *
   * the top-left corner of the screen. (undefined)  *
   ***************************************************
   */
  const unsigned int POSITIONX  = SDL_WINDOWPOS_UNDEFINED;
  const unsigned int POSITIONY  = SDL_WINDOWPOS_UNDEFINED;

  /**
   ***********************************************************************
   * La hauteur (720px) et la largeur (940px) de la fenêtre. (en pixels) *
   ***********************************************************************
   * The window's width (940px) and height (720px). (in pixels)          *
   ***********************************************************************
   */
  const unsigned int LARGEUR     = 940;
  const unsigned int HAUTEUR     = 720;

  /**
   ******************************
   * Le titre de l'application. *
   ******************************
   * The application's title.   *
   ******************************
   */
  const char*        TITRE       = "Kick The Bot - par Yannick Desrosiers et Jonathan Richer dit Laflèche";

  /**
   **********************************************************
   * Si la fenêtre est plein écran. (si faux: sans bordure) *
   **********************************************************
   * If the window is fullscreen. (if false: borderless)    *
   **********************************************************
   */
  const GAME_Bool    FULLSCREEN  = false;  

} GAME__settings;



/**
 ****************************************************************
 * La fonction qui initialise l'application.                    *
 * Si elle retourn < 0, ERREUR!!!!!!! voir GAME_INIT_ReturnCode *
 ****************************************************************
 * The application's initialization function.                   *
 * If returns < 0, ERROR!!!!!!!       see GAME_INIT_ReturnCode  *
 ****************************************************************
 */

GAME_INIT_ReturnCode GAME_Init(GAME_Game *game, GAME_AppSettings &settings);



/**
 *************************************************
 * La fonction qui termine l'application.        *
 *************************************************
 * The function that terminates the application. *
 *************************************************
 */

void GAME_Quit(GAME_Game *game);



/**
 ********************************************************
 * La fonction qui dessine le contenu de la fenêtre.    *
 ********************************************************
 * The function that renders the content on the window. *
 ********************************************************
 */

void GAME_Render(GAME_Game *game);



/**
 ***********************************************
 * La fonction qui met à jour les variables    *
 * de l'application à chaque frame.            *
 ***********************************************
 * The function that updates the application's *
 * variable each frame.                        *
 ***********************************************
 */

void GAME_Update(GAME_Game *game);
