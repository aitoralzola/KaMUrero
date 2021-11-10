#include "sdlHasieratu.h"

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Renderer* gRenderer;
/* AUDIOA */
Mix_Music* gMusic = NULL;

TTF_Font* font = 0;

int SDLHasi()
{
    int hasieratua = 0;

    if (TTF_Init() < 0)
    {
        printf("SDL_TTF couldn't initialize!, SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        textuaGaitu();
    }

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }
    else
    {

        window = SDL_CreateWindow("KaMUrero", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN);
        gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (window == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        }
        else
        {
            screenSurface = SDL_GetWindowSurface(window);
            hasieratua = 1;
        }
    }

    return hasieratua;
}

void textuaGaitu()
{
    font = TTF_OpenFontIndex("C:\\Windows\\Fonts\\Arial.TTF", 20, 0);
    if (!font)
    {
        printf("TTF_OpenFontIndex: %s\n", TTF_GetError());
    }
}

void textuaIdatzi(int x, int y, char* str)
{
    SDL_Surface* textSurface;
    SDL_Texture* mTexture;
    SDL_Color textColor = { 0, 0, 0};
    SDL_Rect src, dst;

    if (font == 0)
    {
        textuaGaitu();
    }
    textSurface = TTF_RenderText_Blended(font, str, textColor);
    mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
    src.x = 0; dst.x = x;
    src.y = 0; dst.y = y;
    src.w = dst.w = textSurface->w;
    src.h = dst.h = textSurface->h;
    SDL_RenderCopy(gRenderer, mTexture, &src, &dst);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(mTexture);
}

void textuaDesgaitu()
{
    if (font != 0)
    {
        TTF_CloseFont(font);
        font = 0;
        SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
        SDL_RenderClear(gRenderer);
        irudiakMarraztu();
    }
}

int irudiaMarraztu(SDL_Texture* texture, SDL_Rect* pDest)
{
    SDL_Rect source;

    source.x = 0;
    source.y = 0;
    source.w = pDest->w;
    source.h = pDest->h;
    SDL_RenderCopy(gRenderer, texture, &source, pDest);

    return 0;
}

void bukatu()
{
    Mix_FreeMusic(gMusic);
    gMusic = NULL;
    SDL_DestroyWindow(window);
    window = NULL;
    Mix_Quit();
    SDL_Quit();
}