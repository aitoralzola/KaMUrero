#ifndef SDLHASIERATU_H
#define SDLHASIERATU_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <SDL.h>
#include <time.h>
#include <Windows.h>
#include <SDL_ttf.h>
#include "irudiak.h"
#include <SDL_mixer.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 800
#define GAME_OVER -1

SDL_Renderer * gRenderer;

int SDLHasi();
int irudiaMarraztu(SDL_Texture* texture, SDL_Rect* pDest);
void textuaGaitu(void);
void textuaIdatzi(int x, int y, char* str);
void textuaDesgaitu(void);
void bukatu();

#endif