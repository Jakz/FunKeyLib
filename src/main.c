#include <stdio.h>
#include <SDL/SDL.h>

#include "menu.h"

FILE* __cdecl __iob_func(void)
{
  FILE _iob[] = { *stdin, *stdout, *stderr };
  return _iob;
}

int main(int argc, char* argv[])
{
  
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    return -1;

  SDL_Surface* surface = SDL_SetVideoMode(240, 240, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

  int exit = 0;
  SDL_Event event;

  while (!exit)
  {
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
        case SDL_QUIT: exit = 1; break;
        case SDL_KEYDOWN:
        {
          if (event.key.keysym.sym == SDLK_ESCAPE)
            exit = 1;
        }
        case SDLK_h:
        {
          FK_InitMenu();
          FK_RunMenu(surface);
        }
      }
    }

    uint32_t color = SDL_MapRGB(surface->format, rand() % 256, rand() % 256, rand() % 256);
    SDL_FillRect(surface, NULL, color);
    SDL_Flip(surface);
  }






  SDL_FreeSurface(surface);
  SDL_Quit();

  return 0;
}